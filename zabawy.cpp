#include <iostream>
using namespace std;

int main() {
	unsigned int testCase = 1;
	
	while(testCase <2048)
	{
		testCase <<= 1;
		cout <<"Wynik: "<<testCase <<endl; 
	}
	bool a = false;
	bool b = true;
	
	cout << ((a&&b) ? "Prawda" : "Falsz") <<endl;
	return 0;
}
