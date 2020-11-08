#include<bits/stdc++.h>
using namespace std;
int a[5];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t;scanf("%d",&t);t--;
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(a[3]>=a[2]&&a[3]>=a[1]){
		if(a[3]-min(a[1],a[2])>max(a[1],a[2])){
			cout<<1<<endl;
		}else{
			cout<<3<<endl;
		}
	}else if(a[2]>a[3]&&a[2]>=a[1]){
		if(a[2]-min(a[1],a[3])>max(a[1],a[3])){
			cout<<1<<endl;
		}else{
			cout<<3<<endl;
		}
	}else if(a[1]>a[3]&&a[1]>a[2]){
		if(a[1]-min(a[2],a[3])>max(a[2],a[3])){
			cout<<1<<endl;
		}else{
			cout<<endl;
		}
	}
	while(t--){
		int b;cin>>b>>a[1]>>b>>a[2]>>b>>a[3];
		if(a[3]>=a[2]&&a[3]>=a[1]){
		if(a[3]-min(a[1],a[2])>max(a[1],a[2])){
			cout<<1<<endl;
		}else{
			cout<<3<<endl;
		}
	}else if(a[2]>a[3]&&a[2]>=a[1]){
		if(a[2]-min(a[1],a[3])>max(a[1],a[3])){
			cout<<1<<endl;
		}else{
			cout<<3<<endl;
		}
	}else if(a[1]>a[3]&&a[1]>a[2]){
		if(a[1]-min(a[2],a[3])>max(a[2],a[3])){
			cout<<1<<endl;
		}else{
			cout<<endl;
		}
	}
	}
	return 0;
}