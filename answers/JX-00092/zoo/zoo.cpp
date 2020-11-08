#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;
long long n,m,c,k,a[1021202],b[121321],c[455513],ans,tot;
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n>>m>>c>>k;
	ans=(2,k);
	for(int i=1;i<=n;i++)
		 cin>>a[i];
	for(int i=1;i<=m;i++){
		  cin>>b[i]>>c[i];
		tot+=c[i];
	}
	cout<<ans-2;
	
return 0;
}
