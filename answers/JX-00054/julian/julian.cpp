//1 1 4473 BC
#include<bits/stdc++.h>
using namespace std;
long long q,r;
const int gre[13]={31,28,31,30,31,30,31,31,30,31,30,31},gre1[13]={31,29,31,30,31,30,31,31,30,31,30,31};
int d,m,y,bc;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%lld",&q);
	for(int i=1;i<=q;i++){
		d=1,m=1,y=4473,bc=1;
		scanf("%lld",&r);
		int yn=4*r/1460;
		cout<<yn<<endl;
	}
	return 0;
}

