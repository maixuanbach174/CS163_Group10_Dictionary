#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <sstream>
#include <io.h>
#include <codecvt>
#include <fcntl.h>
#include "VieTrie.h";
using namespace std;


void readEmoji(VieTrieNode* root)
{
	ifstream in("emoji_df.csv");
	SetConsoleOutputCP(CP_UTF8);
	if (!in)
		cout << "Can't open";
	string line, emo, limiter = ",", def;
	while (getline(in, line))
	{
		size_t pos = line.find(limiter);
		emo = line.substr(0, pos);
		def = line.substr(pos + 1);
		#include <windows.h>
#include <string>
#include <sstream>
#include <io.h>
#include <codecvt>
#include <fcntl.h>
#include "VieTrie.h"
using namespace std;


void readEmoji(VieTrieNode* root)
{
	wifstream in("emoji_df.csv");
	_setmode(_fileno(stdin), _O_U8TEXT);
	_setmode(_fileno(stdout), _O_U8TEXT);
	locale loc(locale(), new codecvt_utf8_utf16<wchar_t>);
	in.imbue(loc);
	if (!in)
		cout << "Can't open";
	wstring line, emo, limiter = L",", def;
	while (getline(in, line))
	{
		size_t pos = line.find(limiter);
		emo = line.substr(0, pos);
		def = line.substr(pos + 1);
		VieInsert(root, emo, def);
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

	}
	in.close();
	out.close();
}

//int main()
//{
//	VieTrieNode* root = new VieTrieNode();
//	readEmoji(root);
//	return 0;
//}
