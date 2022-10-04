#include <iostream>
void Merge(int arr[], int left, int right) {
    int it1 = 0;
    int it2 = 0;
    int mid = (right + left) / 2;
    int result[right - left];
    while (left + it1 < mid and mid + it2 < right) {
        if (arr[left + it1] < arr[mid + it2]) {
            result[it1 + it2] = arr[left + it1];
            it1 += 1;
        } else {
            result[it1 + it2] = arr[mid + it2];
            it2 += 1;
        }
    }
    while (left + it1 < mid) {
        result[it1 + it2] = arr[left + it1];
        it1 += 1;
    }
    while (mid + it2 < right) {
        result[it1 + it2] = arr[mid + it2];
        it2 += 1;
    }
    for (int i = 0; i < it1 + it2; i++) {
        arr[left + i] = result[i];
    }
}

void MergeSort(int arr[], int left, int right){
    if(left+1>=right){
        return;
    }
    int mid=(left+right)/2;
    MergeSort(arr,left, mid);
    MergeSort(arr,mid, right);
    Merge(arr,left, right);
}

int Partition(int arr[], int left, int right) {
    int x = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= x) {
            i += 1;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[right]);
    return i + 1;
}

void QuickSort(int arr[], int left, int right) {
    if (left < right) {
        int q = Partition(arr, left, right);
        QuickSort(arr, left, q - 1);
        QuickSort(arr, q + 1, right);
    }
}

int main(){

    return 0;
}