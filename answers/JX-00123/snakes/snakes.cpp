#include<cstdio>
#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
using namespace std;
ifstream fin("snakes.in");
ofstream fout("snakes.out");
int t;
int n;
int w;
int main(){
   
	fin>>t;while(fin>>n);
	   w=2t+1;   
	for(int i=1;i<=t;i++){
		      fout<<w<<endl;
		      w-=2;
		   }
	
	  return 0;
	}