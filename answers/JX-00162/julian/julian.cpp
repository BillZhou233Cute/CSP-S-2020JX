#include<iostream>
#include<cstdio>
#include<cstdlib>
int que,q[100010],a,b,c,d,e,f,g;
int year[100010],month[100010],daily[100010],rps[2]={365,366};
bool gyq[100010];//公元前检查 true公元前，false公元后
int mon[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
int monl[13]={0,31,60,91,121,152,182,213,244,274,305,335,366};
int yet,yett,usd,rp;
void fin()
{
	for(c=1;c<=que;c++)
	{
		yet=0;yett=0;usd=0;//年份已有，年份剩余，月份    暂存
		if(q[c]<=1721423)
		{
			gyq[c]=true;
			yet=q[c]/1461;
			yet*=4;
			yett=q[c]%1461;
			if(yett>=366){yett-=366;yet++;}
			if(yett>=365){yett-=365;yet++;}
			if(yett>=365){yett-=365;yet++;}
			if(yett>=365){yett-=365;yet++;}
			if(yet%4==0)
				for(d=1;d<=12;d++)
				{
					if(yett<monl[d]){month[c]=d;yett-=monl[d-1];break;}
				}
			if(yet%4!=0)
				for(d=1;d<=12;d++)
				{
					if(yett<mon[d]){month[c]=d;yett-=mon[d-1];break;}
				}
			daily[c]=yett+1;
			year[c]=4713-yet;
		}
		
		
		if(q[c]>=1721424)
		{
			q[c]-=1721423;
			if(q[c]<577826)
			{
				gyq[c]=false;
				yet=q[c]/1461;
				yet*=4;
				yett=q[c]%1461;
				if(yett>=365){yett-=365;yet++;}
				if(yett>=365){yett-=365;yet++;}
				if(yett>=365){yett-=365;yet++;}
				if(yett>=366){yett-=366;yet++;}
				if(yet%4==0)
				for(d=1;d<=12;d++)
				{
					if(yett<monl[d]){month[c]=d;yett-=monl[d-1];break;}
				}
			if(yet%4!=0)
				for(d=1;d<=12;d++)
				{
					if(yett<mon[d]){month[c]=d;yett-=mon[d-1];break;}
				}
			daily[c]=yett;
			year[c]=yet+1;
			}
			if(q[c]>=577826)
			{
				gyq[c]=false;
				year[c]=1582;
				q[c]-=577826;
				q[c]+=288;
				usd=q[c];
				while(1)
				{
					if(usd<365&&rp==0)break;
					if(usd<366&&rp==1)break;
					rp=0;
					if((yet)%4==0&&((yet)%100!=0))rp++;
					if((yet)%400==0)rp++;
					usd-=rps[rp];
					yet++;
				}
				yet--;
				yett=usd;
				if(yet%4==0&&yet%100!=0)
				for(d=1;d<=12;d++)
				{
					if(yett<monl[d]){month[c]=d;yett-=monl[d-1];break;}
				}
				if(yet%400==0)
				for(d=1;d<=12;d++)
				{
					if(yett<monl[d]){month[c]=d;yett-=monl[d-1];break;}
				}
				if(yet%4!=0||(yet%100==0&&yet%400!=0))
				for(d=1;d<=12;d++)
				{
					if(yett<mon[d]){month[c]=d;yett-=mon[d-1];break;}
				}
			daily[c]=yett;
			year[c]+=(yet+1);
			}
		}
	}
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&que);
	for(a=1;a<=que;a++)
		scanf("%d",&q[a]);
	fin();
	for(b=1;b<=que;b++)
	{
		printf("%d %d %d",daily[b],month[b],year[b]);
		if(gyq[b]==true)printf(" BC");
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
