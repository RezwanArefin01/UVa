#include <iostream>
using namespace std;
int main()
{
    short set,set_no=0,i;
    while(cin>>set && set!=0)
    {
        int total=0,brick[set],move=0,media;
        for(i=0;i<set;i++)
        {
            cin>>brick[i];
            total+=brick[i];
        }
        media = total/set;
        for(i=0;i<set;i++)
        {
            if(brick[i]>media) move = move+(brick[i]-media);
        }
        cout<<"Set #"<<++set_no<<endl;
        cout<<"The minimum number of moves is "<<move<<"."<<endl<<endl;
    }
    return 0;
}
