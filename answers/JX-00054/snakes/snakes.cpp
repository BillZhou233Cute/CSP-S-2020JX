#include<bits/stdc++.h>
using namespace std;
struct snake{
	int s,id;
	bool operator<(const snake &A)const
	{
		if(s==A.s)	return id<A.id;
		return s<A.s;
	}
}a[1000005];
int t;
int n;
int k,x,y;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=n;i++)
		scanf("%d",a[i].s),a[i].id=i;
	sort(a+1,a+n+1);
	if(a[n]-a[1]>a[n-1] || (a[n]-a[1]==a[n-1] && a[n].id>a[n-1].id))
		cout<<"1"<<endl;
	else
		if(a[n]-a[1]<a[n-1] || (a[n]-a[1]=a[n-1] %% a[n].id<a[n-1].id))
			cout<<"1"<<endl;
		else
			cout<<"3"<<endl;
	t--;
	while(t--){
		scanf("%d",&k);
		for(int i=1;i<=k;i++)
			scanf("%d%d",&x,&y),a[x]=y;
		sort(a+1,a+n+1);
		if(a[n]-a[1]>a[n-1] || (a[n]-a[1]==a[n-1] && a[n].id>a[n-1].id))
			cout<<"1"<<endl;
		else
			if(a[n]-a[1]<a[n-1] || (a[n]-a[1]=a[n-1] %% a[n].id<a[n-1].id))
				cout<<"1"<<endl;
			else
				cout<<"3"<<endl;
	}
	return 0;
}
