#include <iostream>
#include <cstdio>
#include <ctime>
//using namespace std;
//#define DEBUG

int T;

int is_run(int year, int month, int day) {
	if ((year == 1582 && month == 10 && day >= 5) || year > 1582) {
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) return 1;
	} else if (year < 1582 && year > 0) {
		if (year % 4 == 0) return 1;
	} else if (year < 0) {
		if ((year + 1) % 4 == 0) return 1;
	}
	
	return 0;
}

int main() {
	#ifndef DEBUG
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	#else
	clock_t begin = clock();
	#endif
	
	scanf("%d", &T);
	while (T--) {
		int a, year = -4713, month = 1, day = 1;
		scanf("%d", &a);
		
		day += a;
		while (day > 28) {
			for (int i = 1; i <= 12; i++) {
				if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
					if (day > 31) day -= 31, month++;
				} else if (i == 2) {
					if (is_run(year, month, day) && day > 29) day -= 29, month++;
					else if (day > 28) day -= 28, month++;
				} else {
					if (day > 30) day -= 30, month++;
				}
				
				year += month / 12;
				month %= 12;
				if (month <= 0) month += 12, year--;
				
				if (year == 0) year = 1;
			}
		}
		
		if (year >= 1582) day += 10;
		
		if (day > 28) {
			int i = month;
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
				if (day > 31) day -= 31, month++;
			} else if (i == 2) {
				if (is_run(year, month, day) && day > 29) day -= 29, month++;
				else if (day > 28) day -= 28, month++;
			} else {
				if (day > 30) day -= 30, month++;
			}
			
			year += month / 12;
			month %= 12;
			if (month <= 0) month += 12, year--;
				
			if (year == 0) year = 1;
		}
		
		if (year > 0) {
			printf("%d %d %d\n", day, month, year);
		} else {
			year *= -1;
			printf("%d %d %d BC\n", day, month, year);
		}
	}
	
	#ifdef DEBUG
	clock_t end = clock();
	std::cout << "Time used: " << (end - begin) / 1000 << "s" << std::endl;
	//printf("Time used: %d\n", begin - end);
	#endif
	
	return 0;
}

