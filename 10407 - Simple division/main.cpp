#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}
int main() {
    vector<int> numbers;
    int n;
    while(cin>>n &&n) {
        numbers.clear();
        numbers.push_back(n);
        while(cin>>n&&n){
            numbers.push_back(n);
        }
        sort(numbers.begin(),numbers.end());
        for (size_t i = 0; i < numbers.size() - 1; ++i)
            numbers[i] = abs(numbers[i + 1] - numbers[i]);
        numbers.erase(numbers.end() - 1);
        int g  = numbers[0];
        for(int i=0;i<numbers.size();i++) {
            g = gcd(g,numbers[i]);
        }
        cout<<g<<endl;
    }
}
