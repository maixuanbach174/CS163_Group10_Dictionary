#include "Trie.h"

TrieNode::TrieNode()
{
    for(int i = 0; i < ALPHABET_SIZE; ++i) children[i] = nullptr;
    isEndOfWord = false;
    definition = "";
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


bool insert(TrieNode* &root, string word, string def)
{
    if (root == nullptr)
        root = new TrieNode();
    TrieNode* pCrawl = root;
    for (int i = 0; i < word.length(); i++)
    {
        int index = word[i] - 'a';
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
    string filename = "english_english.csv";
    ifstream dict(filename);
    if (!dict)
    {
        cout << "Can't open file!";
        return;
    }
    string line, separator = "\"\"", word, def;
    while (getline(dict, line))
    {
        stringstream ss(line);
        string tmp;
        getline(ss, tmp, ',');
        word = tmp;
        cout << word << endl;
        getline(ss, tmp);
        def = tmp;
        if (line.find("\"\"") != string::npos)
        {
            while (getline(dict, line))
            {
                if (line.find("\"\"") == string::npos)
                    def += line.substr(0, line.length() - 3);
                else
                    def += line;
            }
        }
        insert(root, word, def);
    }
}
