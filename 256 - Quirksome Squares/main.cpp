#include<bits/stdc++.h>
using namespace std;

string ans[] = {"00\n01\n81\n","0000\n0001\n2025\n3025\n9801\n","000000\n000001\n088209\n494209\n998001\n",
"00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n"};
int main() {
    int n; while(cin>>n) cout<<ans[(n>>1) - 1];
}
