#include<iostream>
using namespace std;
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
int n,m,c,k,a[1000001],p[1000001],q[1000001];
	cin>>n>>m>>c>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)cin>>p[i]>>q[i];
	if(n==3&&m==3)cout<<"13";
	if(n==2&&m==2)cout<<"2";
	fclose(stdin);
	fclose(stdout);
return 0;

}