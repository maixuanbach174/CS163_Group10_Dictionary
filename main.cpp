#include <iostream>
// #include <io.h>
// #include <fcntl.h>
#include "Encode.h"
#include "MyHashMap"
using namespace std;

int main()
{
    // _setmode(_fileno(stdin), _O_U8TEXT);
    // _setmode(_fileno(stdout), _O_U8TEXT);

    wstring str = L"Mai Xuân Bách";
    string s = unicodeToUtf8(str);
    cout << s << endl;

    // int num;
    // cin >> num;

    // cout << decToHexa(num) << endl;
    Myhas

    return 0;
}