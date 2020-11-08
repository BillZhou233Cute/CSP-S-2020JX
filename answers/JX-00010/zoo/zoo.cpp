#include<bits/stdc++.h>
#define MAXN 1000010
#define ull unsigned long long
using namespace std;
inline ull read(){
	char c=getchar();ull x=0;
	while(!isdigit(c)){c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x;
}
map<ull,bool>vis;
int n,m,c,k;
vector<int>v[70];
unsigned long long s,sum,d[MAXN],ans;
bool check(ull x){
	ull tep=sum,cnt=0;
	while(tep>0||x>0){
		if(v[cnt].size()>0&&tep%2==0&&x%2==1)return 0;
		tep/=2;x/=2;cnt++;
	}
	return 1;
}
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read();m=read();c=read();k=read();
	for(int i=1;i<=n;i++){
		d[i]=read();s|=d[i];vis[i]=1;
	}
	for(int i=1;i<=m;i++){
		int x=read();
		if((1<<x)&s)sum|=(1<<x);
		v[x].push_back(read());
	}
	for(ull i=(1<<k)-1;i>=0;i--)
		if(!vis[i]&&check(i))ans++;
	cout<<ans;
	return 0;
}
