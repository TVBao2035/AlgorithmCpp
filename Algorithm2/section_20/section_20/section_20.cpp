#include <iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;
/*
Anh Việt đang thông kê số liệu cho công ty, anh muốn giá trị nhỏ thứ hai
ở trong một dãy số nguyên.

Hãy giúp anh Việt tìm ra giá trị đó, nếu không có kết quả như yêu cầu thì trả về "NO".
*/
string findSecondValue(vector<int> documentNumbers) {
    set<int> eniquenNumber;
    for (int i = 0; i < documentNumbers.size(); i++) {
        eniquenNumber.insert(documentNumbers[i]);
    }
    set<int>::iterator it = eniquenNumber.begin();
    advance(it, 1);
    if (eniquenNumber.size() > 1) return to_string(*it);
    return "no";
}
int main()
{
    vector<int> documentNumbers;
    int lenght; cout << "enter numbers for documnet: "; cin >> lenght;
    cout << "enter elements for document: " << endl;
    for (int i = 0; i < lenght; i++) {
        int store; cin >> store; documentNumbers.push_back(store);
    };
    cout << "second value is " << findSecondValue(documentNumbers);
    return 0;
}