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

int a, b, n, t;

int solve(string s, int t, int q)
{
	int ans = 0;
	int L = 0;
	int size = s.size();
	int mark = 0;
	q = n - q;
	for(int i = 0; i < size; i++){
		if(i < q)
			mark = 2;
		else
			mark = 1;
		if(s[i] == 'w')
			t -= b + 1;
		else
			t -= 1;
	/*	if(i == n + 1){
			cout << L << " " << t << "  ff"<< endl;	
		}*/
		
		while(t < 0){
			if(s[L] == 'w')
				t += 2*a + b + 1;
			else
				t += 2*a + 1;
			L++;
		}
		if(L <= q && i >= q)
			ans = max(ans, i - L + 1);
		t -= a*mark;
	}
	return ans;
}

int main()
{
	string s;
	cin >> n >> a >> b >> t >> s;
	s += s;
	int ans = 0;
	int t1 = t;
	int i;
	for(i = 0; i < n; i++){
		if(s[i] == 'w'){
			t1 -= 1 + b;
		}else
			t1 -= 1;
	//	cout << t1 << " " << i << endl;

		if(t1 < 0) { break;}
		t1 -= a;
	}
	ans = i;
	if(ans == n) { cout << n << endl; return 0;}
	
	int t2 = t;
	for(i = 0; i < n; i++){
		int q = (n - i) % n;
		if(s[q] == 'w')
			t2 -= b + 1;
		else
			t2 -= 1;
		if(t2 < 0){ break;}
		t2 -= a;
	}
	ans = max(ans, i);
	if(ans == n) {cout << n << endl; return 0;}

	ans = max(ans, solve(s, t, 0));
	reverse(s.begin(), s.end());
	ans = max(ans, solve(s, t, 1));

	cout << (ans > n ? n : ans) << endl;
	return 0;
}
