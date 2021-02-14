#pragma once
#include "linesegment.h"
//#include <hash.h>

#include <vector>
#include <utility>
#include <map>

#ifndef merge_H
#define merge_H

std::map < std::pair<double, double>, std::vector<LineSegment>> collinearMapInsertion(std::vector<LineSegment>& lineSegments);

std::vector<LineSegment> mergeHelper(std::vector<LineSegment> &lineSegments);
std::vector<LineSegment> mergeLines(std::map<std::pair<double, double>, std::vector<LineSegment>>& collinearMap);
void thread_mergeLines(std::map<std::pair<double, double>, std::vector<LineSegment>>& collinearLinesMap, const unsigned totalThreads,
	const unsigned threadID, std::vector<std::pair<double, double>> keys, std::vector<LineSegment>& resultVec);

#endif