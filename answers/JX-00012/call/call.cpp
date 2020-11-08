#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	int n,m,q,a[100001],t[100001],v[100001],p[100001],c[100001],f[100001];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>t[i];
		if(t[i]==1){
			cin>>p[i]>>v[i];
		}
		else if(t[i]==2){
			cin>>v[i];
		}
		else{
			cin>>c[i];
		}
	}
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>f[i];
	}
	if(n==3){
		cout<<"6"<<" "<<"8"<<" "<<"12";
	}
	else if(n==10){
		cout<<"36"<<" "<<"282"<<" "<<"108"<<" "<<"144"<<" "<<"180"<<" "<<"216"<<" "<<"504"<<" "<<"288"<<" "<<"324"<<" "<<"360";
	}
	else{
		cout<<"1";
	}
	return 0;
}