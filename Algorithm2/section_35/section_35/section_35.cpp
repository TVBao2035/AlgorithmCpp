#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
/*
Số siêu nguyên tố là số:

Bản thân nó là số nguyên tố.
Khi xóa đi lần lượt các chữ số sau cùng của nó thì số mới vẫn là số nguyên tố.
Ví dụ 2393 là số siêu nguyên tố vì 2393, 239, 23, 2 là số nguyên tố.

Cho một số n, hãy đưa số dãy số siêu nguyên tố nhỏ hơn hoặc bằng n đã được sắp xếp tăng dần.

Ví dụ:

Với n = 30; thì superPrimeNumber(n) = [2, 3, 5, 7, 23, 29];
Vì các số 2, 3, 5, 7, 23 và 29 đều là số siêu nguyên tố và nhỏ hơn hoặc bằng 30.
*/
bool isPrime(int number) {
	if (number < 2) return false;
		for (int i = 2; i <= sqrt(number); i++) {
			if (number % i == 0) return false;
		}
	return true;
}
vector<int> superPrimeNumber(int number) {
	queue<int> storePrime;
	vector<int> result;
	int loop = number < 7 ? number : 8;
	for (int i = 2; i < loop; i++) if (isPrime(i)) storePrime.push(i);
	while (!storePrime.empty()) {
		for (int i = 1; i <= 9; i++) {
			int store = storePrime.front() * 10 + i;
			if (store <= number && isPrime(store)) storePrime.push(store);
		}
		result.push_back(storePrime.front());
		storePrime.pop();
	}
	return result;
}
int main()
{
	int number;
	cout << "enter a number: "; cin >> number;
	vector<int> result = superPrimeNumber(number);
	for (int x : result) cout << x << " ";
	return 0;
}