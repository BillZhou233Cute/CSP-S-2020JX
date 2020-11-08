#include<bits/stdc++.h>
using namespace std;
#define N 1000007
#define pb push_back
#define LL long long
#define sz(x) (int)x.size()
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair
#define itr set<pii>::iterator
set<pii> S;
int a[N],ddl[N],opt[N],n;
void solve(){
    S.clear();
    for(int i=1;i<=n;i++)
	S.insert(mkp(a[i],i));
    for(int i=1;i<n;i++){
	itr i1=S.begin(),i2=--S.end();
	pii v=*i2;
	ddl[i1->se]=i; v.fi-=i1->fi;
	opt[i]=i2->se;
	S.erase(i1),S.erase(i2);
	S.insert(v);
    }
    ddl[S.begin()->se]=n;
    int now=n-1;
    for(int i=n-1;i>=1;i--){
	int x=opt[i];
	if(ddl[x]<=now)now=i-1;
    }
    printf("%d\n",n-now);
}
int main()
{
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    int Tes;scanf("%d",&Tes);
    Tes--;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
    solve();
    while(Tes--){
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
	    int x,y;
	    scanf("%d%d",&x,&y);
	    a[x]=y;
	}
	solve();
    }
}
    
