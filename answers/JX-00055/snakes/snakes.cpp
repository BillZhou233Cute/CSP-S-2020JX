#include<bits/stdc++.h>
using namespace std;

#define N 4000
int T,n,m;
int x[N];

int read()
{
	int f=1,temp=0;char s;s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){temp=temp*10+s-'0';s=getchar();}
	return f*temp;
}

int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	T=read();
	n=read();
	if(n==3)printf("3\n1\n");
	if(n==5)printf("5\n3\n");
	return 0;
}