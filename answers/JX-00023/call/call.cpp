#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, m, q;
int arr[maxn];
int coun1 = 1, coun2 = 1, coun3 = 1;
struct nod1{
	int ele, num;
};
struct nod2{
	int type;
	int addr;
};
struct nod3{
	vector<int> doin;
};
nod1 f1[maxn];
int f2[maxn];
nod2 doi[maxn];
nod3 f3[maxn];
/*int lowbit(int x)
{
	return x & (-x);
	}
void add(int x, int d)
{
	while(x <= n)
	{
		arr[x] += d;
		x += lowbit(x);
		}
	}*/
void fun1(int a, int ad)
{
	//cout << a << " " << ad << " type1" << endl;
	arr[a] += ad;
	}
void fun2(int a)
{
	//cout << a << " type2" << endl;
	for(int i = 1; i <= n; i++)
		arr[i] *= a;
	}
void fun3(int el)
{
	//cout << el << " type3" << endl;
	for(int i = 0; i < f3[el].doin.size(); i++)
	{
		//cout << f3[el].doin[i] << " " ;
		if(doi[f3[el].doin[i]].type == 1)
		{
			fun1(f1[doi[f3[el].doin[i]].addr].ele, f1[doi[f3[el].doin[i]].addr].num);
			}
		else
		{
			fun2(f2[doi[f3[el].doin[i]].addr]);
			}
		}
	}
int main()
{
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	cin >> m;
	int type;
	for(int j = 1; j <= m; j++)
	{
		cin >> type;
		if(type == 1)
		{
			cin >> f1[coun1].ele >> f1[coun1].num;
			doi[j].type = 1; 
			doi[j].addr = coun1;
			coun1++;
			}
		if(type == 2)
		{
			cin >> f2[coun2];
			doi[j].type = 2;
			doi[j].addr = coun2;
			coun2++;
			}
		if(type == 3)
		{
			int f;
			cin >> f;
			int tmp;
			for(int i = 1; i <= f; i++)
			{
				cin >> tmp;
				f3[coun3].doin.push_back(tmp);
				}
			doi[j].type = 3;
			doi[j].addr = coun3;
			coun3++;
			}
		}
	cin >> q;;
	int tmp1;
	for(int i = 1; i <= q; i++)
	{
		cin >> tmp1;
		if(doi[tmp1].type == 1)
		{
			fun1(f1[doi[tmp1].addr].ele, f1[doi[tmp1].addr].num);
			}
		else if(doi[tmp1].type == 2)
		{
			fun2(f2[doi[tmp1].addr]);
			}
		else if(doi[tmp1].type == 3)
		{
			fun3(doi[tmp1].addr);
			}
		}
	/*for(int i = 1; i <= m; i++)
	{
		cout << doi[i].type << " " << doi[i].addr;
		cout << endl;
		}*/
	for(int i = 1; i <= n; i++)
		printf("%d ", arr[i]);
	return 0;
	}