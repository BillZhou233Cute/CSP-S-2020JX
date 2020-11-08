#include<bits/stdc++.h>
using namespace std;
const int MAXN = 21;
int a[MAXN],p[MAXN],q[MAXN],book[MAXN];
int n,m,c,k;

int main(){
  freopen("zoo.in","r",stdin);
  freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;++i){
		scanf("%d%d",&p[i],&q[i]);
	}
	for(int i=1;i<=m;++i){
		int flag=0;
		for(int j=1;j<=n;++j){
			if(a[j]&(1<<p[i])) flag=1;
		}
	    if(flag==0) book[p[i]]=1;
	}
	int sum=0;
    for(int i=1;i<=k;++i){
		if(book[i]==1) sum++;
	}	
	printf("%d",(1<<(k-sum))-n);
	return 0;
}
