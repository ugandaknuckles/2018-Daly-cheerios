#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main() {

	string line;
	ofstream myfile("duck.txt");
	myfile << "your ducks are \"bad\" good " << endl;
	myfile << "your ducks are nice" << endl;
	myfile.close();
	ifstream myfile1("duck.txt");
	int input;
	cin >> input;
	if (myfile1.is_open()) 
	{ 
		while (getline(myfile1, line))
		{
	for (int i = 0; i < input; i++)
		cout << line << endl;
		}
		myfile1.close();
	}
	else
		cout << "unableto open file";
	system("pause");
}
