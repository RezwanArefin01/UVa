#include<bits/stdc++.h>
using namespace std;

void DecodeAndPrint(string &phrase){
    reverse(phrase.begin(), phrase.end());
    int pos = 0;
    string output = "";
    while (pos + 1 <phrase.size()) {
        int len = 2;if (phrase[pos] == '1') ++len;
        output += static_cast<char>(atoi(phrase.substr(pos, len).c_str()));
        pos += len;
    }
    cout << output;
}
int main() {
    string str;
    while(getline(cin, str)) {
        int len = str.size();
        if(isdigit(str[0])) DecodeAndPrint(str);
        else {
            for(int i=len-1; i >= 0; i--) {
                int t = (int)str[i];
                while(t > 0) cout<<t%10, t/=10;
            }
        } cout<<endl;
    }
}
