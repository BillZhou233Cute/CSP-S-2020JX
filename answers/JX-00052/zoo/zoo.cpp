#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define pb push_back
#define sz(x) (int)x.size()
const int N=1e6+7;
const int M=1e8+7;
const int K=107;
int p[N],q[N];
ull a[N];
bool use[M],can[K];
int main()
{
    freopen("zoo.in","r",stdin);
    freopen("zoo.out","w",stdout);
    int n,m,c,k;
    scanf("%d%d%d%d",&n,&m,&c,&k);
    for(int i=1;i<=n;i++)
	scanf("%llu",&a[i]);
    for(int i=1;i<=m;i++)
	scanf("%d%d",&p[i],&q[i]);
    ull sum=0;
    for(int i=1;i<=n;i++)
	sum|=a[i];
    for(int i=1;i<=m;i++){
	if((sum>>p[i])&1)
	    use[q[i]]=1;
    }
    memset(can,1,sizeof(can));
    for(int i=1;i<=m;i++)
	if(!use[q[i]])
	    can[p[i]]=0;
    int cnt=0;
    for(int i=0;i<=k-1;i++)
	if(can[i])cnt++;
    if(cnt==64){
	if(n==0){
	    puts("18446744073709551616");
	}
	else{
	    ull ans=0ull-(ull)n;
	    printf("%llu\n",ans);
	}
    }
    else{
	ull ans=(1ull<<cnt)-n;
	printf("%llu\n",ans);
    }
    return 0;
}
    
