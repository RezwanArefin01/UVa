#include<bits/stdc++.h>
using namespace std;

int cube[201];
int main() {
    for(int i=0; i<201; i++) cube[i] = i*i*i; int s,d;
    for(int a=6; a<=200; a++) {
        s = 0; for(int b = 2; 3*cube[b] <= cube[a]; b++) {
            s+=cube[b]; for(int c=b; 2*cube[c] <= (cube[a] - cube[b]); c++) {
                s+=cube[c];
                d = c;
                while(s + cube[d] < cube[a]) d++;
                s+=cube[d]; if(s == cube[a])
                    printf("Cube = %d, Triple = (%d,%d,%d)\n", a,b,c,d);
                s-=(cube[c] + cube[d]);
            } s -= cube[b];
        }
    }
}
