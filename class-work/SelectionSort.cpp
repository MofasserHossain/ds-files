#include <iostream>
using namespace std;

int selectionSort(int A[], int Size)
{
	int i, j, smallest;
	for (j = 1; j < Size; j++)
	{
		smallest = j;
		for (i = j + 1; i <= Size; i++)
		{
			if (A[i] < A[smallest])
				smallest = i;
		}
		swap(A[j], A[smallest]);
	}
	return 0;
}

int main()
{
	int Size, i;
	cout << "Enter the array Size: ";
	cin >> Size;
	int A[Size];
	srand(time(0));
	for (i = 1; i <= Size; i++)
		A[i] = rand() % 50;

	cout << "Array elements are: ";
	for (i = 1; i <= Size; i++)
		cout << A[i] << " ";

	selectionSort(A, Size);

	cout << "\nArray elements after sorting: ";
	for (i = 1; i <= Size; i++)
		cout << A[i] << " ";

	cout << endl;
}