#include <cstdio>
#include <iostream>

using namespace std;
int t,a[3005],n;
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int k;
		if(i==1){
			scanf("%d",&n);
			for(int j=1;j<=n;j++){
				scanf("%d",&a[j]);
			}
		}
		else{
			scanf("%d",&k);
			int x,y;
			for(int j=1;j<=k;j++){
				scanf("%d%d",&x,&y);
				a[x]=y;
			}
		}
		if(a[3]-a[1]<a[2]){
			printf("%d\n",3);
		}
		else{
			printf("%d\n",1);
		}
	}
	return 0;
}