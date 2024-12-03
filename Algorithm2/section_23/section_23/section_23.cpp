#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <list>
using namespace std;
/*
Việt đang muốn tạo ra những từ khác nhau từ chuỗi word. Với một chu kỳ, 
Anh bắt đầu bằng cách lấy ký tự cuối cùng của chuỗi word và di chuyển nó lên đầu.
Anh có thể thực hiện chu kỳ này rất nhiều lần.

Ví dụ lên tục thực hiện chu kỳ biến đổi đó trên word = "abcda" thì anh Việt sẽ nhận được các từ "aabcd", "daabc",...


Anh Việt muốn biết rằng mình có thể tạo được bao nhiều từ riêng biệt bằng cách biến đổi trên.

Ví dụ:

Với word = "abcd" thì kết quả sẽ là  cyclicWord(word) = 4
các từ mà anh Việt có thể nhận được là "abcd", "dabc", "cdab" và "bcda".
*/
vector<string> creatNewString(string word) {
	set<string> storeString;
	for (int i = 0; i < word.length(); i++) {
		char oneChar = word.back();
		word.pop_back();
		word.insert(word.begin(), oneChar);
		storeString.insert(word);
	}
	vector<string> result(storeString.begin(), storeString.end());
	return result;
}
int main()
{
	string word;
	cout << "enter the word: "; fflush(stdin); getline(cin,word);
	vector<string> result;
	result=creatNewString(word);
	cout << "result:";
	for (string x : result) cout << x<<" ";
	return 0;
}

