#include <iostream>
#include<set>
#include<vector>
#include<string>
using namespace std;
/*
Trong ngôn ngữ Aramic từ có thể đại diện cho các đối tượng.

Các từ trong Aramic có tính chất đặc biệt:

Một từ là một gốc nếu nó không chứa cùng một chữ cái nhiều lần.
Một gốc và tất cả các hoán vị của nó cũng chỉ đại diện cho cùng một đối tượng.
Từ gốc x của một từ y là từ chứa tất cả các chữ cái xuất hiện trong y theo cách mà mỗi chữ cái xuất hiện một lần. Ví dụ: gốc của "aaaa", "aa", "aaa" là "a", gốc của "aabb", "bab", "baabb", "ab" là "ab".
Bất kỳ từ nào trong Aramic đại diện cho cùng một đối tượng với gốc của nó.
Bạn có một dãy từ Aramic. Hãy đưa ra số lượng đối tượng khác nhau trong dãy đó.

Ví dụ:

Với words = ["a","aa","aaa","ab","abb"] thì kết quả là: aramic(words) = 2.
*/
int numberAramic(vector<string> vectorString) {
    set<string> result;
    for (int i = 0; i < vectorString.size(); i++) {
        string store = vectorString[i];
        set<char> storeChar(store.begin(),store.end());
        string addWord = "";
        set<char>::iterator it;
        for (it = storeChar.begin(); it != storeChar.end(); it++) {
            addWord += *it;
        }
        result.insert(addWord);
    }
    return result.size();
}

int main()
{
    vector<string> vectorString;
    int length; cout << "enter length: "; cin >> length;
    cout << "enter elements string: " << endl;
    for (int i = 0; i < length; i++) {
        string word; cin>>word;
        vectorString.push_back(word);
    }
    cout << "result: " << numberAramic(vectorString);
}
