#include<iostream>
#include<cstdio>
#include<cmath>
#define INF 1200005
using namespace std;
int n,m,c,k;
int ani[INF],rle[INF],sl[INF];
bool vis[INF];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ani[i]);
		vis[ani[i]]=1;
		}
	for(int i=1;i<=m;i++)
		scanf("%d%d",&rle[i],&sl[INF]);
	unsigned long long tp=pow(2,k); 
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<tp;j++)
		{
			int tt=j;
			int cnt=0;
			while(cnt<rle[i])
			{
				cnt++;
				tt/=2;
				}
			if(tt%2==1)
				vis[j]=1;
			}
		}
	unsigned long long ccnt=0;
	for(int i=1;i<=tp;i++)
		ccnt+=vis[i];
	ccnt=ccnt-n;
	printf("%d",ccnt);
	return 0;
}