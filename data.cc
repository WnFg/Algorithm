#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int maxn = 10000;
const int Q = 100;

int d[1000000];

int main()
{
	srand(10);
	int T = 10;
	while(T--){
	int t = maxn;
	while(t--){
		d[t] = rand()%1000;
	}
	sort(d, d+maxn);
	cout << maxn << " " << Q << endl;
	for(int i = 0; i < maxn; i++)
		cout << d[i] << " ";
	cout << endl;
	int q = Q;
	while(q--){
		int a = abs(rand()%maxn) + 1;
		int b = abs(rand()%maxn) + 1;
		if(a > b) swap(a, b);
		cout << a << " " << b << endl;
	}
	}
	cout << 0 << endl;
	return 0;
}
