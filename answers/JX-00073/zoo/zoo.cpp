#include<bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll;
typedef unsigned long long ull;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
static char buf[100000],*p1=buf,*p2=buf;
inline int read(void){
	reg bool f=false;
	reg char ch=getchar();
	reg int res=0;
	while(!isdigit(ch))f|=(ch=='-'),ch=getchar();
	while(isdigit(ch))res=10*res+(ch^'0'),ch=getchar();
	return f?-res:res;
}

inline ull readull(void){
	reg char ch=getchar();
	reg ull res=0;
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=10ull*res+(ch^'0'),ch=getchar();
	return res;
}

const int MAXN=1e6+5;
const int MAXM=1e6+5;

int n,m,c,k;
ull a[MAXN];
int p[MAXM],q[MAXM];

inline ull count(reg ull x){
	reg ull res=0;
	while(x){
		if(x&1)
			++res;
		x>>=1;
	}
	return res;
}

int main(void){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);

	n=read(),m=read(),c=read(),k=read();
	reg ull A=0;
	for(reg int i=1;i<=n;++i){
		a[i]=readull();
		A|=a[i];
	}
	reg ull Need=0;
	for(reg int i=1;i<=m;++i){
		p[i]=read(),q[i]=read();
		Need|=(1ull<<p[i]);
		if((A>>p[i])&1)
			Need^=(1ull<<p[i]);
	}
	reg ull U=(1ull<<k)-1;
	reg ull sub=U^Need;
	reg ull cnt=count(sub);
	reg ull ans=(1ull<<cnt)-n;
	printf("%llu\n",ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
