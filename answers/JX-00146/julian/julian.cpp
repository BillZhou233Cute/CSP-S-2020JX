#include<bits/stdc++.h>
using namespace std;
int year;
string s;
int   a[100002];
#define ll long long 
int read(){
	ll x=0;
	int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
int kk()
	{
	int n;
	cin>>n;
	n=n+1;
	if(n<2299161)
	{
		while(n>365)
		{
		n-=365;
		year++;
		if((year-1)%4==0)
		n-=1;
		}
		if(year>4713){ year=year-4713-1;s=" ";}
		else if(year<=4713) {year=4713-year;s="BC";}
		int mouth=0;
			 if(n>31)
			 {
		       	n-=31;
			mouth++;
			 }
			 else if(n==31)
			{
			   mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 }
			 else 
			{ mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 return 0;}
			if(n==28&&(year-1)%4!=0)
			{
				mouth=2;
				cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;
				return 0;
			}
			else if(n>28&&((year-1)%4!=0))
			{
				n-=28;
				mouth++;
			}
			else if((((year-1)%100!=0&&(year-1)%100!=0)||((year-1)%400==0))&&n>29)
			{
				n-=29;
				mouth++;
			}
			if(n>31)
			 {
		       	n-=31;
			mouth++;
			 }
			 else if(n==31)
			{
			   mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 }
			 else 
			{ mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 }//3
			if(n>30)
			 {
		       	n-=30;
				mouth++;
			 }
			 else if(n==30)
			{
				 mouth++;
				   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 }
			 else 
			{ mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 }//4
			if(n>31)
			 {
		       	n-=31;
			mouth++;
			 }
			 else if(n==31)
			{
			   mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 }
			 else 
			{ mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 }//5
			if(n>30)
			 {
		       	n-=30;
			mouth++;
			 }
			 else if(n==30)
			{
			   mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 }
			 else 
			{ mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 }//6
			if(n>31)
			 {
		       	n-=31;
			mouth++;
			 }
			 else if(n==31)
			{
				 mouth++;
				   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 }
			 else 
			{ mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 }//7
			if(n>31)
			 {
		       	n-=31;
			mouth++;
			 }
			 else if(n==31)
			{
			   mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 }
			 else 
			{ mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 }//8
			if(n>30)
			 {
		       	n-=30;
			mouth++;
			 }
			 else if(n==30)
			{
				 mouth++;
				   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 }
			 else
			{ mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 }//9
			if(n>31)
			 {
		       	n-=31;
			mouth++;
			 }
			 else if(n==31)
			{
				 mouth++;
				   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 }
			 else 
			{ mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 }//10
			if(n>30)
			 {
		       	n-=30;
			mouth++;
			 }
			 else if(n==30)
			{
			   mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 }
			 else 
			{ mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 }//11
			if(n>31)
			 {
		       	n-=31;
			mouth++;
			 }
			 else if(n==31)
			{
			   mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 }
			 else 
			{ mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<s<<endl;return 0;
			 }//12
	}
	if(n>=2299161)
	{
		n=n-2299161+10;
		while(n>365)
		{
		n-=365;
		year++;
		if(year%4==0)
			n-=1;
		}
		s;
			int mouth=0;
			 if(n>31)
			 {
		       	n-=31;
				mouth++;
			 }
			 else if(n==31)
			{
				 mouth++;
				 cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 }
			 else 
			{ mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 return 0;}
			if(n==28&&(year-1)%4!=0)
			{
				mouth=2;
				cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;
				return 0;
			}
			else if(n>28&&((year-1)%4!=0))
			{
				n-=28;
				mouth++;
			}
			else if((((year-1)%100!=0&&(year-1)%100!=0)||((year-1)%400==0))&&n>29)
			{
				n-=29;
				mouth++;
			}
			if(n>31)
			 {
		       	n-=31;
				mouth++;
			 }
			 else if(n==31)
			{
				 mouth++;
				 cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 }
			 else 
			{ mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 }//3
			if(n>30)
			 {
		       	n-=30;
				mouth++;
			 }
			 else if(n==30)
			{
				 mouth++;
				 cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 }
			 else 
			{ mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 }//4
			if(n>31)
			 {
		       	n-=31;
				mouth++;
			 }
			 else if(n==31)
			{
				 mouth++;
				 cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 }
			 else 
			{ mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 }//5
			if(n>30)
			 {
		       	n-=30;
				mouth++;
			 }
			 else if(n==30)
			{
				 mouth++;
				 cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 }
			 else 
			{ mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 }//6
			if(n>31)
			 {
		       	n-=31;
				mouth++;
			 }
			 else if(n==31)
			{
				 mouth++;
				 cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 }
			 else 
			{ mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 }//7
			if(n>31)
			 {
		       	n-=31;
				mouth++;
			 }
			 else if(n==31)
			{
				 mouth++;
				 cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 }
			 else 
			{ mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 }//8
			if(n>30)
			 {
		       	n-=30;
				mouth++;
			 }
			 else if(n==30)
			{
				 mouth++;
				 cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 }
			 else 
			{ mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 }//9
			if(n>31)
			 {
		       	n-=31;
				mouth++;
			 }
			 else if(n==31)
			{
				 mouth++;
				 cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 }
			 else 
			{ mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 }//10
			if(n>30)
			 {
		       	n-=30;
				mouth++;
			 }
			 else if(n==30)
			{
				 mouth++;
				 cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 }
			 else 
			 {mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 }//11
			if(n>31)
			 {
		       	n-=31;
				mouth++;
			 }
			 else if(n==31)
			{
				 mouth++;
				 cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 }
			 else 
			{ mouth++;
			   cout<<n<<" "<<mouth<<" "<<year<<" "<<endl;return 0;
			 }//12
}	}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int k;
	cin>>k;
	int n;
	for(int i=1;i<=k;i++){
		kk();
	}
	return 0;
}
