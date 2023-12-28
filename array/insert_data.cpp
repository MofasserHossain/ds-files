#include <iostream>
using namespace std;

int main() {
    int Size, i, pos, ele;
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

    cout << "\nEnter the position where you want to insert element: ";
    cin >> pos;

    cout << "\nEnter the element you want to insert: ";
    cin >> ele;

    for (i = Size - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos] = ele;

    cout << "\nElements of array after insertion are: ";
    for (i = 0; i <= Size; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n";

    return 0;
}