#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;
/*
An có một danh sách các sản phẩm trong siêu thị nhưng thật không may trong danh sách lại có những sản phẩm xuất hiện nhiều lần. Bạn hãy giúp An làm lại danh sách sao cho một sản phẩm chỉ xuất hiện một lần trong danh sách và các sản phẩm xuất hiện theo thứ tăng dần trong từ điển.

Ví dụ:

Với products = ["watermelon", "grapes", "grapes", "apple", "grapes"]
thì getDistinctProducts(products) = ["apple", "grapes", "watermelon"].
*/
vector<string> getDistinctProducts(vector<string>nameOfProducts) {
    set<string> uniquenName(nameOfProducts.begin(),nameOfProducts.end());
    vector<string> result(uniquenName.begin(), uniquenName.end());
    return result;

}
int main()
{
    vector<string> nameOfProducts;
    int lengthOfSize; cout << "enter length of size: "; cin >> lengthOfSize;
    cout << "enter products: ";
    for (int i = 0; i < lengthOfSize; i++) {
        string store; cin >> store;
        nameOfProducts.push_back(store);
    }
    nameOfProducts = getDistinctProducts(nameOfProducts);
    cout << "resutl:";
    for (string store : nameOfProducts) cout << store << " ";
    return 0;
}


