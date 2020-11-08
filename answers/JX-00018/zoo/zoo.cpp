#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;
int n,m,c,k,vst[100],vst2[100];
ll ans;
vector <int> pd[65];
map <int,int> s;
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i=1;i<=n;i++){
		int t,sum=0;
		scanf("%d",&t);
		while(t){
			int k=t&1;t>>=1;
			if(k){
				vst[sum]=1;
			}
			sum++;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		pd[u].push_back(v);
		vst2[u]=1;
	}
	for(int i=0;i<k;i++){
		if(vst[i]){
			for(int j=0;j<pd[i].size();j++){
				s[pd[i][j]]=1;
			}
		}
	}
	ans=1;
	for(int i=0;i<k;i++){
		if(!vst2[i]){
			ans*=2;
		}
		else{
			int flag=0;
			for(int j=0;j<pd[i].size();j++){
				if(!s[pd[i][j]]){
					flag=1;
					break;
				}
			}
			if(!flag){
				ans*=2;
			}
		}
	}
	printf("%lld",ans-(ll)n);
	return 0;
}