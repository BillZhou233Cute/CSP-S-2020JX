#include <iostream>
#include <cstdio>
using namespace std;

int days[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, ydays = 365;
long long JDays = 2299160;
long long Q, r;
long long y = -4713 + 1, m = 1, d = 1;
long long dc, tmp;
bool BC, ln;

void julian()
{
	cin >> r;
	//如果是儒略历
	if(r <= JDays)
	{	
		//常量值初始化
		y = -4713 + 1, m = 1, d = 1;

		while(r > 0)
		{
			//润年处理
			ln = ((y % 4) == 0);
			if(ln && m == 1 && d == 1)
			{
				ydays = 1461;
				tmp = r / ydays;
				if(tmp > 0)
				{
					y += tmp * 4;
					r -= tmp * ydays;
					continue;
				}
			}

			if(m == 1 && d == 1)
			{
				ydays = 365;
				if(ln) ydays++;
				if(r >= ydays)
				{
					y++;
					r -= ydays;
					continue;
				}
			}

			if(ln && m == 2)
				days[2] = 29;
			else
				days[2] = 28;

			dc = days[m] - d + 1;
			//距离下月的天数
			tmp = r - dc;
			//如果剩下天数r足以到达下个月
			if(tmp >= 0)
			{
				//扣除相应天数
				r = tmp;
				//月份+1
				m++;
				//日期设为1
				d = 1;
				if(m > 12)
				{
					m = 1;
					y++;
				}
			}
			//如果剩下天数r不足到达下个月
			else
			{
				d += r;
				r = 0;
			}
		}
		//DEBUG
		//cout << "Julian ";
	}
	else
	{
		//常量值初始化
		y = 1582, m = 10, d = 15;
		r -= JDays + 1;

		while(r > 0)
		{
			//润年处理
			ln = ((y % 400) == 0 || ((y % 4) == 0 && (y % 100) != 0));

			if(m == 1 && d == 1)
			{
				ydays = 365;
				if(ln) ydays++;
				if(r >= ydays)
				{
					y++;
					r -= ydays;
					continue;
				}
			}

			if(ln && m == 2)
				days[2] = 29;
			else
				days[2] = 28;

			dc = days[m] - d + 1;
			//距离下月的天数
			tmp = r - dc;
			//如果剩下天数r足以到达下个月
			if(tmp >= 0)
			{
				//扣除相应天数
				r = tmp;
				//月份+1
				m++;
				//日期设为1
				d = 1;
				if(m > 12)
				{
					m = 1;
					y++;
				}
			}
			//如果剩下天数r不足到达下个月
			else
			{
				d += r;
				r = 0;
			}
		}

	}


	BC = (y <= 0);
	if(BC) y = -(y - 1);
	cout << d << " " << m << " " << y;
	if(BC) cout << " BC";
	cout << endl;
}

int main()
{
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	cin >> Q;
	for(long long i = 1; i <= Q; i++)
	{
		julian();
	}
	return 0;
}
