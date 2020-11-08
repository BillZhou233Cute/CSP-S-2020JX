#include<bits/stdc++.h>
using namespace std;
int q;int z;
int rz[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","r",stdout);
	int o=-4713;int j=1,s=0;int y,r,n;
	cin>>q;
	
	for(int i=1;i<=q;i++)
	{
		cin>>z;
		if(o<1582)
		{
			if(o%4==0)
			{
				rz[2]=rz[2]+1;
				
			}
				
		}
		cout<<y<<" "<<r<<" "<<n<<" ";
		if(o<0) cout<<"BC"<<endl;
	}
		
	return 0;
	fclose(stdin);fclose(stdout);
}