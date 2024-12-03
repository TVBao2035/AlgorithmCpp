#include<iostream>
#include<list>
#include<vector>
using namespace std;
/*
Cho trước một list line.

Hãy tính tổng các phần tử trong list.
*/
int sumOfAllElements(list<int> lis) {
	int sum = 0;
	list<int>::iterator it = lis.begin();
	while (it != lis.end()) {
		sum += *it;
		it++;
	}
	return sum;
}
int main()
{
	list<int> lis;
	int sizeOfList; cout << "enter size of list: "; cin >> sizeOfList;
	cout << "enter elements of list:" << endl;
	for (int i = 0; i < sizeOfList; i++) {
		int store; cin >> store; lis.push_back(store);
	}
	cout << "sum of all elements in list is " << sumOfAllElements(lis);
	return 0;
}