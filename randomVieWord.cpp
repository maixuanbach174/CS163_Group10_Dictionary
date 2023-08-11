//#include "VieTrie.h"
#include <iostream>
#include <io.h>
#include <codecvt>
#include <fcntl.h>
#include <fstream>
#include <time.h>
using namespace std;

//struct VieTrieNode
//{
//    VieTrieNode *children[16];
//    bool isEndOfWord;
//    wstring definition;
//    VieTrieNode();
//};
//VieTrieNode::VieTrieNode()
//{
//    for(int i = 0; i < 16; ++i) children[i] = nullptr;
//
//    isEndOfWord = false;
//    definition = L"";
//}
//string decToHexa(int n)
//{
//    string result;
//
//    while(n)
//    {
//        int rem;
//        char c;
//
//        rem = n % 16;
//
//        if(rem < 10)
//        {
//            c = '0' + rem;
//        } else
//        {
//            c = 'A' + rem - 10;
//        }
//
//        result = c + result;
//
//        n /= 16;
//    }
//
//    return result;
//}
//
//string unicodeToUtf8(const wstring& unicodeString) {
//    string utf8String;
//
//    for (const wchar_t& wchar : unicodeString) {
//        if (wchar <= 0x7F) {
//            utf8String += static_cast<char>(wchar);
//        } else if (wchar <= 0x7FF) {
//            utf8String += static_cast<char>(0xC0 | ((wchar >> 6) & 0x1F));
//            utf8String += static_cast<char>(0x80 | (wchar & 0x3F));
//        } else if (wchar <= 0xFFFF) {
//            utf8String += static_cast<char>(0xE0 | ((wchar >> 12) & 0x0F));
//            utf8String += static_cast<char>(0x80 | ((wchar >> 6) & 0x3F));
//            utf8String += static_cast<char>(0x80 | (wchar & 0x3F));
//        } else {
//            utf8String += static_cast<char>(0xF0 | ((wchar >> 18) & 0x07));
//            utf8String += static_cast<char>(0x80 | ((wchar >> 12) & 0x3F));
//            utf8String += static_cast<char>(0x80 | ((wchar >> 6) & 0x3F));
//            utf8String += static_cast<char>(0x80 | (wchar & 0x3F));
//        }
//    }
//    string toconv = "";
//    for (const unsigned char& byte : utf8String) {
//        toconv += decToHexa(byte);
//    }
//    return toconv;
//}
//VieTrieNode * VieFind(VieTrieNode *& root, wstring vieword)
//{
//    if(root == nullptr) return nullptr;
//
//    string encode = unicodeToUtf8(vieword);
//    int si = encode.size();
//
//    VieTrieNode * cur = root;
//    for(int i = 0; i < si; ++i)
//    {
//        int index;
//        if(isdigit(encode[i])) index = encode[i] - '0';
//        else index = encode[i] - 'A' + 10;
//        if(cur->children[index] == nullptr) return nullptr;
//        cur = cur->children[index];
//    }
//
//    if(cur->isEndOfWord) return cur;
//
//    return nullptr;
//}
//
//bool VieInsert(VieTrieNode *& root, wstring vieword, wstring def)
//{
//    if(root == nullptr) root = new VieTrieNode();
//
//    VieTrieNode* pCrawl = root;
//    string encode = unicodeToUtf8(vieword);
//
//    for (int i = 0; i < encode.length(); i++)
//    {
//        int index;
//        if(isdigit(encode[i])) index = encode[i] - '0';
//        else index = encode[i] - 'A' + 10;
//        if (!pCrawl->children[index])
//            pCrawl->children[index] = new VieTrieNode();
//
//        pCrawl = pCrawl->children[index];
//    }
//
//    pCrawl->isEndOfWord = true;
//    pCrawl->definition = def;
//    return pCrawl->isEndOfWord;
//}
//
//void VieDeallocate(VieTrieNode * root)
//{
//    if(root == nullptr) return;
//
//    for(int i = 0; i < 17; ++i)
//    {
//        VieDeallocate(root->children[i]);
//    }
//
//    delete root;
//}
//
//bool isEmpty(VieTrieNode* root)
//{
//    for (int i = 0; i < 16; i++)
//        if (root->children[i])
//            return false;
//    return true;
//}
//
//VieTrieNode* removefunction(VieTrieNode* root, string word, int depth)
//{
//
//    if (!root)
//        return nullptr;
//
//    if (word.size() == depth)
//    {
//        if (root->isEndOfWord)
//        {
//            root->isEndOfWord = false;
//        }
//
//        if (isEmpty(root))
//        {
//            delete(root);
//            root = nullptr;
//        }
//        return root;
//    }
//    int index;
//    if (isdigit(word[depth])) index = word[depth] - '0';
//    else index = word[depth] - 'A' + 10;
//    root->children[index] = removefunction(root->children[index], word, depth + 1);
//   if (isEmpty(root) && root->isEndOfWord == false) {
//        delete (root);
//        root = nullptr;
//    }
//   return root;
//}
//
//VieTrieNode* remove(VieTrieNode* root, wstring vieword)
//{
//    string word = unicodeToUtf8(vieword);
//    int depth = 0;
//    return removefunction(root, word, depth);
//}
//bool isLeafNode(VieTrieNode* root)
//{
//    return root->isEndOfWord != false;
//}
//
//void VieEng(VieTrieNode* root)
//{
//    if (!root)
//        return;
//    int count = 0;
//    wifstream in("Text.txt");
//    _setmode(_fileno(stdin), _O_U16TEXT);
//    _setmode(_fileno(stdout), _O_U16TEXT);
//    locale loc(locale(), new codecvt_utf8_utf16<wchar_t>);
//    in.imbue(loc);
//
//    if (!in)
//    {
//        cout << "not found";
//        return;
//    }
//    wstring flag = L"*", wordFlag = L"\t";
//    wstring line, word, def;
//    bool flagFound = false;
//    while (getline(in, line))
//    {
//        size_t pos = line.find(flag);
//        word = line.substr(0, pos);
//        def = line.substr(pos + 1);
//        size_t wordPos = line.find(wordFlag);
//        word = word.substr(0, wordPos);
//        size_t subPos = 0;
//        wstring subDef;
//        for (int i = 0; i < def.size(); i++)
//        {
//            if (def[i] == L'=' || def[i] == L'+' || i == def.size() - 1)
//            {
//                if (i == def.size() - 1)
//                    subDef += def.substr(subPos, i - subPos + 1);
//                subDef += def.substr(subPos, i - subPos + 1) + L"\n";
//                subPos = i+1;
//            }
//
//        }
//       // wcout << word << " " << subDef << endl << endl;
//        /* wstring track;
//         while (getline(in, track))
//         {
//             if (track.find(flag) != wstring::npos)
//                 break;
//             else
//             {
//                 def += L" " + track;
//             }
//         }*/
//        VieInsert(root, word, subDef);
//    }
//
//    in.close();
//}


std::wstring hexToUnicode(const std::string& hexString) {
    std::wstring unicodeString;
    unsigned int value;

    for (size_t i = 0; i < hexString.length(); i += 2) {
        std::string byteStr = hexString.substr(i, 2);
        sscanf(byteStr.c_str(), "%x", &value);
        unicodeString += static_cast<wchar_t>(value);
    }

    return unicodeString;
}
wstring randomVieWord(VieTrieNode* root)
{
    wstring word=L"";
    srand(time(0));
    VieTrieNode* cur=root;
    string utf8word="";
      do
      {
        int index;
        do
        {
            index=rand()%16;
        }
        while (!cur->children[index]);
        char letter;
        if (index>=10)
        {
            letter=index-10+'A';
        }
        else
        {
            letter=index+'0';
        }
        utf8word+=letter;
        cur=cur->children[index];

      } while ((cur != nullptr) && (!cur->isEndOfWord));

      word=hexToUnicode(utf8word);
      return word;
}
//int main()
//{
//    VieTrieNode* root = new VieTrieNode();
//    VieEng(root);
//
//    wofstream fout("testvie.txt");
//
//   wstring word=randomVieWord(root);
//    fout<<word;
//    if (VieFind(root,word))
//    fout<<VieFind(root,word)->definition;
//    else
//    {
//        wcout<<"not found!";
//    }
//
//    fout.close();
//
//    return 0;
//}

