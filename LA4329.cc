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

#define LL long long
#define max_size 20010

struct arrayTree
{
	int cnt[max_size*5];
	int size;
	inline int f(int x)
	{
		return x & (-x);
	}
	int query(int x)
	{
		int ans = 0;
		while(x){
			ans += cnt[x];
			x -= f(x);
		}
		return ans;
	}
	void add(int pos, int val)
	{
		while(pos <= size){
			cnt[pos] += val;
			pos += f(pos);
		}
	}
};

arrayTree atree;
int below[max_size*5];
int eq[max_size*5];
int a[max_size];
int eqL[max_size];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		memset(atree.cnt, 0, sizeof(atree.cnt));
		atree.size = n;
		LL ans = 0;
		memset(eq, 0, sizeof(eq));
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			eq[a[i]]++;
			eqL[i] = eq[a[i]];
		}
		for(int i = 1; i < 100001; i++)
			below[i] = eq[i - 1] + below[i - 1];
		for(int i = 1; i < n; i++){
			LL ret1 = atree.query(a[i]);
			LL ret2 = i - 1 - ret1 + eqL[i] - 1;
			LL ret3 = n - below[a[i]] - 1 - ret2;
			LL ret4 = below[a[i]] - ret1 - 1 + eq[a[i]];
			ans += ret1 * ret3 + ret2 * ret4;
			atree.add(a[i], 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
