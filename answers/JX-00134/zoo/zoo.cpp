#include<bits/stdc++.h>
#define R register int
#define IN inline
using namespace std;
typedef unsigned long long ull;
const int N=1e6+5;
int n;
int k,m,c;
int func[70];
bool book[70];
set <ull> S;
set <int> chi;
ull a[N];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	chi.insert(0);
	for(R i=1;i<=n;i++) scanf("%lld",&a[i]),S.insert(a[i]);
	ull cnt=0;
	for(R i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		func[x]=y;
	}
	ull tmp=a[1];
	//for(R i=2;i<=n;i++) tmp=tmp|a[i];
	for(R i=0;i<k;i++) 
	{
		if((tmp>>k)&1) 
		chi.insert(func[k]);
	}
	//for(R i=1;i<=10;i++) if(chi.count(i)!=0) cout<<i<<' '; cout<<endl;
	for(ull num=0;num<=(1<<k)-1;num++)
	{
		if(S.count(num)!=0) continue;
		bool flag=true;
		for(R i=0;i<k;i++) 
		{
			if(((tmp>>k)&1)&&chi.count(func[k])==0) 
			{
				flag=false;
				break;
			}	
		}
		if(flag) /*cout<<num<<endl,*/cnt++;
	}
	printf("%lld",cnt);
	return 0;
}