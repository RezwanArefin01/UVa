#include <bits/stdc++.h>
#define N 1000000
using namespace std;
string common;
string dir [100000 + 10];
int length;
char mapping (char c){
    if ( c == 'A' || c == 'B' || c == 'C' ) return '2';
    if ( c == 'D' || c == 'E' || c == 'F' ) return '3';
    if ( c == 'G' || c == 'H' || c == 'I' ) return '4';
    if ( c == 'J' || c == 'K' || c == 'L' ) return '5';
    if ( c == 'M' || c == 'N' || c == 'O' ) return '6';
    if ( c == 'P' || c == 'R' || c == 'S' ) return '7';
    if ( c == 'T' || c == 'U' || c == 'V' ) return '8';
    if ( c == 'W' || c == 'X' || c == 'Y' ) return '9';
    return ' ';
}
void formatIt (char *a)
{
    common.clear ();
    for ( int i = 0; a [i]; i++ ) {
        if ( isdigit (a [i]) ) common += a [i];
        else if ( isalpha (a [i])) common += mapping (a [i]);
    }
    common.insert (3, "-");
}

int main (){
    int testCase;
    scanf ("%d", &testCase);
    bool blank = false;
    while ( testCase-- ) {
        length = 0;
        int directory;
        scanf ("%d", &directory);
        getchar ();
        map <string, int> freq;
        while ( directory-- ) {
            char number [1000];
            gets (number);
            formatIt (number);
            freq [common]++;
            if ( freq [common] == 2 ) dir [length++] = common;
        }
        sort (dir, dir + length);
        if ( blank ) cout << endl;
        blank = true;
        bool printed = false;
        for ( int i = 0; i < length; i++ ) {
            cout << dir [i] << " " << freq [dir [i]] << endl;
            printed = true;
        }
        if ( !printed ) cout << "No duplicates." << endl;
    }
    return 0;
}
