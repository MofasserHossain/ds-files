#include <iostream>
using namespace std;

int main()
{
	int i, j, k, vertices, edges, v, visited[5] = {0};
	int visiting[5] = {0}, step = 1, Stack[5], TOP = 1;

	cout << "Enter the number of vertices: ";
	cin >> vertices;
	int Graph[vertices + 1][vertices + 1] = {0};

	cout << "\nMatrix before input\n";
	for (i = 1; i <= vertices; i++)
	{
		for (j = 1; j <= vertices; j++)
		{
			cout << Graph[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\nEnter the number of Edges: ";
	cin >> edges;
	cout << "\nEnter Edges:\n";
	for (k = 1; k <= edges; k++)
	{
		cin >> i >> j;
		Graph[i][j] = 1;
	}

	cout << "\nMatrix after input: \n";
	for (i = 1; i <= vertices; i++)
	{
		for (j = 1; j <= vertices; j++)
		{
			cout << Graph[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\nEnter the starting vertex: ";
	cin >> v;
	cout << "DFS Order: " << v << " ";
	visited[v] = 1;

	while (step < vertices)
	{
		for (j = vertices; j >= 1; j--)
			if (Graph[v][j] == 1 && visited[j] == 0 && visiting[j] == 0)
			{
				visiting[j] = 1;
				Stack[TOP++] = j;
			}
		v = Stack[--TOP];
		cout << v << " ";
		visited[v] = 1;
		visiting[v] = 0;
		step++;
	}
	cout << "\n\n";
}