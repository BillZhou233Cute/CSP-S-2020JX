#include<bits/stdc++.h>
using namespace std;
long long i,j,k,t,m,n,s,x,y,year,month,day,a[1000000],d[100];
int s1,s2,s3,s4;
int main(){
d[1]=31; d[2]=28; d[3]=31; d[4]=30; d[5]=31; d[6]=30; d[7]=31; d[8]=31; d[9]=30; d[10]=31; d[11]=30; d[12]=31;	
s1=31+28+31+30+31+30+31+31+30+31+30+31;	
s2=6294*s1+1573+s1-30-31+3;		
s3=400*s1+97; 
s4=4*s1+1;	 
freopen("julian.in","r",stdin);
freopen("julian.out","w",stdout);
scanf("%d",&n);
for (i=1; i<=n; i++) cin>>a[i];
for (i=1;  i<=n;  i++){
		year=-4713; month=1; day=1;
	s=a[i]; 
	if (s>s2) {s=s+10+s1-30-31+3;
		year=1582;
		s=s-s2;		
		if (s>s3) { k=s/s3; s=s-s3*k; year=year+k*400; }
		if (s>s1) { k=s/s1; s=s-(k-3)/4-1+(k+year%100)/100-(k-19+year%400)/400-1;
			k=s/s1; s=s-s1*k; year=year+k; }
		if (year/4==0) s=s-1;;	
		for (j=1 ; j<=12; j++) 
			if (s>d[j]) s=s-d[j]; else {
			    month=j; day=day+s; break;
				}
			} else {
			if (s>s4) { k=s/s4; year=year+k*4;
				if (year>=0) year++; s=s-s4*k;
			}
			if (s>s1) { k=s/s1; s=s-(k-2)/4-1;
			k=s/s1; s=s-s1*k; year=year+k; }
			if (year/4==0) s=s-1;	
				
		for (j=1 ; j<=12; j++) 
			if (s>d[j]) s=s-d[j]; else { 
			    month=j; day=day+s;  break;
			}
		}
		m=0;
	    if (year<0) { m=1; year=0-year;}	
		cout<<day<<" "<<month<<" "<<year;
         if (m==1) cout<<" BC";	 cout<<endl;
    }
	return 0;	
}