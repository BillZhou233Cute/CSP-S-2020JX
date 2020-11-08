#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int y[100001],m[100001],d[100001];
int jfour(int l,int r)
{
	return 1+(r-r%4-l+l%4-4)/4;
}
int four(int l,int r){
	int sum=0;
	sum+=1+(r-r%4-l+l%4-4)/4;
	l+=100-l%100;
	r-=r%100;
	sum-=1+(r-l)/100;
	l/=100;
	r/=100;
	sum+=1+(r-r%4-l+l%4-4)/4;
	return sum;	
}
void m_d(int a,int i,bool j,int y)
{
	int F_d=28;
	if((j&&y%4==0)||(!j&&(y%400==0||(y%4==0&&y%100!=0))))
	F_d=29;
	if(a<=31){
		m[i]=1;
		d[i]=a;
		return ;
	}
	a-=31;
	if(a<=F_d){
		m[i]=2;
		d[i]=a;
		return ;
	}
	a-=F_d;
	if(a<=31){
		m[i]=3;
		d[i]=a;
		return ;
	}
	a-=31;
	if(a<=30){
		m[i]=4;
		d[i]=a;
		return ;
	}
	a-=30;
	if(a<=31){
		m[i]=5;
		d[i]=a;
		return ;
	}
	a-=31;
	if(a<=30){
		m[i]=6;
		d[i]=a;
		return ;
	}
	a-=30;
	if(a<=31){
		m[i]=7;
		d[i]=a;
		return ;
	}
	a-=31;
	if(a<=31){
		m[i]=8;
		d[i]=a;
		return ;
	}
	a-=31;
	if(a<=30){
		m[i]=9;
		d[i]=a;
		return ;
	}
	a-=30;
	if(a<=31){
		m[i]=10;
		d[i]=a;
		return ;
	}
	a-=31;
	if(a<=30){
		m[i]=11;
		d[i]=a;
		return ;
	}
	a-=30;
	if(a<=31){
		m[i]=12;
		d[i]=a;
		return ;
	}
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int n,a;
	bool ans[100001]={};
	scanf("%d",&n);
	for(int o=1;o<=n;o++){
		scanf("%d",&a);
		a++;
		if(a<1721818){
			ans[o]=1;
			y[o]=a/365-4712;
			while(jfour(-4712,y[o])+365*(y[o]+4713)<=a)
			y[o]++;
			a-=jfour(-4712,y[o]-1)+365*(y[o]+4712);
			m_d(a,o,1,y[o]);
		}
	}
	for(int i=1;i<=n;i++){
		if(ans[i])
		printf("%d %d %d BC\n",d[i],m[i],1-y[i]);
	}
	return 0;
}
