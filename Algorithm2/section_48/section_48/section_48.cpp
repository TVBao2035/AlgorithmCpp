#include<iostream>
#include<bitset>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	bitset<32> bit(n);
	int index;
	for (index = bit.size()-1; index >= 0; index--) {
		if (bit.test(index)) break;
	}
	vector<int> result;
	for (int i = 0; i <= index; i++) {
		result.push_back(bit[i]);
	}
	for (int x : result) cout << x;
	return 0;
}