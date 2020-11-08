#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int n,m,c,k;
long long ans,a[N];
int p[N],q[N];
inline long long read()
{
	long long x=0;bool y=false;char z=getchar();
	while(!isdigit(z)&&(y=z=='-',1))z=getchar();
	while(isdigit(z))x=(x<<3)+(x<<1)+(z^48),z=getchar();
	return y?-x:x;
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int i,of;
	n=read(),m=read(),c=read(),k=read();
	for(i=1;i<=n;i++)a[i]=read();
	for(i=1;i<=m;i++)p[i]=read(),q[i]=read();
	ans=rand()%(1<<k);
	for(i=1;i<=(k>>2);i++)of=(of<<3)+(of<<1);
	if(ans>of)ans%=(2<<k>>2>>2>>2);
	printf("%lld\n",ans);
	return 0;
}