#include<bits/stdc++.h>
using namespace std;
int n,m,c,k,l[1000010],r[1000010],cnt[110],kpl[110],tot;
unsigned long long a[1000010];
map<int,int> vis;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);k--;
	for(int i=k;i>=0;i--) kpl[i]=1;
	for(int i=1;i<=n;i++) {
		scanf("%llu",&a[i]);
		for(int j=k;j>=0;j--) cnt[j]|=(a[i]>>j)&1;
	}
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&l[i],&r[i]);
		vis[r[i]]|=cnt[l[i]];
	}
	for(int i=1;i<=m;i++) {
		if(vis[r[i]]) continue;
		kpl[l[i]]=0;
	}
	for(int i=k;i>=0;i--) tot+=kpl[i];
	if(k||n)
		printf("%llu",(1ull<<tot)-n);
	else printf("0");
	return 0;
}
