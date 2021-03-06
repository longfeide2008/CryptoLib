/************************************************************************
本类为保证DLL安全，所有传入字符串（char*或wchar_t*）均需要初始化分配空间
（new或数组）后再传入，所有函数均不检查长度是否足够，可以使用
stringx::GetAWConvertLength或stringx::GetGUConvertLength
GetADataLength\GetWDataLength等取得字符串转换所需长度，或使用足够大的空间。
比如：
wchar_t* wstr = new wchar[GetAWConvertLength(str)]; 
wchar_t* wstr = new wchar[str.GetWDataLength()];

本类默认为GBK编码，如果传入的字符串是UTF-8编码，请调用SetEncodeUTF8，以
保证得到想要的结果
************************************************************************/
#pragma once

#include <string>
#include <assert.h>
#include <algorithm>
#include "windows.h"
#include <sstream>

typedef char SXCH;
typedef const char SXCCH;
typedef wchar_t SXWCH;
typedef const wchar_t SXCWCH;
typedef char* SXSTR;
typedef const char* SXCSTR;
typedef wchar_t* SXWSTR;
typedef const wchar_t* SXCWSTR;
typedef unsigned long long SXULL;
typedef const unsigned long long SXCULL;
using std::wstring;
using std::string;
#ifdef _UNICODE
typedef wstring tstring;
typedef SXWCH SXTCH;
typedef SXCWCH SXCTCH;
typedef SXWSTR SXTSTR;
typedef SXCWSTR SXCTSTR;
#else
typedef string tstring;
typedef SXCH SXTCH;
typedef SXCCH SXCTCH;
typedef SXSTR SXTSTR;
typedef SXCSTR SXCTSTR;
#endif

class stringx {
public:
	stringx() {};
	stringx(SXCWCH ch, const UINT rep = 1);
	stringx(SXCSTR src);
	stringx(SXCWSTR src);
	stringx(const string& src);
	stringx(const wstring& src);
	stringx(const stringx& src);
	~stringx() {};

	void SetEncodeUTF8() { isutf8_ = true; }
	void SetEncodeGBK()  { isutf8_ = false; }
	stringx& SetString(SXCWCH ch, const UINT rep = 1);
	stringx& SetString(SXCSTR src);
	stringx& SetString(SXCWSTR src);
	stringx& SetString(const string& src);
	stringx& SetString(const wstring& src);
	stringx& SetString(const stringx& src);
	stringx& SetDigit(SXCULL digit);
	string GetString() const;
	wstring GetWString() const;
	tstring GetTString() const;
	SXCWSTR GetData() const;
	SXSTR GetData(SXSTR out) const;
	SXWSTR GetData(SXWSTR out) const;
	SXULL GetDigit() const;
	wstring& GetBuffer();
	int GetADataLength();
	int GetWDataLength();

	bool IsEncodeUTF8() const { return isutf8_; }
	bool IsDigit() const;

	void Empty();
	bool IsEmpty() const;
	SXULL GetLength() const;
	SXWCH GetAt(const int index) const;
	void SetAt(const int index, SXCWCH ch);
	stringx& Append(const stringx& src);
	stringx& Append(SXCWCH ch, const UINT rep = 1);

	SXWCH operator[] (const UINT index) const;
	stringx& operator=(const stringx& src);
	stringx operator+(const stringx& src) const;
	const stringx& operator+=(const stringx& src);

	int Compare(const stringx& src) const;
	int CompareNoCase(const stringx& src) const;
	bool operator == (const stringx& src) const;
	bool operator != (const stringx& src) const;
	bool operator <= (const stringx& src) const;
	bool operator <  (const stringx& src) const;
	bool operator >= (const stringx& src) const;
	bool operator >  (const stringx& src) const;

	stringx& MakeUpper();
	stringx& MakeLower();

	stringx SubStr(UINT from, UINT to) const;
	stringx Left(UINT length) const;
	stringx Mid(UINT pos, int length) const;
	stringx Right(UINT length) const;

	int Find(const stringx& src, const UINT pos = 0) const;
	int Replace(const stringx& src, const stringx& dest);
	stringx& TrimRight();
	stringx& TrimLeft();
	int DeleteChar(SXWCH ch);

	stringx& __cdecl Format(SXCWSTR str, ...);

	stringx& Encode2GBK();
	stringx& Encode2UTF8();

	static int GetAWConvertLength(SXCSTR str);
	static int GetAWConvertLength(SXCWSTR str);
	static int GetGUConvertLength(SXCSTR str);
	static int GetGUConvertLength(SXCWSTR str);

protected:
	wstring str_;
	bool isutf8_ = false;

	static int ToUpper(int c);
	static int ToLower(int c);

	static SXSTR GBK2UTF8(SXCSTR str, SXSTR out);
	static SXWSTR GBK2UTF8(SXCSTR str, SXWSTR out);
	static SXSTR GBK2UTF8(SXCWSTR str, SXSTR out);
	static SXWSTR GBK2UTF8(SXCWSTR str, SXWSTR out);
	static SXSTR UTF82GBK(SXCSTR str, SXSTR out);
	static SXWSTR UTF82GBK(SXCSTR str, SXWSTR out);
	static SXSTR UTF82GBK(SXCWSTR str, SXSTR out);
	static SXWSTR UTF82GBK(SXCWSTR str, SXWSTR out);
	static SXWSTR Str2WStr(SXCSTR str, SXWSTR out);
	static SXSTR WStr2Str(SXCWSTR str, SXSTR out);
};

typedef stringx STRX;
typedef const stringx CSTRX;