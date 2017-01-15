#include <iostream>

using namespace std;

void sort(int arr1[100],int arr2[100], int arr[100],int s1, int e1, int s2, int e2,int n);
void cutArray(int arr[100],int n);



int main()
{
    int arr[100] = {5,-2,10,23,18,-9,33,0,12};

    cutArray(arr, 9);


    return 0;
}


void cutArray(int arr[100],int n){

   if(n > 1){

       int arr1[100],arr2[100];
        int size1 = (n)/2;
        int size2 = n - size1;

        for(int i = 0; i < size1 ; i++){
            arr1[i] = arr[i];
        }

        for(int i = size1 ; i < n ; i++){
            arr2[i - size1] = arr[i];
        }

        cutArray(arr1,size1);
        cutArray(arr2,size2);

        sort(arr1,arr2,arr,0,size1-1,0,size2-1,0);

   }

}

void sort(int arr1[100],int arr2[100], int arr[100],int s1, int e1, int s2, int e2,int n){
    if(s1 <= e1 || s2 <= e2){
        if(s1 > e1){
            arr[n] = arr2[s2];
            sort(arr1,arr2,arr,s1,e1,++s2,e2,++n);
        }else if(s2 > e2){
            arr[n] = arr1[s1];
            sort(arr1,arr2,arr,++s1,e1,s2,e2,++n);
        }else if (arr1[s1] > arr2[s2]){
            arr[n] = arr2[s2];
            sort(arr1,arr2,arr,s1,e1,++s2,e2,++n);
        }else{
            arr[n] = arr1[s1];
            sort(arr1,arr2,arr,++s1,e1,s2,e2,++n);
        }
    }
}

