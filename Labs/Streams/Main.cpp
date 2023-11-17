#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void func(string aString)
{
    cout << "func: " << aString << endl;
    aString += " Modified";
    cout << "func: " << aString << endl;
}


int main()
{
    ofstream fout("tmp.txt");
    string s1;
    string s2;
    s1 = "Hello ";
    func(s1);

    s2 = "World";
    auto cptr = "C string";
    auto cppstr = "C++ string"s;

    fout << "[" << s1 << s2 << "]\n";

    string big = s1 + s2 + cptr + cppstr;
    fout << big << endl;
    string s3 = "Hello ";
    if (s1 == s3) cout << "s1 is equal to s3";
    cout << "What is your name? ";
    cout.flush();
    cin >> s3;
    fout << "Hello " << s3 << endl;
    fout.close();
}
