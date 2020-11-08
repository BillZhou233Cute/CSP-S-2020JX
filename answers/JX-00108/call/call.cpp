#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
const int MOD=998244353;
using namespace std;
int n,m,c,k,Q;
int a[100005],p[100005],q[100005];
vector<int> km;
struct HS{
	int ty,p,v,l;
	vector<int> t;
}hs[100005];
int cnt[10];
bool vis[100005];
bool cz1=false,cz2=false,shu=true;
int doo(int tt)
{
	int num=1;
	if(hs[tt].ty==1)
		{	
			q[hs[tt].p]+=hs[tt].v;
			//cout << tt<<' '<<q[hs[tt].p] << endl;
			if(!vis[hs[tt].p]){km.push_back(hs[tt].p);vis[hs[tt].p]=true;}
			return 1;
		}
		if(hs[tt].ty==2)
		{
			num*=hs[tt].v;
			if(km.size())for(int i=0;i<km.size();i++) {q[km[i]]*=hs[tt].v;q[km[i]]%=MOD;}
			return num;
		}
		else
		{
			for(int i=0;i<hs[tt].l;i++) 
			{
				//vector<int> G;
				//G=hs[tt].t;
				//cout << hs[tt].t[i] << endl;
				num*=doo(hs[tt].t[i]);
			}
		}
	return num;
}

void puout(int j)
{
	
	for(int i=1;i<=n;i++) printf("%d ",((a[i]%MOD)*(j%MOD)+q[i]%MOD)%MOD);
		exit(0);
}
void d(int k)
{
	if(hs[k].ty==1) a[hs[k].p]+=hs[k].v;
	else
	{
		for(int i=0;i<hs[k].l;i++) d(hs[k].t[i]);
	}
}
int CJ=0;
int main()
{
	memset(q,0,sizeof q);
	memset(vis,false,sizeof vis);
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin >> n ;
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	cin >>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&hs[i].ty);
		if(hs[i].ty==1)
		{scanf("%d%d",&hs[i].p,&hs[i].v);cz1=true;
		}
		else if(hs[i].ty==2)
		{
			scanf("%d",&hs[i].v);cz2=true;
		}
		else
		{
			scanf("%d",&hs[i].l);CJ+=hs[i].l;
			for(int j=1;j<=hs[i].l;j++) {int r;scanf("%d",&r);(hs[i].t).push_back(r);} 
		}
	}
	cin >> Q;
	if(CJ==m-1)
	{
		int i=1;
		for(;i<=m;i++)
		{if(hs[i].ty!=3) break;}
		if(hs[i].ty==1)
		{
			while(Q--)
			{
				int tt;
				scanf("%d",&tt);
				a[hs[i].p]+=hs[i].v%MOD;
			}
			puout(1);
		}
		else
		{
			int num=1;
			while(Q--)
			{
				int tt;
				scanf("%d",&tt);
				num*=hs[i].v;
				num%=MOD;
			}
			puout(num);
		}
	}
	if(CJ==0)
	{int num=1;
		while(Q--)
		{
			int tt;
			scanf("%d",&tt);
			if(hs[tt].ty==1)
			{
				q[hs[tt].p]+=hs[tt].v;
				km.push_back(hs[tt].p);
			}
			else
			{
				num*=hs[tt].v;
				for(int i=0;i<km.size();i++) {q[km[i]]*=hs[tt].v;q[km[i]]%=MOD;}
			}
		}
		puout(num);
	}
	if(!cz1)
	{
		int num=1;
		while(Q--)
		{int tt;
			scanf("%d",&tt);
			num*=hs[tt].v;num%=MOD;}
		puout(num);
	}
	if(!cz2)
	{
		while(Q--)
		{
			int tt;
			scanf("%d",&tt);
			d(tt);
		}
		puout(1);
	}
	int num=1;
	while(Q--)
	{
		int tt;
		scanf("%d",&tt);
		num*=doo(tt);
	}
	puout(num);
	return 0;
}