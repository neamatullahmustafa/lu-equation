
#include <iostream>
using namespace std;
int main()
{
	cout << "lu equation\n";
	float   a[3][3], l[3][3], u[3][3], b[3], x[3], z[3], sum = 0;
	for (int i = 0; i < 3; i++)
	{
		b[i] = 0;
		z[i] = 0;
		x[i] = 0;
		for (int j = 0; j < 3; j++)
		{
			a[i][j] = 0;
			l[i][j] = 0;
			u[i][j] = 0;
		}
		l[i][i] = 1;
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "enter num of equation " << i + 1 << "\n";
		for (int j = 0; j < 3; j++)
		{
			cin >> a[i][j];
			u[i][j] = a[i][j];
		}
	}
	cout << "enter the elements of b matrix \n";
	for (int i = 0; i < 3; i++)
		cin >> b[i];
	l[1][0] = u[1][0] / u[0][0];
	for (int i = 0; i < 3; i++)
		u[1][i] -= l[1][0] * u[0][i];
	l[2][0] = u[2][0] / u[0][0];
	for (int i = 0; i < 3; i++)
		u[2][i] -= l[2][0] * u[0][i];
	l[2][1] = u[2][1] / u[1][1];
	for (int i = 0; i < 3; i++)
		u[2][i] -= l[2][1] * u[1][i];
	z[0] = b[0];
	z[1] = b[1] - l[1][0] * z[0];
	z[2] = b[2] - l[2][0] * z[0] - l[2][1] * z[1];
	x[2] = z[2] / u[2][2];
	x[1] = (z[1] - u[1][2] * x[2]) / u[1][1];
	x[0] = (z[0] - u[0][1] * x[1] - u[0][2] * x[2]) / u[0][0];
	for (int i = 0; i < 3; i++)
	{
		cout << " x " << i + 1 << "=" << x[i] << "\n";
	}
	return 0;
}


