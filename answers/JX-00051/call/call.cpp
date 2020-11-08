#include <iostream>
#include <cstdio>

using namespace std;

int n;
int m;
int a[5050505];

struct fac{
	int type,x,y;
};

fac node[5050505];
int maps[5050][5050];

void work(int num) {
/*	for (int i = 1;i <= n;i++) {
		cout << a[i] << " " ;
	}
	cout << endl;
*/	if (node[num].type == 1) {
		a[node[num].x] += node[num].y;
//		cout << "node[num].x=" << node[num].x << " node[num].y="<< node[num].y << " a[node[num].x]= " << a[node[num].x] << endl;
	}
	else if (node[num].type == 2) {
		for (int i = 1;i <= n;i++) {
			a[i] *= node[num].x;
		}
	}
	else {
		for (int i = 1;i <= node[num].x;i++) {
			work(maps[num][i]);
//			cout << node[num].x << endl;
//			cout << "  maps[num][i] = " << maps[num][i] << endl;
		}
	}
}

int main() {
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) {
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for (int i = 1;i <= m;i++) {
		int l;
		scanf("%d",&l);
		if (l == 1) {
			int q,w;
			scanf("%d%d",&q,&w);
			node[i].type = 1;
			node[i].x = q;
			node[i].y = w;
		}
		else if (l == 2) {
			int q;
			scanf("%d",&q);
			node[i].type = 2;
			node[i].x = q;
		}
		else {
			int q;
			scanf("%d",&q);
			node[i].type = 3;
			node[i].x = q;
			for (int j = 1;j <= node[i].x;j++) {
				int p;
				scanf("%d",&p);
				maps[i][j] = p;
			}
		}
	}
	int v;
	scanf("%d",&v);
	for (int i = 1;i <= v;i++) {
		int op;
		scanf("%d",&op);
		work(op);
	}
	for (int i = 1;i < n;i++) {
		printf("%d ",a[i]);
	}
	printf("%d",a[n]);
	return 0;
}