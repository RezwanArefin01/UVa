#include <iostream>
#include <cmath>
using namespace std;

int x[1000001];
int main(){
    x[0] = 1;
    for (int i = 1; i <= 1000000; ++i)    {
        x[i] = x[(int)floor(i - sqrt((double)i))]
               + x[(int)floor(log((double)i))]
               + x[(int)floor(i * sin((double)i) * sin((double)i))];
        x[i] %= 1000000;
    } int i;
    while (cin >> i, i > -1)
        cout << x[i] << endl;
    return 0;
}
