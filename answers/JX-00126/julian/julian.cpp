#include <cstdio>
#include <cmath>

long long date, apyear, year, month, day, days1[] = {0,31,28,31,30,31,30,31,31,30,31,30,31}, days2[]  = {0,31,29,31,30,31,30,31,31,30,31,30,31}, days3[] = {0,31,28,31,30,31,30,31,31,30,21,30,31};
int q;

bool judge(int y) {
    if (y > 0) {
        if (y <= 1582) {
            if (y % 4 == 0) return true;
            else return false;
        } else {
            if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) return true;
            else return false;
        }
    } else {
        if ((-y) % 4 == 1) return true;
        else return false;
    }
}

int main() {
    freopen("julian.in", "r", stdin);
    freopen("julian.out", "w", stdout);
    
    scanf("%d", &q);
    while (q--) {
        scanf("%lld", &date);
        
        apyear = floor(date / 366);
        if (-4713 + apyear >= 0) apyear++;
        for (int i = -4713; i <= -4713 + apyear - 1; i++) {
            if (i == 0) continue;
            if (i == 1582) date -= 355;
            else if(judge(i)) date -= 366;
            else date -= 365;
        }
        
        month = 1;
        year = apyear-4713;
        day = 1;
        while (date > 0) {
            if (year == 1582) {
                if (date >= days3[month]) date -= days3[month], month++;
                else {
                    day = date+1;
                    break;
                }
            } else if (judge(year)) {
                if (date >= days2[month]) date -= days2[month], month++;
                else {
                    day = date+1;
                    break;
                }
            } else {
                if (date >= days1[month]) date -= days1[month], month++;
                else {
                    day = date+1;
                    break;
                }
            }
            
            if (month == 13) {
                month = 1;
                year++;
            }
            if (year == 0) year++;
        }
        
        if (year < 0) printf("%lld %lld %lld BC\n", day, month, -year);
        else printf("%lld %lld %lld\n", day, month, year);
    }
    
    return 0;
}