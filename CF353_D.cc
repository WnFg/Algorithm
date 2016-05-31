#include <iostream>
#include <algorithm>
using namespace std;

int d[15][100005];
pair<int, int> a[100005];

inline int min(int x, int y) {
	return a[x].second < a[y].second ? x : y;
}

void init(int n) {
	int len = 2;
	for(int i = 1; len <= n; i++) {
		for(int j = 0; i + j <= n; j++) {
			d[i][j] = min(d[i - 1][j], d[i - 1][j + (len >> 1)]);
		}
		len <<= 1;
	}
}

int query(int l, int r) {
	int t = 0;
	while(r - l > (1 << t))
		++t;
	--t;
	return min(d[t][l], d[t][r - (1 << t)]);
}

int ans[100005];

int qq = 0;

void solve(int l, int r, int father) {
	if(r - l == 1) {
		ans[a[l].second] = father;
		return;
	}
	int x = query(l, r);
	
	if(qq++ < 2)
		cout << l << " " << r << " " << x << " " << a[x].second << endl;
	ans[a[x].second] = father;
	if(x > l)
		solve(l , x, a[x].first);
	if(x + 1 < r)
		solve(x + 1, r, a[x].first);
}

int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}

	sort(a, a + n);
	for(int i = 0; i < n; i++)
		d[0][i] = i;
	//cout << "~~~~~~~~" << endl;
	init(n);

	//cout << "zxczxc" << endl;
	solve(0, n, -1);
	
	for(int i = 1; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	
	return 0;
}
