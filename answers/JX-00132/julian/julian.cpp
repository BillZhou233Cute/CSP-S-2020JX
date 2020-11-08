#include<bits/stdc++.h>
using namespace std;
long long read(){ 
	long long x = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){if(c == '-') f = -1;c = getchar();}
	while(c >= '0' && c <= '9'){x = x * 10+ c - '0',c = getchar();}
	return x * f;
}
long long n,x,a,b,c,q,y,j,d[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	n = read();
	b = 1,c = 4713;
	for(int i = 1;i <= n;i++){
		x = read() + 1;
		if(x < 30){
			printf("%lld %lld %lld BC\n",x,b,c);
			continue;
		}
		else if(x < 366){
			for(j = 1;j <= 12;j++){
				if(x <= d[j]) break;				
				x -= d[j];
			}
			printf("%lld %lld %lld BC\n",x,j,c);
			continue;
		}
		else{
			long long p = x / 365,k,l;
			x = x % 365;
			if(p > 6294) k = 1573 + ((p - 6292) / 4) - ((p - 6292 + 82) / 100) + ((p - 6292 + 382) / 400);
			else k = p / 4;
			l = k / 365;
			x = x - (k % 365);
			if(x <= 0){
				x += 365;
				l++;
			}
			p = p - l;
			for(int o = 0;o < 4;o++){
				if(p - o >= 6294){
					if(((p - o - 4712) % 4 == 0 && (p - o - 4712) % 100 != 0) || ((p - o - 4712) % 400 == 0)) x++;
				}
				else{	
					if(p < 4713){
						if((p + o - 1) % 4 == 0) x--;
					}		
			}
			}
 			if(p >= 6294){
				if(((p - 4712) % 4 == 0 && (p - 4712) % 100 != 0) || ((p - 4712) % 400 == 0)) d[2] = 29;
				else d[2] = 28;
			}
			else{	
				if(p < 4713){
					if((p - 1) % 4 == 0) d[2] = 29;
					else d[2] = 28;
				}		
				else{
					if((p - 4712) % 4 == 0) d[2] = 29;
					else d[2] = 28;
				}
			}
			for(j = 1;j <= 12;j++){
				if(x <= d[j]) break;
				x -= d[j];
			}
			if(p >= 6294){
				if(p == 6294){
					if(j == 10 && x > 4) x += 10;	
				}
				else x += 10;
			}
			if(x > d[j]){x -= d[j],j++;}
			if(j > 12){j -= 12,p++;}
			
			if(p < 4713) printf("%lld %lld %lld BC\n",x,j,4713-p);
			else printf("%lld %lld %lld\n",x,j,p - 4712);
		}
	}
	return 0;
}
