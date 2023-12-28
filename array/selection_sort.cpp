#include <iostream>
using namespace std;

// selection sort function
void selection_sort(int arr[], int Size) {
    int i, j, min, temp;
    for (i = 0; i < Size - 1; i++) {
        min = i;
        for (j = i + 1; j < Size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    cout << "\nSorted array is: ";
    for (i = 0; i < Size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int Size, i;
    cout << "\n Enter the size of array: ";
    cin >> Size;

    int arr[Size];

    cout << "\n Enter the elements of array: ";
    for (i = 0; i < Size; i++) {
        cin >> arr[i];
    }

    cout << "\nElements of array are: ";
    for (i = 0; i < Size; i++) {
        cout << arr[i] << " ";
    }

    selection_sort(arr, Size);

    return 0;
}