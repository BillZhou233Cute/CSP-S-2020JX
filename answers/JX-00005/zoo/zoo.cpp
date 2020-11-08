#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<vector>
using namespace std;

int n,m,c,k;
int node[1000000];

vector<int>com[10000];
bool can[10000];
long long mi[1000]={1,2,4,8,16,32};
bool sl[100000];
int main(){
	ifstream cin("zoo.in");
	ofstream cout("zoo.out");

	cin>>n>>m>>c>>k;

	for (int i=1;i<=n;i++){
		cin>>node[i];
	}
    
	
		
		
	for (int  i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		com[x].push_back(y);
	}
	
	for (int i=1;i<=n;i++){
		for (int j=0;j<k;j++)
			if ((node[i]%mi[j+1])&mi[j]){
				for (int t=0;t<com[j].size();t++)
				   sl[com[j][t]]=1;
				}
				
	
	}
	//for (int i=1;i<=c;i++)  cout<<sl[i];	
    int sum=k;
	for (int i=0;i<k;i++){
	   for (int j=0;j<com[i].size();j++)
	        if (!sl[com[i][j]]) sum--;
	}	
	cout<<mi[sum]-n<<'\n';
	
	cin.close();
	cout.close();
	return 0;
}