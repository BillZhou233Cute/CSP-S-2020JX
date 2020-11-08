#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;
int q,day[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
ll r;
void check(ll t,int flag){
	if(t==0){
		printf("1 1 ");
		return ;
	}
	if(t>=1&&t<=30){
		printf("%lld 1 ",t+1);
		return ;
	}
	t-=30;
	for(int i=2;i<=12;i++){
		if(i==2&&flag==1&&t==29){
			printf("%d %d ",29,2);
			return ;
		}
		if(t>day[i]){
			t-=day[i];
		}
		else{
			printf("%lld %d ",t-1,i);
			return ;
		}
	}
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	while(q--){
		scanf("%lld",&r);
		if(r<1719880){
			int t=r/1461,p=0;
			r%=1461;
			if(r<366){
				check(r,1);
				printf("%d BC\n",t+4713);
			}
			else{
				r-=366;
				r++;
				p=r/365;
				r%=365;
				check(r,0);
				printf("%d BC\n",4713-p-1-t);
			}
		}
		else if(r==1710880){
			printf("%d %d %d\n",1,1,1);
		}
	}
	return 0;
}