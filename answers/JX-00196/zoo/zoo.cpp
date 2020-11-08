#include<bits/stdc++.h>
#define re register
#define ull unsigned long long
using namespace std;
inline int read()
{
	re int x=0,f=1;
	re char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') f*=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
inline ull readu()
{
	re ull x=0;
	re char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar()) ;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	return x;
}
const int N=1000005;
struct query{int x,y;}e[N];
int n,m,c,k,num;
bool yor[67],york[67];
ull a[N],ans;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read(),m=read(),c=read(),k=read();
	for(re int i=1;i<=n;i++) 
	{
		a[i]=readu();
		for(re int j=0;j<64;j++)
			if(((a[i]>>j)&1)&&yor[j]==0) yor[j]=1;
	}
	for(re int i=1;i<=m;i++) 
	{
		e[i].x=read(),e[i].y=read();
		if(yor[e[i].x]==0&&york[e[i].x]==0) num++,york[e[i].x]=1;
	}
	for(re int i=0;i<(k-num);i++) ans+=((ull)1<<i);
	cout<<ans-n+1;
	return 0;
}
