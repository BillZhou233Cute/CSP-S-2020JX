#include<bits/stdc++.h>
using namespace std
int a[100001],sum[100001];
int main()
{
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    int t,n;
    cin>>t>>n;
    for(int k=1;k<=t;k++)
    {
         if(k==1)
         {
             for(int i=1;i<=n;i++)
             {
                  cin>>a[i];
                  sum[i]=i;
             }
         }
         else
         {
             for(int i=1;i<=n;i++)
             {
                 cin>>sum[i]>>a[i];
             }
         }
         if(a[n]-a[1]>=a[n-1]&&n!=2)
         {
             n--;
             for(int s=1;s<=n;s++)
             {
                 sum[s]--;
             }
             cout<<n<<endl;
         }else cout<<n<<endl;
         if(n==2)
         {
             if(a[n]==a[n-1])
             cout<<2;
             else cout<<1;
         }
    }
    return 0;
}
