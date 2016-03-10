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

#define uLL unsigned long long

const uLL INF = (uLL)(-1);
pair<uLL, char> str[2][200010];

uLL f[200010];
uLL getHash(const uLL& seed, const uLL& t, const uLL& x)
{
	return t * seed + x;
}

uLL g(uLL x, int y)
{
	uLL ans = 1;
	while(y){
		if(y&1)
			ans *= x;
		x *= x;
		y >>= 1;
	}
	return ans;
}

uLL getVal(int len, int i)
{
	if(len == 0) return 0;

	//if(i > 0)
	return f[i + len] - f[i]*g(7, len) + INF + 1;
	//return f[len - 1];
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	pair<int, char> last;
	string s;
	int t1 = 0, t2 = 0;
	int a;
	for(int i = 0; i < n; i++){
		cin >> a; cin >> s;
		if(i == 0){
			last.first = a;
			last.second = s[1];
			continue;
		}
		if(s[1] == last.second)
			last.first += a;
		else
		{
			str[0][t1++] = last;
			last.first = a, last.second = s[1];
		}
	}
	str[0][t1++] = last;

	last = make_pair(0, '.');
	for(int i = 0; i < m; i++){
		cin >> a, cin >> s;
		if(i == 0){
			last.first = a;
			last.second = s[1];
			continue;
		}
		if(s[1] == last.second)
			last.first += a;
		else{
			str[1][t2++] = last;
			last = make_pair(a, s[1]);
		}
	}
	str[1][t2++] = last;
	if(t2 > t1){
		cout << 0 << endl;
		return 0;
	}
	/*cout << t1 << " " << t2 << endl;
	for(int i = 0; i < t1; i++){
		cout << str[0][i].first << " " << str[0][i].second << endl;
	}*/
	uLL ans = 0;

	if(t2 == 1){
		for(int i = 0; i < t1; i++){
			if(str[0][i].second == str[1][0].second){
				if(str[0][i].first >= str[1][0].first)
					ans += str[0][i].first - str[1][0].first + 1;
			}
		}
		cout << ans << endl;
		return 0;
	}

	uLL hashB = 0;
	if(t2 > 2){
		for(int i = 1; i < t2 - 1; i++){
			hashB = getHash(7, hashB, str[1][i].first*100 + str[1][i].second - 50);
			//cout << hashB <<  " sd" << endl;
		}

		for(int i = 1; i <= t1; i++){
			f[i] = getHash(7, f[i - 1], str[0][i - 1].first*100 + str[0][i - 1].second - 50);
		}
	}

//	cout << hashB << endl;
//	cout << getVal(t2 - 2, 1) << endl;
//	cout << g(7, 1) << endl;
//	cout << f[1]*7 << " " << f[2] << " " << f[2] - f[1] << endl;
	/*cout << f[4] << " " << f[3] << " " << f[2] << " " <<f[1]<< " " << f[1]*g(7,3) << endl;
	cout << g(7,3) << " fg" << endl;

	cout << hashB << endl;*/
	for(int i = 0; i + t2 <= t1; i++){
			if(str[0][i].first >= str[1][0].first && str[0][i].second == str[1][0].second
				&& str[0][i + t2 - 1].first >= str[1][t2 - 1].first 
				&& str[0][i + t2 - 1].second == str[1][t2 - 1].second
				&& hashB == getVal(t2 - 2, i + 1)) ans++;
		}
	cout << ans << endl;
	return 0;
}
