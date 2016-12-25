#include<bits/stdc++.h>
using namespace std;

int main() {
    int *killed[1024]; int d,n,x,y,p,t;
    cin>>t; while(t--) {
        cin>>d>>n;
        for(int i=0; i<1024; i++) {
            killed[i] = new int[1024];
            for(int j=0; j<1024; j++) killed[i][j] = 0;
        }
        while(n--) {
            cin>>x>>y>>p;
            for(int i = x-d; i<= x+d; i++) if(i >=0 && i<1024) {
                for(int j=y-d; j <= y+d; j++) if(j >= 0 && j<1024)
                    killed[i][j] += p;
            }
        } int Max = -1, maxi = -1, maxj = -1;
        for(int i=0;i<1024; i++)
            for(int j=0; j<1024; j++)
                if(killed[i][j] > Max)
                    Max = killed[i][j], maxi = i, maxj = j;
        cout<<maxi<<" " <<maxj<<" " <<Max<<endl;
    }
}
