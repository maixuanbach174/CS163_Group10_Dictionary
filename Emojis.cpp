#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <sstream>
#include <io.h>
#include <codecvt>
#include <fcntl.h>
#include "Trie.h";
using namespace std;


void readEmoji(VieTrieNode* root)
{
	ifstream in("emoji_df.csv");
	ofstream out("Text1.txt");
	SetConsoleOutputCP(CP_UTF8);
	locale loc(locale(), new codecvt_utf8_utf16<wchar_t>);
	in.imbue(loc);
	if (!in)
		cout << "Can't open";
	string line, emo, limiter = ",", def;
	while (getline(in, line))
	{
		out << line;
		size_t pos = line.find(limiter);
		emo = line.substr(0, pos);
		def = line.substr(pos + 1);
		string sub;
		stringstream input(def), modifiedStream;
		while (getline(input, sub, ',')) 
			modifiedStream << sub << "\n";
		def = modifiedStream.str();
		out << emo << " " << def << endl;
		insert(root, emo, def);
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
