#include <sys\stat.h>
#include <dirent.h>
#include <conio.h>
#include <algorithm>
#include "directory.h"
#include <windows.h>
#include <iostream>
#include "Shlwapi.h"
using namespace std;

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        cout<<"Not enough arguments";
        return -1;
    }
    if(argc==2)
    {
        string word(argv[1]);
        directory direct;
        direct.setPath(direct.getCurDir());
        direct.getAllFileWithWord(word);
        return 0;
    }
    string word(argv[1]);
    directory direct;
    string path(argv[2]);
    if(!PathFileExists(path.c_str()))
    {
        cout<<"The path "<<path<<" is not exist";
        return -2;
    }
    path+="\\";
    direct.setPath(path.c_str());
    direct.getAllFileWithWord(word);






}
