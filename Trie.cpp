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

TrieNode* find(TrieNode* root, string& word)
{
    if(root == nullptr) return nullptr;
    
    TrieNode *cur = root;

    for(int i = 0; word[i] != '\0'; ++i)
    {
        int index = word[i] - 'a';
        if(cur->children[index] == nullptr) return nullptr;

        cur = cur->children[index];
    }

    if(cur->isEndOfWord) return cur;
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
    wstring line, def, limiter = L".";
    if (!dict)
    {
        cout << "Can't open file!";
        return;
    }

    while (getline(dict, line))
    {
        size_t firstCommaPos = line.find(L',');
        wstring word = line.substr(0, firstCommaPos);
        //wcout << word << " ";
        def = line.substr(firstCommaPos + 1);
        //wcout << def << endl << endl;
        if (def.find(limiter) != wstring::npos) continue;
        while (getline(dict, line))
        {
            def += line;
            if (line.find(limiter) != wstring::npos)
                break;
        }
        insert(root, word, def);
    }
}


  
vector <string> addFavorite(string word, vector<string> &favList)
{
    favList.push_back(word);
    return favList;
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
    // and lower case)
    TrieNode* root = new TrieNode();
    readEngEng(root);
    cout << "Succesful!";
}
