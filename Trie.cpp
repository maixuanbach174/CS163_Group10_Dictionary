#include "Trie.h"
#include <iostream>
#include <fstream>
using namespace std;
TrieNode::TrieNode()
{
    for(int i = 0; i < ALPHABET_SIZE; ++i) children[i] = nullptr;
    isEndOfWord = false;
    definition = "";
}

TrieNode* find(TrieNode* root, string word)
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


<<<<<<< HEAD
bool insert(TrieNode*& root, string word, string def)
{
    if(root == nullptr) root = new TrieNode();
=======
bool insert(TrieNode* &root, string word, string def)
{
    if (root == nullptr)
        root = new TrieNode();
>>>>>>> origin/Insert_Minh
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


<<<<<<< HEAD
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}




TrieNode* removefunction(TrieNode* root, string word, int depth)

{
    
    if (!root)
        return nullptr;
    if (word.size() == depth)
    {
        if (root->isEndOfWord)
        {
            root->isEndOfWord = false;
        }

        if (isEmpty(root))
        {
            delete(root);
            root = nullptr;
        }
        return root;
    }
    int index = word[depth] - 'a';
    root->children[index] = removefunction(root->children[index], word, depth + 1);
   if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = nullptr;
    }
   return root;

    
}


TrieNode* remove(TrieNode* root, string word)

{
    int depth = 0;
    return removefunction(root, word, depth);
}



void deallocate(TrieNode* root)
{
    if(root == nullptr) return;
    for(int i = 0; i < ALPHABET_SIZE; ++i)
    {
        deallocate(root->children[i]);
    }

    delete root;
}

bool isLeafNode(TrieNode* root)
{
    return root->isEndOfWord != false;
}
void serialize(TrieNode* root, char str[], int level, ofstream& newfile) {
   
    if (isLeafNode(root)) {
        str[level] = '\0';
        newfile.open("new_friends.txt", ios::out | ios::app);  
        if (newfile.is_open()) {
            newfile << str << "\n"; 
            newfile.close(); 
        }
        cout << "Added: " << str << endl;
    }

    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        
        if (root->children[i]) {
            str[level] = i + 'a';
            serialize(root->children[i], str, level + 1, newfile);
        }
=======
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
                {
                    def += line.substr(0, line.length() - 3);
                    break;
                }
                else
                    def += line;
            }
        }
        insert(root, word, def);
>>>>>>> origin/Insert_Minh
    }
}
