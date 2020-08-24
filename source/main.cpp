#include <iostream>
#include "deserialize.h"
#include "linesegment.h"
#include <vector>

int main() {

	std::string input{ "{\"lines\":[{\"id\":\"0-1\",\"start\":[373.44034013711515,-582.9714893905727],\"end\":[562.5097926743379,67.6201009971137]},{\"id\":\"0-2\",\"start\":[-395.24361297250138,-598.0232377709511],\"end\":[373.44034013711515,-582.9714893905727]}]}" };
	std::vector<LineSegment> lineSegments = deserialize_from_string(input);
	std::cout << input;
}