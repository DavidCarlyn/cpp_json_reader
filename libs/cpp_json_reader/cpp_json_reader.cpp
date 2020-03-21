#include "cpp_json_reader.hpp"

#include <fstream>
#include <iostream>
#include <cctype>

enum JSONReadState {
    LookingForStart,
    LookingForKeyStart,
    LookingForKeyEnd,
    LookingForValueStart,
    LookingForValueEnd,
    LookingForComma,
    LookingForStringEnd,
    LookingForArrayEnd,
    Finished
};

JSONObject::JSONObject(std::string file) {
    std::ifstream input;
    input.open(file);

    char c;
    JSONReadState state = JSONReadState::LookingForStart;
    std::string stringValue = "";
    while (input.get(c)) {
        switch (state) {
        case LookingForStart:
            if (c == '{') 
                state = JSONReadState::LookingForKeyStart;
            break;
        case LookingForKeyStart:
            if (c == '}') {
                state = JSONReadState::Finished; 
            } else if (c == '\"') {
                state = JSONReadState::LookingForKeyEnd;
            }
            break;
        case LookingForKeyEnd:
            if (c == '\"') {
                state = JSONReadState::LookingForValueStart;
                break;
            }

            stringValue += c;
            break;
        case LookingForValueStart:
            if (c == ':') {
                state = JSONReadState::LookingForValueEnd;
            }
            break;
        case LookingForValueEnd:
            if (!isspace(c)) {
                if (c == '\"') {
                    state = JSONReadState::LookingForStringEnd;
                }
            }
            break;
        case LookingForStringEnd:
            if (c == '\"') {
                state = JSONReadState::LookingForComma;
                break;
            }
            stringValue += c;
            break;
        default:
            break;
        }

        if (state == JSONReadState::Finished) break;
    }

    std::cout << stringValue << std::endl;

    input.close();
}