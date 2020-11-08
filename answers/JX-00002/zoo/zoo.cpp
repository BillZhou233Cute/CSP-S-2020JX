#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,c,k;
inline int read(){
	int ans=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(!isdigit(ch)){ans=(ans<<3)+(ans<<1)+ch-48;ch=getchar();}
	return ans*f;
}
int main(){
	n=read(),m=read(),c=read(),k=read();
	
