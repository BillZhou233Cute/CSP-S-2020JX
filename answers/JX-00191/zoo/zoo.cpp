#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<vector>
using namespace std;
#define ll long long
const int maxn = 5000;
int f[maxn];
int q[4000][4000];
int  n,m,c,kk,t1,t2;
int  zl;
int ans;
int a[maxn];
bool flag[maxn];
bool tt[maxn];
void ch(int k){
	int cnt=0;
	ll temp=k;
	while(k){
		if(k&1&&f[cnt]){
			q[temp][++q[temp][0]]=f[cnt];
			}
			k>>=1;
			cnt++;
		}
}
void dfs(int k,int x){
	if(k>c-zl){
		return ;
	}
	for(int i=1;i<=c;++i){
		 if(!tt[i]&&i>x){
			 tt[i]=1;
		    	int duojia=0;
		for(int ii=0;ii<pow(2,kk);++ii){
			if(a[ii]) continue;
				bool fla=0;
			for(int j=1;j<=q[i][0];++j){
				if(!tt[q[i][j]]) {fla=1;break;}
				}
				if(!fla) duojia++;
			}
			ans=max(duojia,ans);
			 dfs(k+1,i);
			 if(!flag[i])
			 tt[i]=0;
		}
		}
}
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>kk;
	for(int i=1;i<=n;++i){
	  scanf("%d",&t1);
		a[t1]=1;
		}
	 for(int i=1;i<=m;++i) {
		 scanf("%d",&t1);
		 scanf("%d",&t2);
		 f[t1]=t2;
		 }
	for(int i=0;i<pow(2,kk);++i){
		ch(i);
		if(a[i]) {
			for(int j=1;j<=q[i][0];++j){
				if(!flag[q[i][j]]) {
					flag[q[i][j]]=1;
					zl++;
					}
				}
			}
		}
		for(int i=1;i<=c;++i)  tt[i]=flag[i];
	for(int i=0;i<pow(2,kk);++i){
		    bool fla=0;
		    if(a[i]) continue;
			for(int j=1;j<=q[i][0];++j) if(!flag[q[i][j]]){fla=1;break;}
		    if(fla==0) ans++;
		} 
		dfs(0,0);
		cout<<ans;
		return 0;
	}