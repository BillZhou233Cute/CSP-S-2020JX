#include<bits/stdc++.h>
using namespace std;
int n,m,l[100005],t[100005],sj;
int main()
{
    cin>>n;
   for(int a=1;a<=n;a++)
    cin>>l[a];
   for(int a=1;a<=m;a++)
    cin>t[a];
   for(int a=1;a<=n;a++)
    sj=rand();
    cout<<sj%998244353;
   return 0;
}
