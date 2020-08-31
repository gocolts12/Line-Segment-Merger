#pragma once
#include "linesegment.h"
#include <hash.h>

#include <vector>
#include <utility>
#include <unordered_map>

#ifndef merge_H
#define merge_H

std::unordered_map<Key, std::vector<LineSegment>> collinearMapInsertion(std::vector<LineSegment>& lineSegments);

std::vector<LineSegment> mergeHelper(std::vector<LineSegment> &lineSegments);
std::vector<LineSegment> mergeLines(std::unordered_map<Key, std::vector<LineSegment>>& collinearMap);


#endif