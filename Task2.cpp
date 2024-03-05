#include <iostream>

#define N 17

void pack(int *arrayToPack,int *packedArray,int n){
    for(int i=0;i<n;i++){
        packedArray[arrayToPack[i]]++;
    }
}

void unpack(int *arrayToUnpack,int *packedArray){
    for(int i=0, j=0;j<N+1;){
        if(packedArray[j]>0){
            arrayToUnpack[i] = j;
            packedArray[j]--;
            i++;
        } else {
            j++;
        }
    }
}

template<class T>
void printArray(T *array,int n){
    for(int i=0;i<n;i++){
        std::cout << array[i] << " "; 
    }
    std::cout << std::endl;
}

int main(){
    int size=27,arrayTemplate[] = {0,1,1,2,3,3,4,5,5,6,7,7,8,9,9,10,11,11,12,13,13,14,15,15,16,17,17};
    int packedArray[N+1]={0},*arrayToPack=new int[size],*arrayToUnpack=new int[size];


    for(int i=0;i<size;i++){
        arrayToPack[i]=arrayTemplate[i];
    }


    printArray<int>(arrayToPack,size);
    pack(arrayToPack,packedArray,size);
    printArray<int>(packedArray,N+1);
    unpack(arrayToUnpack,packedArray);
    printArray<int>(arrayToUnpack,size);
    delete arrayToPack,arrayToUnpack;
    return 0;
}