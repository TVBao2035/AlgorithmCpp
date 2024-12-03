#include<iostream>
#include<list>
using namespace std;
/*
Cho list số nguyên, và hai số nguyên k và x. (1 ≤ k ≤ size()).

Hãy thay đổi giá trị của số thứ k trong list thành x.
*/
list<int> changeValue(list<int> &lis, int value, int site) {
	list<int>::iterator it = lis.begin();
	advance(it, site-1);
	*it = value;
	return lis;
}
int main()
{
	list<int> lis;
	int sizeOfList; cout << "enter size of list: "; cin >> sizeOfList;
	cout << "enter elements of list: " << endl;
	for (int i = 0; i < sizeOfList; i++) {
		int store; cin >> store; lis.push_back(store);
	}
	int value, site;
	cout << "enter value: "; cin >> value;
	cout << "enter site: "; cin >> site;
	changeValue(lis, value, site);
	list<int>::iterator it;
	for (it = lis.begin(); it != lis.end(); it++) {
		cout << *it << " ";
	}
	return 0;
}