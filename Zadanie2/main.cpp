#ЛАБ. РАБОТА 3 РЕШЕШИЕ НА C++ ЗАДАЧА 2



#include <iostream>

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 -1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n -1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    for (int i = 0; i < n; i++)
        std::cout << arr[i];

    return 0;
}
