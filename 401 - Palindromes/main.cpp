#include<iostream>
#include<cstring>
#include<map>
using namespace std;
map<char, char> m;

string line;
string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
string r = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
bool IsPal(string s)
{
    if (s==string(s.rbegin(),s.rend()))return true;
    return false;

}
inline bool IsMirror(string a) {
    for(int i = 0; i < a.length() / 2 + a.length() % 2; i++) {
        if(a[a.length() - 1 - i] != m[a[i]])
            return false;
    }
    return true;
}
int main()
{
    for(int i = 0; i < s.length(); i++)
        m[s[i]] = r[i];
    string str;
    int p,m;
    while(cin>>str)
    {
        p=IsPal(str);
        m=IsMirror(str);
        if (!p && !m) cout<<str<<" -- is not a palindrome." ;
        else if (p && !m) cout<<str<<" -- is a regular palindrome.";
        else if (m && !p) cout<<str<<" -- is a mirrored string.";
        else cout<<str<<" -- is a mirrored palindrome." ;
        cout<<endl<<endl;
    }

    return 0;
}
