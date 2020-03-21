#include <iostream>
#include <cpp_json_reader.hpp>

int main(int argc, char *argv[]) {
    std::cout << "Hello World" << std::endl;
    JSONObject myObj(argv[1]);
    std::cout << "File reading complete" << std::endl;
    return 0;
}