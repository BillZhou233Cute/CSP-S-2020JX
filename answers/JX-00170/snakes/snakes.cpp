#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;
int T,n,tot,ans=0,a[100100],id[100100];
inline int read()
{
    int x=0,minus=0; char ch;
    while (!isdigit(ch=getchar())) minus|=(ch=='-');
    while (isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();  
    return minus?-x:x;
}
signed main()
{
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    T=read(),n=read();
    T--;
    for (register int i=1;i<=n;++i) a[i]=read(),id[i]=i;
    tot=0,ans=0;
    while (tot<=n)
    {
	tot++;
	if (id[tot]==n) break;
	if (id[n]==n) ans=tot;
	a[n]-=a[tot];
	for (register int i=n;i>tot+1;--i)
	if (a[i]<a[i-1]) swap(a[i],a[i-1]),swap(id[i],id[i-1]);
	else break;
    }
    printf("%d\n",n-ans+1);
    while (T--)
    {
	int num=read();
	for (register int i=1,x,y;i<=num;++i) x=read(),y=read(),a[x]=y,id[i]=i;
        tot=0,ans=0;
        while (tot<=n)
        {
	tot++;
	if (id[tot]==n) break;
	if (id[n]==n) ans=tot;
	a[n]-=a[tot];
	for (register int i=n;i>tot+1;--i)
	if (a[i]<a[i-1]) swap(a[i],a[i-1]),swap(id[i],id[i-1]);
	else break;
        }
        printf("%d\n",n-ans+1);
    }
    return 0;
}

