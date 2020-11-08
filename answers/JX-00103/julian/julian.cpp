#include<iostream>
#include<fstream>
using namespace std;

int m[14]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int run,q,n,mouth,year,day,BC;

int abs(int x) {
	return -x;
}

bool ju(int x){
	if(x<0){
		int now=abs(x)-1+4;
		if(now % 4 ==0) return true;
		return false;
	}
	if(x>0 && x<1582){
		if(x%4 == 0) return true;
		return false;
	}
	if(x>1582) {
		if( (x%4 == 0&& x%100 != 0)|| (x%400 ==0) ) return true;
		return false;
	}
	return false;
}

void judge(int x){
	//year
	while(n>=365){
		n-=365;
		if(year == 1582) n+=10;
		
		if(year<0){
			int now=abs(year)-1+4;
			if(now % 4 ==0){
				if(n <=0 ) {n+=365;break;}
				n--;
			}
		}
		if(year>0 && year<1582){
			if(year%4 == 0){
				if(n<=0){n+=365;break;}
				n--;
			}
		}
	
		if(year >1582) {
			if( (year%4 == 0&& year%100 != 0  && n == 0)|| (year%400 ==0 && n == 0) ) {n+=365;break;}
			if( (year%4 == 0&& year%100 != 0  && n > 0)|| (year%400 ==0 && n > 0) ) {n--;}
		}
	
		year++;

		if(year == 0) {
			year = 1;
			run = 1;
		}
		run++;
	}
	if(year == 1582 && n>=355) {year ++;n-=355;}
	//mouth day
	for(int i=1;i<=12;i++){
		if(n>=m[i])n-=m[i];
		else {day+=n;break;}
		
		if(i == 2 && ju(year) ) n--;
		if(n<0){day=28;break;}
		mouth = i+1;
	}
	return;
}

int main(){
	ifstream fin("julian.in");
	fstream fout("julian.out");
	fin>>q;
	for(int i=1;i<=q;i++){
		fin>>n;
		day=1;
		mouth=1;
		year=-4713;
		judge(n);
		if(year<0) fout<<day<<' '<<mouth<<' '<<abs(year)<<' '<<"BC"<<endl;
		else fout<<day<<' ' <<mouth<<' '<<year<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}