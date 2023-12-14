#pragma once

#include <string>
#include <vector>
class StringUtil
{
public:
	static std::string GBKtoUTF8(const std::string& str);
	static std::string UTF8toGBK(const std::string& strSrc);
	static std::vector<std::string> StringSplit(const std::string& str, char delim);
};

