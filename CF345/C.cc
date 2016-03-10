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
#define maxn 200010
pair<int, int> a[maxn], b[maxn];
int n;

void findEq(pair<int, int>* p, vector<int>& ans)
{
	int last = p[0].first;
	int t = 0;
	ans.push_back(1);
	for(int i = 1; i < n; i++){
		if(p[i].first != last){
			t++;
			ans.push_back(1);
		}else
			ans[t]++;
		last = p[i].first;
	}
}

void Eq(pair<int, int>* p , vector<int>& ans)
{
	pair<int, int> last = p[0];
	int t = 0;
	ans.push_back(1);
	for(int i = 1; i < n; i++){
		if(p[i] != last){
			t++;
			ans.push_back(1);
		}else
			ans[t]++;
		last = p[i];
	}
}
int main()
{
	int x, y;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &x, &y);
		a[i].first = x, a[i].second = y;
		b[i].second = x, b[i].first = y;
	}
	sort(a, a + n);
	sort(b, b + n);
	vector<int> Leq, Req, eq;
	findEq(a, Leq);
	findEq(b, Req);
	Eq(a, eq);
	LL ans = 0;
	//cout << Leq.size() << " " << Req.size() << endl;
	for(int i = 0; i < Leq.size(); i++){
		ans += (LL)Leq[i]*(Leq[i] - 1) / 2;
	}

	for(int i = 0; i < Req.size(); i++){
		ans += (LL)Req[i]*(Req[i] - 1) / 2;
	}

	for(int i = 0; i < eq.size(); i++){
		ans -= (LL)eq[i]*(eq[i] - 1) / 2;
	}
	cout << ans << endl;
	return 0;
}
