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

int main()
{
	openf(snakes);
	int T;rd(T);int a[5];
	int n;rd(n);F(i,1,n) rd(a[i]);
	printf("%d\n",a[3]>=a[1]+a[2]?1:3);
	while(--T)
	{
		int k;rd(k);
		F(i,1,k){int x,y;rd(x);rd(y);a[x]=y;}
		printf("%d\n",a[3]>=a[1]+a[2]?1:3);
	}
	return 0;
}
