#include<iostream>
#include<cstdio>
#include<cstdlib>
int a,b,c,x,y,z;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d%d",&x,&y);
	scanf("%d%d%d",&a,&b,&c);
	if(a>=b&&a>=c&&a>=b+c){printf("1");return 0;}
	if(b>a&&b>=c&&b>=a+c){printf("1");return 0;}
	if(c>a&&c>b&&c>a+b){printf("1");return 0;}
	printf("3");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
