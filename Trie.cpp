#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;
const int ALPHABET_SIZE = 26;

struct TrieNode
{
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
    wstring definition;
    TrieNode();
};
TrieNode::TrieNode()
{
    for(int i = 0; i < ALPHABET_SIZE; ++i) children[i] = nullptr;
    isEndOfWord = false;
    definition = L"";
}
void deallocateTrie(TrieNode* node)
{
    if (node == nullptr)
        return;

    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        if (node->children[i] != nullptr)
        {
            deallocateTrie(node->children[i]);
            node->children[i] = nullptr;
        }
    }

    delete node;
}

TrieNode* find(TrieNode*& root, wstring word)
{
    if (root == nullptr) return nullptr;

    TrieNode* cur = root;

    for (int i = 0; i < word.size(); ++i)
    {
        if (!isalpha(word[i])) continue;
        int index = tolower(word[i]) - L'a';
        if (cur->children[index] == nullptr) return nullptr;
        cur = cur->children[index];
    }

    if (cur->isEndOfWord) return cur;
    return nullptr;
}

bool insert(TrieNode*& root, wstring word, wstring def)
{
    if (root == nullptr) root = new TrieNode();
    TrieNode* pCrawl = root;
    for (int i = 0; i < word.length(); i++)
    {
        wchar_t check = tolower(word[i]);
        if (!isalpha(word[i])) continue;
        int index = check - L'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = new TrieNode();

        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
    pCrawl->definition = def;
    return pCrawl->isEndOfWord;
}


void readEngEng(TrieNode* root)                                                  
{
    string filename = "engwords.csv";
    wifstream dict(filename, std::ios::binary);
    wstring line, def, limiter = L".", word;
    if (!dict)
    {
        cout << "Can't open file!";
        return;
    }

    while (getline(dict, line))
    {
        size_t firstCommaPos = line.find(L',');
        word = line.substr(0, firstCommaPos);
        def = line.substr(firstCommaPos + 1);
        insert(root, word, def);
    }
}

  

  
vector <string> addFavorite(string word, vector<string> &favList)
{
    favList.push_back(word);
    return favList;
}

void VieEng(VieTrieNode* root)
{
    if (!root)
        return;
    int count = 0;
    wifstream in("Text.txt");
    _setmode(_fileno(stdin), _O_U8TEXT);
    _setmode(_fileno(stdout), _O_U8TEXT);
    locale loc(locale(), new codecvt_utf8_utf16<wchar_t>);
    in.imbue(loc);

    if (!in)
    {
        cout << "not found";
        return;
    }
    wstring flag = L"*";
    wstring line, word, def;
    bool flagFound = false;
    while (getline(in, line))
    {
        size_t pos = line.find(flag);
        word = line.substr(0, pos);
        def = line.substr(pos + 1);
        size_t subPos = 0;
        wstring subDef;
        for (int i = 0; i < def.size(); i++)
        {
            if (def[i] == L'=' || def[i] == L'+' || i == def.size() - 1)
            {
                if (i == def.size() - 1)
                    subDef += def.substr(subPos, i - subPos + 1);
                subDef += def.substr(subPos, i - subPos + 1) + L"\n";
                subPos = i+1;
            }
        }
        wcout << subDef << endl <<endl;
        /* wstring track;
         while (getline(in, track))
         {
             if (track.find(flag) != wstring::npos)
                 break;
             else
             {
                 def += L" " + track;
             }
         }*/
        VieInsert(root, word, subDef);
    }

    in.close();
}


void removeFavorite(string word, vector<string>& favList)
{
    for (int i=0; i<favList.size(); i++)
    {
        if (favList[i] == word)
        {
            swap(favList[i], favList[favList.size() - 1]);
            favList.pop_back();
        }
    }
}


int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower cas;
    TrieNode* root = new TrieNode();
    readEngEng(root);
    wcout << find(root, L"business")->definition;
}
