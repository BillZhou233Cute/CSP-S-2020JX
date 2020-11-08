#include<bits/stdc++.h>
using namespace std;
int n,m,k,z;
int x=0;
int s[100],e[1000];
int y[1100000];
int n_[1100000][100],ny[1100000][100],nx[1100000],pd[100];
long long c,sum,ans;
void er(int i){
	int flag=1,num=-1;
	while(flag==1){
		num++;
		if(i%2==0&&i!=0){
			n_[x][num]=0;
		}else if(i%2==1){
			n_[x][num]=1;
			i--;
		}else if(i==0){
			flag=0;
		}
		i=i/2;
	}
	nx[x]=num;
}
int er2(long long l,int u){
	int flag=1,num=-1;
	while(flag==1){
		num++;
		if(l%2==0&&l!=0){
			e[num]=0;
		}else if(l%2==1){
			e[num]=1;
			l--;
		}else if(l==0){
			flag=0;
		}
		l=l/2;
	}
	if(e[u]==1&&pd[u]==1){
		return 1;
	}
}
int main(){
	freopen("zoo.num++;in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin >> n >> m >> c >> k;
	for(int i=1;i<=n;i++){
		cin >> y[i];
		y[i]=y[i]+1;
		er(y[i]);
		x++;
	}
	for(int i=0;i<n;i++){
		int t=0;
		for(int j=nx[i]-1;j>=0;j--){
			ny[i][t]=n_[i][j];
			t++;
		}
	}
	for(int i=1;i<=m;i++){
		cin >> s[i] >> e[i];
		pd[s[i]]=0;
		for(int i=0;i<n;i++){
			if(ny[i][s[i]]==1){
				pd[s[i]]=1;
				z++;
				break;
			}else{
				continue;
			}
		}
	}
	ans=2;
	for(int i=1;i<=k;i++){
		ans*=2;
	}
	for(long long i=1;i<=ans;i++){
		for(int j=1;j<=m;j++){
			for(int z=1;z<=n;z++){
				if(er2(i,s[j])==1&&i!=y[z]){
					sum++;
					break;
				}
			}
		}
	}
	cout << sum-z;
	fclose(stdin);fclose(stdout);
	return 0;
}