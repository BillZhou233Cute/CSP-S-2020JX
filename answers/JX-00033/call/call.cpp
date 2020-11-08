#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=10001;
struct data{
	int type,x,id[N];
}fun[N];
int n,m,a[N],S;
void jia(int i,int x){
	a[i]+=x;
}
void cheng(int x){
	for(int i=1;i<=n;i++) a[i]*=x;
}
void done(int b){
	switch(fun[b].type){
			case 1:{
				a[fun[b].id[0]]+=fun[b].x;
				break;
			}
			case 2:{
				for(int i=1;i<=n;i++)
					a[i]*=fun[b].x;
				break;
			}
			case 3:{
				for(int i=1;i<=fun[b].id[0];i++){
					done(fun[b].id[i]);
				}
				break;
			}
		}
}
int main(){
	freopen("call3.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&fun[i].type);
		switch(fun[i].type){
			case 1:{
				scanf("%d",&fun[i].id[0]);
				scanf("%d",&fun[i].x);
				break;
			}
			case 2:{
				scanf("%d",&fun[i].x);
				break;
			}
			case 3:{
				scanf("%d",&fun[i].id[0]);
				for(int j=1;j<=fun[i].id[0];j++){
					scanf("%d",&fun[i].id[j]);
				}
				break;
			}
		}
	}
	scanf("%d",&S);
	for(int i=1;i<=S;i++){
		int b;
		scanf("%d",&b);
		done(b);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}