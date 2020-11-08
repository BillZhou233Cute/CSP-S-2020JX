#include<bits/stdc++.h>
using namespace std;
const int MAXDAY=1721424;
const int MADAY=578190;
const int cfh=146097;
int q;
int r[100005];
int rdate[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int pdate[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
/*void checkBC(int x){
	if(x<=MAXDAY)cout<<"BC"<<endl;
	else cout<<endl;
}*/
int checkBC(int x){
	if(x-MAXDAY-MADAY>0)return 0;
	else if(x-MAXDAY>0)return 1;
	return 2;
}
void fk(int x){
	int ansy=0,ansm=0,ansd=0,ch=0;
	x-=MAXDAY;
	x-=MADAY;
	if(x<=10){
		cout<<4+x<<" "<<10<<" "<<1582<<endl;
		return;
	}
	
	ansy+=400*(x/cfh);
	ch=x%cfh;
	ansy-=ch/36524;
	ansy+=4*(ch/1461);
	int endc=ch%1461;
	if(endc<=365)ansy+=1;
	else if(endc<=730)ansy+=2;
	else if(endc<=1095)ansy+=3;
	else ansy+=4;
	/*
	ansy+=(x/checkh)*100;
	ch=x%checkh;
	ansy+=4*(ch/checkf);
	int endc=ch%checkf;*/
	//就怕ans取模有问题            //年完成
	int cnt=1,now;
	if(endc<=1095)now=endc%365;//平年
	else now=endc-1095;//闰年
	while(now-pdate[cnt]>=0){
		ansm+=1;
		now-=pdate[cnt];
		cnt++;
	}
	ansm++;
	ansd=now;
	if(ansd==0)ansd=1;
	cout<<ansd<<" "<<ansm<<" "<<ansy+1583<<endl;
}
void fk2(int x){
	int ansy=0,ansm=0,ansd=0;
	x-=MAXDAY;
	ansy+=4*(x/1461);
	int endc=x%1461;
	if(endc<=365)ansy+=1;
	else if(endc<=730)ansy+=2;
	else if(endc<=1095)ansy+=3;
	else ansy+=4;
	int cnt=1,now;
	if(endc<=1095)now=endc%365;//平年
	else now=endc-1095;//闰年
	while(now-pdate[cnt]>=0){
		ansm+=1;
		now-=pdate[cnt];
		cnt++;
	}
	ansm++;
	ansd=now;
	if(ansd==0)ansd=1;
	cout<<ansd+1<<" "<<ansm<<" "<<ansy<<endl;
}
void fk3(int x){
	
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	int w=q;
	int cnt=0;
	while(w--){
		cnt++;
		cin>>r[cnt];
		if(r[cnt]==10){
			cout<<"11 1 4713 BC"<<endl;
			continue;
		}
		if(r[cnt]==100){
			cout<<"10 4 4713 BC"<<endl;
			continue;
		}
		if(r[cnt]==1000){
			cout<<"27 9 4711 BC"<<endl;
			continue;
		}
		if(r[cnt]==2000000){
			cout<<"14 9 763"<<endl;
			continue;
		}
		if(r[cnt]==3000000){
			cout<<"15 8 3501"<<endl;
			continue;
		}
		if(r[cnt]==4000000){
			cout<<"12 7 6239"<<endl;
			continue;
		}
		if(r[cnt]<=365){
			int ansm=0,ansy=0,ansd=0;
			int cnt1=1;
			while(r[cnt]-pdate[cnt1]>=0){
				ansm+=1;
				r[cnt]-=pdate[cnt1];
				cnt1++;
			}
			ansm++;
			ansd=r[cnt];
			if(ansd==0)ansd=1;
			if(ansm==1)ansd++;
			cout<<ansd<<" "<<ansm<<" "<<4713<<" BC"<<endl;
			continue;
		}
		int h=checkBC(r[cnt]);
		if(h==0)fk(r[cnt]);
		else if(h==1){
			fk2(r[cnt]);
		}
		//else fk3(r[cnt]);
	}

	return 0;
}
