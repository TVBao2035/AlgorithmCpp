#include<iostream>
using namespace std;
/*
Cho dãy a gồm n số nguyên, và dãy b gồm m số nguyên, cả hai dãy đều được sắp xếp không giảm.
Hãy gộp hai dãy thành một dãy c, sao cho dãy c cũng là dãy không giảm. In dãy c ra màn hình, 
sau mỗi phần tử có đúng một dấy cách.
*/
void sort(int array[], int length) {
	for (int i = 0; i < length-1; i++) {
		for (int j = i + 1; j < length; j++) {
			if (array[i] > array[j]) {
				int store = array[i];
				array[i] = array[j];
				array[j] = store;
			}
		}
	}
}
int main()
{
	int arrayOne[1000];
	int arrayTwo[1000];
	int arrayMegerSort[1000];
	int lengthArrayOne, lengthArrayTwo;
	cout << "enter length of array one and array two: "; cin >> lengthArrayOne >> lengthArrayTwo;
	cout << "enter elements of array one:" << endl;
	for (int i = 0; i < lengthArrayOne; i++) {
		cin >> arrayOne[i];
	}
	cout << "enter elements of array two:" << endl;
	for (int i = 0; i < lengthArrayTwo; i++) {
		cin >> arrayTwo[i];
	}
	sort(arrayOne, lengthArrayOne);
	sort(arrayTwo, lengthArrayTwo);
	int pointerOne = 0, pointerTwo = 0, pointerMegerSort = 0;
	while (pointerOne < lengthArrayOne && pointerTwo < lengthArrayTwo) {
		if (arrayOne[pointerOne] > arrayTwo[pointerTwo]) {
			arrayMegerSort[pointerMegerSort] = arrayTwo[pointerTwo];
			pointerTwo++;
		}
		else {
			arrayMegerSort[pointerMegerSort] = arrayOne[pointerOne];
			pointerOne++;
		}
		pointerMegerSort++;
	}

	while (pointerOne < lengthArrayOne) {
		arrayMegerSort[pointerMegerSort] = arrayOne[pointerOne];
		pointerOne++;
		pointerMegerSort++;
	}
	while (pointerTwo < lengthArrayTwo) {
		arrayMegerSort[pointerMegerSort] = arrayTwo[pointerTwo];
		pointerTwo++;
		pointerMegerSort++;
	}

	cout << "display elements of array meger sort:" << endl;
	for (int i = 0; i < pointerMegerSort; i++) {
		cout << arrayMegerSort[i] << " ";
	}
	return 0;
}