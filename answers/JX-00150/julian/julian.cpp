#include<bits/stdc++.h>
using namespace std
int a[100001],y1[100001],m[100001],d[100001],y2[100001];
int main()
{
    freopen("julian.in","r",stdin);
    freopen("julian.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
         cin>>a[i];
         y1[i]=4713;
         m[i]=1;
         d[i]=1;
         while(a[i]>30)
         {
             if(m[i]==4||m[i]==6||m[i]==7||m[i]==9||m[i]==11)
             {
                 if(d[i]==30)
                 {
                     d[i]=1;
                     m[i]++;
                 }
             }
             if(m[i]==3||m[i]==5||m[i]==8||m[i]==10)
             {
                 if(d[i]==31)
                 {
                     d[i]=0;
                     m[i]++;
                 }
             }
             if(m[i]==2&&d[i]==28&&y1[i]%4!=1&&y1[i]>0)
             {
                 m[i]++;
                 d[i]==0;
             }
             if(m[i]==2&&d[i]==29&&y1[i]%4==1&&y1[i]>0)
             {
                 m[i]++;
                 d[i]==0;
             }
             if(m[i]==2&&d[i]==28&&y2[i]%4!=0&&y1[i]<0)
             {
                 m[i]++;
                 d[i]==0;
             }
             if(m[i]==2&&d[i]==29&&y2[i]%4==0&&y1[i]<0)
             {
                 m[i]++;
                 d[i]==0;
             }
             if(m[i]==12&&d[i]==31)
             {
                 y1[i]--;
                 m[i]=1;
                 d[i]=0;
             }
             d[i]++;
             a[i]--; 
             if(y1[i]<=0)
             {
                 y2[i]=(1-y1[i]);
             }
         }
         if(y1[i]<0)
         {
             cout<<d[i]<<" "<<m[i]<<" "<<y2[i];
         }
         if(y1[i]>0)
         {
             cout<<d[i]<<" "<<m[i]<<" "<<y1[i]<<" "<<"BC";
         }
    }
    return 0;
}

