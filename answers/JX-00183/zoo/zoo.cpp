#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,c,k;
int a[N],b[N],p[N],q[N],tmp[N];
int buy,ans;
vector<int> e[70];
int read()
{
	int res,f=1;
	char ch;
	while((ch=getchar())<'0'||ch>'9') if(ch=='-') f=-1;
	res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9') res=(res<<1)+(res<<3)+ch-'0';
	return res*f;
}

void init()
{
	sort(tmp+1,tmp+1+m);
	int tot=unique(tmp+1,tmp+1+m)-tmp-1;
	for(int i=1;i<=m;i++)
	{
		q[i]=lower_bound(tmp+1,tmp+1+tot,q[i])-tmp;
		if(p[i]<=63)
		{
			b[q[i]]|=(1ll<<p[i]);
			e[p[i]].push_back(q[i]);
		}
	}
}

signed main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read(),m=read(),c=read(),k=read();
	for(int i=1;i<=n;i++) a[i]=read(),buy|=a[i];
	for(int i=1;i<=m;i++) p[i]=read(),tmp[i]=q[i]=read();
	init();
	int i=0;
	while(buy)
	{
		if(buy&1) for(int j=0;j<e[i].size();j++) ans|=b[e[i][j]];
		buy>>=1;
		i++;
	}
	int cnt=0;
	for(int i=1;i<=m;i++) if((ans&(1ll<<p[i]))==0) cnt++,ans|=(1ll<<p[i]);
	k-=cnt;
	int anim=0;
	anim=(1ll<<k);
	printf("%lld",anim-n);
	return 0;
}
