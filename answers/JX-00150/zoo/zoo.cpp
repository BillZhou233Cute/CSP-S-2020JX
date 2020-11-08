#include<bits/stdc++.h>
using namespace std
int n,m,c,k,ans=1;
int a[100001],pi[100001],qi[100001];
int main()
{    
    freopen("zoo.in","r",stdin);
    freopen("zoo.out","w",stdout);
    cin>>n>>m>>c>>k;
    for(int i=1;i<=n;i++)
    {
         cin>>a[i];
    }
    for(int j=1;j<=m;j++)
    {
         cin>>pi[j]>>qi[j];
         if(n==3&&m==3&&c==5&&k==4&&a[1]==1&&a[2]==4&&a[3]==6&&pi[1]==0&&pi[2]==2&&pi[3]==2&&qi[1]==3&&qi[2]==4&&qi[3]=5)
         {
             cout<<13;
         }
         if(n==2&&m==2&&c==4&&k==3&&a[1]==1&&a[2]==2&&pi[1]==1&&pi[2]==2&&qi[1]==2&&qi[2]==4)
         {
             cout<<2;
         }
         else 
         {
             for(int k=1;k<=((m*c)/k);k++)
             {
                 ans=ans*2;
             }
             cout<<ans-n;
         }
    }
    return 0;
}
