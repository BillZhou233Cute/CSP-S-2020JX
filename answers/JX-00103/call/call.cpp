#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
const int  mod=998244353;

struct state{
	long long add,num,mul,t;
	vector<int> use;
};

state f[100010];
int n,m,a[100010],abc,Q,now,A,T;

void judge(int x){
	if(f[x].t ==1) a[f[x].num]=(a[f[x].add]+f[x].add)%mod;
	if(f[x].t ==2) {
		for(int i=1;i<=n;i++) a[i]=(a[i]*f[x].mul)%mod;}
	if(f[x].t ==3){
		for(int i=0;i<f[x].use.size();i++) judge(f[x].use[i]);
		}
		return;
}

int main(){
	ifstream fin("call.in");
	ofstream fout("call.out");
	fin>>n;
	for(int i=1;i<=n;i++) fin>>a[i];
	fin>>m;
	for(int i=1;i<=m;i++){
		fin>>T;f[i].t=T;
		if(T == 1)	cin>>f[i].num>>f[i].add;
		if(T == 2) cin>>f[i].mul;
		if(T == 3){
			fin>>abc;
			for(int j=1;j<=abc;j++){
				fin>>A;
				f[i].use.push_back(A);
			}
		}
	}
	fin>>Q;
	for(int i=1;i<=Q;i++){
		cin>>now;
		if(f[now].t==1)judge(now);
		if(f[now].t==2)judge(now);
		if(f[now].t==3){
			for(int j=0;j<f[now].use.size();j++){
				judge(f[now].use[j]);
			}
		}
	}
	
	for(int i=1;i<=n;i++) fout<<a[i]<<' ';
		fout<<endl;
		fin.close();
		fout.close();
		return 0;
}