#include<bits/stdc++.h>
using namespace std;

string sound[] = {"BFPV", "CGJKQSXZ", "DT", "L", "MN", "R"};
int main() {
    int prev = -1;
    string str;
    while(getline(cin,str)) { int t = str.size(); prev = -1;
        for(int i=0; i<t; i++) for(int j=0; j<6; j++ ){
            size_t found = sound[j].find(str[i]);
            if(found != string::npos) {
                if(prev!=j) {
                    prev = j; cout<<j+1; break;
                }else break;
            }else if(j+1 == 6) {prev = -1; break;}
        }
        puts("");
    }
}
