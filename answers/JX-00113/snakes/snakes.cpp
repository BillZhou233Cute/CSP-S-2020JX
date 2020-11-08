#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pre(i,a,b) for(int i=a;i>=b;i--)
#define N 200005
using namespace std;
int n,a[N],b[N];
void calc(){
	if(n==3){
		if(b[3]-b[1]>=b[2])puts("1");
		else puts("3");
	}
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T;scanf("%d",&T);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)b[i]=a[i];
	calc();
	T--;
	while(T--){
		int k;scanf("%d",&k);
		rep(i,1,k){
			int x,y;scanf("%d%d",&x,&y);a[x]=y;
		}
		rep(i,1,n)b[i]=a[i];
		calc();
	}
	return 0;
}
/*
g++ snakes.cpp -o snake -Wall
*/
