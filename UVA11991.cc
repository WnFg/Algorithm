#include <iostream>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

map<int, vector<int> > mp;
int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF){
		int a;
		for(int i = 0; i < n; i++){
			scanf("%d", &a);
			mp[a].push_back(i + 1);
		}
		int k, v;
		while(m--){
			scanf("%d %d", &k, &v);
			if(k > mp[v].size())
				printf("0\n");
			else
				printf("%d\n", mp[v][k - 1]);
		}
		mp.clear();
	}
	return 0;
}
