#include <iostream>
#include <queue>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

priority_queue<pair<int, int> > que;
int num[3001];

int main()
{
	char s[100];
	int a, period;
	memset(num, -1, sizeof(num));
	while(scanf("%s", s) != EOF && s[0] != '#'){
		scanf("%d %d", &a, &period);
		num[a] = period;
	}
	int k;
	scanf("%d", &k);
	for(int i = 0; i < 3001; i++)
		if(num[i] != -1)
			que.push(make_pair(-num[i], -i));
	
	while(k--){
		pair<int, int> p = que.top();
		printf("%d\n", -p.second);
		que.pop();
		que.push(make_pair(p.first - num[-p.second], p.second));
	}
	while(!que.empty()){
		que.pop();
	}
	return 0;
}
