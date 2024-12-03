#include<iostream>
#include<list>
#include<vector>
using namespace std;
/*
Cho một list chứa các số nguyên và một số nguyên n, 
hãy xóa những phần tử có giá trị lớn hơn hoặc bằng n trong list đó.
*/
list<int> removeElements(list<int>lis, int value) {
	list<int>::iterator it = lis.begin();
	while (it != lis.end()) {
		if (*it >= value) {
			it = lis.erase(it);//important
	/* tại sao phải gán it = lis.earse(it).
	vì khi gọi hàm erase() thì it không còn trỏ đến lis mà trỏ đến vị trí vừa xóa.
	Nên ta gán it = lis.earse(it) vì erase() khi xóa phần thì nó sẽ trả về con trỏ ở vị 
	trí bên phải phần tử vừa xóa*/
		}
		else {
			it++;
		}
	}
	return lis;
}
int main()
{
	list<int> lis;
	int element;
	cout << "enter an element: "; cin >> element;
	for (int i = 0; i < element; i++) {
		int store; cin >> store; lis.push_back(store);
	}
	int value; cout << "enter a value :"; cin >> value;
	lis = removeElements(lis, value);
	vector<int> vec(lis.begin(), lis.end());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	return 0;
}