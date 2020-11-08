#include<iostream>
#include<fstream>

using namespace std;

int T,n,a[2010],k,sa=0;

int main(){
	ifstream cin("snakes.in");
	ofstream cout("snakes.out");
	int xx,yy;
	cin>>T;
	for(int j=1;j<=T;j++){
	if(j==1){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		}	else{
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>xx>>yy;
			a[xx]=yy;
			}
		}
		if(n==3){
			if(a[3]-a[1]>=a[2])cout<<1<<endl;else{cout<<3<<endl;}
			continue;
			}
		
		
	}
	cin.close();
	cout.close();
	
return 0;
}