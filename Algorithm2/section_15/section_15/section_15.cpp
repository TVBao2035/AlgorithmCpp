#include<iostream>
#include<list>
#include<vector>
using namespace std;
/*
Cho list số nguyên và hai số nguyên first và last.
(1 ≤ first ≤ last  ≤ size).

Hãy xóa các phần tử bắt đầu từ số thứ first đến số thứ last.
*/
list<int> changeList(list<int> lis, int first, int last) {
	list<int>::iterator it1, it2;
	it1 = lis.begin(); it2 = lis.begin();
	advance(it1, first-1); advance(it2, last);
	lis.erase(it1, it2);
	return lis;
}
int main()
{
	list<int> lis;
	cout << "enter size of list: ";
	int sizeOfList; cin >> sizeOfList;
	cout << "enter elements of list: " << endl;
	for (int i = 0; i < sizeOfList; i++) {
		int store; cin >> store; lis.push_back(store);
	}
	int first, last;
	cout << "enter first site: "; cin >> first;
	cout << "enter last site: "; cin >> last;
	lis = changeList(lis, first, last);
	vector<int> vec(lis.begin(), lis.end());
	for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
	return 0;
}