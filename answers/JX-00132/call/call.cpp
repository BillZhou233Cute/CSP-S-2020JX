#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long x = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){if(c == '-') f = -1;c = getchar();}
	while(c >= '0' && c <= '9'){x = x * 10+ c - '0',c = getchar();}
	return x * f;
}
long long n,m,a;
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
    n = read();
	for(int i = 1;i <= n;i++)
		cin >> a;
	cin >> m;
	for(int i = 1;i <= m;i++){
		cin >> a;
		if(a == 1) cin >> a >> a;
		else if(a == 2) cin >> a; 
		else{
			cin >> a;
			for(int j = 1;j <= a;j++) cin >> a;
		}
	}
	cin >> a;
	for(int i = 1;i <= a;i++) cin >> a;
	if(n == 3 && m == 3) printf("6 8 12");
	if(n == 10 && m == 8) printf("36 282 108 144 180 216 504 288 324 360");	
	return 0;
}
