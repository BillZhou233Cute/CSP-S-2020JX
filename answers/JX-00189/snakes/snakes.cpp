#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<map>
#include<cstring>
#include<queue>
using namespace std;
#define ll long long
const int N=1e6+10;
inline void rd(int &x){
	x=0;bool flag=0;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-'){flag=1;ch=getchar();};
	while(ch>='0'&&ch<='9')x=x*10+(ch-'0'),ch=getchar();
	if(flag)x=-x;
}
inline void rd(ll &x){
	x=0;bool flag=0;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-'){flag=1;ch=getchar();};
	while(ch>='0'&&ch<='9')x=x*10ll+(ch-'0'),ch=getchar();
	if(flag)x=-x;
}
int n,k,ans;
struct node{
	int val,id;
}a[N];
inline bool operator <(node x,node y){
	return x.val!=y.val?x.val<y.val:x.id<y.id;
}
struct edge{
	int val,id;
}b[N];
inline bool operator <(edge x,edge y){
	return x.val!=y.val?x.val>y.val:x.id>y.id;
}
priority_queue<node>v;
priority_queue<edge>e;
int f[N];
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t;rd(t);
	for(int tt=1;tt<=t;++tt){
		if(tt==1)
		rd(n);
		else 
		rd(k);
		if(tt==1){
			for(int i=1;i<=n;++i){rd(a[i].val);a[i].id=i;v.push(a[i]);b[i].id=i;b[i].val=a[i].val;e.push(b[i]);};
		}
		else{
			for(int i=1,x,y;i<=k;++i){rd(x);rd(y);a[x].val=y;}
			for(int i=1;i<=n;++i){a[i].id=i;v.push(a[i]);b[i].id=i;b[i].val=a[i].val;e.push(b[i]);};
		}
		int siz=n;
		
		while(siz>3){
			node x=v.top();v.pop();
			edge y=e.top();e.pop();
			while(y.id==x.id){
				e.pop();y=e.top();
			}
			edge z=e.top();
			while(z.id==y.id){
				e.pop();z=e.top();
			}
			if(x.val-y.val>z.val||(x.val-y.val==z.val&&x.id>z.id)){
				--siz;
				x.val-=y.val;
				v.push(x);
				y.id=x.id;y.val=x.val;
				e.push(y);
			}
			else break;
		}if(siz>3){
		node x=v.top();v.pop();
		edge y=e.top();e.pop();
		edge z=e.top();
			if(!(x.val>y.val||(x.val==y.val&&x.id>y.id)))continue;
		x.val-=y.val;
		v.push(x);
		y.id=x.id;y.val=x.val;
			e.push(y);
			
			x=v.top();v.pop();
			y=e.top();e.pop();
			while(y.id==x.id){
				e.pop();y=e.top();
			}
			z=e.top();
			while(z.id==y.id){
				e.pop();z=e.top();
			}
			//if(x.val<y.val||(x.val==y.val&&x.i))--siz;
			if(!(x.val-y.val>z.val||(x.val-y.val==z.val&&x.id>z.id)))--siz;
		}
		if(siz==3){
			node x=v.top();v.pop();
			edge y=e.top();e.pop();
			edge z=e.top();
			if(x.val-y.val>z.val||(x.val-y.val==z.val&&x.id>z.id))siz=1;
		}
		
		while(v.size())v.pop();
		while(e.size())e.pop();
		printf("%d\n",siz);
	}
	return 0;
}
