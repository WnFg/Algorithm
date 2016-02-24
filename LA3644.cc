#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <string>
#include <set>
using namespace std;
int f[100010];
int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}
int main()
{
	int a, b;
	int ans = 0;
	for(int i = 0; i < 100010; i++)
			f[i] = i;
	while(scanf("%d", &a) != EOF){
		if(a == -1){
			printf("%d\n", ans);
			ans = 0;
			for(int i = 0; i < 100010; i++)
				f[i] = i;
			continue;
		}		
		scanf("%d", &b);
		if((a = find(a)) == (b = find(b)))
			ans++;
		else
			f[a] = b;
	}
	return 0;
}
