#include<bits/stdc++.h>
using namespace std;
bitset<64>sl,ban;
int n,m,c,k;
int a[1000005],p[1000005],q[1000005];
int cnt;
int main()
{
//	freopen("zoo.in","r",stdin);
//	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sl|=a[i];
	}
	cout<<sl<<endl;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&p[i],&q[i]);
		if(!sl[p[i]])	cnt++;
	}
	cout<<((1<<(k-cnt))-n)<<endl;
	return 0;
}
