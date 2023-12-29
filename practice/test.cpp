#include <iostream>
using namespace std;

int main()
{

    int i, position = -1, value, size, start, end, mid;

    cout << "Enter the size of the array : \t";

    cin >> size;

    int array[size];

    srand(time(0));

    for (i = 1; i <= size; i++)
    {
        array[i] = rand() % 50;
    }

    cout << "Array elements are: ";
    for (i = 1; i <= size; i++)
    {
        cout << array[i] << " ";
    }

    cout << "\nEnter the value you want to search: ";
    cin >> value;

    start = 1;
    end = size;
    mid = (start + end) / 2;

    while (start <= end)
    {
        if (array[mid] == value)
        {
            position = mid;
            break;
        }
        else if (array[mid] < value)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }

    if (position == -1)
    {
        cout << "Value not found";
    }
    else
    {
        cout << "Value found at position " << position;
    }

    cout << endl;
    return 0;
}