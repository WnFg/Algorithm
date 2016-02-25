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

pair<int, int> f[20010];

int find(int x)
{
	if(x == f[x].first){
		return x;
	}else{
		int fa = find(f[x].first);
		f[x].second += f[f[x].first].second;
		f[x].first = fa;
	}
	return f[x].first;
}

int main()
{
	int T;
	scanf("%d", &T);
	char c;
	while(T--){
		int n;
		scanf("%d", &n);
		for(int i = 0; i <= n; i++)
			f[i].first = i, f[i].second = 0;
		int u, v;
		while(cin >> c && c != 'O'){
			if(c == 'I'){
				scanf("%d %d", &u, &v);
				f[u].first = v;
				f[u].second = abs(u - v);
			}else{
				scanf("%d", &u);
				find(u);
				printf("%d\n", f[u].second);
			}
		}
	}
	return 0;
}
