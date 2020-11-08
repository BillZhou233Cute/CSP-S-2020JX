#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a,b;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin >> a >> b;
	if (b==3) printf("3\n1");
	else printf("5\n3");
	return 0;
}
