#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
int year = -4713;
int m = 1;
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day = 1;
int n;
bool r;
int q;

int read()
{
    char c = getchar();
    int f = 1, res = 0;
    while(c < '0' || c > '9')
    {
        if(c == '-')
            f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res * f;
}

int main()
{
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
    q = read();
    for(int i = 1;i <= q;i++)
    {
        n = read();
        year = -4713;
        day = 1;
        m = 1;
        for(long long j = n;j >0;j--)
        {
                if(year == 1582 && m == 10 && day == 5)
				{
					day = 15;
					continue;
				}
        day ++;
        if(day > month[m])
        {
            m ++;
            day  = 1;
        }
        if(m == 13)
        {
            m = 1;
            year ++;
            if(year <= 1582 && m <= 10 && day <= 4)
                if(!year % 4)
                    month[2] = 29;
                else
                    month[2] = 28;
            else
                if(((!year % 4) && (year % 100)) || !year % 400)
                    month[2] = 29;
                else
                    month[2] = 28;
        }
		if(!year)
            year = 1;

        }
		        cout << day << " " << m << " ";
        if(year < 0)
            cout << -year << " BC" << endl;
        else
            cout << year << endl;
    }
    return 0;
}
