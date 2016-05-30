#include <iostream>
using namespace std;

using pair_type = pair<int, pair<void*, void*> >;

void dfs(pair_type* root, int value) {
	if(value > root->first) {
		if(root->second.second == NULL) {
			root->second.second = new pair_type{value, {NULL, NULL}};
			cout << root->first << endl;
			return;
		}else {
			dfs((pair_type*)root->second.second, value);
		}
	}else {
		if(root->second.first == NULL) {
			root->second.first = new pair_type{value, {NULL, NULL}};
			cout << root->first << endl;
			return;
		}else {
			dfs((pair_type*)root->second.first, value);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int a;
	cin >> a;
	pair_type* root = new pair_type{a, {NULL, NULL}};

	for(int i = 1; i < n; i++) {
		cin >> a;
		dfs(root, a);
	}
	return 0;
}
