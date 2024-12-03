#include<iostream>
#include<stack>
#include<vector>
using namespace std;
/*
Đề bài
Bạn được cho một dãy các số nguyên arr và số nguyên dương k,
nhiệm vụ của bạn là xóa đi k số đầu tiên mà nhỏ hơn số đứng ngay sau nó(xóa arr[i] nếu arr[i + 1] > arr[i]).
Lưu ý nếu xóa arr[i + 1] thì arr[i + 2] trở thành số đứng ngay sau arr[i], arr[i + 3] đứng sau arr[i + 2]...

Ví dụ

Cho arr = [20,10,25,30,40], k = 2, removeElements(arr, k) = [25,30,40]
Sau khi xóa 10 thì 20 trở nên nhỏ hơn 25 nên xóa tiếp 20. 
Lúc này đã xóa đủ 3 phần tử nên [25,30,40] là kết quả trả về.
Đầu vào luôn thỏa mãn trong dãy số luôn có nhiều hơn hoặc đủ k phần tử dể xóa.
*/
vector<int> removeElements(vector<int> arrayNumbers, int word) {
	stack<int> storeNumbers;
	vector<int> result;
	for (int i = 0; i < arrayNumbers.size(); i++) {// lap qua cac phan tu trong mang
		if (storeNumbers.empty()) storeNumbers.push(arrayNumbers[i]);//neu stack trong thi push vao stack
		else {
			if (storeNumbers.top() >= arrayNumbers[i]) {
				storeNumbers.push(arrayNumbers[i]);
			}
			else {
				while (word > 0 && !storeNumbers.empty() && storeNumbers.top() < arrayNumbers[i]) {
					storeNumbers.pop();
					word--;
				}
				if (word == 0) { // neu word = 0 thi chuyen cac phan tu tu stack sang vector
					while (!storeNumbers.empty()) {
						result.push_back(storeNumbers.top());
						storeNumbers.pop();
					}
					reverse(result.begin(), result.end());//dao cac phan tu
					for (int j = i; j < arrayNumbers.size(); j++) result.push_back(arrayNumbers[j]);// them cac phan tu con lai vao vector
					break;
				}
				if (storeNumbers.empty()) storeNumbers.push(arrayNumbers[i]);
			}
		}
	}
	return result;
}
int main()
{
	vector<int> arrayNumbers;
	int length;
	cout << "enter number of elements: "; cin >> length;
	cout << "enter elements : " << endl;
	for (int i = 0; i < length; i++) {
		int  store; cin >> store; arrayNumbers.push_back(store);
	}
	int word;
	cout << "enter number of eares:"; cin >> word;
	arrayNumbers = removeElements(arrayNumbers, word);
	for (int x : arrayNumbers) cout << x << " ";
	return 0;
}