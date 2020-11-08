#include <cstdio>

using namespace std;


int read() {
	int x = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch - '0');
		ch = getchar();
	}
	return x * w;
}

struct cal{
	int year;
	int month;
	int day;
	
	void initZero() {
		year = -4713;
		month = 1;
		day = 1;
	}
	
	void print() {
		if (year > 0) {
			printf("%d %d %d\n", day, month, year);
		} else {
			printf("%d %d %d BC\n", day, month, 0 - year);
		}
	}
	
	void addDay(int d) {
		int total = d;
		bool crossMonth = false;
		while (total > 0) {
			bool canAddMonth = true;
			/*if (isBigger(1582, 10, 15)) {
				
			} else if (isBigger(1582, 10, 5) && isSmaller(1582, 10, 14)) {
				printf("error");
			} else if (isSmaller(1582, 10, 4)) {
				
			}*/
			int cad = canAddDay();
			if (isBigger(1581, 10, 15)) {
			//printf("CanAddDay: %d, total: %d\n", cad, total);
			//print();
			}
			if (cad <= 0 || total - cad < 0) {
				canAddMonth = false;
				if (cad < 0) {
					day = 15;
					total -= 0 - cad;
					//printf("particular situation: total: %d, cad: %d\n", total, cad);
					//print();
				} else {
					day += total;
					if (crossMonth) day--;
					total = 0;
					if (isBigger(1581, 10, 15)) {
					//printf("node#1, total: %d\n", total);
					//print();
					}
				}
			} else {
				crossMonth = true;
				day = 1;
				total -= cad;
				if (isBigger(1581, 10, 15)) {
				//printf("node#2, total: %d\n", total);
				//print();
				}
			}
			if (isBigger(1581, 10, 15)) {
			//printf("node#3, total: %d\n", total);
			//print();
			}
			if (canAddMonth) {
				month++;
				if (month > 12) {
					addOneYear();
					month = 1;
				}
			}
		}
	}
	
	void addOneYear() {
		(year != -1) ? year++ : year += 2;
	}
	
	int canAddDay() {
		if (month == 2) {
			if (isBigger(1582, 10, 15)) {
				if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
					return 30 - day;
				} else {
					return 29 - day;
				}
			} else if (isBigger(1582, 10, 5) && isSmaller(1582, 10, 14)) {
				printf("error2");
				return 0;
			} else if (isSmaller(1582, 10, 4)) {
				if (year % 4 == 0) {
					return 30 - day;
				} else {
					return 29 - day;
				}
			} else return 0;
		} else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 12) {
			return 32 - day;
		} else if (month == 4 || month == 6 || month == 9 || month == 11) {
			return 31 - day;
		} else if (month == 10) {
			if (year == 1582 && day <= 4) {
				return 0 - (5 - day);
			} else return 32 - day;
		}
		return 0;
	}
	
	bool isBigger(int yy, int mm, int dd) {
		return year >= yy || (year == yy && month >= mm) || (year == yy && month == mm && day >= dd);
	}
	
	bool isSmaller(int yy, int mm, int dd) {
		return year <= yy || (year == yy && month <= mm) || (year == yy && month == mm && day <= dd);
	}
	
};

int main(void) {

	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	
	int Q = read();
	for (int i = 0; i < Q; i++) {
		int julian = read();
		cal c;
		c.initZero();
		c.addDay(julian);
		c.print();
	}
	
	return 0;
}
