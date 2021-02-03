//
// Created by Yousif Alebyary on 3/2/2021.
//

#include "ResourcePath.hpp"
#include <filesystem>

std::string resourcePath(void) {
    std::__fs::filesystem::path p = "Resources";
    return std::__fs::filesystem::absolute(p).string() + '/';
}
