
#include "StringUtil.h"
#include <sstream>
#include <windows.h>

std::string StringUtil::GBKtoUTF8(const std::string& strSrc)
{
	std::string strout = "";
	WCHAR* strGBK;
	int len = MultiByteToWideChar(CP_ACP, 0, strSrc.c_str(), -1, NULL, 0);
	strGBK = new WCHAR[len];
	MultiByteToWideChar(CP_ACP, 0, strSrc.c_str(), -1, strGBK, len);
	len = WideCharToMultiByte(CP_UTF8, 0, strGBK, -1, NULL, 0, NULL, NULL);
	char* strUTF8 = new char[len];
	WideCharToMultiByte(CP_UTF8, 0, strGBK, -1, strUTF8, len, NULL, NULL);
	strout = strUTF8;
	delete[] strGBK;
	strGBK = NULL;
	delete[] strUTF8;
	strUTF8 = NULL;
	return strout;
}

std::string StringUtil::UTF8toGBK(const std::string& strSrc)
{
	std::string strout = "";
	int len = MultiByteToWideChar(CP_UTF8, 0, strSrc.c_str(), -1, NULL, 0);
	unsigned short* wszGBK = new unsigned short[len + 1];
	memset(wszGBK, 0, len * 2 + 2);
	MultiByteToWideChar(CP_UTF8, 0, strSrc.c_str(), -1, (LPWSTR)wszGBK, len);

	len = WideCharToMultiByte(CP_ACP, 0, (LPWSTR)wszGBK, -1, NULL, 0, NULL, NULL);
	char* szGBK = new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, (LPWSTR)wszGBK, -1, szGBK, len, NULL, NULL);
	strout = szGBK;
	delete[]szGBK;
	delete[]wszGBK;
	return strout;
}



std::vector<std::string> StringUtil::StringSplit(const std::string& str, char delim) {
	std::stringstream ss(str);
	std::string item;
	std::vector<std::string> elems;
	while (std::getline(ss, item, delim)) {
		if (!item.empty()) {
			elems.push_back(item);
		}
	}
	return elems;
}