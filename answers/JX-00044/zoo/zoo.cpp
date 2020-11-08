#include<bits/stdc++.h>
using namespace std;
#define read(a) scanf("%d",& a );
#define ll unsigned long long
int n,m,c,k,s,cp;
ll a[1000010],as;
ll p,q,ps,qs,ss=1;
bool b[10010];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i=1;i<=n;i++)
		scanf("%llu",&a[i]),as|=a[i];
	for(int i=1;i<=m;i++)
	{
		scanf("%llu%llu",&p,&q);
		ps|=1<<p;
		if(!b[p])
		{
			cp++;
			b[p]=1;
		}
	}
	qs=ps&as;
	do
	{
		s++;
		qs&=qs-1;
	}while(qs);
//	cout<<as<<' '<<ps<<' '<<qs<<' '<<s<<endl;
	for(int i=1;i<=k+s-cp;i++)
		ss*=2;
	printf("%llu",ss-n);
	return 0;
}