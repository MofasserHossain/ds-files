#include <iostream>
using namespace std;

int bubbleSort(int A[], int Size)
{
	int step, compare;
	for (step = 1; step < Size; step++)
	{
		for (compare = 1; compare <= Size - step; compare++)
		{
			if (A[compare] > A[compare + 1])
				swap(A[compare], A[compare + 1]);
		}
	}
	return 0;
}

int main()
{
	int Size, i, BEG, END, MID, S_ITEM;
	cout << "Enter the array Size: ";
	cin >> Size;
	int A[Size];
	srand(time(0));
	for (i = 1; i <= Size; i++)
		A[i] = rand() % 50;
	cout << "Array elements are: ";
	for (i = 1; i <= Size; i++)
		cout << A[i] << " ";
	bubbleSort(A, Size);
	cout << "\nArray elements after sorting: ";
	for (i = 1; i <= Size; i++)
		cout << A[i] << " ";
	cout << endl;
}