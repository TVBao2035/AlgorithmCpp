#include<iostream>
#include<vector>
using namespace std;
/*Cho một vector các số nguyên v, hãy sắp xếp các số nguyên trong vector này 
theo thứ tự tăng dần.
*/
void sortVector(vector<int> &vec) {
	vector<int>::iterator it,it2;
	for (it = vec.begin(); it != vec.end(); it++) {
		for (it2 = it ; it2 != vec.end(); it2++) {
			if (*it > *it2) {
				int store = *it;
				*it = *it2;
				*it2 = store;
			}
		}
	}
}
int main()
{
	vector<int> vec;
	int lengthOfVector;
	cout << "length of vector: "; cin >> lengthOfVector;
	cout << "enter elements of vector:" << endl;
	for (int i = 0; i < lengthOfVector; i++) {
		int store;
		cin >> store;
		vec.push_back(store);
	}
	sortVector(vec);
	for (int x : vec) {
		cout << x << " ";
	}
	return 0;
}