#include<cstdio>
int main()
{
	freopen("1.out","w",stdout);
	for(int i=0;i<1721386;i++)
		if((i%4==0&&i%100!=0)||i%400==0)
			printf("366,");
			else
				printf("365.");
	}