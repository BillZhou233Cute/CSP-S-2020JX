#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
long long n,m,c,k,cz,ans,a,b,f;
int ani[1000005];
int pd[65],p[65];

int main(){
	ifstream cin("zoo.in");
	ofstream cout("zoo.out");
		cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++) cin>>ani[i];	
		for(int i=1;i<=n;i++){
			b=ani[i];
			for(int j=63;j>=0;j--){
				if(b>=pow(2,j)){b=b-pow(2,j);p[j]=1;}
			}
		}
		for(int i=1;i<=m;i++){
			cin>>a>>b;
			if(p[a]==0) {
				pd[b]==1;
				cz++;
			}
		}
		for(int i=k-1;i>=0;i++){
				if(pd[i]==1) f=i;
		}
		if(f!=(k-1)) ans=pow(2,(k-cz))-n-pow(2,f);
		else ans=pow(2,(k-cz))-n;
		cout<<ans<<'\n';
		cin.close();
		cout.close();
		return 0;
	}