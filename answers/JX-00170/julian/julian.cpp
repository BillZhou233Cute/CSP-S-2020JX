#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;
const int som=2299160,now=4713;
int Q,ans[100];
inline int read()
{
    int x=0,minus=0; char ch;
    while (!isdigit(ch=getchar())) minus|=(ch=='-');
    while (isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();  
    return minus?-x:x;
}
void mon(int x)
{
    int res=1;
    if (x>=31&&res==1) res+=1,x-=31;//1
    if (x>=28&&res==2)//2
    {
      	if ((ans[1]<0&&ans[1]%4!=0)||(ans[1]>0&&ans[1]%4!=1)) x-=28,res+=1;
	else if (x>=29) x-=29,res+=1;
    }
    if (x>=31&&res==3) res+=1,x-=31;//3
    if (x>=30&&res==4) res+=1,x-=30;//4
    if (x>=31&&res==5) res+=1,x-=31;//5
    if (x>=30&&res==6) res+=1,x-=30;//6
    if (x>=31&&res==7) res+=1,x-=31;//7
    if (x>=31&&res==8) res+=1,x-=31;//8
    if (x>=30&&res==9) res+=1,x-=30;//9
    if (x>=31&&res==10) res+=1,x-=31;//10
    if (x>=30&&res==11) res+=1,x-=30;//11
    ans[2]=res,ans[3]=x+1;
}
void mon2(int x)
{
    int res=1;
    if (x>=31&&res==1) res+=1,x-=31;//1
    if (x>=28&&res==2)//2
    {
      	if (ans[1]%4!=0) x-=28,res+=1;
	else if (x>=29) x-=29,res+=1;
    }
    if (x>=31&&res==3) res+=1,x-=31;//3
    if (x>=30&&res==4) res+=1,x-=30;//4
    if (x>=31&&res==5) res+=1,x-=31;//5
    if (x>=30&&res==6) res+=1,x-=30;//6
    if (x>=31&&res==7) res+=1,x-=31;//7
    if (x>=31&&res==8) res+=1,x-=31;//8
    if (x>=30&&res==9) res+=1,x-=30;//9
    if (x>=31&&res==10) res+=1,x-=31;//10
    if (x>=30&&res==11) res+=1,x-=30;//11
    ans[2]=res,ans[3]=x+1;
}
void work1(int x)
{
    int num=x/366,siz=x%366;
    siz+=num*3/4;
    ans[1]=now-num;
    while (siz>=366||(siz==365&&ans[1]%4!=1))
    {
        ans[1]-=1;
  	if (ans[1]%4!=0) siz-=365;
	else siz-=366;
    }    
    if (ans[1]<=0) ans[1]-=1;
    mon(siz);
    printf("%d %d ",ans[3],ans[2]);
    if (ans[1]<0) printf("%d\n",-ans[1]);
    else printf("%d BC\n",ans[1]);
}
void work2(int x)
{
    x-=som;
    if (x<=77) 
    {
	if (x<17)
	{
	    printf("%d 10 1582\n",14+x);
	    return ;
	}
	if (x<47)
	{
	    printf("%d 11 1582\n",x-16);
	    return ;
	}
	printf("%d 12 1582\n",x-46);
	return ;
    }
    x-=77;
    int num=x/366,siz=x%366;
    siz+=num/400*303+(num%4);
    if (num>117) siz+=(num/100%4)-1;
    ans[1]=1583+num;
    while (siz>=366||(siz==365&&(ans[1]%4!=0||(ans[1]%100==0&&ans[1]%400!=0))))
    {
  	if (ans[1]%4!=0||(ans[1]%100==0&&ans[1]%400!=0)) siz-=365;
	else siz-=366;       
        ans[1]+=1;
    }
    mon2(siz);
    printf("%d %d %d\n",ans[3],ans[2],ans[1]);
}
signed main()
{
    freopen("julian.in","r",stdin);
    freopen("julian.out","w",stdout);
    Q=read();
    while (Q--)
    {	
	int dat=read();
	if (dat<=som) work1(dat);//4 10 1582
	else work2(dat);//15 10 1582
    }
    return 0;
}

