#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream input("Density.inp");
    ofstream output("Density.out");

    int count = 0;
    int array[1000];
    while(input>>array[count]) count++;

    int index = 0;
    int row, column;
    row = array[index];
    index++;
    column = array[index];
    index++;

    int matrix[100][100];
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            matrix[i][j] = array[index];
            index++;
        }
    }

   for(int i = 0; i < row; i++){
      for(int j = 0; j < column; j++){
          int x[] ={-1, 1, 0, 0,-1, 1,-1, 1};
          int y[] ={ 0, 0, 1,-1, 1,-1,-1, 1};
          int check = false;
          for(index = 0; index < 8; index++){
            int t = i + x[index];
            int z = j + y[index];
            if(t >= 0 && z >= 0 && t < row && z < column ){
                if(matrix[i][j] > matrix[t][z]) check = true;
                else{
                    check = false;
                    break;
                }
            }
          }
          if(check) output<<i+1<<" "<<j+1<<endl;
      }
   }

   output.close();
   input.close();
    return 0;
}