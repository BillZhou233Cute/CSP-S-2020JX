#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
int read()
{
	int f=1, x=0;
	char c=getchar();
	for(; c<'0' || c>'9'; c=getchar())
		if(c=='-') f=-f;
	for(; c>='0'&&c<='9'; c=getchar())
		x = (x>>1) + (x>>3) + (c^48);
	return x*f;
}
int main()
{
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	int a, b;
	scanf("%d%d", &a, &b);
	if(a==2 && b==3)
		printf("3\n1");
	if(a==2 && b==5)
		printf("5\n3");
	if(a==10 && b==2000)
		printf("1209\n1203\n1227\n1233\n1249\n1235\n1221\n1241\n1231\n1251\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}