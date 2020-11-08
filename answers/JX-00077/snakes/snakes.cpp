#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t,n;
	scanf("%d",&t);
	int a[30001];
	int ans[30001];
	for(int q=1;q<=t;q++){
		scanf("%d",&n);
		if(q==1){
			for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		}
		else{
			int s,d;
			for(int i=1;i<=n;i++){
				scanf("%d%d",&s,&d);
				a[s]=d;
			}
		}
	if(a[3]>=a[2]){
		if(a[3]>=a[1]){
			if(a[3]>=a[2]+a[1])
			ans[q]=1;
			else
			ans[q]=3;
		}else{
			if(a[1]>a[3]+a[2])
			ans[q]=1;
			else
			ans[q]=3;
		}
	}else{
		if(a[2]>=a[1]){
			if(a[2]>a[1]+a[3]||(a[2]==a[1]+a[3]&&a[1]>a[3]))
			ans[q]=1;
			else
			ans[q]=3;
		}else{
			if(a[1]>a[2]+a[3])
			ans[q]=1;
			else
			ans[q]=3;
		}
	}
}
for(int i=1;i<=t;i++)
printf("%d\n",ans[i]);
return 0;
}
