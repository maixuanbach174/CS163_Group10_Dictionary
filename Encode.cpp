#include "Encode.h"

string decToHexa(int n)
{
    string result;

    while(n)
    {
        int rem;
        char c;

        rem = n % 16;

        if(rem < 10)
        {
            c = '0' + rem;
        } else
        {
            c = 'A' + rem - 10;
        }

        result = c + result;

        n /= 16;
    }

    return result;
}

string unicodeToUtf8(const wstring& unicodeString) {
    string utf8String;
 
    for (const wchar_t& wchar : unicodeString) {
        if (wchar <= 0x7F) {
            utf8String += static_cast<char>(wchar);
        } else if (wchar <= 0x7FF) {
            utf8String += static_cast<char>(0xC0 | ((wchar >> 6) & 0x1F));
            utf8String += static_cast<char>(0x80 | (wchar & 0x3F));
        } else if (wchar <= 0xFFFF) {
            utf8String += static_cast<char>(0xE0 | ((wchar >> 12) & 0x0F));
            utf8String += static_cast<char>(0x80 | ((wchar >> 6) & 0x3F));
            utf8String += static_cast<char>(0x80 | (wchar & 0x3F));
        } else {
            utf8String += static_cast<char>(0xF0 | ((wchar >> 18) & 0x07));
            utf8String += static_cast<char>(0x80 | ((wchar >> 12) & 0x3F));
            utf8String += static_cast<char>(0x80 | ((wchar >> 6) & 0x3F));
            utf8String += static_cast<char>(0x80 | (wchar & 0x3F));
        }
    }
    string toconv = "";
    for (const unsigned char& byte : utf8String) {
        toconv += decToHexa(byte);
        toconv += "#";
    }
    toconv.pop_back();
    return toconv;
}