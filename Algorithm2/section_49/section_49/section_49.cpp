#include<iostream>
#include<bitset>
#include<vector>
using namespace std;

int main()
{
	int c;
	cin >> c;
	bitset<c> bit(c);
	
	cout << bit;
	return 0;
}