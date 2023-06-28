#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
using namespace std;

string decToHexa(int n)
{
    // ans string to store hexadecimal number
    string ans = "";
    
    while (n != 0) {
        // remainder variable to store remainder
        int rem = 0;
          
        // ch variable to store each character
        char ch;
        // storing remainder in rem variable.
        rem = n % 16;
  
        // check if temp < 10
        if (rem < 10) {
            ch = rem + 48;
        }
        else {
            ch = rem + 55;
        }
          
        // updating the ans string with the character variable
        ans += ch;
        n = n / 16;
    }
      
    // reversing the ans string to get the final result
    int i = 0, j = ans.size() - 1;
    while(i <= j)
    {
      swap(ans[i], ans[j]);
      i++;
      j--;
    }
    return ans;
}

std::string unicodeToUtf8(const std::wstring& unicodeString) {
    std::string utf8String;
 
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

int main()
{
    wstring s = L"Mai xuân Bách";

    string result = unicodeToUtf8(s);
    cout << result << endl;

    return 0;
}