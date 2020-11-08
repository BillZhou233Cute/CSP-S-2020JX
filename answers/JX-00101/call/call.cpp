#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define re register
#define il inline
#define F(i,a,b) for(re int i=a,i##_end=b;i<=i##_end;++i)
#define UF(i,a,b) for(re int i=a,i##_end=b;i>=i##_end;--i)
template<typename T> il T rd(T&x)
{
	x=0;T f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*=f;
}
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
il ll rd(){ll x;rd(x);return x;}

#include<vector>
#define int ll
const int N=200005;
const ll p=998244353;
vector<int> cal[N];
vector<pair<int,ll> > ad[N];
ll mult[N];
ll a[N];
bool ok[N];
ll tmp[N],tmp2[N];bool have[N],have2[N];
void dfs(int u)
{
	if(ok[u]) return;
	F(i,0,(int)cal[u].size()-1) dfs(cal[u][i]);
	mult[u]=1;
	UF(i,(int)cal[u].size()-1,0){tmp[cal[u][i]]=(tmp[cal[u][i]]+mult[u])%p;mult[u]=mult[u]*mult[cal[u][i]]%p;}
	vector<int> tmp3;tmp3.clear();
	F(i,0,(int)cal[u].size()-1)
	{
		if(have2[cal[u][i]]) continue;have2[cal[u][i]]=true;
		F(j,0,(int)ad[cal[u][i]].size()-1)
		{pair<int,ll>x=ad[cal[u][i]][j];tmp2[x.first]=(tmp2[x.first]+x.second*tmp[cal[u][i]]%p)%p;if(!have[x.first]) have[x.first]=true,tmp3.push_back(x.first);}
	}
	F(i,0,(int)tmp3.size()-1) if(tmp2[tmp3[i]]){ad[u].push_back(make_pair(tmp3[i],tmp2[tmp3[i]]));tmp2[tmp3[i]]=0;have[tmp3[i]]=false;}
	F(i,0,(int)cal[u].size()-1) tmp[cal[u][i]]=0,have2[cal[u][i]]=false;
	ok[u]=true;
}
signed main()
{
	openf(call);
	int n=rd();F(i,1,n) rd(a[i]);
	int m=rd();
	F(i,1,m)
	{
		int type=rd();ad[i].clear();cal[i].clear();ok[i]=true;
		if(type==1){mult[i]=1;int pp=rd();int v=rd();ad[i].push_back(make_pair(pp,(ll)v));}
		if(type==2){mult[i]=rd();}
		if(type==3){ok[i]=false;int c=rd();while(c--)cal[i].push_back(rd());}
	}
	F(i,1,max(n,m+1)) tmp[i]=tmp2[i]=have[i]=0;
	ok[m+1]=false;ad[m+1].clear();cal[m+1].clear();int c=rd();while(c--)cal[m+1].push_back(rd());
	dfs(m+1);
	F(i,1,n) a[i]=a[i]*mult[m+1]%p;
	F(i,0,(int)ad[m+1].size()-1){pair<int,ll>x=ad[m+1][i];a[x.first]+=x.second;a[x.first]%=p;}
	F(i,1,n-1) printf("%lld ",a[i]%p);printf("%lld\n",a[n]%p);
	/*
	printf("\n------------\n");
	F(i,1,m+1)
	{
		printf("func#%lld:",i);
		printf("mult=%lld;",mult[i]);
		printf("add=");F(j,0,(int)ad[i].size()-1)printf("%c{%lld,%lld}",",["[j==0],ad[i][j].first,ad[i][j].second);
		if(ad[i].size()==0) printf("[");printf("].\n");
	}
	*/
	return 0;
}
