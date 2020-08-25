#pragma once

#include "deserialize.h"
#include "linesegment.h"
#include "merge.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <utility>

int main() {

	//Sample input to test sorting lamba. If correct, it will swap 2nd and 3rd element
	std::string input{ "{\"lines\":[{\"id\":\"0-1\",\"start\":[1.0,1.0],\"end\":[3.0,3.0]},{\"id\":\"0-3\",\"start\":[4.0,4.0],\"end\":[7.0,7.0]},{\"id\":\"0-2\",\"start\":[2.0,2.0],\"end\":[5,5]}]}" };
	std::vector<LineSegment> lineSegments = deserialize_from_string(input);

	auto collinearLinesMap = collinearMapInsertion(lineSegments);

	std::vector<LineSegment> resultVector = mergeLines(collinearLinesMap);

	std::cin.get();

}