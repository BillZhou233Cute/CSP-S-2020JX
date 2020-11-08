#include<bits/stdc++.h>
#define R register int
#define IN inline
using namespace std;
const int N=1e6+5;
int T,n,k;
int a[N],b[N];
int st;
int killing[N];
bool killed[N];
int ans;
IN int read()
{
	char ch;int f=1;
	while((ch=getchar())<'0'||ch>'9') if(ch=='-') f=-1;
	int x=ch-'0';
	while((ch=getchar())>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0';
	return x*f;
}
IN void dfs(int type)
{
	if(type==0)
	{
		
	}
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	T=read();int lft;
	for(R cnt=1;cnt<=T;cnt++)
	{
		lft=n;ans=0;
		if(cnt==1)
		{
			n=read();
			for(R i=1;i<=n;i++) a[i]=read();
		}
		else
		{
			k=read();
			for(R i=1;i<=k;i++) 
			{
				int x=read(),y=read();
				a[x]=y;
			}
		}
		memset(killing,0,sizeof(killing));
		memset(killed,0,sizeof(killed));
		dfs(0);dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}