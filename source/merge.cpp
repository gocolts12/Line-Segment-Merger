#pragma once
#define _USE_MATH_DEFINES

#include "linesegment.h"
//#include "hash.h"

#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
#include <utility>
#include <cmath>
#include <thread>
#include <iostream>
#include <mutex>


std::mutex mutex;

std::vector<LineSegment> mergeHelper(std::vector<LineSegment>& lineSegments)
{
	//First we sort the collinear lines on the start_x in order 
	//to transpose all segments onto a single axis. The advantage of this is 
	//it allows us to only traverse the list once, and we can simply compare
	//each element to the next in the list based on their x_start values
	std::sort(begin(lineSegments), end(lineSegments), [](const auto& l, const auto& r) { return l < r; });

	//Help performance a bit by caching the size in a variable
	int vecSize = lineSegments.size();

	for (int i = 0; i < vecSize; ++i)
	{
		//Check if we're at the last element and just break out of the loop because the work is done
		if (i == (vecSize - 1)) break;
		else
		{
			//We need to check if the slopes are undefined (or infinity, for the purposes
			//of this program. If they are, all the x values will all be equal, 
			//so we need to compare y values instead
			if (std::isinf(lineSegments[i].getSlope()) && std::isinf(lineSegments[i+1].getSlope()))
			{
				if (lineSegments[i].get_start_y() <= lineSegments[i + 1].get_start_y()
					&& lineSegments[i + 1].get_start_y() <= lineSegments[i].get_end_y())
				{
					//Now we construct a new line segment using the extrema of x and y of the two segments
					LineSegment mergedLine(std::min(lineSegments[i].get_start_x(), lineSegments[i + 1].get_start_x()),
						std::min(lineSegments[i].get_start_y(), lineSegments[i + 1].get_start_y()),
						std::max(lineSegments[i].get_end_x(), lineSegments[i + 1].get_end_x()),
						std::max(lineSegments[i].get_end_y(), lineSegments[i + 1].get_end_y()), lineSegments[i].get_id());

					//Overwrite the first segment with the new segment,  
					//and remove the second line segment used in the merge
					lineSegments[i] = mergedLine;
					std::vector<LineSegment>::iterator it = lineSegments.begin() + (i + 1);
					lineSegments.erase(it);

					//Decrease the size of the vector and move the loop control
					//variable back because the list size has changed
					vecSize--;
					i--;
				}
			}

			//If the next line's x1 lies between the current line's x values, they must
			//overlap, so we merge them
			else if (lineSegments[i].get_start_x() <= lineSegments[i + 1].get_start_x()
				&& lineSegments[i + 1].get_start_x() <= lineSegments[i].get_end_x())
			{
				//Now we construct a new line segment using the extrema of x and y of the two segments
				LineSegment mergedLine(std::min(lineSegments[i].get_start_x(), lineSegments[i + 1].get_start_x()),
					std::min(lineSegments[i].get_start_y(), lineSegments[i + 1].get_start_y()),
					std::max(lineSegments[i].get_end_x(), lineSegments[i + 1].get_end_x()),
					std::max(lineSegments[i].get_end_y(), lineSegments[i + 1].get_end_y()), lineSegments[i].get_id());

				//Overwrite the first segment with the new segment,  
				//and remove the second line segment used in the merge
				lineSegments[i] = mergedLine;
				std::vector<LineSegment>::iterator it = lineSegments.begin() + (i + 1);
				lineSegments.erase(it);

				//Decrease the size of the vector and move the loop control
				//variable back because the list size has changed
				vecSize--;
				i--;
			}
		}
	}
	return lineSegments;
}

void thread_mergeLines(std::map<std::pair<double, double>, std::vector<LineSegment>>& collinearLinesMap, const unsigned totalThreads,
					   const unsigned threadID, std::vector<std::pair<double, double>> keys, std::vector<LineSegment> &resultVec)
{
	const int threadStart = threadID * totalThreads / totalThreads;
	const int threadEnd = (threadID + 1) * totalThreads / totalThreads;

	for (int i = threadStart; i < threadEnd; i++)
	{
		mutex.lock();
		auto l = mergeHelper(collinearLinesMap[keys[i]]);
		mutex.unlock();
		resultVec.insert(resultVec.begin(), l.begin(), l.end());
	}
	
}

std::vector<LineSegment> mergeLines(std::map<std::pair<double, double>, std::vector<LineSegment>>& collinearLinesMap)
{
	std::vector<LineSegment> resultVector1;
	std::vector<LineSegment> resultVector2;
	std::vector<std::pair<double, double>> keysVec;

	for (auto& i : collinearLinesMap)
	{
		keysVec.push_back(i.first);
	}

	std::thread t0(thread_mergeLines, collinearLinesMap, 2, 0, keysVec, resultVector1);
	std::thread t1(thread_mergeLines, collinearLinesMap, 2, 1, keysVec, resultVector2);

	t0.join();
	t1.join();
	
	resultVector1.insert(resultVector1.begin(), resultVector2.begin(), resultVector2.end());

	return resultVector1;
}
std::map < std::pair<double, double>, std::vector<LineSegment>> collinearMapInsertion(std::vector<LineSegment>& lineSegments)
{
	//We use a map containing the slope and yIntercept mapping to a vector 
	//of line segments that have equal slopes and y intercepts. All this lines are
	//collinear, and therefore may be mergeable. Not the cleanest map implementation,
	//but lets get it working first
	std::map<std::pair<double, double>, std::vector<LineSegment>> collinearLinesMap;

	for (auto& i : lineSegments)
	{
		auto slopeInterceptPair = std::make_pair(i.getSlope(), i.getYIntercept());
		auto search = collinearLinesMap.find(slopeInterceptPair);

		//If the slope-intercept combo doesn't exist in the map, make a new 
		//entry and insert
		if (search == collinearLinesMap.end())
		{
			std::vector<LineSegment> lines;
			lines.push_back(i);
			collinearLinesMap.insert(std::make_pair(slopeInterceptPair, lines));
		}
		//Otherwise we have the slope-intercept combo in the map already
		//so just append the segment to the list of collinear segments
		else
		{
			collinearLinesMap[slopeInterceptPair].push_back(i);
		}
	}
	return collinearLinesMap;
}