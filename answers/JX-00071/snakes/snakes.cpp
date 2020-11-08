#include<bits/stdc++.h>
using namespace std;

int t,n,max,ans,i,j;
int a[3000010],b[3000010];

void dfs(){
	b[j] -= b[i];
	

int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d%d",&t,&n);
	i = 1;j = n;
	for(int i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	memcpy(b,a,sizeof a);
	sort(b + 1,b + n + 1);
	max = b[n];
