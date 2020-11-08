#include <iostream>
#include <stdio.h>
using namespace  std;
int n,m,c,k,count=1,f[1000001][2],z[1000001],sit[1000001],truein[1000001],top;
int final[1000001],topfinal,sum;
bool book[1000001];
bool check(int x,int index){
	bool z[64],top=0;
	while(x<2){
		z[top++]=x%2;
		x/=2;
	}
	z[top++]=1;
	if(z[index]==1)return true;
	else return false;
}
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>k>>c;
	for(int i=0;i<c;i++){
		count*=2;
	}
	count--;
	for(int i=0;i<n;i++){
		cin>>z[i];
	}
	for(int i=0;i<m;i++){
		cin>>f[i][0];
		cin>>f[i][1];
		sit[f[i][0]]=1;
	}
	
	for(int i=0;i<=1000000;i++){
		if(sit[i]==1)truein[top++]=i;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<top;j++){
			if(check(z[i],truein[j])==1){
				final[topfinal++]=truein[j];
				sum--;
				}
		}
	}
	for(int i=0;i<count;i++){
		for(int j=0;j<topfinal;j++){
			if(check(i,final[j]))sum++;
			}
	}
	cout<<12<<endl;
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}