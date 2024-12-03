#include<iostream>
#include<queue>
#include<string>
using namespace std;
/*
Huyền có một cái điện thoại, màn hình điện thoại của Huyền chỉ hiển thị được tối đa k tin nhắn.
Màn hình của Huyền hiện thị như sau:

Không hiện thị 2 tin nhắn của cùng một số điện thoại (SĐT) trên cùng một khung hình,
nếu SĐT a gửi tin nhắn đến mà trên màn hình đã có tin nhắn của SĐT a thì màn hình không thay đổi gì.
Khi SĐT a gửi tin nhắn đến mà trên màn hình chưa có tin nhắn của SĐT a thì:
Nếu màn hình chưa đủ k tin nhắn thì tin nhắn của SĐT a sẽ được chèn vào cuối màn hình.
Nếu màn hình đã có đủ k tin nhắn thì thì màn hình sẽ đẩy tin nhắn trên cùng ra 
và sau đó chèn tin nhắn của SĐT a vào cuối màn hình.

Cho dãy a là các SĐT sẽ gửi tin nhắn cho Huyền.
Hỏi sau khi nhận được tin nhắn cuối cùng thì màn hình của Huyền đang hiển thì tin nhắn của các SĐT nào,
đưa ra theo thứ tự từ trên xuống dưới của màn hình.
*/
int main()
{
	int arrayMessagesPhone[1000], allMessagesPhone, widthOfSreen;
	cout << "How many are there message phone: "; cin >> allMessagesPhone;
	cout << endl << "enter width of sreen:"; cin >> widthOfSreen;
	cout << endl << "enter all message phones:" << endl;
	for (int i = 0; i < allMessagesPhone; i++) {
		cin >> arrayMessagesPhone[i];
	}

	queue<int> que;
	int arrayCheck[1000] = {0};
	for (int i = 0; i < allMessagesPhone; i++) {
		if (arrayCheck[arrayMessagesPhone[i]] == 0) {
			if (que.size() == widthOfSreen) {
				que.pop();
				que.push(arrayMessagesPhone[i]);
			}
			else {
				que.push(arrayMessagesPhone[i]);
			}
			arrayCheck[arrayMessagesPhone[i]] = 1;
		}
	}

	string result = "";
	while (!que.empty()) {
		result += to_string(que.front()) + " ";
		que.pop();
	}
	cout << "result: " << result;
	return 0;
}