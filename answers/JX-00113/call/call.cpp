#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pre(i,a,b) for(int i=a;i>=b;i--)
#define N 1000005
#define P 998244353
#define int long long 
using namespace std;
int n,a[N],m,sum,c[N],op[N],p[N],v[N],hav1,hav2;
vector<int>e[N];
namespace task3{
	int mul=1;
	int Pow(int x,int y){
		int now=1;
		for(;y;y>>=1,x=x*x%P)if(y&1)now=now*x%P;	
		return now;
	}
	void calc(int x){
		//cout<<x<<endl;
		if(op[x]==1)a[p[x]]+=v[x]*Pow(mul,P-2)%P;
		else if(op[x]==2)mul*=v[x],mul%=P;
		else{
			for(int i=0;i<(int)e[x].size();i++)calc(e[x][i]);
		}
	}
	void main(){
		int q;scanf("%lld",&q);
		rep(i,1,q){
			int x;scanf("%lld",&x);
			calc(x);
		}
		rep(i,1,n)printf("%lld ",a[i]%P*mul%P);
		putchar('\n');
	}
}
namespace task1{
	int f[N];
	int calc(int x){	
		if(~f[x])return f[x];
		if(op[x]==2)f[x]=v[x];
		else {
			f[x]=1;
			for(int i=0;i<(int)e[x].size();i++)f[x]=f[x]*calc(e[x][i])%P;
		}
		return f[x];
	}
	void main(){
		memset(f,~0,sizeof(f));
		int q;scanf("%lld",&q);
		int mul=1;
		rep(i,1,q){
			int x;scanf("%lld",&x);
			mul*=calc(x);mul%=P;
		}
		rep(i,1,n)printf("%lld ",a[i]*mul%P);
		putchar('\n');
	}
}
namespace task2{
	int w[N],in[N];
	queue<int>qu;
	void main(){
		//cout<<"ss"<<endl;
		int q;scanf("%lld",&q);
		rep(i,1,q){
			int x;scanf("%lld",&x);
			w[x]++;
		}
		rep(x,1,m){
			for(int i=0;i<(int)e[x].size();i++)in[e[x][i]]++;
		}
		rep(i,1,m)if(!in[i])qu.push(i);
		while(!qu.empty()){	
			int x=qu.front();qu.pop();
			//cout<<"ss "<<x<<endl;
			for(int i=0;i<(int)e[x].size();i++){
				w[e[x][i]]+=w[x];in[e[x][i]]--;w[e[x][i]]%=P;
				if(!in[e[x][i]])qu.push(e[x][i]);
			}
		}
		rep(i,1,m)if(op[i]==1){
			a[p[i]]+=w[i]*v[i]%P;
		}
		rep(i,1,n)printf("%lld ",a[i]);putchar('\n');
	}
}
signed main(){
	//freopen("INPUT","r",stdin);
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%lld",&n);
	rep(i,1,n)scanf("%lld",&a[i]);
	scanf("%lld",&m);
	rep(i,1,m){
		scanf("%lld",&op[i]);
		if(op[i]==1)scanf("%lld%lld",&p[i],&v[i]),hav1=1;
		else if(op[i]==2)scanf("%lld",&v[i]),hav2=1;
		else {
			scanf("%lld",&c[i]);sum+=c[i];
			rep(j,1,c[i]){
				int x;scanf("%lld",&x);
				e[i].push_back(x);
			}
		}
	}
	if(!hav1)task1::main();
	else if(!hav2)task2::main();
	else task3::main();
	return 0;
}
/*
g++ call.cpp -o now -Wall
*/
