#include <iostream>

using namespace std;
freopen("julian.in","w",stdin)
freopen("julian.out","r",stdout)
int main()
{
	int tian,yue,ri,nian,Q,r,day,,n;
	nian = 4713;
	yue = 1;
	ri = 1;
	cin>>Q>>r;
	if nian mod 4 = 0
	{n = 365;}
	else n=366;
	if r<=1721425
	{
		if r<=365;
		{
	    ri = ri+r;
		nian = 4713;
		yue = 1;
		cout<<ri<<yue<<ri<<"BC"<<endl;
		return 0;
		}
		else ri=r mod 365;
		yue = r/30-ri;
		nian = 4713-r/365;
		cout<<ri<<" "<<yue<<" "<<ri<<" "<<"BC"<<endl;
		return 0;
	}
	else ri = r-1721425 mod 365;
	yue = r-1721425/30-ri;
	nian = 1+r/365;
	cout<<ri<<" "<<yue<<" "<<nian<<endl;
	return 0;
}
