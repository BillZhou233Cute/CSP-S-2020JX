#include <bits/stdc++.h>
using namespace std;
long long a[100001], m, T[100001], q, nw, P[100001], V[100001];
long long q1, q2, q3[110][110], c[100001], n;
void add(int p, int num)
{
    a[p] += num;
}
void tim(int num)
{
    for(int i = 1; i <= n; i++)
        a[i] *= num;
}
void diao(int nw)
    {
        if(T[nw] == 1)
            add(P[nw], V[nw]);
        if(T[nw] == 2)
            tim(V[nw]);
        if(T[nw] == 3)
        {
            for(int i = 1; i <= c[nw]; i++)
                diao(q3[nw][i]);
        }
        for(int i = 1; i <= n; i++)
        {
            a[i] %= 998244353;
        }
    }
int main()
{
    freopen("call.in", "r", stdin);
    freopen("call.out", "w", stdout);
    cin >> n;
    for(int i = 1; i  <= n; i++)
        cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> T[i];
        if(T[i] == 1)
            cin >> P[i] >> V[i];
        if(T[i] == 2)
            cin >> V[i];
        if(T[i] == 3)
        {
            cin >> c[i];
            for(int j = 1; j <= c[i]; j++)
                cin >> q3[i][j];
        }
    }
    cin >> q;
    for(int i = 1;i <= q; i++)
    {
        cin >> nw;
        diao(nw);
    }
    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}
