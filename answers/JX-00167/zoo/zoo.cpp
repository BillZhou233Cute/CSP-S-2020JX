#include<iostream>
#include<fstream>

using namespace std;
long long n,m,c,k,a;
long long tk[65],tot=0,fff=0;
long long ans=0,jian=0;
bool vis[66];

int main(){
	ifstream cin("zoo.in");
	ofstream cout("zoo.out");
	cin>>n>>m>>c>>k;
	tk[0]=1;
	for(long long i=1;i<=63;i++){tk[i]=tk[i-1]+tk[i-1];}
	for(long long i=1;i<=n;i++){cin>>a;
		tot|=a;
		}
	long long pp,qq;
	for(long long i=1;i<=m;i++){
		cin>>pp>>qq;
		qq=1<<pp;
		
		if(vis[pp]==0)if((tot&qq)!=qq){fff++;vis[pp]=1;}
		}
		
		for(long long i=1;i<=fff;i++){
		jian+=(tk[k-i]);	
			
		}

	ans=tk[k]-n-jian;
	cout<<ans;
		
	cin.close();
	cout.close();
return 0;
	}