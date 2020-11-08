#include<cstdio>
using namespace std;
const int N=1e7;
const int mod=998244353;
int n,m,t,a[N],p,v,c,g,hs[N];
void f1()
{
    int x,y;
    scanf("%d%d",&x,&y);
    a[x]+=y;
}
void f2()
{
    int x;
    scanf("%d",&x);
    for(int j=1;j<=n;j++)
       {
            a[j]*=x;
       }
}
void f3()
{
    int c,num;
    scanf("%d",&c);
    for(int j=1;j<=c;j++)
    {
        scanf("%d",num[j]);
    }
    for(int j=1;j<=c;j++)
    {
        if(hs[num[j]]==1)
        {
            f1();
        }
        if(hs[num[j]]==2)
        {
            f2();  
        }
        if(hs[num[j]]==3)
        {
            f3();
        }
    }
}
void inp()
{
    freopen("call.in","r",stdin);
    freopen("call.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&hs[i]);  
    }
    
}
