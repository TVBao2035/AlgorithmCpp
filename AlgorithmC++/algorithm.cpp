#include<iostream>


void printArry(int arr[], int lenght){
    for(int i=0; i<lenght; i++) std::cout<<arr[i]<<" ";
    std::cout<<std::endl;
}

void bubbleSort(int arr[], int length){
    for(int i=0; i < length-1; i++){
        for(int j=0; j < length;j++){
            if(arr[j+1]<arr[j]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                printArry(arr, length);
            }
        }
    }
}

void insertionSort(int arr[], int length){
    for(int i=1; i<length; i++){
        int j = i-1;
        int currentValue = arr[i];
        while(j>=0 && arr[j] > currentValue){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = currentValue;
    }
}

void selectionSort(int arr[], int length){
    for(int i=0; i<length-1; i++){
        int indexOfMinValue = i;
        int j = i + 1;
        while(j < length){
            if (arr[j] < arr[indexOfMinValue]){
                indexOfMinValue = j;
            }
            j++;
        }
        if (indexOfMinValue != i){
            int temp = arr[i];
            arr[i] = arr[indexOfMinValue];
            arr[indexOfMinValue] = temp;

        }

    }
}
int main(){
    int n = 10;
    int a[n] = {2, 5, 6, 7, 8, 1, 4, 3, 9, 0};
    printArry(a, n);
    bubbleSort(a, n);
    printArry(a, n);
    return 0;
}