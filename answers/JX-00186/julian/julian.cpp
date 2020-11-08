#include<bits/stdc++.h>
using namespace std;
long long t;
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>t;
	while(t--){
		long long x;
		cin>>x;
	if(x<4713*365+1178){
		int z=(x/365);
		int y=(z+1)/4;//润年天数
		int duo=x-365*z-y;//多出天数
		//cout<<y<<" "<<4713-z<<" "<<duo<<" ";
		if(duo>0&&duo<=31)
		{cout<<duo+1<<" "<<"1"<<" "<<4713-z<<" "<<"BC";}
		else if ((duo>31&&duo<=59))
		{if(((z+1%4!=0)||duo!=60))
			cout<<duo-31<<" "<<"2"<<" "<<4713-z<<" "<<"BC";
		else if(duo%100!=0)
			cout<<duo-32<<" "<<"2"<<" "<<4713-z<<" "<<"BC";}
		else if((duo>59&&duo<=90))
		{	if((z+1%4!=0 ||duo!=91))
			cout<<duo-59<<" "<<"3"<<" "<<4713-z<<" "<<"BC";
			else if(duo%100!=0)
			cout<<duo-60<<" "<<"3"<<" "<<4713-z<<" "<<"BC";
			}
		else if((duo>90&&duo<=120)){
			if((z+1%4!=0 &&duo!=121))
			cout<<duo-90<<" "<<"4"<<" "<<4713-z<<" "<<"BC";
			else if(duo%100!=0)
				cout<<duo-91<<" "<<"4"<<" "<<4713-z<<" "<<"BC";}
		else	if((duo>120&&duo<=151)){
			if((z+1%4!=0 &&duo!=152))
			cout<<duo-120<<" "<<"5"<<" "<<4713-z<<" "<<"BC";
			else if(duo%100!=0)
				cout<<duo-121<<" "<<"5"<<" "<<4713-z<<" "<<"BC";}
		else	if((duo>151&&duo<=181)){
			if((z+1%4!=0 &&duo!=182))
			cout<<duo-151<<" "<<"6"<<" "<<4713-z<<" "<<"BC";
			else if(duo%100!=0)
				cout<<duo-152<<" "<<"6"<<" "<<4713-z<<" "<<"BC";}
		else	if((duo>181&&duo<=212)){
			if((z+1%4!=0 &&duo!=213))
			cout<<duo-181<<" "<<"7"<<" "<<4713-z<<" "<<"BC";
			else if(duo%100!=0)
				cout<<duo-182<<" "<<"7"<<" "<<4713-z<<" "<<"BC";}
		else	if((duo>212&&duo<=243)){
			if((z+1%4!=0 &&duo!=244))
			cout<<duo-212<<" "<<"8"<<" "<<4713-z<<" "<<"BC";
			else if(duo%100!=0)
				cout<<duo-213<<" "<<"8"<<" "<<4713-z<<" "<<"BC";}
		else	if((duo>243&&duo<=273)){
			if(z+1%4!=0 &&duo!=274)
			cout<<duo-243<<" "<<"9"<<" "<<4713-z<<" "<<"BC";
			else if(duo%100!=0)
				cout<<duo-244<<" "<<"9"<<" "<<4713-z<<" "<<"BC";}
			else	if((duo>273&&duo<=304)){
				if((z+1%4!=0 &&duo!=305))
			cout<<duo-273<<" "<<"10"<<" "<<4713-z<<" "<<"BC";
			else if(duo%100!=0)
				cout<<duo-274<<" "<<"10"<<" "<<4713-z<<" "<<"BC";}
			else	if(duo>304&&duo<=334){
				if((z+1%4!=0 &&duo!=335))
			cout<<duo-304<<" "<<"11"<<" "<<4713-z<<" "<<"BC";
			else if(duo%100!=0)
				cout<<duo-305<<" "<<"11"<<" "<<4713-z<<" "<<"BC";}
			else	if(duo>334&&duo<=365){
				if((z+1%4!=0 &&duo!=366))
			cout<<duo-334<<" "<<"12"<<" "<<4713-z<<" "<<"BC";
			else if(duo%100!=0)
				cout<<duo-334<<" "<<"12"<<" "<<4713-z<<" "<<"BC";}
		}
		else if(x>4713*365+1178)
		{
			long long  z1=0,k=0;
			int gf=1;
			while(x>k){
				z1++;
				if((z1%4==0&&z1%100!=0)||(z1%400==0))
				{k=k+366;
					gf=0;}
				else {k=k+365;
	gf=1;}				}
	k=k-365;
	if(gf==0)
		k=k-1;
		long long  duo1=x-k-37;
		if(duo1>0&&duo1<=31)
		{cout<<duo1+1<<" "<<"1"<<" "<<z1-4713;}
		else if ((duo1>31&&duo1<=59))
		{if((z1+1%4!=0 ||duo1!=60))
			cout<<duo1-31<<" "<<"2"<<" "<<z1-4713;
		else if(duo1%100!=0)
			cout<<duo1-32<<" "<<"2"<<" "<<z1-4713;}
		else if((duo1>59&&duo1<=90))
		{	if((z1+1%4!=0 ||duo1!=91))
			cout<<duo1-59<<" "<<"3"<<" "<<z1-4713;
			else if(duo1%100!=0)
			cout<<duo1-60<<" "<<"3"<<" "<<z1-4713;
			}
		else if((duo1>90&&duo1<=120)){
			if((z1+1%4!=0 &&duo1!=121))
			cout<<duo1-90<<" "<<"4"<<" "<<z1-4713;
			else if(duo1%100!=0)
				cout<<duo1-91<<" "<<"4"<<" "<<z1-4713;}
		else	if((duo1>120&&duo1<=151)){
			if((z1+1%4!=0 &&duo1!=152))
			cout<<duo1-120<<" "<<"5"<<" "<<z1-4713;
			else if(duo1%100!=0)
				cout<<duo1-121<<" "<<"5"<<" "<<z1-4713;}
		else	if((duo1>151&&duo1<=181)){
			if((z1+1%4!=0 &&duo1!=182))
			cout<<duo1-151<<" "<<"6"<<" "<<z1-4713;
			else if(duo1%100!=0)
				cout<<duo1-152<<" "<<"6"<<" "<<z1-4713;}
		else	if((duo1>181&&duo1<=212)){
			if((z1+1%4!=0 &&duo1!=213))
			cout<<duo1-181<<" "<<"7"<<" "<<z1-4713;
			else if(duo1%100!=0)
				cout<<duo1-182<<" "<<"7"<<" "<<z1-4713;}
		else	if((duo1>212&&duo1<=243)){
			if((z1+1%4!=0 &&duo1!=244))
			cout<<duo1-212<<" "<<"8"<<" "<<z1-4713;
			else if(duo1%100!=0)
				cout<<duo1-213<<" "<<"8"<<" "<<z1-4713;}
		else	if((duo1>243&&duo1<=273)){
			if(z1+1%4!=0 &&duo1!=274)
			cout<<duo1-243<<" "<<"9"<<" "<<z1-4713;
			else if(duo1%100!=0)
				cout<<duo1-244<<" "<<"9"<<" "<<z1-4713;}
			else	if((duo1>273&&duo1<=304)){
				if((z1+1%4!=0 &&duo1!=305))
			cout<<duo1-273<<" "<<"10"<<" "<<z1-4713;
			else if(duo1%100!=0)
				cout<<duo1-274<<" "<<"10"<<" "<<z1-4713;}
			else	if(duo1>304&&duo1<=334){
				if((z1+1%4!=0 &&duo1!=335))
			cout<<duo1-304<<" "<<"11"<<" "<<z1-4713;
			else if(duo1%100!=0)
				cout<<duo1-305<<" "<<"11"<<" "<<z1-4713;}
			else	if(duo1>334&&duo1<=365){
				if((z1+1%4!=0 &&duo1!=366))
			cout<<duo1-334<<" "<<"12"<<" "<<z1-4713;
			else if(duo1%100!=0)
				cout<<duo1-334<<" "<<"12"<<" "<<z1-4713;}
		}
	}
	return 0;}
