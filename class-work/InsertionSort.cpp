#include <iostream>
using namespace std;
int insertionSort(int A[], int Size)
{
	int j, i, key;
	for (j = 2; j <= Size; j++)
	{
		key = A[j];
		i = j - 1;
		while (i >= 1 && A[i] > key)
		{
			A[i + 1] = A[i];
			i = i - 1;
		}
		A[i + 1] = key;
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
	insertionSort(A, Size);
	cout << "\nArray elements after sorting: ";
	for (i = 1; i <= Size; i++)
		cout << A[i] << " ";
	cout << endl;
}