#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
using namespace std;

long long n,m,k,c,ans=1,tot,sum[1000000],p[100000],q[100000],a[100000],vis[100000];
vector<long long> map[100000];

long long math(int x){
	long long mu=1,zi=1;
	for(int i=tot;i>=tot-x+1;i--) mu*=i;
	for(int i=x;i>=1;i--) zi*=i;
	return (long long)mu/zi;
}

int main(){
	ifstream fin("zoo.in");
	ofstream fout("zoo.out");
	fin>>n>>m>>c>>k;
	memset(vis,0,sizeof(vis));
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++){
		fin>>a[i];
		if(a[i] == 0)ans=0;
	}
	for(int i=1;i<=m;i++){
		fin>>p[i]>>q[i];
		vis[p[i]]=1;
		map[ q[i] ].push_back(p[i]);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if( a[i] & (1<<p[j]) ) 	{
				for(long long k=0;k<map[ q[j] ].size();k++){sum[ map[ q[j] ][k] ]=1; }
			}

	for(int i=1;i<=k;i++)	{
		if(vis[i]) if(sum[i]) tot++;
		if(!vis[i]) tot++;
	}
	for(int i=1;i<=tot;i++)	ans+=math(i);
	ans-=n;
	fout<<ans<<endl;
	fin.close();
	fout.close();
	return 0;
}