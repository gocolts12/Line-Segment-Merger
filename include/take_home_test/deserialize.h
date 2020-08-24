//
// Created by Nikolay Shulga on 2019-06-18.
//
// Stub code to test the framework. Feel free to ignore or change.
//
#pragma once
#ifndef TAKE_HOME_TEST_DESERIALIZE_H
#define TAKE_HOME_TEST_DESERIALIZE_H

// STL
#include <string>
#include "linesegment.h"
#include <vector>

std::vector<LineSegment> deserialize_from_string(std::string const& json_data);

#endif //TAKE_HOME_TEST_DESERIALIZE_H
