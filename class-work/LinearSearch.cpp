#include <iostream>
using namespace std;

int main()
{
	int Size, i, S_ITEM, location = 1;
	cout << "Enter the array size: ";
	cin >> Size;
	int Array[Size];

	srand(time(0));
	for (i = 1; i <= Size; i++)
		Array[i] = rand() % 50;

	cout << "Array size: " << Size;
	cout << "\nArray elements are: ";
	for (i = 1; i <= Size; i++)
		cout << Array[i] << " ";

	cout << "\nEnter the search item:  ";
	cin >> S_ITEM;

	while (Array[location] != S_ITEM && location <= Size)
		location = location + 1;

	if (location == Size + 1)
		cout << "Data not found";
	else
		cout << location << " is the location of search item " << S_ITEM;
	cout << endl;
}