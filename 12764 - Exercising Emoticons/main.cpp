#include <bits/stdc++.h>
using namespace std;
string emo[10][3] = {
	{"\\./.",".|..","/o\\."},
    {".o..","/|\\.","/.\\."},
    {"....","....","__\\o"},
    {"....","....","\\_\\o"},
    {"_o_.",".|..","/.\\."},
    {"\\o/.",".|..","/.\\."},
    {"\\o_.","\\|..",".|.."},
    {"\\o/.","\\|/.","...."},
    {"....",".__o","/..|"},
    {".o..","(.).","/.\\."}
};
int main(int argc, char const *argv[]) {
	for(int i=0; i<10; i++) for(int j=0; j<3; j++) 
		for(char &k : emo[i][j]) if(k == '.') k = ' ';
	int t; cin>>t; while(t--) {
		string str; cin>>str; 
		for(int i=0; i<3; i++, cout<<endl) for(int j=0; j < str.size(); j++) {
			if(j) cout<<" "; 
			cout<<emo[str[j] - '0'][i]; 
		} cout<<endl;
	}
} 
