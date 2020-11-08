#include<bits/stdc++.h>
using namespace std;
long long Q,n;
const int BC=1721424;//qian
const int BA=2299161;//1582qian
const int T1=146097;//T400
int m1[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int m2[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
void work1()
{
	int cc=4713,mo=0;
	while(n>366) {
		if(cc%4==1) n-=366;
		else n-=365;
		cc--;
	}
	if(cc%4!=1&&n==366) cc--,n=1;
	if(cc%4==1){
		for(int i=1;i<=12;i++){
			if(n>m2[i]) n-=m2[i];
			else {
				mo=i;
				break;
			}	
		}
	}
	else{
		for(int i=1;i<=12;i++){
			if(n>m1[i]) n-=m1[i];
			else {
				mo=i;
				break;
			}	
		}
	}
	cout<<n<<' '<<mo<<' '<<cc<<" BC"<<endl;
}
void work2()
{
	int cc=1,mo=0;
	while(n>366) {
		if(cc%4==0) n-=366;
		else n-=365;
		cc++;
	}
	if(cc%4!=0&&n==366) cc++,n=1;
	if(cc%4==0){
		for(int i=1;i<=12;i++){
			if(n>m2[i]) n-=m2[i];
			else {
				mo=i;
				break;
			}	
		}
	}
	else{
		for(int i=1;i<=12;i++){
			if(n>m1[i]) n-=m1[i];
			else {
				mo=i;
				break;
			}	
		}
	}
	cout<<n<<' '<<mo<<' '<<cc<<endl;
}
void work3()
{
	int cc=1583,mo=0;
	if(n>T1){
		cc+=400*(n/T1);
		n%=T1;
	}
	while(n>366) {
		if(cc%400==0) n-=366;
		else {
			if(cc%4==0&&cc%100!=0)  n-=366;
			else n-=365;
		}
		cc++;
	}
	if(cc%400!=0&&n==366) cc++,n=1;
	if((cc%100==0||cc%4!=0)&&n==366) cc++,n=1;
	if((cc%4==0&&cc%100!=0)||cc%400==0){
		for(int i=1;i<=12;i++){
			if(n>m2[i]) n-=m2[i];
			else {
				mo=i;
				break;
			}	
		}
	}
	else{
		for(int i=1;i<=12;i++){
			if(n>m1[i]) n-=m1[i];
			else {
				mo=i;
				break;
			}	
		}
	}
	cout<<n<<' '<<mo<<' '<<cc<<endl;
}
void work4()
{
	if(n<=17)
	cout<<n+14<<' '<<10<<' '<<1582<<endl;
	else
	{
		if(n<=47)
			cout<<n-17<<' '<<11<<' '<<1582<<endl;
		else cout<<n-47<<' '<<12<<' '<<1582<<endl;
	}
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>Q;
	while(Q--)
	{
		cin>>n;
		n++;
		if(n<BC)
		{
			work1();
			continue;
		}	
		if(n<=BA){
			n-=BC; work2();
		}
		if(n>BA)
		{
			n-=BA;
			if(n<=78) {
				work4();
			}
			else {
				n-=78;
				work3();
			}
		}
	}
	return 0;
}