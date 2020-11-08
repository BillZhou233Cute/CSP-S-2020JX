#include <iostream>
#include <stdio.h>
using namespace  std;
int n,a[100001],t,T[100001],Tc[20001][20001],z,za;
void sad(int index){
	for(int i=0;i<n;i++){
		if(a[i]>998244353)
			a[i]%=998244353;
	}
	if(Tc[index][0]==1)a[Tc[index][1]]+=Tc[index][2];
	else if(Tc[index][0]==2){
		for(int j=1;j<=n;j++){
			a[j]*=Tc[index][1];
		}
	}
	else{
		for(int j=2;j<=Tc[index][1]	+1;j++){
				sad(Tc[index][j]);
		}
	}
	return;
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>Tc[i][0];
		if(Tc[i][0]==1)cin>>Tc[i][1]>>Tc[i][2];
		else if(Tc[i][0]==2)cin>>Tc[i][1];
		else{
			cin>>Tc[i][1];
			for(int j=2;j<=Tc[i][1]+1;j++){
				cin>>Tc[i][j];
			}
		}
	}
	cin>>z;
	for(int i=0;i<z;i++){
		cin>>za;
		sad(za);
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}