#include<bits/stdc++.h>
#define R register int
using namespace std;
const int N=1e6+5;
int a[N],p[N],q[N],vm[N],vq[N];
int n,m,k,c;
int read()
{
	int f=1;char ch;
	while((ch=getchar())<'0'||ch>'9') if(ch=='-') f=-1;
	int res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9') res=res*10+ch-'0';
	return res*f;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
void work(int x)
{
	int cnt=0;
	while(x)
	{
		if(x&1)vm[cnt]=0,vq[q[cnt]]=1;//第cnt个位置有不需要加钱
		x>>=1;cnt++;
	}
}
bool check(int x)
{
	int cnt=0;
	while(x)
	{
		if(x&1)
		{
			//if()
			//第cnt位置为1,但该位置的q[cnt]已经选过，仍然true
			if(vm[cnt]&&(!vq[q[cnt]])) return false;
		}
		x>>=1;cnt++;
	}
	return true;
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read();m=read();c=read();k=read();
	for(R i=1;i<=n;i++) a[i]=read();//b[a[i]]=1;
	for(R i=1;i<=m;i++)
	{
		p[i]=read();q[p[i]]=read();
		vm[p[i]]=1;//p[i]个位置为1就需要加钱
	}
	for(R i=1;i<=n;i++) work(a[i]);
	long long ma=1,num=0;
	for(R i=1;i<=k;i++) ma*=2;
	for(R i=0;i<ma;i++)
	{
		if(check(i)) num++;
	}
	printf("%lld",num-n);
	fclose(stdin);fclose(stdout);
}