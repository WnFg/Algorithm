#include <iostream>
using namespace std;

#define N 100005

int a[N];

int d[17][N];

inline int min(int x, int y) {
	return a[x] > a[y] ? x : y;
}

void init(int n) {
	int len = 2;
	for(int i = 1; len <= n; i++) {
		for(int j = 0; j + len <= n; j++) {
			d[i][j] = min(d[i - 1][j], d[i - 1][j + len / 2]);
	//		cout << d[0][2] << " " << d[0][3] << " " << i << " " << j << " " << d[i][j] << endl;
		}
		len <<= 1;
	}
}

int query(int l, int r) {
	if(r - l == 1)
		return l;

	int t = 0;
	while(r - l > (1 << t))
		++t;
	--t;

	return min(d[t][l], d[t][r - (1 << t)]);
}

long long dp[N];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++) {
		scanf("%d", &a[i]);
		d[0][i] = i;
	}
	a[n - 1] = n + 1;
	d[0][n - 1] = n - 1;
	init(n);
	
	dp[n - 1] = 0;
	long long ans = 0;
	for(int i = n - 2; i >= 0; --i) {
		int pos = query(i + 1, a[i]);
	//	cout << pos << endl;
		if(pos == n - 1) 
			dp[i] = n - 1 - i;
		else
			dp[i] = dp[pos] + (n - i) - (a[i] - pos);
		ans += dp[i];
	}

	cout << ans << endl;
	return 0;
}
