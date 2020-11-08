#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long x = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){if(c == '-') f = -1;c = getchar();}
	while(c >= '0' && c <= '9'){x = x * 10+ c - '0',c = getchar();}
	return x * f;
}
long long n,m,c,k,p,q,s,w,ans,a[105];
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
    n = read();m = read(),c = read(),k =read();
	c = (1 << c) - 1;
	for(int i = 1;i <= n;i++){
		a[i] = read();s = s | a[i];
	}
	for(int i = 1;i <= m;i++){
		p = read(),q = read();
		long long e = 1 << p;
		if(!(s & e)) w = w | e;
	}
	w = w & c;
	for(int i = 0;i < (1 << k);i++){
		if(!(i & w)) ans++;
	}
	printf("%d",ans - n);
	return 0;
}
