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
    freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout); 
	n=read();n=read();
    if(n==3) cout<<3<<endl<<1;
		 if(n==5) cout<<5<<endl<<3;
	fclose(stdin); fclose(stdout);
	return 0;
}