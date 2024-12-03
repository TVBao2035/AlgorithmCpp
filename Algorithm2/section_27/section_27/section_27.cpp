#include<iostream>
#include<vector>
#include<stack>

using namespace std;
/*
Cho một danh sách các số nguyên dương arr dưới dạng vector<int>. 
Bạn cần phải đưa từng phần tử trong danh sách này vào stack. 
Sau đó output giá trị nhỏ nhất trong stack trước mỗi lần pop(). 
Xem ví dụ để hiểu rõ hơn.

Ví dụ

Với arr = [4,2,6,7,8,1] thìpopMin(arr) = [1,2,2,2,2,4]
Giải thích: từ arr có được stack: [4,2,6,7,8,1] với 1 là top. 
Trước khi pop() thì 1 là giá trị nhỏ nhất và sau khi pop() stack trở thành [4,2,6,7,8] 
và 2 là giá trị nhỏ nhất, cứ thế ta có kết quả [1,2,2,2,2,4].
*/
vector<int> minValues(vector<int> arrayNumbers) {
	stack<int> storeMinValues;
	storeMinValues.push(arrayNumbers.front());
	for (int number : arrayNumbers) {
		if (storeMinValues.top() < number) storeMinValues.push(storeMinValues.top());
		else storeMinValues.push(number);
		
	}
	vector<int> result;
	while (!storeMinValues.empty()) {
		result.push_back(storeMinValues.top());
		storeMinValues.pop();
	}
	return result;
}

int main()
{
	vector<int> arrayNumbers;
	int lengthOfArray;
	cout << "enter length of array: "; cin >> lengthOfArray;
	cout << "enter elements in Array:" << endl;
	for (int i = 0; i < lengthOfArray; i++) {
		int store; cin >> store; arrayNumbers.push_back(store);
	}
	cout << "display result: ";
	arrayNumbers = minValues(arrayNumbers);
	for (int number : arrayNumbers) cout << number << " ";
	return 0;
}