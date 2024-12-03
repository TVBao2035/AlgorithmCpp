#include<iostream>
#include<set>
#include<vector>
using namespace std;
/*
Cho một ma trận gồm các dãy nhị phân khác nhau.

Hãy đưa ra các dãy nhị phân khác nhau trong ma trận đó.
*/
vector<vector<int>> uniquenRows(vector<vector<int>> matrix) {
	set<vector<int>> setMatrix;
	vector<vector<int>> result;
	vector<vector<int>>::iterator it;
	for (it = matrix.begin(); it != matrix.end(); it++) {
		if (!setMatrix.count(*it)) result.push_back(*it);
		setMatrix.insert(*it);
	}
	return result;
}

int main() {
	vector < vector<int>> matrix;
	int row, column;
	cout << "enter row and column: "; cin >> row >> column;
	cout << "enter elements in the matrix:" << endl;
	matrix.resize(row);// khởi tạo hàng cho matrix
	for (int i = 0; i < row; i++) matrix[i].resize(column); //khởi tạo cột cho matrix
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> matrix[i][j];
		}
	}
	cout << "display matrix thought set:" << endl;
	matrix = uniquenRows(matrix);
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < column; j++) {
			cout << matrix[i][j]<<" ";
		}
		cout << endl;
	}
	return 0;
}