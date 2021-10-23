#include "directory.h"
#include <unistd.h>
#include <sys\stat.h>
#include <iostream>
#include <dirent.h>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <map>

void directory::setPath(string str)
{
    path=str;
}

string directory::getPath()
{
    return path;
}

string directory::getCurDir()
{
    char temp[256];
    getcwd(temp, 256);
    path=temp;
    path+="\\";
    return path;
}


void directory::getFile(string Path)
{
    struct dirent *d;
	struct stat dst;

	DIR *dr;

	dr = opendir(Path.c_str());

	if (dr != NULL)
	{
		for (d = readdir(dr); d != NULL; d = readdir(dr))
		{
			string type = d->d_name;
			if(type=="."||type=="..")
                continue;
			type = Path + type;
			if (stat(type.c_str(), &dst) == 0)
			{
				if (dst.st_mode & S_IFDIR)
				{
				    getFile(type+ "\\");
					type = "is a FOLDER.";
				}
				else if (dst.st_mode & S_IFREG)
				{
				    file tmp;
				    tmp.setFileName(type);
				    File.push_back(tmp);
					type = "is a FILE.";
				}
			}
		}
		closedir(dr);
	}

}
void directory::printAllFile()
{
    for(int i=0;i<File.size();i++)
        cout<<File[i].getFileName()<<endl;
}
bool compare(file f1,file f2)
{
    return f1.getFileName()<f2.getFileName();
}
int directory::getAllFileWithWord(string word)
{
    getFile(path);


    int cnt=0;
    map<string,vector<string>> m;
    sort(File.begin(),File.end(),compare);
    for(int i=0;i<File.size();i++)
    {
        File[i].getAllWord();
        if(File[i].isContainTheWord(word))
        {
            string tmp=File[i].getFileName().substr(0,File[i].getFileName().find_last_of('\\'));
            string tmp2=File[i].getFileName().substr(File[i].getFileName().find_last_of('\\')+1);
            map<string,vector<string>>::iterator it=m.find(tmp);
            if(it != m.end())
                it->second.push_back(tmp2);
            else
            {
                m[tmp].push_back(tmp2);
            }
        }

    }
    if(m.empty())
    {
        cout<<"In directory "<<path<<" No file with word found"<<endl;
        return 0;
    }
    for(map<string, vector<string>>::iterator it = m.begin();it != m.end(); ++it)
    {
        cout <<"In the directory "<< it->first << " contain the word: " <<word<<endl;
        for(int j=0;j<(it->second).size();j++)
                cout<<"\t"<<(it->second)[j]<<endl;
    }

    return cnt++;

}
