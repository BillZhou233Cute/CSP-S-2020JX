#include<bits/stdc++.h>
using namespace std;
long long q,n;
int mon[15];
int mo2=29;
inline long long read(){
    long long w=0; int s=1; char c=getchar();
    while(c<'0' || c>'9'){if(c=='-') s=-1; c=getchar();}
    while(c<='9' && c>='0') w=w*10+c-'0',c=getchar();
	return w*s;
}
void wor1(long long &x,long long &y){
    while(x>=366)
        if(y%4==1) y-=1,x-=366;
        else y-=1,x-=365;
}
void wor2(long long &x,long long &y){
    while(x>=366)
        if(y%4==0) y+=1,x-=366;
        else y+=1,x-=365;
}
void work(){
    n=read();
	if(n<1721424){
            
	    long long x=n;
		int mo=1,d=1;long long y=4713;wor1(x,y);
	    while(x){
			x--;d++;
			if(mo!=2){
				if(d>mon[mo]) mo++,d=1;
			}
			if(mo==2){
				if(y%4==1)
					{if(d>mo2) mo++,d=1;}
				if(y%4!=1)
					{if(d>mon[2]) mo++,d=1;}
			}
			if(mo>12) mo-=12,y--;
		} 
       printf("%d %d %lld BC\n",d,mo,y);
       }
       if(n==1721424) cout<<"1 1 1"<<endl;
       if(n>1721424 && n<2299161){
	    long long x=n-1721424;
		int mo=1,d=1;long long y=1;
            wor2(x,y);
	    while(x){
			x--;d++;
			if(mo!=2){
				if(d>mon[mo]) mo++,d=1;
			}
			if(mo==2){
				if(y%4==0)
					{if(d>mo2) mo++,d=1;}
				else
					{if(d>mon[2]) mo++,d=1;}
			}
			if(mo>12) mo=1,y++;
		} 
       printf("%d %d %lld\n",d,mo,y);
       }
       if(n==2299161) cout<<"15 10 1582"<<endl;
       if(n>2299161){
            
	    long long x=n-2299161;
		int mo=10,d=15;long long y=1582;
	    while(x){
			x--;d++;
			if(mo!=2){
				if(d>mon[mo]) mo++,d-=mon[mo];
			}
			if(mo==2){
				if((y%4==0 && y%100!=0) || (y%400==0))
					{if(d>mo2) mo++,d-=mo2;}
				else
					{if(d>mon[2]) mo++,d-=mo2;}
			}
			if(mo>12) mo=1,y++;
		} 
       printf("%d %d %lld\n",d,mo,y);
       }
}		

int main(){
    freopen("julian.in","r",stdin);
    freopen("julian.out","w",stdout);
    mon[1]=31;mon[2]=28;mon[3]=31;mon[4]=30;mon[5]=31;mon[6]=30;
    mon[7]=31;mon[8]=31;mon[9]=30;mon[10]=31;mon[11]=30;mon[12]=31;
    q=read();
	while(q){
	    work();
		q--;
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
