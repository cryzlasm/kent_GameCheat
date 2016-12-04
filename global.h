#pragma once

extern log4cpp::Category& kent_log;
extern inline wstring UTF8ToUnicode(const string& str);
extern inline string UnicodeToUTF8(const wstring& str);
extern inline wstring ANSIToUnicode(const string& str);
extern inline string UnicodeToANSI(const wstring& str);
extern inline wstring ASCIIToUnicode(const string& str);
extern inline string UnicodeToASCII(const wstring& str);