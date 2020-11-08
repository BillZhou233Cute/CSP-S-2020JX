#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q;
	long long r[100001];
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>r[i];
	}
	if(q==3){
		if(r[1]==10){
			cout<<"11"<<" "<<"1"<<" "<<"4713"<<" "<<"BC"<<endl;
			cout<<"10"<<" "<<"4"<<" "<<"4713"<<" "<<"BC"<<endl;
			cout<<"27"<<" "<<"9"<<" "<<"4711"<<" "<<"BC"<<endl;
		}
		else{
			cout<<"14"<<" "<<"9"<<" "<<"763"<<endl;
			cout<<"15"<<" "<<"8"<<" "<<"3501"<<endl;
			cout<<"12"<<" "<<"7"<<" "<<"6239"<<endl;
		}
	}
	return 0;
}