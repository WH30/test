#include <iostream>
#include <algorithm>
#include <string>
#include<queue>
using namespace std;

void nextvisit(string word, vector<string>&wordList,queue<string> &tovisit )
{
    for(int i=0;i<word.size();i++)
    {
        char ch=word[i];
        vector<string>::iterator it;
        for(int j=0;j<25;j++)
        {
            word[i]='a'+j;
            it=find(wordList.begin(),wordList.end(),word);
            if(it!=wordList.end())
            {
                tovisit.push(word);
                wordList.erase(it);
            }
        }
        word[i]=ch;
    }
}


int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
    if(wordList.size()==0)
    return 0;
    int num=2;
    //wordList.push_back(endWord);
    queue<string> tovisit;
    nextvisit(beginWord,wordList,tovisit);
    while(tovisit.size()!=0)
    {
        int n=tovisit.size();
        for(int i=0;i<n;i++)
        {
            string word=tovisit.front();
            if(word==endWord)
            return num;

            tovisit.pop();
            nextvisit(word,wordList,tovisit);
            
        }
        num++;
    }
    return 0;
        
}