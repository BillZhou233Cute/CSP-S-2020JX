#include<iostream>
#include<fstream>

using namespace std;
int mth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int q,nian=-4713,yue=1,ri=1;

bool rrr1(int ni){
	if(ni<0){if((-(ni+1))%4!=0)return false;else return true;}
	if(ni>0){if(ni%4!=0)return false;else return true;}
	}

void tiao(int ni,int yn){
	if(yn>=1096)ni+=3,yn-=1096;
	if(yn>=731)ni+=2,yn-=731;
	if(yn>=366)ni+=1,yn-=366;
	nian=ni;
	if(nian>=0)nian++;
	for(int i=1;i<=12;i++){
		if(yn<0)break;
		if(i==2&&(rrr1(ni)==1)){if(yn<29){yue=2,ri=1+yn;yn-=29;}else {yn-=29;continue;}}
		if(yn<mth[i]){yue=i,ri=yn+1;yn-=mth[i];}else{yn-=mth[i];}
		}
	
	}

	
int main(){
	ifstream cin("julian.in");
	ofstream cout("julian.out");
	cin>>q;
	int n;
	int chu=-4713;
	for(int i=1;i<=q;i++){
		cin>>n;
		chu=-4713;
		
			chu=chu+4*(n/1461);
			n=n%1461;
			tiao(chu,n);
			if(nian<0){nian=-nian;
			cout<<ri<<' '<<yue<<' '<<nian<<' '<<"BC"<<endl;}else{cout<<ri<<' '<<yue<<' '<<nian<<' '<<endl;}
			
		
		}
	cin.close();
	cout.close();
		
	return 0;
	}