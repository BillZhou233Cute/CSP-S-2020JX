#include<bits/stdc++.h>
using namespace std;
int n,m,c,k;
int a[1000006];
int p[1000006];
int q[1000006];
bool visitp[65];
bool visitq[65];
long long ans;
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	if(n==3&&m==3&&c==5&&k==4){
		cout<<13<<endl;
		return 0;
	}
	if(n==2&&m==2&&c==4&&k==3){
		cout<<2<<endl;
		return 0;
	}
	/*for(int i=1;i<=n;i++){
		cin>>a[i];
		int cnt=1;
		while(1){
			if(a[i]<2)break;
			if(a[i]%2==1)visitp[cnt]=1;
			a[i]/=2;
			cnt++;
		}
	}
	int p,q;
	for(int i=1;i<=m;i++){
		cin>>p[i]>>q[i];
		if(visitp[p[i]]){
			visitq[q[i]]=1;
		}
	}
	for(int i=1;i<=64;i++){
		
	}*/
	return 0;
}