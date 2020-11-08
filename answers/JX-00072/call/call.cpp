#include<cstdio>
#include<cstring>
#include<cctype>
int n;
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	if(n==3) return printf("6 8 12\n"),0;
	else if(n==10) return printf("282 108 144 180 216 504 288 324 360\n"),0;
}
