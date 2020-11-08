#include<iostream>
#include<cstdio>
#include<cstdlib>
int n,a[10010],x;
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(x=1;x<=n;x++)
		scanf("%d",&a[x]);
	for(x=1;x<=n;x++)
		printf("%d ",(a[x]+1));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
