#include<iostream>
#include<fstream>
#include<vector>
#define ull unsigned long long
using namespace std;
const long long maxn=1000010;
unsigned long long n,m,c,k,a[maxn],A,p[maxn],q[maxn],sum;
ull boo[2000000];
bool _c[100000000];
vector <ull> vec[65];
//inline ull getb(int x){
//	if(boo[x/64]&(1<<(x%64))) return 1;
//		else return 0;
//}
int main(){
	ifstream cin("zoo.in");
	ofstream cout("zoo.out");
	cin>>n>>m>>c>>k;
	for(ull i=1;i<=n;i++){
		cin>>a[i];
		A=A|a[i];
	}
	ull A0=A;
	while(A0){
		A0/=2;
		while(A0%2==0&&A0) A0/=2;
		sum++;
	}
	sum=1<<sum;
	cout<<sum-n<<endl;
	/*for(ull i=1;i<=m;i++){
		cin>>p[i]>>q[i];
		if((1<<(p[i]-1))&A) _c[q[i]]=true;//含第p[i]位的动物需要的饲料q[i]有了
		vec[p[i]].push_back(q[i]);
	}
	for(ull i=1;i<=k;i++){
		for(ull j=0;j<vec[i].size();j++){
			if(!_c[vec[i][j]]) {sum++;cout<<"第"<<i<<"位"<<endl;break;}//不能找到饲料的位置的个数
		}
	}
	sum=k-sum;
	ull ans=(1<<sum)-n;
	cout<<ans;*/
	return 0;
}