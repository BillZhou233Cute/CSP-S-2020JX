#include<bits/stdc++.h>
using namespace std;
int t,n,k,top=1;
int a[15];
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		if(a[n]-a[n-1]<a[1]){
			cout<<n<<endl;
		}
		else{
			while(a[n]-a[n-1]>a[top]){			
				n--;a[top]=-1;top++;}
			cout<<n<<endl;
		}
	t--;
	while(t--){
		cin>>k;
		int num,x;
		for(int i=1;i<=k;i++){
			cin>>num;
			cin>>x;
			if(a[num]==-1) continue;
			a[num]=x;
		}
		sort(a+1,a+n+1);
		if(a[n]-a[n-1]>a[top]||top==n-1){
			a[n]-=a[top];
			sort(a+1,a+n+1);
			top++;
			n--;
		}
		cout<<n<<endl;
	}
}
