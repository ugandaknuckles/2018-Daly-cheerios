#include <iostream>
using namespace std;

int main() {

	int Arrows[7];
	bool secretNumber = false;

	for (int i = 0; i < 6; i++)
		cin >> Arrows[i];

	for (int i = 0; i < 6; i++)
		if (Arrows[i] == 5)
			secretNumber = true;

	if (secretNumber == true)
		cout << "you a g" << endl;
	else
		cout << "you not a g" << endl;

	system("pause");
}