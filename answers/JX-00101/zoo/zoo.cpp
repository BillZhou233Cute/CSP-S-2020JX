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

const int N=1000006;
#include<vector>
vector<int> need[64];
int lsh[N];bool have[N];
bool ok[64];int m0;
il int lob(int t)
{
	int l=1,r=m0;
	while(l!=r)
	{
		int mid=(l+r)>>1;
		if(lsh[mid]>=t) r=mid;else l=mid+1;
	}
	return l;
}
int main()
{
	openf(zoo);
	int n,m,c,k;rd(n);rd(m);rd(c);rd(k);
	F(j,0,k-1)ok[j]=false;
	F(i,1,n){ull a;rd(a);F(j,0,k-1){if(a&1)ok[j]=true;a>>=1;}}
	F(i,1,m){int p,q;rd(p);rd(q);need[p].push_back(q);lsh[i]=q;}
	sort(lsh+1,lsh+m+1);m0=unique(lsh+1,lsh+m+1)-lsh-1;F(i,1,m0) have[i]=false;
	F(j,0,k-1) F(i,0,(int)need[j].size()-1) need[j][i]=lob(need[j][i]);
	F(j,0,k-1) if(ok[j]) F(i,0,(int)need[j].size()-1) have[need[j][i]]=true;
	int cnt=0;F(j,0,k-1) {bool flg=true;if(!ok[j])F(i,0,(int)need[j].size()-1) if(!have[need[j][i]]) {flg=false;break;}if(flg)++cnt;}
	if(cnt==64) cout<<(ull)-n<<endl;
	else cout<<(1ull<<cnt)-n<<endl;
	return 0;
}
