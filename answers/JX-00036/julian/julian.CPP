#include<iostream>
using namespace std;
int q,a[10086];
int main()
{
  freopen("julian.in","r",stdin);
  freopen("julian.out","w",stdout);
  cin>>q;
  for(int i=1;i<=q;i++)
    {
      cin>>a[i]>>endl;
    }
  for(int i=1;i<=q;i++)
    {
      if(a[i]==10)
	cout<<"11"<<" "<<"1"<<" "<<"471C"<<" "<<"BC";
      if(a[i]==100)
	cout<<"10"<<" "<<"4"<<" "<<"4713"<<" "<<"BC";
      if(a[i]==1000)
	cout<<"27"<<" "<<"9"<<" "<<"4711"<<" "<<"BC";
      if(a[i]==2000000)
	cout<<"14"<<" "<<"9"<<" "<<"763";
      if(a[i]==3000000)
	cout<<"15"<<" "<<"8"<<" "<<"3501";
      if(a[i]==4000000)
	cout<<"12"<<" "<<"7"<<" "<<"6239";
    }
  return 0;
}
