#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int mp[755][755];
int* merge(int a[], int b[], int k)
{
	priority_queue<pair<int, int> > que;
	for(int i = 0; i < k; i++)
		que.push(make_pair(a[0] + b[i], 0));
	int* ans = (int*)malloc(sizeof(int)*k);
	pair<int, int> p;
	for(int i = 0; i < k; i++){
		p = que.top();
		ans[i] = p.first;
		que.pop();
		que.push(make_pair(p.first - a[p.second] + a[p.second + 1], p.second + 1));
	}
	return ans;
}

void solve(int k)
{
	int* p = mp[0];
	int* q;
	for(int i = 1; i < k; i++){
		q = merge(p, mp[i], k);
		if(i > 1) free(p);
		p = q;
	}
    printf("%d", -p[0]);
	for(int i = 1; i < k; i++){
		printf(" %d", -p[i]);
	}
	printf("\n");
}

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int k;
	while(scanf("%d", &k) != EOF){
		int a;
		for(int i = 0; i < k; i++){
			for(int j = 0; j < k; j++){
				scanf("%d", &a);
				mp[i][j] = -a;
			}
			sort(mp[i], mp[i] + k, cmp);
		}
		solve(k);
	}
	return 0;
}
