#include <iostream>
#include <fstream>
#include <string>
#include <io.h>
#include <codecvt>
#include <fcntl.h>
#include <vector>
#include "VieTrie.h"
using namespace std;


void readEmoji(VieTrieNode* root, vector<wstring>& emo, vector<wstring>& def)
{
	wifstream in("emoticons.txt");
	_setmode(_fileno(stdin), _O_U8TEXT);
	_setmode(_fileno(stdout), _O_U8TEXT);
	locale loc(locale(), new codecvt_utf8_utf16<wchar_t>);
	in.imbue(loc);
	//out.imbue(loc);
	if (!in)
		cout << "Can't open";
	wstring line, emoSub, limiter = L"  ", defSub;
	while (getline(in, line))
	{
		size_t pos = line.find(limiter);
		emoSub = line.substr(0, pos);
		defSub = line.substr(pos + 1);
		emo.push_back(emoSub);
		def.push_back(defSub);
		//wcout << line;
	}
	in.close();
}

int main()
{
	VieTrieNode* root = new VieTrieNode();
	readEmoji(root);
	return 0;
}


//int main()
//{
//	VieTrieNode* root = new VieTrieNode();
//	readEmoji(root);
//	return 0;
//}
