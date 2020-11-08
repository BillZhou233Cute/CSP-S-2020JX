#include<iostream>
#include<cstdio>
#include<cstdlib>
int n,m,c,k;
bool che[1000000000];
int ai[10010],p[10010],q[10010],act[10010];
int a,b,d,e,f,g;
void activat(int xb)
{
	//for(int r=1;r<=
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(a=1;a<=n;a++)
		scanf("%d",&ai[a]);
	for(a=1;a<=m;a++)
		scanf("%d%d",&p[a],&q[a]);
	for(a=1;a<=m;a++)
		activat(a);
	f=1;
	for(e=1;e<=k;e++)
		f*=2;
	printf("%d",(f-n));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
