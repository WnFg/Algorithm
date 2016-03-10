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

int cnt[1010];
int d[1010];

int main()
{
	int n;
	scanf("%d", &n);
	int ans = 0;
	int last = 0;	
	int t = 0;
	
	for(int i = 0; i < n; i++)
		scanf("%d", &d[i]);
	sort(d, d + n);
	
	last = d[0];
	cnt[t] = 1;
	for(int i = 1; i < n; i++){
		if(d[i] == last){
			cnt[t]++;
		}else{
			cnt[++t] = 1;
		}
		last = d[i];
	}
	last = 0;
	for(int i = 0; i <= t; i++){
		ans += min(cnt[i], last);
		last = max(cnt[i], last);
	}
	cout << ans << endl;
	return 0;
}
