#include <bits/stdc++.h>
using namespace std;

int indexOf1D(int i, int j, int k, int m, int n);
int main()
{
	// reading the size from the user
	int n, m, p;

	cout << "Length: ";
	cin >> n;
	cout << "Width: ";
	cin >> m;
	cout << "Heigth: ";
	cin >> p;
	cout << "Enter the Values: \n";
	// creating the 3d Matrix
	vector<vector<vector<int>>> mat(n, vector<vector<int>>(m, vector<int>(p)));

	// creating the Flatten vector
	int q = n * m * p;
	vector<int> flatten(q);

	// creating both 3D Matrix and the 1D vector
	int y = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < p; k++)
			{
				cin >> mat[i][j][k];
				y = indexOf1D(i, j, k, m, n);
				flatten[y] = mat[i][j][k];
			}

	// printting the flatten Vector
	for (int i : flatten)
		cout << i << ' ';
}

int indexOf1D(int i, int j, int k, int m, int n)
{
	/* the idea behind the equation is that:
	* if we have 3D matrix of 3 * 3 * 3 so,

	i divided the 3D as 3 faces so i want to take each row in depth of each face then flat it after that i take the row below it and so on

	by which i mean 1 2 3
								4 5 6
								7 8 9  this is the front view of the face

	behind it we can see 10 11 12
									 13 14 15
									 16 17 18 this is the second face which falls behind it vertically

	behind it we can see 19 20 21
									  22 23 24
									  25 26 27

	my idea is to take each row in depth together then flat it so i can take {1 , 10 , 19} then {4 , 13 ,22} then {7 , 6 ,25} and so on



	*/
	return i + n * (j + m * k);

	// if 4 dimensions
	// i + n*(j + m * (k + p*s)) and so on
}