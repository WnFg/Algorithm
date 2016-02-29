#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <cmath>
using namespace std;

//const int maxBit = log2(200010);

int total[200010];
int table[200010][15];
int record[200010]; 

void init(int n)
{
	int a = 0;
	for(int i = 0; i < n; i++){
		table[i][0] = total[i] - a;
		a = total[i];
	}
//	cout << limit << endl;
	int tt = 1;
	for(int j = 1; (1<<j) <= n; j++){
		for(int i = 0; i + (tt << 1) - 1 < n; i++){
			table[i][j] = max(table[i][j - 1], table[i + tt][j - 1]);
		}
		tt <<= 1;
	}
}

int query(int l, int r)
{
	if(record[l] == record[r])
		return r - l + 1;

	int left = total[record[l]] - l, right;
	if(record[r] != 0)
		right =  r + 1 - total[record[r] - 1];
	else
		right = r + 1;
	int ans = max(left, right);
	r = record[r] - 1;
	l = record[l] + 1;
	
	if(r - l < 0)
		return ans;
	
	int len = 0;
	while( 1 << (len + 1) <= r - l + 1)  len++;
	int t = 1 << len;
	return max(ans, max(table[l][len], table[r - t + 1][len]));
}
int main()
{
	int n, q;
	while(scanf("%d", &n), n != 0){
	//	cout << log2(n) << endl;
		memset(total, 0, sizeof(total));
		scanf("%d", &q);
		int t = -1, last = -9999999;
		int a;
		for(int i = 0; i < n; i++){
			scanf("%d", &a);
			if(a != last){
				if(t > -1){
					total[t + 1] = 1 + total[t];
					++t;
				}
				else
					total[++t] = 1;
			}else
				total[t]++;
			record[i] = t;
			last = a;
		}
		init(t + 1);
		int l, r;
		while(q--){
			scanf("%d %d", &l, &r);
			if(l > r) swap(l, r);
			printf("%d\n", query(l - 1, r - 1));
		}
	}
	return 0;
}
