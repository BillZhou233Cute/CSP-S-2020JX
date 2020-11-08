#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#define N 1000010
using namespace std;

int T,n,a[N];
priority_queue<int>q;

int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0' || c>'9') f=(c=='-')?-1:1,c=getchar();
	while(c>='0' && c<='9') x=x*10+c-48,c=getchar();
	return x*f;
}

int b[N];

void work(){
	for(int i=1;i<=n;i++) b[i]=a[i]; 
	int tot=n;
	while(1){
		if(tot==2){tot--;break;}
		if(a[tot]-a[1]<a[2]) break;
		int now=lower_bound(a+1,a+tot+1,a[tot]-a[1])-a;
		for(int i=2;i<=now;i++) a[i-1]=a[i];
		a[now]=a[tot]-a[1];
		tot--;
	}
	printf("%d\n",tot);
	for(int i=1;i<=n;i++) a[i]=b[i];
	return;
}

int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	T=read();n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	work();
	T--;
	while(T--){
		int k=read();
		for(int i=1;i<=k;i++){
			int x=read(),y=read();
			a[x]=y;
		}
		work();
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
