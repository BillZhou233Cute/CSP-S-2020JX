#include<iostream>
#include<cstdio>
using namespace std;
int q,a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++){
		int n;
		cin>>n;
		if(n<=58) n++;
		int y1=n/1461;
		n-=1461*y1;
		int y2=n/361;
		n-=365*y2;
		int ty=4*y1+y2;
		if(ty>6295){
			n+=(ty-6295)/4;
			n%=365;
		}
		if(ty>4713){
			ty++;
			for(int i=1;i<=12;i++){
				if(n>a[i]) n-=a[i];
				else{
					cout<<n<<" "<<i<<" ";
					break;
				}
			}
			cout<<ty-4713;
		}
		else{
			for(int i=1;i<=12;i++){
				if(n>a[i]) n-=a[i];
				else{
					cout<<n<<" "<<i<<" ";
					break;
				}
			}
			cout<<4713-ty<<" "<<"BC";
		}
		cout<<endl;
	}
	
	return 0;
}