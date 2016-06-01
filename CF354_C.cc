#include <iostream>
using namespace std;

char a[100005];

int f(char c, int n, int m) {
	int ans = 0;
	int t = 0;
	int l = 0;
	for(int i = 0; i < n && l < n - ans; i++) {
		if(a[i] == c)
			++t;

		while(t > m) {
			if(a[l] == c)
				--t;
			++l;
		}
		ans = max(ans, i - l + 1);
	}
	return ans;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	getchar();
	gets(a);
	//cout << a << endl;
	cout << max(f('a', n, m), f('b', n, m)) << endl;
	return 0;
}
