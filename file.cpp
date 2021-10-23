#include "file.h"
#include <fstream>
#include <algorithm>
#include <sstream>
void file::getAllWord()
{
    fstream f;
    f.open(fileName.c_str(),ios::in);
    if (!f.is_open())
    {
        cout<<"cant open "<<fileName;
        return;
    }
    string word;
    while(f>>word)
    {
        if(!isalpha(word.back())&&!isdigit(word.back()))
            word.pop_back();
        allWord.push_back(word);

    }
    f.close();
}

bool file::isContainTheWord(string str)
{
    istringstream ss(str);
    string temp;
    while(ss>>temp)
        checkWord.push_back(temp);

    vector<string>::iterator it;
    for(int i=0;i<checkWord.size();i++)
    {
        it=find(allWord.begin(),allWord.end(),checkWord[i]);
        if(it==allWord.end())
            return false;
    }
    return true;
}
void file::setFileName(string name)
{
    fileName=name;
}

string file::getFileName()
{
    return fileName;
}
