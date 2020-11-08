#include<cstdio>
#include<vector>
#include<algorithm>
#define int ll
typedef long long ll;
int num=0;
struct node {int p,q;} t[1000005];
int d[1000005];
bool cnt[1000005];
std::vector<int> vec[1000005];
inline int read() {
	register int x=0,f=1;register char s=getchar();
	while(s>'9'||s<'0') {if(s=='-') f=-1;s=getchar();}
	while(s>='0'&&s<='9') {x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main() {
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int n=read(),m=read(),c=read(),k=read(),S0=0,S1=0,tot=k;
	for(register int i=1;i<=n;++i) {S0|=read();}
	for(register int i=1;i<=m;++i) {
		t[i].p=read();t[i].q=read();
		d[++num]=t[i].q;
	}
	std::sort(d+1,d+1+num);
	num=std::unique(d+1,d+1+num)-d-1;
	for(register int i=1;i<=m;++i) {
		t[i].q=std::lower_bound(d+1,d+1+num,t[i].q)-d;
		vec[t[i].q].push_back(t[i].p);
		if(S0>>(t[i].p)&1) cnt[t[i].q]=1;
	}
	for(register int i=1;i<=num;++i) {
		if(cnt[i]) continue;
		for(register int j=0;j<vec[i].size();++j) {
			S1|=(1ll<<vec[i][j]);	
		}
	}		
	for(register int i=0;i<k;++i) {if(S1>>i&1) --tot;}
	printf("%llu\n",(1ull<<tot)-n);
	return 0;
}
