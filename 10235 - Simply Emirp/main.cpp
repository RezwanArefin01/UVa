#include <iostream>
using namespace std;
long int n,r,newn;
int temp;
inline bool IsPrime( long int number )
{
 if ( ( (!(number & 1)) && number != 2 ) || (number < 2) || (number % 3 == 0 && number != 3) )
  return (false);

 for( int k = 1; 36*k*k-12*k < number;++k)
  if ( (number % (6*k+1) == 0) || (number % (6*k-1) == 0) )
   return (false);
  return true;
 }
int main()
{
    while(cin>>n)
    {
        if(!IsPrime(n)) cout<<n<<" is not prime."<<endl;
        else
        {
            newn=n;
            r=0;
            while(n)
            {
                temp=n%10;
                n/=10;
                r = (r*10)+temp;
            }
            if(r!=newn && IsPrime(newn))
            {
                if(IsPrime(r)) cout<<newn<<" is emirp."<<endl;
                else cout<<newn<<" is prime."<<endl;
            }
            if(r==newn)
            {
                if(IsPrime(r)) cout<<newn<<" is prime."<<endl;
                else cout<<newn<<" is not prime."<<endl;
            }
        }
    }
    return 0;
}
