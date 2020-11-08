#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
int  n, m, c, k;
int sum=0,ans=0,summ=0;
scanf("%d%d%d%d",&n,&m,&c,&k);
int a[n+1],p[m+1],q[c+1],pan[k+1];
for(int i=1;i<=n;i++){
scanf("%d",&a[i]);
}
for(int i=1;i<=m;i++){
scanf("%d%d",&p[i],&q[i]);
}
for(int i=1;i<=m;i++)
{summ=0;
	for(int j=1;j<=n;j++)
{
if(a[j]%(int)pow(2,p[i]+1)<pow(2,p[i])){
	summ++;
	}
	if(summ==n){
	pan[sum]=p[i];
	sum++;}

}}
for(int  i=0;i<=pow(2,k)-1;i++){
	for(int j=0;j<sum;j++){
	if(i%(int)pow(2,pan[j]+1)>=pow(2,pan[j])){
	ans++;
		continue;
}

}}
if(sum==0){
	cout<<pow(2,k)-n;
}
else{cout<<pow(2,k)-n-ans;}
return 0;
}
