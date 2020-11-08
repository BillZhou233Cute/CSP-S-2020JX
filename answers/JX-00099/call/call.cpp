#include <stdio.h>
#include <vector>
using namespace std;

#define MAXN 10003
#define MOD 998244353

int N, A[MAXN], M, U[MAXN], Q, C, Tmp, PtrP = 0, PtrM = 0, PtrC = 0, i, j, Buffer = 1, LastOp = 0;

struct Func {
	int type, ptr;
} F[MAXN];

struct Plus {
	int p, v;
} P[MAXN];

vector<int> L[MAXN];
vector<int> seq;

int main() {
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		scanf("%d", &A[i]);
	scanf("%d", &M);
	for (i = 1; i <= M; i++) {
		scanf("%d", &F[i].type);
		switch (F[i].type) {
			case 1:
				scanf("%d%d", &P[PtrP].p, &P[PtrP].v);
				F[i].ptr = PtrP++;
				break;
			case 2:
				scanf("%d", &U[PtrM]);
				F[i].ptr = PtrM++;
				break;
			case 3:
				scanf("%d", &C);
				while (C--) {
					scanf("%d", &Tmp);
					L[PtrC].push_back(Tmp);
				}
				F[i].ptr = PtrC++;
				break;
		}
	}
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d", &Tmp);
		if (F[Tmp].type != 3)
			seq.push_back(Tmp);
		else
			for (i = 0; i < (int)L[F[Tmp].ptr].size(); i++)
				seq.push_back(L[F[Tmp].ptr][i]);
	}
	for (i = 0 ; i < (int)seq.size(); i++) {
		if (F[seq[i]].type == 2) {
			if (LastOp == 2)
				Buffer = (Buffer * U[F[seq[i]].ptr]) % MOD;
			else
				Buffer = U[F[seq[i]].ptr] % MOD;
		}
		else {
			if (LastOp == 2) {
				for (j = 1; j <= N; j++)
					A[j] = (A[j] * Buffer) % MOD;
				Buffer = 1;
			}
			A[P[F[seq[i]].ptr].p] = (A[P[F[seq[i]].ptr].p] + P[F[seq[i]].ptr].v) % MOD;
		}
		LastOp = F[seq[i]].type;
	}
	for (i = 1; i <= N; i++)
		printf("%d ", Buffer == 1 ? A[i] : (A[i] * Buffer) % MOD);
	printf("\n");
	return 0;
}

