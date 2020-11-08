#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

struct bb{
	long long s,wei;
	long long  zhi;
	vector<long long > diao;
	}b[100010];

long long n,m,q,a[100010];

	
void use(long long  iq){
	if(b[iq].s==1){a[b[iq].wei]+=b[iq].zhi;}
	if(b[iq].s==2)for(long long  i=1;i<=n;i++)a[i]*=b[iq].zhi;
	if(b[iq].s==3){
		for(long long  i=0;i<b[iq].diao.size();i++){
			use(b[iq].diao[i]);
			}
		}
	
}
	
	
	
int main(){
	ifstream cin("call.in");
	ofstream cout("call.out");
	cin>>n;
	for(long long  i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	long long  sub,bu,kk;
	for(long long  i=1;i<=m;i++){
		cin>>sub>>bu;
		if(sub==3){
			b[i].s=3;
			for(long long  j=1;j<=bu;j++){
				cin>>kk;
				b[i].diao.push_back(kk);
				}
			}else{
				if(sub==2){
				b[i].s=sub;
				b[i].zhi=bu;}else{
					cin>>kk;
					b[i].s=sub;
					b[i].wei=bu;
					b[i].zhi=kk;
					}
				}
		}
	cin>>q;
		long long  iq;
	for(long long  i=1;i<=q;i++){
		cin>>iq;
		use(iq);
		}
	for(long long i=1;i<=n;i++)cout<<a[i]<<' ';
	
	cin.close();
	cout.close();
	
	return 0;
	}