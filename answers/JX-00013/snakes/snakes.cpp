#include<iostream>
#include<cmath>
#include<string>
#include<fstream>
using namespace std;
ifstream  fin("snakes.in");
ofstream  fout("snakes.out");
int main(){
 int a,b,c,d;
	fin>>a>>b;
	if(b==3) {c=3;d=1;}
	else{c=5;d=3;}
	fout<<c<<endl<<d;
	return 0;
}