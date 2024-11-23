#include <iostream>
using namespace std;

int main()
{
	string text, pattern;
	int i, j, count = 0;
	cout << "Enter the text: ";
	getline(cin, text);

	cout << "Enter the pattern: ";
	getline(cin, pattern);

	int lengthText = text.length();
	int patternLength = pattern.length();

	for (i = 0; i < lengthText; i++)
	{
		for (j = 0; j < patternLength; j++)
		{
			if (text[i + j] != pattern[j])
				break;
		}
		if (patternLength == j)
		{
			count++;
			cout << "Pattern found in location: " << i << endl;
		}
	}
	if (count == 0)
		cout << "No pattern found!!";
	else
		cout << "There are " << count << " number of patterns found";
	cout << endl;
}