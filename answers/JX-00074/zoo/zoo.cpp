#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ull long long
const int N=1e6+5;
ull n,m,c,k,animal,eat,a[N],p,q,ysy,base[70];
bool vis[100];

inline LL read()
{
	register LL x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)) f^=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return f ? x:-x;
}

int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	
	n=read(),m=read(),c=read(),k=read();
	
	base[1]=1;
	for(int i=1;i<=k;++i) base[i]=base[i-1]*2+1;
	
	for(int i=1;i<=n;++i) a[i]=read(),animal|=a[i];
	
	ysy=k;
	for(int i=1;i<=m;++i)
	{
		p=read(),q=read();
		if(animal&(1<<p)) ;
		else if(!vis[p]) vis[p]=1,ysy--;
	}
	
	if(ysy) cout<<base[ysy]-n+1<<endl;
	
	return 0;
}
