#include <iostream>
using namespace std;

int main() {
	double Cost = 0;
	double Tax = 0;
	double Tip = 0;
	double Total = 0;
	double cost = 0;
	cout << "enter cost" << endl;
	cin >> cost;
	Tax = cost * 0.675;
	Tip = (Cost + Tax) * 015;
	Total = cost + Tax + Tip;

	cout << cost << endl;
	cout << Tax << endl;
	cout << Tip << endl;
	cout << Total << endl;




}