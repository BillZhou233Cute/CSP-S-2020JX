#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 1582 + 4712;
int r;
int d,m,y;
int q;
int y1 = 365*3+366;
int mon1[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int mon2[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};

int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d",&r);
		d = 1,m = 1,y = 4712;
		int yx1 = r / y1 * 4,mx;
		r %= y1;
		if(r > y1 - 365) yx1+= 3,r -= y1 - 365;
		else if(r > y1 - 2 * 365) yx1 += 2, r -= y1 - 2 * 365;
		else if(r > y1 - 3 * 365) yx1 += 1,r -= y1 - 3 * 365;
		y -= yx1;
		if(y >= 0){
			if(y % 4 == 0){
				for(int i=1;i<=12;i++){
					if(r - mon2[i] < 0) {mx = i;break;}
					r -= mon2[i];
				}
			}
			else{
				for(int i=1;i<=12;i++){
					if(r - mon1[i] < 0) {mx = i;break;}
					r -= mon1[i];
				}
			}
			printf("%d %d %d BC\n",d+r,mx,y+1);
		}
		else {
			y = -y;
			if(y % 4 == 0){
				for(int i=1;i<=12;i++){
					if(r - mon2[i] < 0) {mx = i;break;}
					r -= mon2[i];
				}
			}
			else{
				for(int i=1;i<=12;i++){
					if(r - mon1[i] < 0) {mx = i;break;}
					r -= mon1[i];
				}
			}
			printf("%d %d %d BC\n",d+r,mx,y);
		}
	}
	return 0;
}