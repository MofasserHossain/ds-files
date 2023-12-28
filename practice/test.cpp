#include <iostream>
using namespace std;

int main()
{

    int i, position = -1, value, size;

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

    for (i = 1; i <= size; i++)
    {
        if (array[i] == value)
        {
            position = i;
            break;
        }
    }

    if (position == -1)
    {
        cout << "Data not found";
    }
    else
    {
        cout << position << " is the location of search item " << value;
    }

    cout << endl;
    return 0;
}