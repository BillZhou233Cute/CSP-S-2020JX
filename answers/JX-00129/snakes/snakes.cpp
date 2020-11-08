#include<cstdio>
#include<algorithm>
#define maxn 1000005
#define ri register int
using namespace std;
struct snake{
	int id,pow;
}a[maxn];
inline int read(){
	ri x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
bool cmp( snake x , snake y){ 
	if(x.pow>y.pow) return true;
	else if(x.pow==y.pow&&x.id>y.id) return true; 
}
bool cmp1( snake x , snake y){ 
	if(x.pow>y.pow) return true;
	if(x.pow==y.pow&&x.id>y.id) return true; 
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	ri t=read(),flag=1,n,ans;
	while(t--){
		if(flag){
			n=read(),ans=n;
			for(ri i=1;i<=n;++i)	a[i].pow=read(),a[i].id=i;
			flag=0;
		}
		else{
			ri k=read(),ans=n;
			for(ri i=1;i<=k;++i){
				ri x=read(),y=read();
				for(ri j=1;j<=n;++j) if(a[j].id==x) a[j].pow=y;
			}
		}
		sort(a+1,a+n+1,cmp);
		while(1){
			a[1].pow-=a[n].pow;
			ri t=a[1].id;
			for(ri i=1;i<=n;++i){
				for(ri j=i+1;j<=n;++j){
					if(a[i].pow<a[j].pow) swap(a[i],a[j]);
					else if(a[i].pow==a[j].pow&&a[i].id<a[j].id) swap(a[i],a[j]);
				}
			}
			ans--;
			if(a[n].id==t){
				if(ans==1) ans--;
				if(ans==-1) ans++;
				printf("%d\n",ans+1);
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}