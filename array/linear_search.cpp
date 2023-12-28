#include <iostream>
using namespace std;

int main() {
    int Size, i, ele;
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

    cout << "\n";

    cout << "\nEnter the element you want to search: ";
    cin >> ele;

    for (i = 0; i < Size; i++) {
        if (arr[i] == ele) {
            cout << "\nElement found at position " << i + 1 << "\n";
            break;
        }
    }

    if (i == Size) {
        cout << "\n Element not found \n";
    }

    return 0;
}


// by while loop
#include <iostream>
using namespace std;

int main() {
    int Size, i, ele;
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

    cout << "\n";

    cout << "\nEnter the element you want to search: ";
    cin >> ele;

    i = 0;
    while (i < Size) {
        if (arr[i] == ele) {
            cout << "\nElement found at position " << i + 1 << "\n";
            break;
        }
        i++;
    }

    if (i == Size) {
        cout << "\n Element not found \n";
    }

    return 0;
}