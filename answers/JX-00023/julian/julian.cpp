#include<bits/stdc++.h>
using namespace std;
int mon1[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int mon[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 	273, 304, 334, 365};
int n;
void solve(int x)
{
	int c = x;
	//int day, month, year;
	int y_pa, d_pa, m_pa;
	if(x <= 2299160)//before 4 10 1582  count with 4 years a turn
	{
		if(x <= 1721424)
		{y_pa = x / 1461;
		x -= y_pa * 1461;
		int t = x / 365;
		y_pa += t;
		x -= t * 365;
		for(int i = 1; i <= 11; i++)
		{
			if(x < mon[i + 1])
			{
				m_pa = i;
				break;
				}}
		d_pa = x - mon[m_pa];
		//printf("%d %d\n", m_pa + 1, x);
		if(y_pa == 0 && m_pa == 1)
		{
			printf("%d %d %d ", mon[m_pa] + d_pa  + 1, m_pa, 4713 - y_pa);
			}
		else
			printf("%d %d %d ", d_pa, m_pa + 1, 4713 - y_pa);
		printf("BC");}
		else if(x > 1721424)
		{
			x -= 1721424;
			y_pa = x / 1461;
		x -= y_pa * 1461;
			y_pa *= 4;
		int t = x / 365;
		y_pa += t;
		x -= t * 365;
		for(int i = 1; i <= 11; i++)
		{
			if(x < mon[i + 1])
			{
				m_pa = i;
				break;
				}}
		d_pa = x - mon[m_pa];
		//printf("%d %d\n", m_pa + 1, x);
		printf("%d %d %d ", d_pa + 1, m_pa + 1, y_pa + 1);
				}
		/*if(c <= 1721424)
		{printf("%d %d %d ", d_pa, m_pa + 1, (4713 - y_pa));
			printf("BC");}
		else if (c > 1721424)
		{printf("%d %d %d", d_pa, m_pa + 1, (y_pa - 4713));}*/
	}
	else if(x > 2299160)
	{
		x -= 1721424;
			y_pa = x / 1461;
		x -= y_pa * 1461;
			y_pa *= 4;
		int t = x / 365;
		y_pa += t;
		x -= t * 365;
		for(int i = 1; i <= 11; i++)
		{
			if(x < mon[i + 1])
			{
				m_pa = i;
				break;
				}}
		d_pa = x - mon[m_pa];
		//printf("%d %d\n", m_pa + 1, x);
		/*int temp1 = (y_pa + 1 - 1582);
		int minus = (temp1%4) + temp1 - (temp1/4);
		for(int k = minus; k >= 0; k--)
		{
			if(d_pa + 1 > 1)
				d_pa--;
			else if(d_pa + 1  == 1)
			{
				m_pa--;
				d_pa = mon1[m_pa + 1];
				}
			}*/
		printf("%d %d %d ", d_pa + 1, m_pa + 1, y_pa + 1);
		
		}
}
int main()
{
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	scanf("%d", &n);
	int tmp;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &tmp);
		solve(tmp);
		}
	return 0;
	}