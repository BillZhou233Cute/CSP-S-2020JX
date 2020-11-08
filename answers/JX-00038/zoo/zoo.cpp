#include<iostream>
#include<cstdio>
using namespace std;
int o[10000010];
int p[10000010];
int main(){
freopen("power.in","r",stdin);
freopen("power.out","w",stdout);
	long long y,k,b,h,m,g;
	cin>>y;
	if(y%2!=0){
		cout<<"-1";
		return 0;
		}
	
	else if(y%2==0)
	{
		k=2;
		o[k]=2;
		b=2;
		p[b]=2;
		h=b+k;
		if(h!=y){
			k=k+2;
			}
			if(k=y-2){
				k=2;
				b=b+2;
				}
				if(h==y){
					if(k>b){
						m=k;
						g=b;
						}
						else{
							m=b;
							g=k;
							}
					}
					
	}
	cout<<m<<g;
	return 0;
}
