#include <vector>
#include <iostream>
using namespace std;
class file
{
private:
    vector<string> allWord;
    string fileName;
    vector<string> checkWord;
public:
    void getAllWord();
    bool isContainTheWord(string str);
    void setFileName(string name);
    string getFileName();
};
