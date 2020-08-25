#pragma once
#include "linesegment.h"

#include <vector>
#include <utility>
#include <map>

#ifndef merge_H
#define merge_H

std::map < std::pair<double, double>, std::vector<LineSegment>> collinearMapInsertion(std::vector<LineSegment> &lineSegments);

std::vector<LineSegment> mergeHelper(std::vector<LineSegment> &lineSegments);
std::vector<LineSegment> mergeLines(std::map<std::pair<double, double>, std::vector<LineSegment>>& collinearMap);


#endif