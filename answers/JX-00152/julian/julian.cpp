#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int t;
	int n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=30){
			cout<<1+n<<" "<<1<<" "<<4713<<" "<<"BC"<<endl;
		}else if(n>30&&n<=59){
			cout<<n-30<<" "<<2<<" "<<4713<<" "<<"BC"<<endl;
		}else if(n>59&&n<=90){
			cout<<n-59<<" "<<3<<" "<<4713<<" "<<"BC"<<endl;
		}else if(n>90&&n<=120){
			cout<<n-90<<" "<<4<<" "<<4713<<" "<<"BC"<<endl;
		}else if(n>120&&n<=151){
			cout<<n-120<<" "<<5<<" "<<4713<<" "<<"BC"<<endl;
		}else if(n>151&&n<=181){
			cout<<n-151<<" "<<6<<" "<<4713<<" "<<"BC"<<endl;
		}else if(n>181&&n<=212){
			cout<<n-181<<" "<<7<<" "<<4713<<" "<<"BC"<<endl;
		}else if(n>212&&n<=243){
			cout<<n-212<<" "<<8<<" "<<4713<<" "<<"BC"<<endl;
		}else if(n>243&&n<=273){
			cout<<n-243<<" "<<9<<" "<<4713<<" "<<"BC"<<endl;
		}else if(n>273&&n<=304){
			cout<<n-273<<" "<<10<<" "<<4713<<" "<<"BC"<<endl;
		}else if(n>304&&n<=334){
			cout<<n-304<<" "<<11<<" "<<4713<<" "<<"BC"<<endl;
		}else if(n>334&&n<=365){
			cout<<n-334<<" "<<12<<" "<<4713<<" "<<"BC"<<endl;
		}else if(n==366){
			cout<<1<<" "<<1<<" "<<4712<<" "<<"BC"<<endl;
		}
	}
	return 0;
}