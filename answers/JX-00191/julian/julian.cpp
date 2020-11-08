#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
#define ll long long
int temp[123]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	ll n;
	cin>>n;
	while(n--){
	    int t=4713;
		 ll d;
		bool f;
		int yue=1,ri=1;
		scanf("%lld",&d);
	    if(d<=1721424) {
			while(1){
			  f=(t-1)%4;
			 if(f&&d-365<0) {
				 for(int i=1;i<=12;++i){
					  if(d-temp[i]>=0){
						   yue++;
						  }
						  else {
							  ri+=d;
							  break;
							  }
							  d-=temp[i];
					 }
					 break;
			}
			 if(!f&&d-366<0) {
				 for(int i=1;i<=12;++i){
					  if((d-temp[i]>=0&&i!=2)||(d-temp[i]-1>=0&&i==2)){
						   yue++;
						  }
						  else {
							  ri+=d;
							  break;
							  }
							  d-=temp[i];
							  if(i==2) d--;
					 }
					 break;
			}
			 t--;
			 d-=365;
			 if(!f) d--;
			 if(t==0) break;
			}
					printf("%d %d %d BC\n",ri,yue,t);
			}
			else if(d<=2298884){
				 d-=1721424;
				 t=1;
					while(1){
			        f=t%4;
			      if(f&&d-365<0) {
				 for(int i=1;i<=12;++i){
					  if(d-temp[i]>=0){
						   yue++;
						  }
						  else {
							  ri+=d;
							  break;
							  }
							  d-=temp[i];
					 }
					 break;
			}
			 if(!f&&d-366<0) {
				 for(int i=1;i<=12;++i){
					  if((d-temp[i]>=0&&i!=2)||(d-temp[i]-1>=0&&i==2)){
						   yue++;
						  }
						  else {
							  ri+=d;
							  break;
							  }
							  d-=temp[i];
							  if(i==2) d--;
					 }
					 break;
			}
			 t++;
			 d-=365;
			 if(!f) d--;
			 }
			printf("%d %d %d \n",ri,yue,t);
			}
			else {
				yue=1;
				ri=1;
				t=1582;
				d-=2298884;
				 d+=365;
				 for(int i=1;i<=12;++i){
					  if(i!=10){
					  if(d-temp[i]>=0){
						   yue++;
						  }
						  else {
							  ri+=d;
							  break;
							  }
							  d-=temp[i];}
							else {
								if(d-21>=0) {
									yue++;
									}
									else {
										ri+=d-10;
										break;
										}
										d-=21;
								}
					 }
					 if(d<=0) {printf("%d %d %d \n",ri,yue,t);}
					 else {
						 yue=1;
						 ri=1;
				while(1){
			if(!(t%400)||(!(t%4)&&(t%100))) f=0;
			else f=1;
			 if(f&&d-365<0) {
				 for(int i=1;i<=12;++i){
					  if(d-temp[i]>0){
						   yue++;
						  }
						  else {
							  ri+=d;
							  break;
							  }
							  d-=temp[i];
					 }
					 break;
			}
			 if(!f&&d-366<0) {
				 for(int i=1;i<=12;++i){
					  if((d-temp[i]>0&&i!=2)||(d-temp[i]-1>0&&i==2)){
						   yue++;
						  }
						  else {
							  ri+=d;
							  break;
							  }
							  d-=temp[i];
							  if(i==2) d--;
					 }
					 break;
			}
			 t++;
			 d-=365;
			 if(!f) d--;
			}
			}
					printf("%d %d %d \n",ri,yue,t);
		}
		}
		//nmsl
		return 0;
}