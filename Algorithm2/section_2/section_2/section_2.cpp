#include<iostream>
using namespace std;
/*
Nhập và một số nguyên dương n, tiếp theo là n số nguyên dương lần lượt là các phần tử của một dãy số,
hãy đếm tần số (số lần xuất hiện) của các số trong dãy và in nó ra màn hình dưới dạng sau:
"a1 - t1; a2 - t2; ... an - tn; ",trong đó t1 là số lần xuất hiện của số a1, t2 là số lần xuất hiện 
của a2, ... a1, a2, .. an không trùng nhau và được sắp xếp tăng dần
*/
int main()
{
	int a[1000];
	int b[1000] = {0};
	int n;
	cout << "enter n: "; cin >> n;
	cout << "enter a[0] to a[" << n - 1 << "]:" << endl;
	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > max) {
			max = a[i];
		}
	}


	for (int i = 0; i < n; i++) {
		b[a[i]]++;
	}

	for (int i = 0; i <= max; i++) {
		if (b[i] != 0) {
			cout << i << "-" << b[i] << endl;
		}
	}
	return 0;
}