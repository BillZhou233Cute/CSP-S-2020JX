#include<cstdio>
using namespace std;
int dir[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int q;
int r(int n,int d)
{
	if(0==d&&1==n%4)
		return true;
	if(1==d&&0==n%4)
		return true;
	if(2==d&&((0==n%4&&0!=n%100)||(0==n%400&&400<=n)))
		return true;
	return false;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int julian;
		scanf("%d",&julian);
		if(julian<=1721424)
		{
			int y=4713;
			while(true)
			{
				if(julian<=366)
					if(r(y,0))
					{
						dir[3]++;
						for(int i=1;i<=12;i++)
							if(julian<=dir[i])
							{
								//if(1==i||(2==i&&julian<=28))
									//printf("%d %d %d BC\n",julian+1,i,y);
								//else
									printf("%d %d %d BC\n",julian+1,i,y);
								dir[3]--;
								break;
							}
							else
								julian-=dir[i];
						break;
					}
					else
					{
						//printf("dfdfdfdf\n");
						if(366==julian)
						{
							printf("1 1 %d BC\n",y-1);
							break;
						}
						for(int i=1;i<=12;i++)
							if(julian<=dir[i])
							{
								printf("%d %d %d BC\n",julian+1,i,y);
								break;
							}
							else
								julian-=dir[i];
						break;		
					}
				else
				{	
					if(r(y,0))
						julian-=1;
					y--;
					julian-=365;
				}
			}
		}
		if(1721424<julian&&julian<=2299526)
		{
			julian-=1721424;
			int y=1;
			while(true)
			{
				if(julian<=366)
					if(r(y,1))
					{
						dir[3]++;
						for(int i=1;i<=12;i++)
							if(julian<=dir[i])
							{
								//if(1==i||(2==i&&julian<=28))
									//printf("%d %d %d BC\n",julian+1,i,y);
								//else
									printf("%d %d %d\n",julian+1,i,y);
								dir[3]--;
								break;
							}
							else
								julian-=dir[i];
						break;
					}
					else
					{
						//printf("dfdfdfdf\n");
						if(366==julian)
						{
							printf("1 1 %d \n",y+1);
							break;
						}
						for(int i=1;i<=12;i++)
							if(julian<=dir[i])
							{
								printf("%d %d %d \n",julian+1,i,y);
								break;
							}
							else
								julian-=dir[i];
						break;		
					}
				else
				{	
					if(r(y,1))
						julian-=1;
					y++;
					julian-=365;
				}
			}
		}
		if(2299526<julian)
		{
			julian-=2299526;
			if(julian<=17)
			{	
				printf("%d %d %d\n",14+julian,10,1582);
				break;
			}
			if(julian>=18&&julian<=47)
			{
				printf("%d %d %d\n",julian-17,11,1582);
				break;
			}
			if(julian>=48&&julian<=78)
			{
				printf("%d %d %d\n",julian-47,12,1582);
				break;
			}
			if(julian>=79)
			{
				julian-=78;
				int y=1583;
				while(true)
				{
					if(julian<=366)
						if(r(y,2))
						{
							dir[3]++;
							for(int i=1;i<=12;i++)
								if(julian<=dir[i])
								{
									printf("%d %d %d\n",julian+1,i,y+1);
									dir[3]--;
									break;
								}
								else
									julian-=dir[i];
							break;
						}
						else
						{
							if(366==julian)
							{
								printf("1 1 %d \n",y+2);
								break;
							}
							for(int i=1;i<=12;i++) 
								if(julian<=dir[i])
								{
									printf("%d %d %d \n",julian+1,i,y+1);
									break;
								}
								else
									julian-=dir[i];
							break;		
						}
					else
					{	
						if(r(y,2))
							julian-=1;
						y++;
						julian-=365;
					}
				}
			}
		}
	}
	//4713 1 1     1721424
	//1582 10 4  578102
	//2299526
	return 0;
}