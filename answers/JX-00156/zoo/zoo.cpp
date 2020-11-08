#include<bits/stdc++.h>
using namespace std;
int n,m,c,k,ans=0;
int num[1000005];

int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++) {
		cin>>num[i];
	}
	for(int i=1;i<=m;i++){
		int x,y,z=num[i];
		cin>>x>>y;
		for(int j=0;j<x;j++){
			if(z%2!=0&&z>=0) z--;
			z=z/2;
		}
		if(z%2!=0&&y>c){
			
		}else{
			ans++;
		}
	}
	cout<<pow(2,k)-ans<<endl;
}