#include "getRandomDefinition.hpp"

vector <wstring> getRandomDefintion(vector <vector <wstring>> definition,vector <wstring> word, int& correctIndex)
{
    vector<wstring> res;
    int s=definition.size();
     int randomIndex=rand()%s;
     int ss=definition[randomIndex].size();
     int line=0;
     if (ss==1)
     {
         res.push_back(definition[randomIndex][0]);
     }
     else if (ss==2)
     {


         res.push_back(definition[randomIndex][1]);

     }
     else
     {
         line=(rand()%(ss-1))+1;
         res.push_back(definition[randomIndex][line]);
     }

    vector <wstring> words;
    words.push_back(word[randomIndex]);
    int randomIndex1,randomIndex2,randomIndex3;
    do
    {
        randomIndex1=rand()%s;
    }
    while (randomIndex1==randomIndex);
    do
    {
        randomIndex2=rand()%s;
    }
    while ((randomIndex2==randomIndex1)or(randomIndex2==randomIndex));
    do
    {
        randomIndex3=rand()%s;
    }
    while ((randomIndex3==randomIndex2)or(randomIndex3==randomIndex1)or(randomIndex3==randomIndex));
    words.push_back(word[randomIndex1]);
    words.push_back(word[randomIndex2]);
    words.push_back(word[randomIndex3]);
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(words.begin(), words.end(), rng);
    for(int i = 0; i < words.size(); ++i)
    {
        if(words[i] == word[randomIndex])
        {
            correctIndex = i;
        }
    }
    res.insert(res.end(),words.begin(),words.end());
    return res;
}

