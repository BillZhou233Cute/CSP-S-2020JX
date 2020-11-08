/*

Code by W-YI

*/
#include <iostream>
#include <fstream>
using namespace std;

long long data[100001];
long run[100001];
long long n,m,q;

struct datlib{
	
	int type;//函数类型
	long long p;//操作下标:针对type=1
	long long v;//对于type=1or2为操作值;对于type=3为函数操作个数
	//long* g;
	
};

long g[10001][10001];//操作函数个数:针对type=3 第一个数据是函数编号即funs[x]的x,第二个是操作值

struct datlib funs[1000001];

void fun1(long long p,long long v){
	
	data[p]+=v;
	
}

void fun2(long long v){
	
	for(long long i=1;i<=n;i++){
		data[i]*=v;
	}
	
}

void fun3(long long v,long* list){
	
	for(long long i=0;i<v;i++){
		
		//cout<<"	调用:第"<<list[i]<<"个函数\n	 函数类型:"<<funs[list[i]].type<<endl;
		
		if(funs[list[i]].type==1){
			
			//cout<<"	  描述: 将下标"<<funs[list[i]].p<<"的值加"<<funs[list[i]].v<<endl;
			fun1(funs[list[i]].p,funs[list[i]].v);
			
		}
		
		if(funs[list[i]].type==2){
			
			//cout<<"	  描述: 将全部数据的值乘"<<funs[list[i]].v<<endl;
			fun2(funs[list[i]].v);
			
		}
		
		if(funs[list[i]].type==3){
			
			
			//cout<<"	  描述: 调用"<<funs[list[i]].v<<"个函数,分别为:";
			//for(long long j=0;j<funs[list[i]].v;j++)cout<<g[list[i]][j]<<",";
			//cout<<endl;
			fun3(funs[list[i]].v,g[list[i]]);
			
		}
		
	}
	
}


int main(){
	freopen ("call.in","r",stdin);
	freopen ("call.out","w",stdout);
	
	cin>>n;
	
	for(long long i=1;i<=n;i++){
		cin>>data[i];
	}
	
	cin>>m;
	
	for(long long i=1;i<=m;i++){
		
		cin>>funs[i].type;
		
		if(funs[i].type==1){
			cin>>funs[i].p>>funs[i].v;
		}
		if(funs[i].type==2){
			cin>>funs[i].v;
		}
		if(funs[i].type==3){
			cin>>funs[i].v;
			
			for(long long j=0;j<funs[i].v;j++){
				
				cin>>g[i][j];
				
			}
			
		}
		
	}
	
	cin>>q;
	
	for(long long i=0;i<q;i++){
		cin>>run[i];
	}
	
	for(long long i=0;i<q;i++){
		
		
		//cout<<"调用:第"<<run[i]<<"个函数\n 函数类型:"<<funs[run[i]].type<<endl;
		
		
		if(funs[run[i]].type==1){
			
			//cout<<"  描述: 将下标"<<funs[run[i]].p<<"的值加"<<funs[run[i]].v<<endl;
			fun1(funs[run[i]].p,funs[run[i]].v);
			
		}
		
		if(funs[run[i]].type==2){
			
			//cout<<"  描述: 将全部数据的值乘"<<funs[run[i]].v<<endl;
			fun2(funs[run[i]].v);
			
		}
		
		if(funs[run[i]].type==3){
			
			
			//cout<<"  描述: 调用"<<funs[run[i]].v<<"个函数,分别为:";
			//for(long long j=0;j<funs[run[i]].v;j++)cout<<g[run[i]][j]<<",";
			//cout<<endl;
			fun3(funs[run[i]].v,g[run[i]]);
			
		}
		
	}
	
	
	for(long long i=1;i<=n;i++){
		cout<<data[i]%998244353<<' ';
	}
	
	
	fclose (stdout);
	fclose (stdin);
	return 0;
}