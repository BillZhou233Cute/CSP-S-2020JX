/*

Code by W-YI

*/
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct time{
	int d;//一月的天数
	bool y;//是否为闰年
};

struct time now;

void setnow(int year,int mon,int day){
	
	//判定闰年
	now.y=false;
	if((year<1582)||(year==1852&&mon<=10)||(year==1852&&mon==10&&day<=4)){
		if(year%4==0)now.y=true;
	}else{
		if((year%400==0)||((year%4==0)&&(year%100!=0)))now.y=true;
			else now.y=false;
	}
	
	//不同月份的日期
	
	//big month
	if(mon == 1||mon == 3||mon == 5||mon == 7||mon == 8||mon == 10||mon == 12)now.d=31;
	//small month
	else if(mon == 4||mon == 6||mon == 9||mon == 11)now.d=30;
	//feb - big
	else if(mon==2&&now.y)now.d=29;
	//feb - amsll
	else if(mon==2&&!now.y)now.d=28;
	
	
}

int main(){
	freopen ("julian.in","r",stdin);
	freopen ("julian.out","w",stdout);
	
	
	//给定一个不含小数部分的儒略日,计算出该儒略日所对应的公历日期。
	
	
	long long q;
	
	cin>>q;
	
	for (long long i=0;i<q;i++){
		
		//INPUT---------------------------------------
		long long n;
		cin>>n;
		
		//calc.ing------------------------------------
		
		int d=1,mon=1,y=-4712;
		//注:BC年数的数值用实际BC年数+1获得;输出时必须-1
		//cout<<"\n是否闰年:"<<now.y<<"一月天数"<<now.d<<"日期	";
		
		for(long long j=0;j<n;j++){
			d++;
			if(y==1852&&mon==10&&d==5){
				d=15;
			}
			setnow(y,mon,d);
			
			if(d>now.d){
				mon++;
				d=1;
			}
			if(mon>12){
				y++;
				mon=1;
			}
		}
		
		//OUTPUT-------------------------------------
		if(y<=0){
			cout<<d<<' '<<mon<<' '<<abs(y-1)<<" BC"<<endl;
		}else{
			cout<<d<<' '<<mon<<' '<<y<<endl;
		}
		
	}
	
	
	
	
	
	
	fclose (stdout);
	fclose (stdin);
	return 0;
}