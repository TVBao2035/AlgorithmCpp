#include<iostream>
#include<queue>
#include<string>
#include<math.h>
using namespace std;
/*
Số siêu nguyên tố là số:

Bản thân nó là số nguyên tố.
Khi xóa đi lần lượt các chữ số sau cùng của nó, thì số mới vẫn là số nguyên tố.
Ví dụ 2393 là số siêu nguyên tố vì 2393, 239, 23, 2 là số nguyên tố.

Cho một số n, hãy đưa số dãy số siêu nguyên tố nhỏ hơn hoặc bằng n, các số đã được sắp xếp tăng dần.
*/
bool isPrime(int number) {
	for (int i = 2; i <= sqrt(number); i++) {
		if (number % i == 0) return false;
	}
	return true;
}
int main()
{
	int number;
	queue <int> que;
	cout << "enter a prime:";
	cin >> number;

	for (int i = 1; i <= 7; i++) {
		if (isPrime(i) == true) {
			que.push(i);
		}
	}
	string result = "";
	while (!que.empty()) {
		result += to_string(que.front()) + " ";
		for (int i = 0; i < 10; i++) {
			int addPrime = que.front() * 10 + i;
			if (isPrime(addPrime)==true && addPrime<=number) {
				que.push(addPrime);
			}
		}
		que.pop();
	}
	cout << "result: " << result << endl;
	return 0;
}