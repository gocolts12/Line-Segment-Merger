//
// Created by Nikolay Shulga on 2019-06-18.
//
#pragma once

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>
#include <map>
#include <utility>
#include <chrono>

#include "deserialize.h"
#include "merge.h"

using namespace std::chrono;

//// stub to test the framework. Replace/modify as needed.
//TEST_CASE("no merges") {
//
//    auto start = std::chrono::high_resolution_clock::now();
//
//    std::string input{ "{\"lines\":[{\"id\":\"0-1\",\"start\":[373.44034013711515,-582.9714893905727],\"end\":[562.5097926743379,67.6201009971137]},{\"id\":\"0-2\",\"start\":[-395.24361297250138,-598.0232377709511],\"end\":[373.44034013711515,-582.9714893905727]}]}" };
//    std::vector<LineSegment> resultVector = deserialize_from_string(input);
//    auto map = collinearMapInsertion(resultVector);
//    resultVector = mergeLines(map);
//
//    std::vector<LineSegment> test_case_lines;
//    //use emplace for easy push_back in-place
//    test_case_lines.emplace_back(-395.24361297250138, -598.0232377709511, 373.44034013711515, -582.9714893905727, "0-2");
//    test_case_lines.emplace_back(373.44034013711515, -582.9714893905727, 562.5097926743379, 67.6201009971137, "0-1");
//
//    //Sort for assurance of equality
//    std::sort(begin(test_case_lines), end(test_case_lines), [](const auto& l, const auto& r) { return l < r; });
//    std::sort(begin(resultVector), end(resultVector), [](const auto& l, const auto& r) { return l < r; });
//
//    REQUIRE(test_case_lines == resultVector);
//    auto end = std::chrono::high_resolution_clock::now();
//    std::cout << "Time taken: " << std::chrono::duration_cast<microseconds>(end - start).count() << std::endl;
//
//}
//
//TEST_CASE("single line, no merge possible") {
//    auto start = std::chrono::high_resolution_clock::now();
//
//    std::string input{ "{\"lines\":[{\"id\":\"0-1\",\"start\":[373.44034013711515,-582.9714893905727],\"end\":[562.5097926743379,67.6201009971137]}]}" };
//    std::vector<LineSegment> resultVector = deserialize_from_string(input);
//    auto map = collinearMapInsertion(resultVector);
//    resultVector = mergeLines(map);
//
//
//    std::vector<LineSegment> test_case_lines;
//    //use emplace for easy push_back in-place
//    test_case_lines.emplace_back(373.44034013711515, -582.9714893905727, 562.5097926743379, 67.6201009971137, "0-1");
//
//
//    REQUIRE(test_case_lines == resultVector);
//    auto end = std::chrono::high_resolution_clock::now();
//    std::cout << "Time taken: " << std::chrono::duration_cast<microseconds>(end - start).count() << std::endl;
//
//}
//
//TEST_CASE("merge all lines into one") {
//    auto start = std::chrono::high_resolution_clock::now();
//
//    std::string input{ "{\"lines\":[{\"id\":\"0-1\",\"start\":[1.0,1.0],\"end\":[3.0,3.0]},{\"id\":\"0-3\",\"start\":[4.0,4.0],\"end\":[7.0,7.0]},{\"id\":\"0-2\",\"start\":[2.0,2.0],\"end\":[5.0,5.0]}]}" };
//    std::vector<LineSegment> resultVector = deserialize_from_string(input);
//    auto map = collinearMapInsertion(resultVector);
//    resultVector = mergeLines(map);
//
//    std::vector<LineSegment> test_case_lines;
//    //use emplace for easy push_back in-place
//    test_case_lines.emplace_back(1.0, 1.0, 7.0, 7.0, "0-1");
//
//    //Sort for assurance of equality
//    std::sort(begin(test_case_lines), end(test_case_lines), [](const auto& l, const auto& r) { return l < r; });
//    std::sort(begin(resultVector), end(resultVector), [](const auto& l, const auto& r) { return l < r; });
//
//    REQUIRE(test_case_lines == resultVector);
//    auto end = std::chrono::high_resolution_clock::now();
//    std::cout << "Time taken: " << std::chrono::duration_cast<microseconds>(end - start).count() << std::endl;
//
//}
//
TEST_CASE("merge multiple separate sets ") {
    auto start = std::chrono::high_resolution_clock::now();

    std::string input{ "{\"lines\":[{\"id\":\"0-1\",\"start\":[1.0,1.0],\"end\":[4.0,4.0]},{\"id\":\"0-2\",\"start\":[3.0,3.0],\"end\":[7.0,7.0]}, {\"id\":\"0-3\",\"start\":[0.0,2.0],\"end\":[2.0,4.0]}, {\"id\":\"0-4\",\"start\":[1.0,3.0],\"end\":[4.0,6.0]}]}"};
    std::vector<LineSegment> resultVector = deserialize_from_string(input);
    auto map = collinearMapInsertion(resultVector);
    resultVector = mergeLines(map);

    std::vector<LineSegment> test_case_lines;
    //use emplace for easy push_back in-place
    test_case_lines.emplace_back(1.0, 1.0, 7.0, 7.0, "0-1");
    test_case_lines.emplace_back(0.0, 2.0, 4.0, 6.0, "0-3");

    //Sort for assurance of equality
    std::sort(begin(test_case_lines), end(test_case_lines), [](const auto& l, const auto& r) { return l < r; });
    std::sort(begin(resultVector), end(resultVector), [](const auto& l, const auto& r) { return l < r; });


    REQUIRE(test_case_lines == resultVector);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Time taken: " << std::chrono::duration_cast<microseconds>(end - start).count() << std::endl;

}
//
//TEST_CASE("merge 2 vertical lines") {
//    auto start = std::chrono::high_resolution_clock::now();
//
//    std::string input{ "{\"lines\":[{\"id\":\"0-1\",\"start\":[0.0,0.0],\"end\":[0.0,3.0]},{\"id\":\"0-2\",\"start\":[0.0,3.0],\"end\":[0.0,5.0]}]}" };
//    
//    std::vector<LineSegment> resultVector = deserialize_from_string(input);
//    
//    auto map = collinearMapInsertion(resultVector);
//    
//    resultVector = mergeLines(map);
//
//    std::vector<LineSegment> test_case_lines;
//
//    //use emplace for easy push_back in-place
//    test_case_lines.emplace_back(0.0, 0.0, 0.0, 5.0, "0-1");
//
//    //Sort both for assurance of equality
//    std::sort(begin(test_case_lines), end(test_case_lines), [](const auto& l, const auto& r) { return l < r; });
//    std::sort(begin(resultVector), end(resultVector), [](const auto& l, const auto& r) { return l < r; });
//
//    REQUIRE(test_case_lines == resultVector);
//    auto end = std::chrono::high_resolution_clock::now();
//    std::cout << "Time taken: " << std::chrono::duration_cast<microseconds>(end - start).count() << std::endl;
//
//}
//
//TEST_CASE("2 vertical lines that do not merge") {
//    auto start = std::chrono::high_resolution_clock::now();
//
//    std::string input{ "{\"lines\":[{\"id\":\"0-1\",\"start\":[0.0,0.0],\"end\":[0.0,3.0]},{\"id\":\"0-2\",\"start\":[0.0,4.0],\"end\":[0.0,5.0]}]}" };
//
//    std::vector<LineSegment> resultVector = deserialize_from_string(input);
//
//    auto map = collinearMapInsertion(resultVector);
//
//    resultVector = mergeLines(map);
//
//    std::vector<LineSegment> test_case_lines;
//
//    //use emplace for easy push_back in-place
//    test_case_lines.emplace_back(0.0, 0.0, 0.0, 3.0, "0-1");
//    test_case_lines.emplace_back(0.0, 4.0, 0.0, 5.0, "0-2");
//
//    //Sort both for assurance of equality
//    std::sort(begin(test_case_lines), end(test_case_lines), [](const auto& l, const auto& r) { return l < r; });
//    std::sort(begin(resultVector), end(resultVector), [](const auto& l, const auto& r) { return l < r; });
//
//    REQUIRE(test_case_lines == resultVector);
//    auto end = std::chrono::high_resolution_clock::now();
//    std::cout << "Time taken: " << std::chrono::duration_cast<microseconds>(end - start).count() << std::endl;
//
//}