#include <iostream>
#include<queue>
#include<vector>
using namespace std;
/*
Cho một ma trận trong đó mỗi ô trong ma trận có thể
có các giá trị 0, 1 hoặc 2 có nghĩa sau:

0: Là một ô trống.
1: Là một quả cam tươi.
2: Là một quả cam bị hỏng.

Chúng ta phải xác định thời gian tối thiểu mà 
tất cả các quả cam bị hỏng. Một quả cam hỏng ở chỉ số [i, j] 
có thể làm hỏng quả cam tươi khác ở các chỉ số
[i-1, j], [i + 1, j], [i, j-1], [i, j + 1]
(lên , xuống, trái và phải). Nếu không thể bị hỏng tất cả quả cam thì trả về -1.
Ví dụ:

Với matrix = [
[2x, 1x, 0, 2x, 1x],
[1x, 0, 1x, 2x, 1x],
[1x, 0, 0, 2x, 1x]].
cam thoi =1
cam thom =0
cam bi dong hoa = 0
time 2
Thì đầu ra có dạng  rotOrange(matrix) = 2

Với matrix = [
[2, 1, 0, 2, 1],
[0, 0, 1, 2, 1],
[1, 0, 0, 2, 1]].
Thì đầu ra có dạng rotOrange(matrix) = -1
*/
int rotOrange(vector<vector<int>> matrixOfOrange, int row, int column) {
    queue<int> x, y;
    int time = 0, badfruit = 0, goodfruit = 0, changefruit = 0;
    //kiểm tra so lượng goodfruit and badfruit 
    for (int i = 0; i < matrixOfOrange.size(); i++) {
        for (int j = 0; j < matrixOfOrange[i].size(); j++) {
            if (matrixOfOrange[i][j] == 2) {
                x.push(i);
                y.push(j);
                badfruit++;
                matrixOfOrange[i][j] = 0;
            }
            else if (matrixOfOrange[i][j] == 1) {
                goodfruit++;
            }
        }
    }

    while (!x.empty()) {
        badfruit--;//bỏ quả badfruit
        int z[] = { 0 ,1, 0 ,-1 };
        int t[] = { 1,0,-1,0 };
        for (int d = 0; d < 4; d++) {
            int xx = x.front() + z[d];
            int yy = y.front() + t[d];
            //kiểm tra xung quanh quả badfruit có quả goodfuit không 
            if (xx >= 0 && xx < matrixOfOrange.size() && yy >= 0 && yy < matrixOfOrange[1].size() && matrixOfOrange[xx][yy] == 1) {
                matrixOfOrange[xx][yy] = 0;
                goodfruit--; //giảm quả goodfruit
                changefruit++;//số quả thay đổi trừ good sang bad
                x.push(xx);
                y.push(yy);
            }
        }
        if (changefruit > 0 && badfruit == 0) {//nếu hêt quả badfruit đợt này
            badfruit = changefruit; // quả đang thay dổi sẽ hư 
            changefruit = 0;//quả thay dổi hết
            time++;//sồ lần bỏ quả hư 
        }
        x.pop();
        y.pop();
    }
    if (goodfruit == 0) {// tất cả bị thối 
        return time;
    }
    return -1;
}
int main()
{
    vector<vector<int>> matrixOfOrange;
    int row, column;
    cout << "enter row and column of matrix of orange: "; cin >> row >> column;
    matrixOfOrange.resize(row);

    for (int i = 0; i < row; i++)  matrixOfOrange[i].resize(column);

    cout << "enter elements in matrix of orange:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> matrixOfOrange[i][j];
        }
    }

    cout << "result: " << rotOrange(matrixOfOrange,row,column);
    return 0;
}

