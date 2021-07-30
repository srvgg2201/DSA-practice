#include<iostream>
using namespace std;

//HEAP SORT: O(nlogn) in all cases || in place sorting || space complexity : O(1)

//uses the concept of a max-heap. Largest value is present at the root.
//extract max value from root and swap it with the last value in the array, repeat n times : O(n)
    //call heapify on the reduced heap : O(logn)
// Total time complexity : O(n*logn)

void max_heapify(int arr[], int n, int i) {
    
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < n && arr[largest] < arr[left]) 
        largest = left;
    
    if(right < n && arr[largest] < arr[right])
        largest = right;

    //if root is not largest, swap it with the larger child
    if(largest != i) {
        swap(arr[largest], arr[i]);

        //heapify the affected subtree
        max_heapify(arr, n, largest);
    }       
         
}


void heap_sort(int arr[], int n) {
    //build heap from the array in bottom-up manner. Leaf nodes don't need to be checked.
    for(int i = n/2 - 1; i >= 0; i--) {      // i = n/2 - 1 gives the index of the last internal node with children
        max_heapify(arr, n, i);
    }

    //extract max element from top and put it at the end of the array
    for(int i = n-1; i >= 0; i--) {
        swap(arr[i], arr[0]);

        //call max heapify on the reduced heap
        max_heapify(arr, i, 0);
    }
}
int main() {
    int arr[] = {10, 5, 6, 12, 32, 2};
    int n = sizeof(arr)/ sizeof(arr[0]);
    heap_sort(arr, n);
    cout << "sorted array : \n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

}