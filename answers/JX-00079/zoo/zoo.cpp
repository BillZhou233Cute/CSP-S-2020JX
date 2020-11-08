#include<cstdio>
#include<iostream>
#define ri register int 
#define ll long long
#define maxn 400005
#define inf 0x7fffffff
using namespace std;
int a[maxn];
inline int read(){
	ri x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}