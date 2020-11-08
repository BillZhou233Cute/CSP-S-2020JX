#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int N=1e6+5;

inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

int a[N];
int b[N],len;
int n;
struct node{
	int id,val;
}re[N];
inline bool cmp(node x,node y)
{
	if(x.val!=y.val) return x.val>y.val;
	return x.id>y.id;
}

int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	//cout<<2000*2000*log2(2000)*10<<endl;
	int T=read();
	int u,v;
	for(int t=1;t<=T;t++)
	{
		if(t==1) 
		{
			n=read();
			for(int i=1;i<=n;i++) a[i]=read();
		}
		else
		{
			int k=read();
			for(int i=1;i<=k;i++)
			{
				u=read(); v=read();
				a[u]=v;
			}
		}
		for(int i=1;i<=n;i++)
		{
			re[i].val=a[i];
			re[i].id=i;
		}
		int ans=n;
		while(true)
		{
			if(ans==1) break;
			sort(re+1,re+ans+1,cmp);		
			//cout<<re[1].val<<endl;
			if(ans==2) 
			{
				re[1].val-=re[2].val;
				ans--;
			}
			else
			{
				if(re[1].val-re[ans].val<re[ans-1].val||(re[1].val-re[ans].val==re[ans-1].val&&re[1].id<re[2].id)) break;
				else 
				{
					re[1].val-=re[ans].val;
					ans--;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
