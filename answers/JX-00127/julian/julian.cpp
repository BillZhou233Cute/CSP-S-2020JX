#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
using namespace std;
#define int long long
#define il inline
#define next nee
#define re register int
#define inf 1e18
il int read()
{
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')f=-1,ch=getchar();
    while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
    return x*f;
}
il void print(int x)
{
    if(x<0)putchar('-'),x=-x;
    if(x/10)print(x/10);
    putchar(x%10+'0');
}
int n,m,a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
il void search1(int x)
{
    bool k=0;int ans1=4713,ans2=1,ans3=1;
    if(x<=365)ans1=4713,k=1;
    else ans1=4713-(x/1461)*4,x=(x%1461);
    if(x>=366){
        x-=366;ans1--;
        while(x>=365)ans1--,x-=365;
    }
    else k=1;
    for(re i=1;i<=12;i++)
    {
        if(i!=2||!k){if(x>=a[i]){x-=a[i];ans2++;continue;}}
        if(i==2&&k){if(x>=29){x-=29;ans2++;continue;}}
        break;
    }
    ans3+=x;
    print(ans3);putchar(' ');print(ans2);putchar(' ');print(ans1);printf(" BC\n");
}
il void search2(int x)
{
    bool k=0;int ans1,ans2=1,ans3=1;
	x-=1721424;
    ans1=(x/1461)*4+1;x=(x%1461);
	if(x>=1095)k=1;
    for(re i=1;i<=3;i++)
	{
		if(x>=365){x-=365;ans1++;continue;}
		break;
	}
    for(re i=1;i<=12;i++)
    {
        if(i!=2||!k){if(x>=a[i]){x-=a[i];ans2++;continue;}}
        if(i==2&&k){if(x>=29){x-=29;ans2++;continue;}}
        break;
    }
    ans3+=x;
    print(ans3);putchar(' ');print(ans2);putchar(' ');print(ans1);putchar('\n');
}
il void change(int &x,int &y)
{
	int x1=y;
	y+=(x/366);x-=(y-x1)*365;
}
il void search3(int x)
{
    bool k=0;int ans1=1582,ans2=1,ans3=1;
	x=x-1721424-577460+11;
    ans1+=(x/146097)*400;x=(x%146097);
	change(x,ans1);
	if((x>=730&&x<1096)&&((!(ans1+3)%4&&(ans1+3)%100)||!(ans1+3)%400))k=1;
    for(re i=1;i<=3;i++)
	{
		if(i<3){if(x>=365){x-=365;ans1++;continue;}}
		else if(i==3){if(k){if(x>=366){x-=366;ans1++;continue;}}
		else{if(x>=365){x-=365;ans1++;continue;}}}
		break;
	}
    for(re i=1;i<=12;i++)
    {
        if(i!=2||!k){if(x>=a[i]){x-=a[i];ans2++;continue;}}
        if(i==2&&k){if(x>=29){x-=29;ans2++;continue;}}
        break;
    }
    ans3+=x;
    print(ans3);putchar(' ');print(ans2);putchar(' ');print(ans1);putchar('\n');
}
signed main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    n=read();
    while(n--)
    {
        m=read();
        if(m<1721424){search1(m);continue;}
        if(m<2299161){search2(m);continue;}
        search3(m);
    }
    return 0;
}
