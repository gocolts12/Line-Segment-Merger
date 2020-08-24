#include <iostream>
#include "deserialize.h"
#include "linesegment.h"
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <utility>
#pragma once

int main() {

	//Sample input to test sorting lamba. If correct, it will swap 2nd and 3rd element
	std::string input{ "{\"lines\":[{\"id\":\"0-1\",\"start\":[1.0,1.0],\"end\":[3.0,3.0]},{\"id\":\"0-3\",\"start\":[4.0,4.0],\"end\":[7.0,7.0]},{\"id\":\"0-2\",\"start\":[2.0,2.0],\"end\":[5,5]}]}" };
	std::vector<LineSegment> lineSegments = deserialize_from_string(input);

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
			std::cout << "new entry" << std::endl;
			std::vector<LineSegment> lines;
			lines.push_back(i);
			collinearLinesMap.insert(std::make_pair(slopeInterceptPair, lines));
		}
		//Otherwise we have the slope-intercept combo in the map already
		//so just append the segment to the list of collinear segments
		else 
		{ 
			std::cout << "found entry already" << std::endl;
			collinearLinesMap[slopeInterceptPair].push_back(i); 
		}

	}

	
	for (auto &i : collinearLinesMap)
	{
		std::cout << i.second.size();
	}

	//When we sort, we sort based on start_x to transpose all segments onto a single axis
	//std::sort(begin(lineSegments), end(lineSegments), [](auto l, auto r) {
	//	return l < r; });

	//std::cout << lineSegments[1].get_start_x() << lineSegments[2].get_start_x() << std::endl;

}