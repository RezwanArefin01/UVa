#include<bits/stdc++.h>
using namespace std;

int main() {
    char in[10];
    int max = 11, min = 0, guess;
    bool valid = true;
    while(cin>>guess && guess) {
        scanf("%*s %s", in);
        if(in[0] == 'h') {
            if(guess <= min) valid = false;
            if(guess < max) max = guess;
        }else if (in[0] == 'l') {
            if(guess >= max) valid = false;
            if(guess > min) min = guess;
        }
        else {
            if(guess > min && guess < max && valid)
                puts("Stan may be honest");
            else puts("Stan is dishonest");
            min = 0, max = 11, valid = true;
        }
    }
}
