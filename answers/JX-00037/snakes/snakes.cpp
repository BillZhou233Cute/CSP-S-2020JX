#include <iostream>
#include <stdio.h>
using namespace  std;
int t,n,a[3]={0},maxl=0,sum=0,r[11]={0},l;
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t>>n;
	for(int i=0;i<3;i++){
		cin>>a[i];
		sum+=a[i];
		maxl=max(maxl,a[i]);
	}
	if(maxl>sum-maxl)r[0]=1;
	else r[0]=3;
	sum=0;
	maxl=0;
	for(int i=0;i<t-1;i++){
		cin>>l;
		int c,b;
		for(int j=0;j<l;j++){
			cin>>c>>b;
			a[c]=b;
		}
		for(int j=0;j<3;j++){
			sum+=a[j];
			maxl=max(maxl,a[j]);
		}
		if(maxl>sum-maxl)r[i+1]=1;
		else r[i+1]=3;
		sum=maxl=0;
	}
	for(int i=0;i<t;i++){
		cout<<r[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}