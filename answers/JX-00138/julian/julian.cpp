#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<stack>
long long n,t1,t2=-4713,t3=1,t4=1;
int moth1[13]={0,31,29,31,30,31,30,31,31,30,31,30,31},moth2[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool  l1=0,l2=0;
using namespace std;
bool LL()
{
	if(t2<0) return (-t2-1)%4==0;
	if(t2>0&&t2<=1583)	return t2%4==0;
	if(t2>1583) return t2%4==0&&t2%100!=0;
}
void p()
{
	t4+=t1;
	if(LL())
		{
			if(t4>moth1[t3])
				{t4-=moth1[t3];t3++;}
		}
	else
		{
			if(t4>moth2[t3])
				{t4-=moth2[t3];t3++;}
		}
        	if(t2<0)	cout<<t4<<" "<<t3<<" "<<-t2<<" BC\n";
	if(t2>0)	cout<<t4<<" "<<t3<<" "<<t2<<endl;
}
void YY()
{
	if(t1<31)	{p();t1=-1;return;}
	for(int i=1;i<=10;i++)
	{
		if(t1>=moth2[i]){t1-=moth2[i];}
			else{break;}
	}	
	if(t1<4) {p();t1=-1;return;}
		else{	t1-=1;t4=15;return;}
}	
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++)
	{
		t2=-4713;
		t3=t4=1;
		cin>>t1;
		while((LL()&&t1>=366)||(!LL()&&t1>=365))
		{
			if(LL())	t1-=366;
			else	t1-=365;
			t2++;
			if(t2==0)	break;
		}
		if(t2==0) t2=1;
		while(((LL()&&t1>=366)||(!LL()&&t1>=365))&&t2>0)
		{
			if(LL())	t1-=366;
			else	t1-=365;
			t2++;
			if(t2<=1583)	YY();
		}
		if(t1==-1)break;
		for( t3;t3<=12;t3++)
		{
			if(LL())
			{
			if(t1>=moth1[i]){t1-=moth1[t3];}
			else{break;}
			}
			else
			{
			if(t1>=moth2[i]){t1-=moth2[t3];}
			else{break;}
			}
		}
			p();continue;
	}
	return 0;
}