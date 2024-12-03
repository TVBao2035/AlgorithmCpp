#include <iostream>
#include<set>
#include<vector>
using namespace std;
/*
Cho một dãy số nguyên arr và số nguyên k.

Hãy tìm ra hai số:

Số m là số nhỏ nhất trong dãy lớn hơn k. Nếu không có thì m = -1.
Số n là số nhỏ nhất trong dãy lớn hơn hoặc bằng k. Nếu không có thì n = -1.
Kết quả trả về là dãy gồm 2 số [m,n].
*/
vector<int> findTwoElements(vector<int> arrayNumbers, int key) {
    set<int> setArray(arrayNumbers.begin(), arrayNumbers.end());
    set<int>::iterator it = setArray.upper_bound(key);
    int m, n;
    if (it == setArray.end()) m = -1;
    else m = *it;
    it = setArray.lower_bound(key);
    if (it == setArray.end()) n = -1;
    else n = *it;

    return { m,n };
}
int main()
{
    vector<int> arrayNumbers;
    int lengthVector;
    cout << "enter length vector: "; cin >> lengthVector;
    cout << "enter element of vector:" << endl;
    for (int i = 0; i < lengthVector; i++) {
        int store; cin >> store; arrayNumbers.push_back(store);
    }
    cout << "enter a key : "; int key; cin >> key;

    cout << "result: " << findTwoElements(arrayNumbers, key)[0]<<" - "<<findTwoElements(arrayNumbers, key)[1];
    return 0;
}


