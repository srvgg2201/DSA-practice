#include<iostream>
using namespace std;

//QUICK SORT: best case time complexity: O(nlogn) || worst case: O(n^2) || space complexity: O(1) in-place sorting
//divide and conquer algorithm



//partition function that returns the index of pivot element placed at its correct position in the sorted array
int partition(int* a, int start, int end) {
    int pivot = a[end]; //using last element as the pivot
    int partition_index = start; //stores the index till which partition has been done, set as start initially
    for(int i = start; i < end; i++) { //scan the array till second last element and compare each element with pivot
        if(a[i] <= pivot) {
            swap(a[i], a[partition_index]);
            partition_index++;
        }
    }
    swap(a[partition_index], a[end]); //swapping the pivot to its correct position in the sorted array
    return partition_index;
}

void quick_sort(int* a, int start, int end) {
    if(start < end) {
        int pivot = partition(a, start, end); //pivot stores the index of pivot at its correct position in the sorted array
        quick_sort(a, start, pivot-1); //calling quicksort recursively on first partition (before pivot)
        quick_sort(a, pivot+1, end); //calling quicksort recursively on second partition (after pivot)
    }
}

int main() {
    int n;
    cout << "Enter size :";
    cin >> n;
    int* a = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // int a[] = {8, 6, 2, 5, 9, 1, 3};
    // int a_size = sizeof(a)/ sizeof(a[0]);
    quick_sort(a, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0; 
}