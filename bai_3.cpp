#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream input("Pandemic.inp");
    ofstream output("Pandemic.out");
    int array[1000];
    int index = 0;
    while(input>>array[index]) index++;

    int row = array[0];
    int count = 2;
    int column = array[1];

    int map[100][100];
    char plan[100][100];
    int treatment = 0;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            map[i][j] = array[count];
            
            if(map[i][j]==1) {
                plan[i][j] = 'O';
                treatment++;
            } else plan[i][j] = '#';
            count++;
        }
    }
    
    int captain = array[count];
    int x[6], y[6];
    int t = 0, z = 0;
    count++;
    for(int i = count; i<index ;i++){
        if(t == z){
            x[t] = array[i]-1;
            t++;
        } else{
            y[z] = array[i]-1;
            z++;
        }
    }
    

    for(int i=0; i < captain; i++){
        int xx[] = {-1, 1, 0, 0,-1, 1,-1, 1};
        int yy[] = { 0, 0, 1,-1, 1,-1,-1, 1};
        if(map[x[i]][y[i]] == 1){
            plan[x[i]][y[i]] = 'X';
            map[x[i]][y[i]] = 0;
            treatment--;
        }
        for(index = 0; index < 8; index++){
            int X = x[i] + xx[index];
            int Y = y[i] + yy[index];
            if(X>=0 && Y>=0 && X<row && Y<column && map[X][Y] == 1){
                plan[X][Y] = 'X';
                map[X][Y] = 0;
                treatment--;
            }
        }
    }
    output<<treatment<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            output<<plan[i][j]<<" ";
        }
        output<<endl;
    }
    return 0;
}