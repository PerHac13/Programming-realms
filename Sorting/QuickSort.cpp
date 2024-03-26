#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int partition(int arr[], int low, int high)
{

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSort(int arr[], int low, int high)
{

    if (low < high)
    {
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

int main()
{

    int arr[] = {9, 3, 9, 5, 2, 8, 7};

    QuickSort(arr, 0, 6);

    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";

    return 0;
}