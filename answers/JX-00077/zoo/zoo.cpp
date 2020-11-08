#include <cstdio>
#include <cmath>
using namespace std;
bool b[1000000];int p[100],q[100];bool qp[100];int u[1000000];
void t(int n){
	if(n==0)
	return ;
	int p=0;
	while(pow(2,p)<=n)p++;p--;
	b[p]=1;
	t(n-pow(2,p));
}
int t_(int n,int h)
{
	if(n==0)
	return h;
	int p=0;
	while(pow(2,p)<=n)p++;p--;
	h++;
	u[h]=p;
	n-=pow(2,p);
	return t_(n,h);
}
int main()
{
  freopen("zoo.in","r",stdin);
  freopen("zoo.out","w",stdout);
	int n,m,c,k;
	scanf("%d%d%d%d",&n,&m,&c,&k);
	long long a=pow(2,k);
	int mm;
	for(int i=1;i<=n;i++){
		scanf("%d",&mm);
		t(mm);
	}
	for(int i=1;i<=m;i++)
	scanf("%d%d",&q[i],&p[i]);
	for(int i=1;i<=m;i++){
		if(!qp[i]&&b[q[i]]){
			qp[i]=1;
			b[p[i]]=1;
			i=1;
		}
	}
	int h;
	long long ans=0;
	for(int i=1;i<=a;i++){
		h=t_(i,0);
		bool p=1;
		for(int j=1;j<=h;j++){
			if(!b[u[j]]){
			        p=0;
				break;
			}
		}
		if(p)ans++;
	}
	printf("%lld",ans-n);
	return 0;
}
