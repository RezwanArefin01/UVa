#include<bits/stdc++.h>
using namespace std;
int main(){
    string num;
    while(getline(cin, num) && num != "0") {
        int s = 0;
        for(int i=0; i<num.size(); i++) {
            if(i%2) s -= (num[i] - '0');
            else s += (num[i] - '0');
        }
        if(s % 11 == 0) {cout<<num; puts(" is a multiple of 11.");}
        else {cout<<num; puts(" is not a multiple of 11.");}
    }
}
