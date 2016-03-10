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

const int maxn = 1000000 + 10;
const int INF = 0x3f3f3f3f;

int N, Q, d[maxn][35];

struct Num{
	int n, c, l, r;
	bool operator<(const Num& a) const{
		return c < a.c;
	}
};

Num num[maxn];

int RMQ(int l, int r)
{
	if(l > r) return 0;
	int k = 0;
	while(1 << (k + 1) <= r - l + 1) k++;
	return max(d[l][k], d[r - (1 << k) + 1][k]);
}

int main()
{
	int a, b;
	num[0].n = -INF;
	while(scanf("%d", &N)&&N){
		scanf("%d", &Q);
		for(int i = 1; i <= N; i++){
			scanf("%d", &num[i].n);
			if(num[i].n == num[i - 1].n){
				num[i].c = num[i - 1].c + 1;
				num[i].l = num[i - 1].l;
			}else{
				num[i].c = 1;
				num[i].l = i;
			}
		}
		num[N+1].n = -INF;
		for(int i = N; i > 0; i--){
			if(num[i].n == num[i + 1].n)
				num[i].r = num[i+1].r;
			else
				num[i].r = i;
		}
		memset(d, 0, sizeof(d));
		for(int i = 0; i < N; i++) d[i][0] = num[i].c;
		for(int j = 1; 1 << j <= N; j++)
			for(int i = 0; i + (1 << j) - 1 <= N; i++)
				d[i][j] = max(d[i][j - 1], d[i+(1<<(j-1))][j-1]);
		for(int i = 0; i < Q; i++){
			scanf("%d %d", &a, &b);
			if(a > b) swap(a, b);
			int ans = RMQ(num[a].r+1, num[b].l-1);
			ans = max(ans, num[a].r - a + 1);
			ans = max(ans, b - num[b].l + 1);
			if(num[a].r >= b) ans = b - a + 1;
			printf("%d\n", ans);
		}
	}
	return 0;
}
