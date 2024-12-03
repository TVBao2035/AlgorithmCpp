#include<iostream>
using namespace std;
/*
Nhập và một số nguyên dương n, tiếp theo là n số nguyên dương lần lượt là các phần tử của một dãy số a.
Hãy kiểm tra xem dãy a có phải là dãy đơn điệu hay không, trả về "YES" nếu có, "NO" nếu không.

Một dãy đơn điệu khi nó là dãy số tăng (a[i] > a[i-1]), hoặc dãy số giảm (a[i] < a[i-1]).
*/
int main()
{
	bool increase = false;
	bool reduce = false;
	int a[100], n;
	cout << "enter n: "; cin >> n;
	cout << "enter a[0] to a[" << n - 1 << "]: " << endl;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n-1; i++) {
		if (a[i] >= a[i + 1]) increase = true;
		else reduce = true;
	}
	if (n == 1) {
		increase = true;
		reduce = false;
	}
	if ((increase == true && reduce == false) || (increase == false && reduce == true)) cout << "YES";
	else cout << "NO";
	return 0;
}