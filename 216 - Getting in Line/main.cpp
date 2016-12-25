#include<bits/stdc++.h>
using namespace std;

int main() {
    int co = 0, n;
    while(cin>>n && n) {
        vector<pair<int,int> > p(n), sol(n);
        double best;
        for(int i=0 ;i<n;i++) cin>>p[i].first>>p[i].second;
        sol = p; best = 1E10;
        sort(p.begin(), p.end());
        do {
            double now = 0.0;
            for(int i=0; i<n-1;i++)
                now += hypot(p[i].first - p[i+1].first, p[i].second - p[i+1].second) + 16.0;
            if(now < best) best = now, sol = p;
        }while(next_permutation(p.begin(), p.end()));
        puts("**********************************************************");
        cout<<"Network #"<<++co<<endl;
        for(int i=0 ;i<n-1; i++)
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",sol[i].first, sol[i].second,
                                                                                    sol[i+1].first, sol[i+1].second,
                                                                                    hypot(sol[i].first - sol[i+1].first,
                                                                                          sol[i].second - sol[i+1].second) + 16.0);
        printf("Number of feet of cable required is %.2f.\n", best);
    }
}
