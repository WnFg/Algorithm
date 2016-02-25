#include <iostream>
using namespace std;
#define max_size 20010
struct arrayTree
{
	int cnt[max_size];
	int size;
	inline int f(int x)
	{
		return x & (-x);
	}
	int query(int x)
	{
		int ans = 0;
		while(x){
			ans += cnt[x];
			x -= f(x);
		}
		return ans;
	}
	void add(int pos, int val)
	{
		while(pos <= size){
			cnt[pos] += val;
			pos += f(pos);
		}
	}
};

int main()
{
}
