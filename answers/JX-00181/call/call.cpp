#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
struct ope{
	int t;
	int p,v;
	int num,q[1005];
}o[100005];
int n,m;
int a[100005];
void opera(int x)
{
	for(int i=1;i<=o[x].num;i++){
		if(o[o[x].q[i]].t==1){
			a[o[o[x].q[i]].p]=(a[o[o[x].q[i]].p]+o[o[x].q[i]].v)%mod;
		}else if(o[o[x].q[i]].t==2){
			for(int j=1;j<=n;j++){
				a[j]=a[j]*o[o[x].q[i]].v%mod;
			}
		}else{
			opera(o[x].q[i]);
		}
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&o[i].t);
		if(o[i].t==1){
			scanf("%d%d",&o[i].p,&o[i].v);
		}else if(o[i].t==2){
			scanf("%d",&o[i].v);
		}else if(o[i].t==3){
			scanf("%d",&o[i].num);
			for(int j=1;j<=o[i].num;j++){
				scanf("%d",&o[i].q[j]);
			}
		}
	}
	scanf("%d",&m);
	while(m--){
		int f;scanf("%d",&f);
		if(o[f].t==1){
			a[o[f].p]=(a[o[f].p]+o[f].v)%mod;
		}else if(o[f].t==2){
			for(int j=1;j<=n;j++){
				a[j]=a[j]*o[f].v%mod;
			}
		}else{
			opera(f);
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}