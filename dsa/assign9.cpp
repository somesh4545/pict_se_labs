// implement Heap sort to sort given set of values using max or min heap.
// ref : https : // www.geeksforgeeks.org/heap-sort-for-decreasing-order-using-min-heap/
// theory : https://www.geeksforgeeks.org/heap-sort/
// heap sort complexity is nlogn while heap complexity is n

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int i, int n)
{
    int largest = i;
    int l = i * 2;
    int r = i * 2 + 1;

    if (l < n && arr[l] < arr[largest])
    {
        largest = l;
    }

    if (r < n && arr[r] < arr[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, i, n);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[i], arr[0]);
        heapify(arr, 0, i);
    }
}

int main()
{

    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    buildHeap(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}