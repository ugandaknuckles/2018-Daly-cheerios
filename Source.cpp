#include <iostream>
using namespace std;

int main()
{
	int rows;
	int slope = 0;

	cout << "Enter number of rows ";
	cin >> rows;

	for (int i = 1; i <= rows; ++i)
	{
		for (int j = 1; j <= rows - i; ++j) {
			cout << " ";
		}
		for (int j =1; j<= i +slope; j++){
			cout << "*";
		}
		cout << "\n";
		slope += 1;
	}

	
}