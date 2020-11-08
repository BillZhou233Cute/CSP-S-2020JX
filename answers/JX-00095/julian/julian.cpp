#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
int q, r[100005], month1[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365}, month2[13] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}, rn[2]={365, 366};
using namespace std;
int m1(int d)
{
	if(d <= month1[1])return 1;
	if(d <= month1[2])return 2;
	if(d <= month1[3])return 3;
	if(d <= month1[4])return 4;
	if(d <= month1[5])return 5;
	if(d <= month1[6])return 6;
	if(d <= month1[7])return 7;
	if(d <= month1[8])return 8;
	if(d <= month1[9])return 9;
	if(d <= month1[10])return 10;
	if(d <= month1[11])return 11;
	if(d <= month1[12])return 12;
	return 0;
}
int m2(int d)
{
	if(d <= month2[1])return 1;
	if(d <= month2[2])return 2;
	if(d <= month2[3])return 3;
	if(d <= month2[4])return 4;
	if(d <= month2[5])return 5;
	if(d <= month2[6])return 6;
	if(d <= month2[7])return 7;
	if(d <= month2[8])return 8;
	if(d <= month2[9])return 9;
	if(d <= month2[10])return 10;
	if(d <= month2[11])return 11;
	if(d <= month2[12])return 12;
	return  0;
}
int main()
{
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	scanf("%d", &q);
	for(int i = 1; i <= q; i++)
	{
		int y = -4713, m, n, yn;
		scanf("%d", &r[i]);
		r[i] += 1;
		if(r[i] > 2299161)
			r[i] += 10;
		while(1)
		{
			if(y == 0)y = 1;
			if((y < 0 && (y + 1) % 4 == 0 ) || (y > 0 && y % 4 == 0))
			{
				yn = 1;
			}
			else yn = 0;
			if(y % 100 == 0 && y % 400 == 0 && y >= 1583)
				yn = 1;
			if(y % 100 == 0 && y % 400 != 0 && y >= 1583)
				yn = 0;
			if(r[i] > rn[yn])
			{
				y += 1;
				r[i] -= rn[yn];
			}
			else break;
		}
		if(yn == 1)
		{
			m = m2(r[i]);
			n = r[i] - month2[m - 1];
		}
		else 
		{
			m = m1(r[i]);
			n = r[i] - month1[m - 1];
		}
		if(y < 0)
			printf("%d %d %d BC\n", n, m, -1*y);
		else
			printf("%d %d %d\n", n, m, y);
	}
	return 0;
}