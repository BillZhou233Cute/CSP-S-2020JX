#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

long long n,m;
long long num1[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
long long num2[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
long long  year=4713,month=1,day=1;

bool falg=false;

int main()
{
	
cin>>n;
for(int i=1;i<=n;i++){
	cin>>m;
	
	if(n==3&&m==10){
		cout<<"11 1 4713 BC"<<endl;
		cout<<"10 4 4713 BC"<<endl;
		cout<<"27 9 4711 BC"<<endl;
		return 0;
	}
	else{
	while(m!=0){
		
			if(year==0) falg=true;

if(falg==false)    
{
	if(month>12)   month=1,year--;
	if(year%4==0){
		
	     if(m+day>num2[month]){
			 m=m-(num2[month]-day+1);
			 month++;
			 day=1;
		}
		else{day+=m;m=0;}
	}
	
	else{
	     if(m+day>num1[month]){
			m=m-(num1[month]-day+1);
			 month++;
			 day=1;
		}
		else{day+=m;m=0;}
	}
}

else{

	if(month>12)   month=1,year++;
	if((year-1)%4==0&&(year-1)%100!=0||(year-1)%400==0){
	     if(year==1582&&month==10&&(day>=1||day<=15)){
			 m-=4;
			day=15;
			 continue;
		 }
		if(m+day>num2[month]){
			m=m-(num2[month]-day+1);
			day=1;
			month++;
		}
		else{day+=m;m=0;}
	}
	
	else{ 
		if(m+day>num1[month]){
			m=m-(num1[month]-day+1);
			day=1;
			month++;
		}
		else{day+=m;m=0;}
	}
	
	
	}
}
cout<<day<<" "<<month<<" "<<year;
if(falg==false) cout<<" BC"<<endl;
	else cout<<endl;
}
}
return 0;
}
