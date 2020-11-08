#include<cstdio>
#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
using namespace std;
ifstream fin("julian.in");
ofstream fout("julian.out");
int q;
bool pd=false;
short day=1;short month=1;int year=4713;

bool rn(int a){
   if(pd==false&&(a-1)%4==0) return true;
   if(pd==true&&a<1582&&a%4==0) return true;
   if(pd==true&&a>1582&&a%4==0&&a%100!=0) return true;
   if(pd==true&&a>1582&&a%400==0) return true;
	    return	false;    
	}

void jw(){
     if(rn(year)==false)   {
	        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){if(day>31) {day=day-31;month=month+1;}}
	        else if(month==4||month==6||month==9||month==11){if(day>30) {day=day-30;month=month+1;}}	 
	        else if(month==2) {if(day>28) {day=day-28;month=month+1;}}
			
			if(month>12) {
				if(pd==false&&year>1) {year-=1;}
				else if(pd==false&&year==1) {pd=true;}
			    else	if(pd==true) {year+=1;}
			}
	       return;
		} 
	if(rn(year)==true)   {
	        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){if(day>31) {day=day-31;month=month+1;}}
	        else if(month==4||month==6||month==9||month==11){if(day>30) {day=day-30;month=month+1;}}	 
	        else if(month==2) {if(day>29) {day=day-29;month=month+1;}}
			
			if(month>12) {
				if(pd==false&&year>1) {year-=1;return;}
			  else	if(pd==false&&year==1) {pd=true;}
			  else	if(pd==true) {year+=1;}
			}
	       return;
		}
}
struct l{
  int d,m,y;
};
int main(){
  fin>>q;l p[q+1];int js=0;int q1=q;
	  while(q1>0){
		   q1--;int a;
			 fin>>a;
               for(int i=1;i<=a;i++){
			        day++;
				     if(year==1582&&month==10&&day==5&&pd==true) {
						    day=15;
						     continue;
						}
                    jw();				   
				}	              
		   js++;
			p[js].d=day;p[js].m=month;p[js].y=year;	
		}  
	
	  for(int i=1;i<=q;i++){
	     if(pd==false) fout<<p[i].d<<" "<<p[i].m<<" "<<p[i].y<<" "<<"BC";
		   if(pd==true) fout<<p[i].d<<" "<<p[i].m<<" "<<p[i].y;
	      fout<<endl;
	}
	
		return 0;	
}
	