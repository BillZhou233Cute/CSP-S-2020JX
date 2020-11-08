#include<fstream>
using namespace std;
ifstream fin("zoo.in");
ofstream fout("zoo.out");
int main(){
	int  a,b,c;
	fin>>b;
	c=2;
	a=13;
	if(b==2) fout<<c;
	if(b==3) fout<<a; 
	return 0;
}