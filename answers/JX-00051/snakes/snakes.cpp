#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

int t;

struct node {
	int dis,num;
};

node a[5050505];
node b[5050505];

bool cmp(node x,node y) {
	if (x.dis == y.dis)  {
		if (x.num < y.num) return 0;
		else return 1;
	}
		else return x.dis < y.dis;
}
int n,tt;
int main() {
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&t);
	for (int i = 1;i <= t;i++) {
		
		if (i == 1) {
			
			scanf("%d",&n);
			tt = n;
			for (int j = 1;j <= n;j++) {
				scanf("%d",&a[j].dis);
				a[j].num = j;
				b[j].dis = a[j].dis;
				b[j].num = a[j].num;
			}
			while (true) {
				sort(a+1,a+n+1,cmp);
				if (n == 2 && a[n].dis >= a[1].dis) {
					n--;
					break;
				}
				if (a[n].dis - a[1].dis > a[2].dis) {
					a[1].dis = a[n].dis - a[1].dis;
					a[1].num = a[n].num;
					n--;
				}
				else if (a[n].dis - a[1].dis == a[2].dis) {
					if (a[n].num > a[2].num) {
						a[1].dis = a[n].dis - a[1].dis;
						a[1].num = a[n].num;
						n--;
					}
					else break;
				}
				else break;
			}
		}
		else {
			int k;
			scanf("%d",&k);
			n = tt;
			for (int j = 1;j <= n;j++) {
				a[j].num = b[j].num;
				a[j].dis = b[j].dis;
			}
			for (int j = 1;j <= k;j++) {
				int o,p;
				scanf("%d%d",&o,&p);
				a[o].dis = p;
			}
			
			while (true) {
				sort(a+1,a+n+1,cmp);
//				for (int j = 1;j <= n;j++) {
//					cout << a[j].dis << " " ;
//				}
//				cout << n;
//				cout << endl;
				if (n == 2 && a[n].dis >= a[1].dis) {
					n--;
					break;
				}
				if (a[n].dis - a[1].dis > a[2].dis) {
					a[1].dis = a[n].dis - a[1].dis;
					a[1].num = a[n].num;
					n--;
				}
				else if (a[n].dis - a[1].dis == a[2].dis) {
					if (a[n].num > a[2].num) {
						a[1].dis = a[n].dis - a[1].dis;
						a[1].num = a[n].num;
						n--;
					}
					else break;
				}
				else break;
			}
		}
		cout << n << endl;
	}
	return 0;
}