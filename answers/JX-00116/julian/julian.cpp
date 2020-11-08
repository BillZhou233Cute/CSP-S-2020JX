#include <iostream>
#include <cstdio>

using namespace std;

int q, r, year, month, day;
bool neg = true;

int main()
{
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	cin >> q;
	while (q--)
	{
		cin >> r;
		year = 4713;
		month = 1;
		day = 1;
		while (year > 0)
		{
			if ((year - 2) % 4 == 0)
			{
				if (r >= 366)
				{
					year--;
					r -= 366;
				}
				else break;
			}
			else
			{
				if (r >= 365)
				{
					year--;
					r -= 365;
				}
				else break;
			}
		}
		if (year <= 0)
		{
			year = -year;
			month = 12;
			day = 31;
			if (r <= 577737)
			{
				while (r > 0)
				{
					if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
					{
						if (day < 31)
						{
							day++;
						}
						else
						{
							if (month == 12)
							{
								month = 1;
								year++;
							}
							else month++;
							day = 1;
						}
					}
					else if (month == 4 || month == 6 || month == 9 || month == 11)
					{
						if (day < 30)
						{
							day++;
						}
						else
						{
							month++;
							day = 1;
						}
					}
					else
					{
						if (year % 4 == 0)
						{
							if (day < 29)
							{
								day++;
							}
							else
							{
								month++;
								day = 1;
							}
						}
						else
						{
							if (day < 28)
							{
								day++;
							}
							else
							{
								month++;
								day = 1;
							}
						}
					}
					r--;
				}
			}
			else
			{
				year = 1582;
				month = 10;
				day = 14;
				r -= 577737;
				while (r > 0)
				{
					if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
					{
						if (day < 31)
						{
							day++;
						}
						else
						{
							if (month == 12)
							{
								month = 1;
								year++;
							}
							else month++;
							day = 1;
						}
					}
					else if (month == 4 || month == 6 || month == 9 || month == 11)
					{
						if (day < 30)
						{
							day++;
						}
						else
						{
							month++;
							day = 1;
						}
					}
					else
					{
						if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
						{
							if (day < 29)
							{
								day++;
							}
							else
							{
								month++;
								day = 1;
							}
						}
						else
						{
							if (day < 28)
							{
								day++;
							}
							else
							{
								month++;
								day = 1;
							}
						}
					}
					r--;
				}
			}
			cout << day << ' ' << month << ' ' << year << endl;
		}
		else
		{
			while (r > 0)
			{
				if (day > 1)
				{
					day--;
				}
				else
				{
					if (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11)
					{
						month--;
						day = 31;
					}
					else if (month == 1)
					{
						month = 12;
						day = 31;
						year--;
					}
					else if (month == 5 || month == 7 || month == 10 || month == 12)
					{
						month--;
						day = 30;
					}
					else if (month == 3)
					{
						if ((year - 1) % 4 == 0)
						{
							month--;
							day = 29;
						}
						else
						{
							month--;
							day = 28;
						}
					}
				}
				r--;
			}
			cout << day << ' ' << month << ' ' << year << " BC" << endl;
		}
	}
	return 0;
}
