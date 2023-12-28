#include <iostream>

using namespace std;

int main()
{
	int Size, i, BEG, END, MID, S_ITEM;
	cout<<"Enter the array Size: ";
	cin>>Size;
	int A[Size];
	
	for(i=1; i<=Size; i++)
		cin>>A[i];
	
	cout<<"Array elements are: ";
	for(i=1; i<=Size; i++)
		cout<<A[i]<<" ";
	
	BEG = 1, END = Size, MID = (BEG+END)/2;
	
	cout<<"Enter your Search item: ";
	cin>>S_ITEM;
	
	while(A[MID] != S_ITEM && BEG<=END)
	{
		if(S_ITEM<A[MID])
			END = MID-1;
		else
			BEG = MID+1;
		MID = (BEG+END)/2;
	}
	
	if(A[MID] == S_ITEM)
		cout<<MID<<" is the location of item "<<S_ITEM;
	else
		cout<<"Data not found";
	cout<<endl;
}