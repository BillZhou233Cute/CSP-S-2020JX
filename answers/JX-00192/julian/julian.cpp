#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull q, r, m, d, tmp1, tmp2;
ll y;

inline ull getMonthDay(ull month, ull yearDate)
{
    switch (month)
    {
        case 1: return 31; break;
        case 3: return 31; break;
        case 5: return 31; break;
        case 7: return 31; break;
        case 8: return 31; break;
        case 12: return 31; break;
        case 4: return 30; break;
        case 6: return 30; break;
        case 9: return 30; break;
        case 11: return 30; break;
        case 2: return ((yearDate == 366)? 29: 28); break;
        case 10: return ((yearDate == 355)? 21: 31); break;
    }
}

int main()
{
    // This is CSP-S 2020 T1 by BillZhou233
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("julian.in", "r", stdin);
    freopen("julian.out", "w", stdout);
    cin >> q;
    for (register ull i = 0; i < q; ++i)
    {
        cin >> r;
        if (r < 1721424)
        {
            y = 4712;
            if (r >= 1461)
            {
                y -= (r / 1461) * 4;
                r %= 1461;
            }
            tmp1 = 366;
            if (r >= tmp1)
            {
                --r;
                y -= (r / 365);
                r %= 365;
                tmp1 = 365;
            }
            y = 0 - 1 - y;
        }
        else if (r < 2298884)
        {
            y = 1;
            r -= 1721424;
            if (r >= 1461)
            {
                y += (r / 1461) * 4;
                r %= 1461;
            }
            tmp1 = 365;
            if (r >= 1095)
            {
                y += 3;
                r %= 365;
                tmp1 = 366;
            }
            else if (r > 365)
            {
                y += (r / 365);
                r %= 365;
            }
        }
        else if (r < 2299239)
        {
            y = 1582;
            r -= 2298884;
            tmp1 = 355;
        }
        else if (r < 2305448)
        {
            y = 1583;
            r -= 2299239;
            if (r >= 1461)
            {
                y += (r / 1461) * 4;
                r %= 1461;
            }
            tmp1 = 365;
            if (r > 731)
            {
                --r;
                y += (r / 365);
                r %= 365;
            }
            else if (r > 365)
            {
                ++y;
                r -= 365;
                tmp1 = 366;
            }
        }
        else
        {
            y = 1600;
            r -= 2305448;
            if (r >= 146097)
            {
                y += (r / 146097) * 400;
                r %= 146097;
            }
            if (r >= 36525)
            {
                --r;
                y += (r / 36524) * 100;
                r %= 36524;
            }
            tmp1 = (y % 400)? 1460: 1461;
            if (r >= tmp1)
            {
                if (tmp1 == 1460) ++r;
                y += (r / 1461) * 4;
                r %= 1461;
            }
            tmp1 = (((y % 100) == 0) && (y % 400))? 365: 366;
            if (r >= tmp1)
            {
                if (tmp1 == 366) --r;
                y += (r / 365);
                r %= 365;
                tmp1 = 365;
            }
        }
        m = 1;
        tmp2 = getMonthDay(m, tmp1);
        while (r >= tmp2)
        {
            r -= tmp2;
            tmp2 = getMonthDay(++m, tmp1);
        }
        d = r + 1;
        if (y == 1582 && m == 10 && d > 4) d += 10;
        if (y > 0) cout << d << " " << m << " " << y << endl;
        else cout << d << " " << m << " "  << 0 - y << " BC" << endl;
    }
    fclose(stdin); fclose(stdout);
    return 0;
}
