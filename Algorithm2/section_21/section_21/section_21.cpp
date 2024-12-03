#include <iostream>
#include <set>
#include<vector>
#include<string>
using namespace std;
/*
Cho hai dãy arr1 và arr2 thuộc kiểu vetor<string>. 
Bạn tạo một dãy từ hai dãy trên theo điều kiện sau:

Kết quả chỉ chứa các chuôi riêng biệt (Không có hai chuỗi nào giống nhau).
Kết quả chứa các phần tử trong arr1 mà không xuất hiện trong arr2.
Các phần tử các dãy kết quả được sắp xếp theo thứ tự từ điểm từ nhỏ đến lớn.
*/
vector<string> megerArray(vector<string> arrayFirst, vector<string> arraySecond) {
    set<string> setArray(arrayFirst.begin(), arrayFirst.end());
    vector<string>::iterator it = arraySecond.begin();
    while (it != arraySecond.end()) {
        if (setArray.find(*it) != setArray.end()) {
            setArray.erase(setArray.find(*it));
        }  
        it++;
    }
    vector<string> result(setArray.begin(), setArray.end());
    return result;
}
int main()
{
    vector<string> arrayStringFirst,arrayStringSecond, arrayString;
    int lengthOfArrayFirst, lengthOfArraySecond;
    cout << "enter length of array first and array second: "; 
    cin >> lengthOfArrayFirst>>lengthOfArraySecond;
    cout << "enter the string elements of array first: " << endl;
    for (int i = 0; i < lengthOfArrayFirst; i++) {
        string store; cin >> store; arrayStringFirst.push_back(store);
    }
    cout << "enter the string elements of array second: " << endl;
    for (int i = 0; i < lengthOfArraySecond; i++) {
        string store; cin >> store; arrayStringSecond.push_back(store);
    }
    arrayString = megerArray(arrayStringFirst, arrayStringSecond);
    cout << "result: " << endl;
    for (string x : arrayString) cout << x << " ";

    return 0;
}

