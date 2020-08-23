//
// Created by Nikolay Shulga on 2019-06-18.
//

#include "deserialize.h"

// STL
#include <string>

// RapidJSON
#include "document.h"
#include "rapidjson.h"

using namespace rapidjson;

// Input data format/parsing.
// Input is a JSON file. The root object is an array called "lines". These are line segments.
// Each line segment has an id "id" (string), starting point "start and an end point "end".
// Points are represented as an array of two doubles. These correspond to X and Y cartesian coordinates.

void deserialize(Document& doc) {
    auto const& lines_json = doc["lines"];
    if (lines_json.IsArray()){
        auto lines_array = lines_json.GetArray();
        for (auto& line : lines_array) {
            auto const& id_json = line["id"];
            auto const& start_json = line["start"];
            auto const& end_json = line["end"];
            if (id_json.IsString() && start_json.IsArray() && end_json.IsArray()) {
                auto start_x = start_json.GetArray()[0].GetDouble(),
                    start_y = start_json.GetArray()[1].GetDouble(),
                    end_x = end_json.GetArray()[0].GetDouble(),
                    end_y = end_json.GetArray()[1].GetDouble();

                auto id = id_json.GetString();
            }
        }
    }
}

void deserialize_from_string(std::string const &json_data){
    Document doc;
    doc.Parse(json_data.c_str());
    deserialize(doc);
}