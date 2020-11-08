#include<bits/stdc++.h>
using namespace std;
int T,r,p,k,year,month,day,AG;
int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&T);
	p=273+1574+6294*365;
	k=4712*365+1178;
	AG=400*365+97;
	while(T--) {
		scanf("%d",&r);
		if(r<p) {
			if(r<k) {
				year=r/1441*4;
				r%=1441;
				if(r>=366) year++,r-=366;
				year+=r/365;
				r%=365;
				year=4713-year;
				if(((year)%4)==1) m[2]++;
				int res=0;
				month=1;
				for(int i=1;i<=12;i++) if(r<m[i]) break;else r-=m[i],month++;
				if((year%4)==1) m[2]--;
				printf("%d %d %d BC\n",r+1,month,year);
			}
			else {
				r-=k;
				year=r/1461*4;
				r%=1461;
				if(r>=366) year++,r-=366;
				year+=r/365,r%=365;
				if((year%4)==1) m[2]++;
				int res=0;
				month=1;
				for(int i=1;i<=12;i++) if(r<m[i]) break;else r-=m[i],month++;
				if((year%4)==1) m[2]--;
				printf("%d %d %d\n",r+1,month,year);
			}
		}
		else {
			r-=p;
			r+=10;
			if(r<17) printf("%d 10 1582\n",15+r);
			else {
				r-=17;
				if(r>=61) {
					r-=61;
					year=1583+r/AG*400;
					r%=AG;
					year+=r/(100*365+24)*100;
					r%=(100*365+24);
					year+=r/(4*365+1)*4;
					r%=(4*365+1);
					if(r<365) {
						if(((year%4)==1&&(year%100)!=1)||(year%400)==0) m[2]++;
						int res=0;
						month=1;
						for(int i=1;i<=12;i++) if(r<m[i]) break;else r-=m[i],month++;
						if((year%4)==1) m[2]--;
						printf("%d %d %d\n",r+1,month,year);
					}
					else {
						if(r>=366) {
							r-=366,year++;
							year+=r/365,r%=365;
							if(((year%4)==1&&(year%100)!=1)||(year%400)==0) m[2]++;
							int res=0;
							month=1;
							for(int i=1;i<=12;i++) if(r<m[i]) break;else r-=m[i],month++;
							if((year%4)==1) m[2]--;
							printf("%d %d %d\n",r+1,month,year);
						}
						else {
							if(((year%4)==1&&(year%100)!=1)||(year%400)==0) m[2]++;
							int res=0;
							month=1;
							for(int i=1;i<=12;i++) if(r<m[i]) break;else r-=m[i],month++;
							if((year%4)==1) m[2]--;
							printf("%d %d %d\n",r+1,month,year);
						}
					}
				}
				else {
					if(r<30) printf("%d 11 1582\n",r+1);
					else r-=30,printf("%d 12 1582\n",r+1);
				}
			}
		}
	}
	return 0;
}
