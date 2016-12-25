#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define N 20000000
bool mark [N];
vector <int> primeList;
int s;
vector<int> twinPrime;
void sieve()
{
    memset(mark, true, sizeof (mark));
    mark [0] = mark [1] = false;
    for ( int i = 4; i < N; i += 2 )
        mark [i] = false;

    for ( int i = 3; i * i <= N; i++ ) {
        if ( mark [i] ) {
            for ( int j = i * i; j < N; j += 2 * i )
                mark [j] = false;
        }}
    primeList.clear ();
    primeList.push_back (2);

    for ( int i = 3; i < N; i += 2 ) {
        if ( mark [i] )
            primeList.push_back (i);
            cout<<i <<" " ;
    }
}
int main()
{
    sieve();
    for ( size_t i = 1; i < primeList.size (); i++ ) {
        if ( primeList [i] - primeList [i - 1] == 2 )
            twinPrime.push_back (primeList [i - 1]);
    }
    while(cin>>s)
    {
        cout<<"("<<twinPrime[s-1]<<", "<<twinPrime[s-1]+2<<")"<<endl;
    }
    return 0;
}
