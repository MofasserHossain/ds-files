#include <iostream>
using namespace std;

int main() {
    int Size, i, pos;
    cout << "\nEnter the size of array: ";
    cin >> Size;

    int arr[Size];

    cout << "\nEnter the elements of array: ";
    for (i = 0; i < Size; i++) {
        cin >> arr[i];
    }

    cout << "\nElements of array are: ";
    for (i = 0; i < Size; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n";

    cout << "\nEnter the position where you want to remove element: ";
    cin >> pos;

    for (i = pos; i < Size; i++) {
        arr[i] = arr[i + 1];
    }

    cout << "\nElements of array after insertion are: ";
    for (i = 0; i < Size - 1; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n";

    return 0;
}