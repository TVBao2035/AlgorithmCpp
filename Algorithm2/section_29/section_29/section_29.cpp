#include <iostream>
#include<stack>
#include<vector>
using namespace std;
/*
* Cho chiều cao của các thanh gỗ theo thứ tự từ trái qua phải, 
ứng với mỗi thanh gỗ bạn gần phải xác định khoảng cách tới thanh 
gỗ nằm bên trái và dài hơn nó là bao nhiêu.
Ví dụ

Chiều cao các thanh gỗ là arr = [100,80,60,70,60,75,85]

Output sẽ có dạng stickSpan[arr] = [1,1,1,2,1,4,6]
*/
vector<int> stickSpan(vector<int> higthOfWooden) {
	stack<int> index;
	vector<int> stick;
	index.push(0);//thêm vị trí với index 0;
	stick.push_back(1);//khoảng cách của phần tử đầu
	int size = higthOfWooden.size();
	for (int i = 1; i < size; i++) {
		while (!index.empty() && higthOfWooden[index.top()] <= higthOfWooden[i]) index.pop();
		stick.push_back(index.empty() ? i + 1 : i - index.top());//nếu index rỗng là phần tử đang xét là lớn nhất nên khoảng cách là i+1
											//còn lại thì phần tử đang xét nhỏ hơn một phần tử trong index nên khoảng cách là i-index.top();
		index.push(i); //thêm index của phần tử cao nhất (phần tử đang xét) nếu index trống; còn lại là phần tử đang xét;
	}
	return stick;
}
int main()
{
	vector<int> higthOfWooden;
	int length;
	cout << "enter number of wooden: "; cin >> length;
	for (int i = 0; i < length; i++) {
		int store; cin >> store; higthOfWooden.push_back(store);
	}
	higthOfWooden = stickSpan(higthOfWooden);
	for (int number : higthOfWooden) cout << number << " ";
	return 0;
}

