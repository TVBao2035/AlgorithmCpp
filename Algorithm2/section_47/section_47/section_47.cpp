#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
/*
Cho danh sách các sản phẩm của 2 kho hàng A và B. 
Do chiến lược kinh doanh bạn được giao nhiệm nhập các sản phẩm từ kho
B vào kho A sao cho những sản phẩm nào đã có trong kho A thì không nhập.

Ví dụ:

Với A = ["Banana", "Banana", "Apple"],
B = ["Orange", "Apple", "Orange", "Watermelon"],
thì mergeProducts(A, B) = [true, false, false, true].
Lưu ý: Sản phẩm thứ 3 trong kho B là "Orange" sẽ không được nhập vì 
trong kho A đã có một sản phẩm như vậy.
*/


int main()
{
	vector<string> wareHouseA = { "Banana", "Banana", "Apple" },
		wareHouseB = { "Orange", "Apple", "Orange", "Watermelon" };
	map<string, bool> mapStringBool;
	for (auto produce : wareHouseA) mapStringBool[produce] = true;
	vector<bool> result;
	for (auto produce : wareHouseB) {
		if (mapStringBool.find(produce) == mapStringBool.end()) {
			mapStringBool.insert(make_pair(produce, true));
			result.push_back(true);
		}
		else result.push_back(false);
	}

	for (bool x : result) cout << x << endl;
	return 0;
}