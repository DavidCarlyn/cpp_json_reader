/*

    cpp_json_reader.hpp
    Written By: David Carlyn
    Year: 2020

*/

#ifndef JSONOBJECT
#define JSONOBJECT

#include <string>

class JSONObject {
    public:
        JSONObject(std::string file);
    private:
        int data[100];
};

#endif