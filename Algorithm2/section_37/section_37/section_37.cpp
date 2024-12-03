#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//Cho ma trận các số chỉ chứa giá trị 0 và 1.
//  Hai phần tử được coi là cùng một cụm khi 2 
// phần tử này có chung cạnh và đều có giá trị
//  bằng 1. Các phần tử có giá trị bằng 0 không được coi là một cụm.Bạn hãy viết hàm đếm số cụm của một ma trận cho trước.
//
//Ví dụ :
//
//Cho matriix =
//[[1, 0, 0, 1, 1], 1 0 0 1 1
//[0, 1, 1, 1, 1],  
//[1, 1, 0, 0, 0],
//[0, 0, 1, 0, 1]]
 /*
 1 0 0 1 1
 0 1 1 1 1
 1 1 0 0 0
 0 0 1 0 1
 */
//Ouput sẽ có dạng cluster(matriix) = 4
int cluster(vector<vector<int>> matrix) {
	int result = 0;
	queue<int> x, y;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			if (matrix[i][j] == 1) {
				x.push(i);
				y.push(j);
				result++;
				matrix[i][j] = 0;
			}
			while (!x.empty()) {
				int z[] = { 0, 1, 0, -1 };
				int t[] = { 1, 0, -1, 0 };
				for (int index = 0; index < 4; index++) {
					int xx = (x.front() + z[index]);
					int yy = (y.front() + t[index]);
					if (xx >= 0 && 
						xx< matrix.size() && 
						yy >= 0 && 
						yy < matrix[1].size() && 
						matrix[xx][yy]==1)

					{
						x.push(xx);
						y.push(yy);
						matrix[xx][yy] = 0;
					}
				}
				x.pop();
				y.pop();
			}
		}
	}
	return result;
}
int main()
{
	vector<vector<int>> matrix;
	int row, column;
	cin >> row >> column;
	matrix.resize(row);
	for (int i = 0; i < matrix.size(); i++) {
		matrix[i].resize(column);
	}
	cout << "enter matrix: " << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> matrix[i][j];
		}
	}
	cout << "answer: " << cluster(matrix);
	return 0;
}