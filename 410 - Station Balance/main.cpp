#include<bits/stdc++.h>
using namespace std;
int c,s, Set = 0;
int main() {

    while(cin>>c>>s) {
        double sum = 0, avg,tmp;
        vector<int> chm;
        for(int i=0; i<s; i++) {
            cin>>tmp; sum+=tmp; chm.push_back(tmp);
        } avg = sum/c;
        for(int i=0 ; i < 2*c-s; i++) chm.push_back(0);
        sort(chm.begin(), chm.end());
        cout<<"Set #"<<++Set<<endl;
        double balance = 0;
        for(int i=0; i<c; i++) {
            cout<<" " <<i<<":";
            if(chm[i] == 0){
                if(chm[chm.size()-i-1])  cout<<" " <<chm[chm.size()-i-1]<<endl;
                else puts("");
                balance += fabs(chm[chm.size()-i-1] - avg);
            }
            else {
                cout<<" " <<chm[i]<<" " <<chm[chm.size()-i-1]<<endl;
                balance += fabs(chm[i] + chm[chm.size()-i-1] - avg);
            }
        }
        printf("IMBALANCE = %.5f\n\n", balance);
    }
}
