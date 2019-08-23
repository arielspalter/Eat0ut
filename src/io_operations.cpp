#include "../include/io_operations.h"
#include <iostream>
#include <string>

std::string ioperations::ToLower(std::string input_string)
{
    std::string output_string;
    for (size_t i = 0; i < input_string.size(); i++)
    {
        output_string.push_back(tolower(input_string[i]));
    }
    return output_string;
}