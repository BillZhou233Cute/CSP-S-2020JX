#include <cstdio>
#include <cstdlib>
using namespace std;
int q;
int n;
int y,m,d;
bool run;
const int yue[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main() {
    freopen("julian.in", "r", stdin);
    freopen("julian.out", "w",stdout);
    scanf("%d", &q);
    for (int i = 1;i <= q;i++) {
        scanf("%d", &n);
        if (n >= 2299209) {
            n -= 2299209;
            y = 1582;
            if (n < 78) {
                m = 10;
                if (n < 18) d = 15+n;
                else {
                    while (yue[m] <= n) {
                        n -= yue[m++];
                    }
                }
            }
            else {
                y = 1583;n -= 78;
            }
            printf("%d %d %d\n", d, m, y);
        }
        else if (n >= 1721424) {
            n -= 1721424;
            y = 1;
            y += (n/1461)*4;n %= 1461;
            if (n <= 1095) {run = 0;y += ((n-1) / 365);n %= 365;}
            else {run = 1;y+=3;n %= 1095;}
            m = 1;
            while (yue[m] <= n) {
                if (run && m == 2) {n -= yue[m++]+1;}
                n -= yue[m++];
            }
            d = n+1;
            printf("%d %d %d\n", d, m, y);
        }
        else {
            y = -4713;
            y += (n/1461)*4;n %= 1461;
            if (n > 366) {run = 0;y += ((n-1) / 365);n = (n-1) % 365;}
            else run = 1;
            m = 1;
            while (yue[m] <= n) {
                if (run && m == 2) {n -= yue[m++]+1;}
                n -= yue[m++];
            }
            d = n+1;
            printf("%d %d %d BC\n", d, m, abs(y));
        }
    }
    fclose(stdin);fclose(stdout);
    return 0;
}           
