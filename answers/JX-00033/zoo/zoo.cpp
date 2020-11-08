#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1000001,C=100000001;
struct Rule{
	int q,p;
}rule[N];
int n,m,c,k,a[N];
int fo,ans=0;
bool Q[C],visa[64],visb[N];
int f_pow(int a,int x){
	int ans=1,base=a;
	while(x>0){
		if(x&1) ans*=base;
		base+=base;
	}
	return ans;
}
bool chk(int x,int y){
	y=rule[y].p;
	for(int i=1;i<=y;i++)
		x=x>>1;
	if(x&1) return true;
	return false;
}
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	fo=f_pow(2,k);
	for(int i=1;i<=n;i++) {scanf("%d",&a[i]);visa[a[i]]=true;}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&rule[i].p,&rule[i].q);
		for(int j=1;j<=n;j++)
			if(chk(a[j],i)){Q[rule[i].q]=true;break;}
	}
	for(int i=0;i<fo;i++){
		if(visa[i])continue;
		for(int j=1;j<=m;j++){
		    if(chk(i,j)&&Q[rule[j].q]){ans++;}
	    }
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}