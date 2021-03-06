/*************************************************************************
�ı��Ժ�è�̶���SHA256���룺http://blog.csdn.net/c_duoduo/article/details/43889759
*************************************************************************/
#pragma once

namespace CryptoLib {
class Hash_SHA256 {
public:
	static STRX Generate(STRX dat);
	static STRX GenerateFile(STRX filename);

protected:
	static char* StrSHA256(const char* str, long long length, char* sha256);
	static char* FileSHA256(const char* file, char* sha256);
};
}