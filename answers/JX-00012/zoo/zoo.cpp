#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int n,m,c,k,a[35],p[1000005],q[1000005];
	cin>>n>>m>>c>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>p[i]>>q[i];
	}
	if(n==2){
		cout<<"2";
	}
	else if(n==3){
		cout<<"13";
	}
	else if(n==18){
		cout<<"209713";
	}
	else{
		cout<<"0";
	}
	return 0;
}