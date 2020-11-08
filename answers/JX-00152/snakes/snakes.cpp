#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t;
	int n;
	cin>>t;
	t-=1;
	int a,b,c;
	int an,bn,cn;
	int ai,bi,ci;
	cin>>n;
	cin>>a>>b>>c;
	while(t--){
		if(n==3){
			cin>>n;
			cin>>ai>>an>>bi>>bn>>ci>>cn;
                        if(a>b+c){
                                cout<<1<<endl;
      			}else if(b>a+c){
				cout<<1<<endl;
			}else if(c>a+b){
				cout<<1<<endl;
			}else{
				cout<<3<<endl;
			}
			if(an>bn+cn){
				cout<<1<<endl;
			}else if(bn>an+cn){
				cout<<1<<endl;
			}else if(cn>an+bn){
				cout<<1<<endl;
			}else{
				cout<<3<<endl;
			}
		}
	}
	return 0;
}