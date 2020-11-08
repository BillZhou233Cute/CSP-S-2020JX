#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,c,k;
long long a[1000009],p[1000009],q[1000009],sl,request,now;
int main()
{int i,j;
freopen("zoo.in","r",stdin);
 freopen("zoo.out","w",stdout);
 scanf("%d%d%d%d",&n,&m,&c,&k);
 for(i=1;i<=n;i++) scanf("%lld",&a[i]);
 for(i=1;i<=m;i++)
	   {scanf("%lld%lld",&p[i],&q[i]);
		 request=request|(1<<p[i]);
	   }
 //cout<<request<<endl;
 for(i=1;i<=n;i++)
	  now=now|(request&a[i]);
 //cout<<now<<endl;
 long long ans=pow(2,k);
 long long  minus=0;
 for(i=0;i<=k;i++)
   if((((now>>i)&1)==0)&&(((request>>i)&1)==1))  minus++;
 //cout<<minus<<endl;
 //now=(now>>2)&1;cout<<now<<endl;
  minus=(k-minus)*2*minus+n;
 cout<<ans-minus;
 return 0;
}
