#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
const int maxx=1e5;
using namespace std;
int y,m,d,que,mod;
int day[13];
void move(int que,int jud)
{
	int j=1;
	while(que>day[j])
	{
		que=que-day[j];
		if((jud!=0)&&(j==2))
		{que--;cout<<"^><^\n";}
		j++;m++;
		cout<<que<<"que@@@@\n";
	}
	d+=que;
	que=0;
}
int main()
{
	int num,n,ans[maxx][4],i;
	bool jud;//0--BC;1--AD
	day[1]=31;day[2]=28;day[3]=31;day[4]=30;day[5]=31;
	day[6]=30;day[7]=31;day[8]=31;day[9]=30;day[10]=31;
	day[11]=30;day[12]=31;
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		y=4713;m=1;d=1;jud=0;
		scanf("%d",&que);
		while(que!=0)
		{
			if(que>=1461)
			{
				que-=1461;
				if(jud)y+=4;
				else if(y<4){y-=5;y=-y;jud=1;}
				else y-=4;
			}
			else if(que<366)
			     {
					 if(jud)
					 {
						 if(((y%4==0)&&(y&100!=0))||(y%400==0))
			  		         {move(que,1);break;}
						 else {move(que,0);break;}
				     }
					 else 
					 {
						 if((y-1)%4==0&&(y-1)%100!=0)
			  		         {move(que,1);break;}
						 else if((y-1)%400==0) {move(que,1);break;}
						 else {move(que,0);break;}
				     }
				 }
			else if(que>=366&&que<1461)
			     {
					 que-=366;
					 if(jud)
					 {
						 y++;
				     }
					 else 
					 {
						 if(y!=1)y--;
				     }
					 int change=que/365;
					 mod=que%365;
					 if(jud)
					 {
						 move(mod,0);
				         y+=change;
						 break;
				     }
					 else 
					 {
						 move(mod,0);
				         if(jud) y+=change;
				         else if(y<change){y-=change-1;jud=1;}
				         else y-=change;
						 break;
			    	 }
					 
				  }
		}
		ans[i][0]=d;ans[i][1]=m;ans[i][2]=y;ans[i][3]=jud;
	}
	for(i=0;i<num;i++)
	{
		if(ans[i][3])printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
		else printf("%d %d %d BC\n",ans[i][0],ans[i][1],ans[i][2]);
	}
	return 0;
}
