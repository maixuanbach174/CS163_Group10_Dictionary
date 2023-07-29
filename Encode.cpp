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
    }
    return toconv;
}
wstring UTF8toUnicode(const string& s)
{
    wstring ws;
    wchar_t wc;
    for (int i = 0; i < s.length(); )
    {
        char c = s[i];
        if ((c & 0x80) == 0)
        {
            wc = c;
            ++i;
        }
        else if ((c & 0xE0) == 0xC0)
        {
            wc = (s[i] & 0x1F) << 6;
            wc |= (s[i + 1] & 0x3F);
            i += 2;
        }
        else if ((c & 0xF0) == 0xE0)
        {
            wc = (s[i] & 0xF) << 12;
            wc |= (s[i + 1] & 0x3F) << 6;
            wc |= (s[i + 2] & 0x3F);
            i += 3;
        }
        else if ((c & 0xF8) == 0xF0)
        {
            wc = (s[i] & 0x7) << 18;
            wc |= (s[i + 1] & 0x3F) << 12;
            wc |= (s[i + 2] & 0x3F) << 6;
            wc |= (s[i + 3] & 0x3F);
            i += 4;
        }
        else if ((c & 0xFC) == 0xF8)
        {
            wc = (s[i] & 0x3) << 24;
            wc |= (s[i] & 0x3F) << 18;
            wc |= (s[i] & 0x3F) << 12;
            wc |= (s[i] & 0x3F) << 6;
            wc |= (s[i] & 0x3F);
            i += 5;
        }
        else if ((c & 0xFE) == 0xFC)
        {
            wc = (s[i] & 0x1) << 30;
            wc |= (s[i] & 0x3F) << 24;
            wc |= (s[i] & 0x3F) << 18;
            wc |= (s[i] & 0x3F) << 12;
            wc |= (s[i] & 0x3F) << 6;
            wc |= (s[i] & 0x3F);
            i += 6;
        }
        ws += wc;
    }
    return ws;
}