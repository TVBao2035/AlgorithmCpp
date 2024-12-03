#include <iostream>
#include<list>
#include<vector>
using namespace std;
/*
Cho một list các số nguyên. Hãy sắp xếp các phần tử trong list theo thứ tự không giảm.
*/
list<int> sortElements(list<int>lis) {
    list<int>::iterator it, its;
    for (it = lis.begin(); it != lis.end(); it++) {
        for (its = it; its != lis.end(); its++) {
            if (*it > *its) {
                int store = *it;
                *it = *its;
                *its = store;
            }
        }
    }
    return lis;
}
int main()
{
    list<int>lis{9,8,7,6,5,2,3,1,4,0};
    lis = sortElements(lis);
    vector<int>vec(lis.begin(), lis.end());
    for (int x : vec) cout << x << " ";
    return 0;
}
