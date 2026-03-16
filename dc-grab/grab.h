#pragma once
#include <vector>
#include <string>
#include <cstdint>

std::string readFile(const std::string& path);
std::vector<uint8_t> getMasterKey();
std::vector<std::string> scanLevelDB(const std::string& dir, const std::vector<uint8_t>& masterKey);
