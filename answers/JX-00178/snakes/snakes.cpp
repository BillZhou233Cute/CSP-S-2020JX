#include<bits/stdc++.h>
using namespace std;
int t,n,k;

struct s{
	int len;
	int num;
}a[4];

bool tmp(s a,s b){
    return a.len<b.len;
}	

int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i].len);
			a[i].num=i;
		}
		sort(a+1,a+1+n,tmp);
		if((a[3].len-a[1].len>a[2].len)||((a[3].len-a[1].len==a[2].len)&&(a[3].num<a[2].num))) printf("1");
		else printf("3");
	}		
	return 0;
}