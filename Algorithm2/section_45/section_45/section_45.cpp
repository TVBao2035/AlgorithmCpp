#include<iostream>
#include<map>
#include<vector>

using namespace std;
/*
Cho một dãy gồm các số nguyên, hãy đơn ra số thỏa mãn là số lớn nhất trong những số có tần số bé nhất.

Ví dụ:

Với arr = [2,2,4,4,7,7,7] thì largestElement(arr) = 4.

Với arr = [1,3,4,5,5] thì largestElement(arr) = 4.
*/
int main()
{
	vector<int> array;
	int length;
	cout << "enter length of array: ";
	cin >> length;
	cout << "enter elements in array:" << endl;
	for (int i = 0; i < length; i++) {
		int temp; cin >> temp;
		array.push_back(temp);
	}

	map<int, int> mapInt;
	int maxFrequency = 0;
	for (auto x : array) {
		mapInt[x]++;
		if (mapInt[x] > maxFrequency) {
			maxFrequency = mapInt[x];
		}
	}
	int result;
	for (auto x : mapInt) {
		if (x.second <=maxFrequency) {
			maxFrequency = x.second;
			result = x.first;
		}
	}
	
	cout << result << " " << maxFrequency;
	return 0;
}