#include<bits/stdc++.h>
#define IL inline
#define LL unsigned long long
using namespace std;
const int N=1e6+3;
LL n,m,C,k,c[N],b[100],s,ans=1;
IL LL in(){
	char c;int f=1;
	while((c=getchar())<'0'||c>'9')
		if(c=='-') f=-1;
	LL x=c-'0';
	while((c=getchar())>='0'&&c<='9')
		x=x*10+c-'0';
	return x*f;
	}
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	LL x,y;
	n=in(),m=in(),C=in(),k=in();
	for(int i=1;i<=n;++i) s|=in();
	for(int i=1;i<=m;++i)
		x=in(),y=in(),b[x]=1;
	for(int i=0;i<k;++i)
		if((s>>i&1)||(!b[i])) ans<<=1;
	cout<<ans-n<<endl;
	return 0;
	}