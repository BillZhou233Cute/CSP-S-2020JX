#include<bits/stdc++.h>
using namespace std;
int q;
int n;
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin >> q;
	for(int i=1;i<=q;i++){
		cin >> n;
		if(n<=30){
			cout << 1+n  << " " << 1 << " " << 4713  << " " << BC << endl;
		}eelse if(n>30&&n<=58){
			cout << n-30 << " " << 2 << " " << 4713  << " " << BC << endl;
		}else if(n>58&&n<=89){
			cout << n-58 << " " << 3 << " " << 4713  << " " << BC << endl;
		}else if(n>89&&n<=119){
			cout << n-89<< " " << 4 << " " << 4713  << " " << BC << endl;
		}else if(n>119&&n<=150){
			cout << n-19 << " " << 5 << " " << 4713  << " " << BC << endl;
		}else if(n>150&&n<=180){
			cout << n-150 << " " << 6 << " " << 4713  << " " << BC << endl;
		}else if(n>180&&n<=211){
			cout << n-180 << " " << 7 << " " << 4713  << " " << BC << endl;
		}else if(n>211&&n<=242){
			cout << n-211 << " " << 8 << " " << 4713  << " " << BC << endl;
		}else if(n>242&&n<=272){
			cout << n-242 << " " << 9 << " " << 4713  << " " << BC << endl;
		}else if(n>272&&n<=303){
			cout << n-272 << " " << 10 << " " << 4713  << " " << BC << endl;
		}else if(n>303&&n<=333){
			cout << n-303 << " " << 11 << " " << 4713  << " " << BC << endl;
		}else if(n>333&&n<=364){
			cout << n-333 << " " << 12 << " " << 4713  << " " << BC << endl;
		}
		else if(n==365){
			cout << 1 << " " << 1 << " " << 4712 << " " << BC << endl;
 		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}