#include<bits/stdc++.h>
#define IL inline
#define LL long long
using namespace std;
const int N=3e6+3;
int n,m,a[N],las[N];
struct hh{
	int id,val;
	bool operator<(const hh &a)const{
		return val^a.val?val<a.val:id<a.id;}
	};
set<hh>st;
set<hh>::iterator it1,it2;
IL int in(){
	char c;int f=1;
	while((c=getchar())<'0'||c>'9')
		if(c=='-') f=-1;
	int x=c-'0';
	while((c=getchar())>='0'&&c<='9')
		x=x*10+c-'0';
	return x*f;
	}
void solve(){
	st.clear();memset(las,0,sizeof(las));int ans=n;
	for(int i=1;i<=n;++i) st.insert((hh){i,a[i]});
	int i;
	for(i=1;i<n;++i){
		it2=st.begin(),it1=st.end(),--it1;
		int id1=it1->id,id2=it2->id,v1=it1->val,v2=it2->val;
		if(las[id2]){ans=las[id2];break;}
		las[id1]=i;
		st.erase(it1),st.erase(st.begin());
		st.insert((hh){id1,v1-v2});
		}
	printf("%d\n",n-ans+1);
	}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t=in()-1,x,y;
	n=in();
	for(int i=1;i<=n;++i) a[i]=in();
	solve();
	while(t--){
		m=in();
		while(m--) x=in(),y=in(),a[x]=y;
		solve();
		}
	return 0;
	}