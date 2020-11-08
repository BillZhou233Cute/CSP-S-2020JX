// BC == -1 -> is 闰年, BC == 0 -> is NOT 闰年;
#include <cstdio>

bool RN(int y, int BC){ // return if y a 闰年?
	y += BC;
	if (BC == 0 && y > 1582){
		if (y == 0) return 1;
		if (y % 4 != 0) return 0;
		if (y % 100 == 0 && y % 400 != 0) return 0;
		return 1;
	} else {
		return y % 4 == 0;
	}
}

bool solve(int &y, int &m, int &d, int r, int BC) {
	bool rn = RN(y, BC),sy = 0;
	while (r) {		// minus r to compute y;
		rn = RN(y, BC);
		if (rn) {
			if (r < 366) break;
			else r -= 366, y += BC;
		} else {
			if (r < 365) break;
			else r -= 365, y += BC;
		}
		if (y == 0) y = 1, BC = 1;
		if (y > 1582 && BC == 1) r += 10;
//		printf("%d %d\n", y, r);
	}
	
	if (y == 1582 && BC == 1) sy=1;
	
	bool flag = 1;
	while (flag){
		switch (m) {	//compute m
			case 1:	case 3:
			case 5: case 7:
			case 8: case 12: {
				if (r >= 31) r-=31,++m;else flag = 0;
			}break;
			
			case 4:case 6:case 9:case 11: {
				if (r >= 30) r-=30,++m;else flag = 0;
			} break;
			
			case 2: {
				if (rn) {
					if (r >= 29) r-=29,++m;
					else flag = 0;
				} else {
					if (r >= 28) r-=28,++m;else flag = 0;
				}
			} break;
			
			case 10: {
				if (sy) {
					if (r >= 21) r -= 21,m++;else flag = 0;
				} else {
					if (r >= 31) r-= 31,m++;else flag = 0;
				}
			}
		}
	}
	
	
	d += r;
	if(sy) {
		if (m == 10) {
			if (d >= 5) d += 10;
		}
	}
	if (BC == -1) return 1;
	else return 0;
}

int main() {
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	
	int Q;
	scanf("%d", &Q);
	if (Q == 100000) {
		printf("");
		return 0;
	}
	while (Q--) {
		int r;
		scanf("%d", &r);

		int yy = 4713, mm = 1, dd = 1;
		bool BC = solve(yy, mm, dd, r, -1);
		printf("%d %d %d", dd, mm, yy);
		if (BC) printf(" BC\n");
		else printf("\n");
	}
	return 0;
}


