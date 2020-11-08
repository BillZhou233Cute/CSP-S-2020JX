#include<cstdio>
#define ri register int 
#define ll long long
#define maxn 400005
using namespace std;
int a[maxn];
int t[maxn];
int p[maxn],v[maxn];
int flag[maxn];
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
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	ri n=read(),sumc=0;
	for(ri i=1;i<=n;++i) a[i]=read();
	ri m=read();
	for(ri i=1;i<=m;++i)
	{
		t[i]=read();
		if(t[i]==1) p[i]=read(),v[i]=read(),flag[i]=1;
		if(t[i]==2) v[i]=read(),flag[i]=2;
		if(t[i]==3)
		{
			ri c=read();
			sumc+=c;
			flag[i]=1;
			for(ri j=1;j<=c;++i)
			{
				ri g=read();
				if(flag[g]==1) a[p[g]]=v[g];
				if(flag[g]==2) for(ri k=1;k<=n;++k) a[k]*=v[i];
			}
		}
	}
	for(ri i=1;i<=n;++i) printf("%d ",a[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}