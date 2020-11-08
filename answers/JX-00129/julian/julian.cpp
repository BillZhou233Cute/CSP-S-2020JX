#include<cstdio>
#define y4 1461
#define gl 2299249
#define gy 1721424
#define ri register int
inline int read(){
	ri x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int print(ri r,ri m,ri year,ri f){
	if(f)	printf("%d %d %d BC\n",r,m,year);
	else printf("%d %d %d\n",r,m,year); 
	return 0;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	ri q=read();
	while(q--){
		ri r=read();
		if(r<gy){
			ri year=4713-(r/y4)*4,flag=0;
			if(r>=y4) r-=(r/y4)*y4;
			if(r>=366) year--,r-=366;
			if(r<365) flag=1;
			year-=(r/365),r%=365;
			ri m=1;
			while(r>=28&&m<=12){
				if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&r>=31) m++,r-=31;
				if(m==2&&flag&&r>=29) m++,r-=29;
				if(m==2&&!flag&&r>=28) m++,r-=28;
				if((m==4||m==6||m==9||m==11)&&r>=30) m++,r-=30;
				if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&r<31) break;
				if((m==4||m==6||m==9||m==11)&&r<30) break;
			}
			print(r+1,m,year,1);
		}
		else if(r>=gy&&r<=gl){
			r-=gy,r++;
			ri year=r/y4*4,flag=0;
			if(r>=y4) r-=r/y4*y4;
			if(r>=365&&r<1461) year+=r/365,r-=r/365*365;
			if(year%4==0) flag=1;
			ri m=1;
			while(r>=28&&m<=12){
				if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&r>=31) m++,r-=31;
				if(m==2&&flag&&r>=29) m++,r-=29;
				if(m==2&&!flag&&r>=28) m++,r-=28;
				if((m==4||m==6||m==9||m==11)&&r>=30) m++,r-=30;
				if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&r<31) break;
				if((m==4||m==6||m==9||m==11)&&r<30) break;
			}
			print(r,m,year+1,0);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}