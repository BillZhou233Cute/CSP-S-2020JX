#include<iostream>
using namespace std;
int a[100001],b[100001],c[100001],e[100001],d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
const int M=4713*365+4713/4+1,N=277+1582*365+1582/4;
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q,sum;
	cin>>q;
	int r1;
	for(sum=0;sum<q;sum++){
	
	cin>>r1;
	if(r1>M){
		int x1,x2,x4=1;
		r1=r1-M+365;
		if(r1>N){
			r1+=-1;
		    x1=r1/(365*400+97)*400;
			
			x1+=(r1%(365*400+97))/(365*100+24)*100;
			
			x1+=((r1%(365*400+97))%(365*100+24))/(365*4+1)*4;
			x1+=(((r1%(365*400+97))%(365*100+24))%(365*4+1))/365;
			x2=r1%365-x1/4+x1/100-x1/400-1;
		}else{
			x1=r1/(365*4+1)*4+(r1%(365*4+1))/365;
		    x2=r1%365-x1/4;
		}
		while(x2<0){
			x2+=365+!(x1%4);
		}
		if(x1%4==0){
			d[2]+=1;
			x2+=1;
		}
			int i=1;
			while(x2>d[i]&&i<12){
				x4++;
				x2-=d[i];
				i++;
			}	
			a[sum]=x2+1,b[sum]=x4,c[sum]=x1;
		   e[sum]=0;
		
	}else{
		int x1=r1/(365*4+1)*4+(r1%(365*4+1))/365;
		int x2=r1%365-x1/4-1;
		if(x1%4==0){
			d[2]+=1;
			x2+=1;
		}while(x2<0){
			x2+=365+!(x1%4);
		}
			int i=1,x4=1;
			while(x2>d[i]&&i<12){
				x4++;
				x2-=d[i];
				i++;
			}	
			a[sum]=x2+1,b[sum]=x4,c[sum]=4713-x1;
		
		e[sum]=1;
	}
	
	d[2]=28;
	
	}
	for(int i=0;i<q;i++){
		cout<<a[i]<<" "<<b[i]<<" "<<c[i];
		if(e[i]==1)cout<<" "<<"BC";
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
return 0;
}