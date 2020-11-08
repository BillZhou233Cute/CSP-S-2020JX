#include<bits/stdc++.h>
#define re register
#define mod 998244353
using namespace std;
inline int read()
{
	re int x=0,f=1;
	re char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') f*=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
const int N=100005;
int n,m,q,type[N],p[N],val[N],st[N],ed[N],kp[1000005],len,op[N];
long long a[N];
void gui(int x)
{
	if(type[x]==1) {(a[p[x]]+=val[x])%=mod;return ;}
	else if(type[x]==2) 
	{
		for(re int i=1;i<=n;i++)
			(a[i]*=val[x])%=mod;
		return ;
	}
	for(re int i=st[op[x]];i<=ed[op[x]];i++)
		gui(kp[i]);
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(re int i=1;i<=n;i++) a[i]=read();
	m=read();
	for(re int i=1,mid;i<=m;i++) 
	{
		type[i]=read();
		if(type[i]==1) p[i]=read(),val[i]=read();
		else if(type[i]==2) val[i]=read();
		else 
		{
			mid=read();len++;
			for(re int j=1;j<=mid;j++)
				kp[j+ed[len-1]]=read();
			st[len]=ed[len-1]+1,ed[len]=ed[len-1]+mid;
			op[i]=len;
		}
	}
	q=read();
	for(re int i=1,x;i<=q;i++)
	{
		x=read();
		gui(x);
	}
	for(re int i=1;i<=n;i++) printf("%lld ",a[i]);
	return 0;
}
/*
10
1 2 3 4 5 6 7 8 9 10
8
3 2 2 3
3 2 4 5
3 2 5 8
2 2
3 2 6 7
1 2 5
1 7 6
2 3
3
1 2 3
*/
