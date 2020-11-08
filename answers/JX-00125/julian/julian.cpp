#include<bits/stdc++.h>
using namespace std;
int T,y = -4713,m = 1,d = 1;
int r;
int num[3000005];
int theyear(int x){
	if(x == 1582) return 355;
	if(x < 1582){ 
		if(x < 0) x = -x;
		return (x % 4 == 0) ? 366 : 365;
	} else return (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0)) ? 366 : 365;
} 
int moe[20] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int mo[20];
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	for(int i = 1;i <= 3000000;i++) num[i] = num[i - 1] + (theyear(i - 4714)) - 365;
	scanf("%d",&T);
	while(T--){
		y = -4713;
		m = 1;
		d = 1;
		for(int i = 1;i <= 12;i++) mo[i] = moe[i];
		scanf("%d",&r);
		int z = r / 365;
		r -= (z * 365) + num[z];
		while(r < 0) r += theyear(z - 4714),z--;
		y += z;
		if(y == 1582) mo[10] -= 10;
		if(theyear(y) == 366) mo[2]++;
		while(r >= mo[m]) r -= mo[m],m++;
		d += r;
		if(y == 1582 && m == 10) d += 10;
		if(y >= 0) y++;
		if(y < 0) printf("%d %d %d BC\n",d,m,-y);
		else printf("%d %d %d\n",d,m,y);
	}
	return 0;
}
