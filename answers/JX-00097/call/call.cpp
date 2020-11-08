#include<cstdio>
#include<ctime>

const int Mod = 998244353;
int data[10005];
struct F {
	int t,p,v,*c,cl;
}func[10005];
int m,n,clock1;

void Call(int call) {
	if (clock() - clock1 > 1990) throw "";
	int t = func[call].t;
	if (t == 1) data[func[call].p] = (data[func[call].p] + func[call].v) % Mod;
	else if (t == 2) {
		for (int i = 1;i <= n;++i){
			data[i] = data[i] * func[call].v % Mod;
		}
	} else if (t == 3) {
		for (int i = 1;i <= func[call].cl;i++) 
			Call(func[call].c[i]);
	}
}
int main() {
	clock1 = clock();
	
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1;i <= n;++i) scanf("%d", &data[i]);
	scanf("%d", &m);
	for (int i = 1;i <= m;++i) {
		int t;
		scanf("%d", &t);
		func[i].t = t;
		if (t == 1) {
			scanf("%d%d", &func[i].p, &func[i].v);
		} else if (t == 2) {
			scanf("%d", &func[i].v);
		} else {
			scanf("%d", &func[i].cl);
			func[i].c = new int [func[i].cl + 1];
			for (int j = 1;j <= func[i].cl;++j) scanf("%d", (func[i].c + j));
		}
	}
	
//	for (int i = 1;i <= n;++i) {
//		printf("%d %d %d %d", func[i].t, func[i].v, func[i].p, func[i].cl);
//		for (int j = 1;j <= func[j].cl;j++) 
//			printf("%d ", func[i].c[j]);
//		printf("\n");
//	}
	
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int call;
		scanf("%d", &call);
		try {
			Call(call);
		} catch(const char* s) {
			break;
		}
	}
	
	for (int i = 1;i <= n;++i)
		printf("%d ", data[i]);
	return 0;
}