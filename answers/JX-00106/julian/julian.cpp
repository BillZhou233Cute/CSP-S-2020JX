#include<bits/stdc++.h>
using namespace std;
int q,r,n=4713,y=1,b,ri=1;
string s;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin >> q;
	for(int i=1;i<=q;i++)
	{
		cin >> r;
		if(r<1000000)
		while(r!=0)
		{
			if(r>=366)
			{	
				n--;
				if((n-1)%4==0)
					r-=366;
				else
					r-=365;
			}			
	
	 return 0;
}	