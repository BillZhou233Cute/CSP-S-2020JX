#include<bits/stdc++.h>
using namespace std;
int a[1000003];
int b[1000003];
int ans;
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int n,t,k;
	cin>>t;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	if(n==3){
		sort(a+1,a+4);
		if(a[3]-a[1]>=a[2])cout<<1<<endl;
		else cout<<3<<endl;
		t--;
		while(t--){
			cin>>k;
			int x,y;
			for(int i=1;i<=k;i++){
				cin>>x>>y;
				a[x]=y;
			}
			sort(a+1,a+4);
			if(a[3]-a[1]>=a[2])cout<<1<<endl;
			else cout<<3<<endl;
		}
	}
	else if(n<=10){
		ans=n;
		sort(b+1,b+n+1);
		int cnt=1;
		while(b[n]-b[cnt]>=b[n-1]){
			b[n]-=b[cnt];
			ans--;
		}
		cout<<ans<<endl;
		t--;
		while(t--){
			ans=n;
			cin>>k;
			int x,y;
			for(int i=1;i<=k;i++){
				cin>>x>>y;
				a[x]=y;
			}
			for(int i=1;i<=n;i++)b[i]=a[i];
			sort(b+1,b+n+1);
			int cnt=1;
			while(b[n]-b[cnt]>=b[n-1]){
				b[n]-=b[cnt];
				ans--;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}



