#include<iostream>
#include<cmath>
#include<string>
#include<fstream>
using namespace std;
ofstream fout("julian.out");
ifstream fin("julian.in");	
int q,i,n,f,m;
int cur[6];
	char s1;
int main(){
	f=0;
	fin>>q;
	long long a[q+1];
	string s[q+1];
	int d[14];
	d[0]=0;
	d[1]=31;
	d[2]=28;
	d[3]=31;
	d[4]=30;
	d[5]=31;
	d[6]=30;
	d[7]=31;
    d[8]=31;
    d[9]=30;
    d[10]=31;
    d[11]=30;
    d[12]=31; 
    d[13]=29;
    int day,month;
     long long year; 	
	for(i=1;i<=q;i++){
	  fin>>a[i];
	  day=1;
     month=1;
     year=4713; 
		for(int j=1;j<=a[i];j++){
		   day++;
			if (year%4==1&&month==2){
				if(day>d[13]){
			     month++;
				 day=1;
				}
			else {
			  j++;
			  day++;	
			}	
				}
			else{ 
				if (day>d[month]){
				month++;
				day=1;
			}
		  }	
			if (month>12){
			   year--;
			   month=1;
			}
		if(year<=0){
		  f=1;
		  year=1;
			m=j;
		  break;	
		}
		}
		if(f==1){
		for(int j=m;j<=a[i];j++){
			if (year==1582&&month==10&&day==5){
			  day=15;
			}
			if (j!=m)day++;
			if ((year>1582&&year%400==0&&month==2)||(year>1582&&year%4==0&&month==2&&year%100!=0) || (year<=1582&&year%4==0&&month==2)){
			if(day>d[13]){
			     month++;
				 day=1;
			}
			else {
			  j++;
			  day++;	
			}	
		   }
			else{ 
			if (day>d[month]){
				month++;
				day=1;
			}
		  }	
			if (month>12){
			   year++;
			   month=1;
			}
		}
		}
			n=0;
		while(day!=0){
			n++;
			cur[n]=day%10;
			day=day/10;
		}
		for(int j=n;j>=1;j--){
	       s1=cur[j]+'0';
			s[i]+=s1;
		}
		s[i]+=" ";
		n=0;
		while(month!=0){
			n++;
			cur[n]=month%10;
			month=month/10;
		}
		for(int j=n;j>=1;j--){
	       s1=cur[j]+'0';
			s[i]+=s1;
		}
		s[i]+=" ";
		n=0;
		while(year!=0){
			n++;
			cur[n]=year%10;
			year=year/10;
		}
		for(int j=n;j>=1;j--){
	       s1=cur[j]+'0';
			s[i]+=s1;
		}
		s[i]+=" ";
		if(f==0) s[i]+="BC";
	}
	for(i=1;i<=q;i++){
	   fout<<s[i]<<endl;
		}
	return 0;
}
