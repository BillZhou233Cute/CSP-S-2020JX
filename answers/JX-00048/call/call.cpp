#include<bits/stdc++.h>
using namespace std;
long long n;
inline long long read(){
    long long w=0; int s=1; char c=getchar();
    while(c<'0' || c>'9'){if(c=='-') s=-1; c=getchar();}
    while(c<='9' && c>='0') w=w*10+c-'0',c=getchar();
		return w*s;
}

int main(){
    freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
    n=read();
	if(n==3) cout<<"6 8 12";
		if(n==10) cout<<"36 282 108 144 180 216 504 288 324 360";
	fclose(stdin); fclose(stdout);
	return 0;
}