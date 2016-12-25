#include<bits/stdc++.h>
using namespace std;

int main() {
    double s1, s2;
    cin>>s1>>s2;
    for(double s = s1; s <= s2; s += 0.01) {
        for(double b = 0.00; b <= s; b += 0.01) {
            int flag = false;
            for(double a = 0.00; a <= b; a += 0.01) {
                double c = s - a - b;
                if(s == a*b*c) {
                    printf("%lf = %lf + %lf + %lf = %lf * %lf * %lf\n", s,a,b,c,a,b,c);
                    flag = true; break;
                }
            }
            if(flag) break;
        }
    }
}
