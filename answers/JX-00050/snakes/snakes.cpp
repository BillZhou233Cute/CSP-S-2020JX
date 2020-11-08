#include<bits/stdc++.h>
#define R register int
using namespace std;
const int N=1e6+5;
int n,a[N];
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
struct node{
	int num,pos;
	bool operator <(const node &b) const
	{
		if(num!=b.num) return num<b.num;
		return pos>b.pos;
	}
}b[N];
int work()
{
	for(R i=1;i<=n;i++) b[i].num=a[i],b[i].pos=i;
	int cnt=n;
	while(cnt!=1)
	{
		if(cnt!=2&&b[cnt].num-b[1].num<b[2].num||(b[cnt].pos<b[2].pos&&b[cnt].num-b[1].num==b[2].num))
			break;
		else 
		{
			int tmp=b[1].num;
			for(R i=1;i<=cnt-2;i++) b[i].num=b[i+1].num;
			b[cnt-1].num=b[cnt].num-tmp;
			cnt--;
			sort(b+1,b+cnt+1);
		}
	}
	return cnt;
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t=read();
	n=read();
	for(R i=1;i<=n;i++) a[i]=read();//,a[i].pos=i;
	write(work());putchar('\n');
	for(R o=2;o<=t;o++)
	{
		int k=read();
		for(R i=1;i<=k;i++)
		{
			int x=read(),y=read();
			a[x]=y;
		}
		write(work());putchar('\n');
	}
	fclose(stdin);fclose(stdout);
}