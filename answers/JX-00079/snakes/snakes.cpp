#include<cstdio>
#include<iostream>
#define ri register int 
#define ll long long
#define maxn 400005
#define inf 0x7fffffff
using namespace std;
int a[maxn];
inline int read(){
	ri x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	ri T=read(),n,flag=1;
	while(T--)
	{
		if(flag){ n=read();for(ri i=1;i<=n;++i) a[i]=read();flag=0;}
		else
		{
			ri k=read();
			for(ri i=1;i<=k;++i){ ri x=read(),y=read();a[x]=y;}
		}
		ri a1=a[1],a2=a[2],a3=a[3];
		if(a1>a2) swap(a1,a2);
		if(a2>a3) swap(a2,a3);
		if(a3-a1>a2) printf("1\n");
		else printf("3\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}