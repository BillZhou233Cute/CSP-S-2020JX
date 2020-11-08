#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

ll r;
int month[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void work() {
	cin >> r;
	
	//400年
	//4年 1461
	//特殊点 2298884
	if(r > 2298884) {
		int temp = r - 2298884;
		temp = min(temp, 10);
		temp = max(temp, 0);
		r += temp;
	}
	
	
	
	ll a = (r / 1461) * 4;
	r %= 1461;
	if(r >= 366) r -= 366, a++;
	while(r >= 365) r-= 365, a++;
	//cout << r << " " << a << endl;
	
	ll by = -4713 + a;
	if(by >= 0) by++;
	//cout << by << endl;
	//算出现在年份，除去公元0年
	if(by > 1600) r += ((by-1600) / 400) * 3;
	
	
	//如果现在是闰年，二月变化
	if(by < 0) {
		if((-by) % 4 == 1) month[2] = 29;
		else month[2] = 28;
	}else {
		if((by % 4 == 0 && by % 100 != 0) || (by % 400 == 0)) month[2] = 29;
		else month[2] = 28;
	}
	
	//得出月份
	ll bm = 1;
	for(int i = 1; i <= 12; i++) {
		if(r >= month[i]) r -= month[i], bm++;
	}
	
	//得出日子
	ll bd = 1 + r;
	
	if(by < 0) cout << bd << " " << bm << " " << -by << " BC" <<endl;
	else cout << bd << " " << bm << " " << by << endl;
}

int main() {
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);

	int q; cin >> q;
	while(q--) {
		work();
	}

	return 0;
}
