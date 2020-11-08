#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int q;

int _day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main() {
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	while(q--) {
		int n;
		int year,month,day;
		year = -4713;
		month = 1,day = 1;
		scanf("%d",&n);
		for (int i = 1;i <= n;i++) {
			if (year < 0) {
				bool flag = false;
				if (year == -1 && month == 12 && day == 31) flag = true;
				if ((-1*year) % 4 == 1) _day[2] = 29;
				day++;
				if (day > _day[month]) {
					month++;
					day = 1;
				}
				if (month > 12) {
					year++;
					month = 1;
				}
				_day[2] = 28;
//				cout << i << " " << year << " " << month << "  " << day << "  " << endl;
				if (flag) {
					year = 1;
				}
			}
//			else if (year == 0) {
//				year = 1;
//				printf("%d,%d,%d,%d\n",i,year,month,day);
//				day = month = 1;
//				continue;
//			}
			else if (year > 0 && year < 1582) {
//				printf("%d,%d,%d,%d\n",i,year,month,day);
				if (year % 4 == 0) _day[2] = 29;
				day++;
				if (day > _day[month]) {
					month++;
					day = 1;
				}
				if (month > 12) {
					month = 1;
					year++;
				}
				_day[2] = 28;
			}
			else if (year >= 1582){
//				if (year == 1582 && month == 10 && day == 5) {
//					day = 14;
//				}
				bool flag = false;
				if (year == 1582 && month == 10 && day == 4) flag = true;
				if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
					_day[2] = 29;
				}
				else _day[2] = 28;
				day++;
				if (day > _day[month]) {
					day = 1;
					month++;
				}
				if (month > 12) {
					month = 1;
					year++;
				}
				if (flag) day = 15;
			}
		}
		if (year < 0) printf("%d %d %d BC\n",day,month,-1*year);
		else printf("%d %d %d\n",day,month,year);
//		for (int i = 1;i <= cnt;i++) {
//			if (run[i] != run[i-1]) cout << run[i] << " " ;
//		}
	}
	
	return 0;
}