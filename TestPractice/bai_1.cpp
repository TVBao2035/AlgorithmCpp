#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream input("Frequency.inp");
    ofstream output("Frequency.out");
    int array[1000];
    int count = 0;
    while(input>>array[count]) count++;

    int index = 0;
    int number = array[index];
    index++;

    int arrayNew[1000];
    int length = count-2;
    int key = array[count-1];
    int times[1000] = {0};
    int max = 0;

    for(int i=0; i < length; i++){
        arrayNew[i] = array[index];
        times[arrayNew[i]]++;
        if(max<arrayNew[i]) max = arrayNew[i];
        index++;
    }
    
    int loop = max > length ? max : length;

    for(int i=0;i<loop;i++) if(times[i]>key) output<<i<<":"<<times[i]<<endl;

    cout<<"successful !";
    input.close();
    output.close();
    return 0;
}