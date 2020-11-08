#include<bits/stdc++.h>
using namespace std;
int T,n,a[4];
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&T);
	T--;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(a[3]-a[1]<a[2]){
		printf("3\n");
	}
	if(a[3]-a[1]==a[2]){
		printf("1\n");
	}
	if(a[3]-a[1]>a[2]){
		printf("1\n");
	}
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[x]=y;
		}
		if(a[3]-a[1]<a[2]){
			printf("3\n");
			continue;
		}
		if(a[3]-a[1]==a[2]){
			printf("1\n");
			continue;
		}
		if(a[3]-a[1]>a[2]){
			printf("1\n");
			continue;
		}
	}
	return 0;
}
