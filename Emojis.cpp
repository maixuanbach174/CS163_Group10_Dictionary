#include "Emojis.hpp"

void readEmoji(vector<wstring>& emos, vector<wstring>& defs)
{
	wifstream in("DataSet/emoji_df.csv");
	_setmode(_fileno(stdin), _O_U8TEXT);
	_setmode(_fileno(stdout), _O_U8TEXT);
	locale loc(locale(), new codecvt_utf8_utf16<wchar_t>);
	in.imbue(loc);
	if (!in)
		wcout << "Can't open";
	wstring line, emo, limiter = L",", def;
	while (getline(in, line))
	{
		size_t pos = line.find(limiter);
		emo = line.substr(0, pos);
		def = line.substr(pos + 1);
		emos.push_back(emo);
		defs.push_back(def);
	}
	in.close();
}
