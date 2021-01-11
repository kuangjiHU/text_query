#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("story.txt", ios::in);
    string text;
    while(getline(inFile, text))
    {
        // istringstream line(text);
        cout << text << endl;
    }
}