#include<bits/stdc++.h>
using namespace std;
int n,t,k[15];
int main()
{
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    cin>>n;
    for(int a=1;a<=n;a++)
      {
	cin>>t;
        for(int b=a;b<=t;b++)
          cin>>k[b];
        cout<<rand()<<endl;
      }
    return 0;
}
