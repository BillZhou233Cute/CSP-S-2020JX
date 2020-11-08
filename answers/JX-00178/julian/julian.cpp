#include <bits/stdc++.h>
#include<cstdio>
using namespace std;
const int bc = 1721058;
const int julian =574815;
const int fy = 1461;
int ye[4]={366,365,365,365};
int yy[4]={365,365,365,366};
int mo1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int mo2[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int q,r;

void dealwith(int x){
	int d,m=1,y=0;
	if(x<=bc){
		y+=4*(x/fy);
		x%=fy;
		int k=0;
		x-=ye[k];
		while(x>0){
			k++;
			y++;
			x-=ye[k];
		}
		x+=ye[k];
		if(ye[k]==366){
			x++;
			int l=0;
			x-=mo2[l];
			while(x>0){
				l++;
				m++;
				x-=mo2[l];
			}
		    x+=mo2[l];
			d=x;
			printf("%d %d %d BC\n",d,m,4713-y);
			return;
		}
	    else{
			x++;
			int l=0;
			x-=mo1[l];
			while(x>0){
				l++;
				m++;
				x-=mo1[l];
			}
		    x+=mo1[l];
			d=x;
			printf("%d %d %d BC\n",d,m,4713-y);
			return;
		}
	}
	if(x<=julian+bc){
		x-=bc;
		y+=4*(x/fy);
		x%=fy;
		int k=0;
		x-=yy[k];
		while(x>0){
			k++;
			y++;
			x-=yy[k];
		}
		x+=yy[k];
		if(yy[k]==366){
			x++;
			int l=0;
			x-=mo2[l];
			while(x>0){
				l++;
				m++;
				x-=mo2[l];
			}
		    x+=mo2[l];
			d=x;
			printf("%d %d %d\n",d,m,y);
			return;
		}
	    else{
			x++;
			int l=0;
			x-=mo1[l];
			while(x>0){
				l++;
				m++;
				x-=mo1[l];
			}
		    x+=mo1[l];
			d=x;
			printf("%d %d %d\n",d,m,y);
			return;
		}
	}
}

int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	while(q--){
		scanf("%d",&r);
		dealwith(r);
	}
	return 0;
}	
