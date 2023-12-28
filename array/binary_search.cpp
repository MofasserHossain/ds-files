#include <iostream>
using namespace std;

int main(){
    int Size, i, ele, mid, low, high;
    cout << "\n Enter the size of array: ";
    cin >> Size;

    int arr[Size];

    cout << "\n Enter the elements of array: ";
    for (i = 0; i < Size; i++) {
        cin >> arr[i];
    }

    cout << "\n Elements of array are: ";
    for (i = 0; i < Size; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n ";

    cout << "\n Enter the element you want to search: ";
    cin >> ele;

    low = 0;
    high = Size - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == ele) {
            cout << "\n Element found at position " << mid + 1 << "\n";
            break;
        } else if (arr[mid] < ele) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (low > high) {
        cout << "\n Element not found \n";
    }

    return 0;
}