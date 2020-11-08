#include<bits/stdc++.h>
#define MAXN 1000010
using namespace std;
inline int read(){
	char c=getchar();long long f=1,x=0;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f*x;
}
struct node{
	int opt,w;
}d[MAXN];
bool cmp(node a,node b){
	if(a.w!=b.w)return a.w<b.w;
	return a.opt>b.opt;
}
int T,n;
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	T=read();
	for(int asd=1;asd<=T;asd++){
		if(asd==1){
			n=read();
			for(int i=1;i<=n;i++)d[i].w=read(),d[i].opt=i;
		}
		else{
			int k=read();
			for(int i=1;i<=k;i++){
				int x=read();
				for(int j=1;j<=n;j++)
					if(d[j].opt==x)d[j].w=read();
			}
		}
		sort(d+1,d+n+1,cmp);
		if(d[3].w-d[1].w<d[2].w)printf("3\n");
		else if(d[3].w-d[1].w==d[2].w&&d[2].opt>d[3].opt)printf("3\n");
		else printf("1\n");
	}
	return 0;
}
