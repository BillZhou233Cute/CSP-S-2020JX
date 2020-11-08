#include <stdio.h>

int MDT[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, TD, MD, YANS;
long long Q, R, M, Y;
bool BC, SY;

inline bool specYear() {
	if (Y > 1582) {
		if (Y % 400 == 0) return true;
		return (Y % 4 == 0 && Y % 100 != 0);
	} else {
		if (Y < 0) return ((Y + 1) % 4 == 0);
		return Y % 4 == 0;
	}
}

inline int getTD() {
	YANS = SY ? 366 : 365;
	return (Y == 1582 ? YANS - 10 : YANS);
}

inline int getMD() {
	if (Y == 1582 && M == 10) return 21;
	return (SY && M == 2 ? 29 : MDT[M]);
}

int main() {
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	scanf("%lld", &Q);
	while (Q--) {
		Y = -4713, M = 1, BC = false;
		scanf("%lld", &R);
		SY = specYear();
		TD = getTD();
		while (R - TD >= 0) {
			Y += (Y == -1 ? 2 : 1);
			R -= TD;
			SY = specYear();
			TD = getTD();
		}
		MD = getMD();
		while (R - MD >= 0) {
			M++;
			R -= MD;
			MD = getMD();
		}
		if (Y < 0) {
			Y = -Y;
			BC = true;
		}
		printf("%lld %lld %lld%s\n", R + 1, M, Y, BC ? " BC" : "");
	}
	return 0;
}

