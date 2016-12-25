#include<bits/stdc++.h>
using namespace std;

int main() {
    int c;
    while(cin>>c && c!=-1) {
        string sol, g; int st = 0;
        cin>>sol>>g;
        for(int i=0;i<g.size() && st <= 6 && sol != ""; i++  ){
            if(sol.find(g[i]) != string::npos) {
                sol.erase(remove(sol.begin(), sol.end(), g[i]),
                          sol.end());
            }
            else st++;
        }
        cout << "Round " << c << endl;
        if (st == 7)
            cout << "You lose." << endl;
        else if (sol == "")
            cout << "You win." << endl;
        else
            cout << "You chickened out." << endl;
    }
}
