#include<iostream>
#include<stack>
#include<vector>
using namespace std;
/*
Cho hai stack st1 và st2 đã được sắp xếp theo tứ tự không giảm.

Hãy ghép hai stack đó thành một, yêu cầu là stack mới cũng sắp xếp không giảm.

Ví dụ:

Với st1 = [1, 3, 6, 8] và st2 = [1, 2, 5]
thì stackConcat(st1, str2) = [1, 1, 2, 3, 5, 6, 8].
*/
vector<int> sortOfTwoArray(vector<int> firstArray, vector<int> secondArray) {
	stack<int> firstStack,secondStack, increaseStack;
	for (int number : firstArray) firstStack.push(number);
	for (int number : secondArray) secondStack.push(number);
	
	while (!firstStack.empty() && !secondStack.empty()) {
		if (firstStack.top() < secondStack.top()) {
			increaseStack.push(secondStack.top());
			secondStack.pop();
		}
		else {
			increaseStack.push(firstStack.top());
			firstStack.pop();
		}
	}
	while (!firstStack.empty()) {
		increaseStack.push(firstStack.top());
		firstStack.pop();
	}
	while (!secondStack.empty()) {
		increaseStack.push(secondStack.empty());
		secondStack.pop();
	}
	vector<int>result;
	while (!increaseStack.empty()) {
		result.push_back(increaseStack.top());
		increaseStack.pop();
	}
	return result;
}
int main()
{
	vector<int> firstArray, secondArray, resultArray;
	int firstLength, secondLength;
	cout << "enter of the first array: "; cin >> firstLength;
	cout << "enter of the second array: "; cin >> secondLength;
	cout << "enter elements in the first array:" << endl;
	int firstStore; cin >> firstStore; firstArray.push_back(firstStore);
	for (int i = 0; i < firstLength; i++) {
		do {
			 cin >> firstStore; 
			 if (firstStore < firstArray.front()) cout << "please enter again!" << endl;
		} while (firstArray.front() > firstStore);
		firstArray.push_back(firstStore);
	}
	cout << "enter elements in the second array:" << endl;
	int secondStore; cin >> secondStore; secondArray.push_back(secondStore);
	for (int i = 0; i < secondLength; i++) {
		do {
			cin >> secondStore;
			if (secondStore < secondArray.front()) cout << "please enter again!" << endl;
		} while (secondArray.front() > secondStore);
		secondArray.push_back(secondStore);
	}
	resultArray = sortOfTwoArray(firstArray, secondArray);
	cout << "display result: " << endl;
	for (int number : resultArray) cout << number << " ";
	return 0;
}