#include<bits/stdc++.h>
using namespace std;
int read(){
	long long x=0;
	int f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
int a[105],p[100005][2];
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t;
	scanf("%d",&t);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	t=t-1;
	if(a[3]-a[1]>=a[2]) cout<<'1'<<endl;
	else cout<<'3'<<endl;
	while(t--)
	{
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			scanf("%d",&p[i][1]);
			scanf("%d",&p[i][2]);
		}
	
		for(int i=1;i<=k;i++){
			a[p[i][1]]=p[i][2];
		}
		if(a[3]-a[1]>=a[2]) cout<<'1'<<endl;
		else cout<<'3'<<endl;
	}
	return 0;
}
