#include "file.h"
class directory
{
private:
    vector<file> File;
    string path;
    void getFile(string str);
public:
    void setPath(string str);
    string getPath();
    string getCurDir();
    void printAllFile();
    int getAllFileWithWord(string word);

};
