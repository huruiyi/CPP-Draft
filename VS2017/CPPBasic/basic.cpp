#include<iostream>
#include "windows.h"
using namespace std;

int main9()
{
	using namespace std;
	int yams[3];    // creates array with three elements
	yams[0] = 7;    // assign value to first element
	yams[1] = 8;
	yams[2] = 6;

	int yamcosts[3] = { 20, 30, 5 }; // create, initialize array
									 // NOTE: If your C++ compiler or translator can't initialize
									 // this array, use static int yamcosts[3] instead of
									 // int yamcosts[3]

	cout << "Total yams = ";
	cout << yams[0] + yams[1] + yams[2] << endl;
	cout << "The package with " << yams[1] << " yams costs ";
	cout << yamcosts[1] << " cents per yam.\n";
	int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
	total = total + yams[2] * yamcosts[2];
	cout << "The total yam expense is " << total << " cents.\n";

	cout << "\nSize of yams array = " << sizeof yams;
	cout << " bytes.\n";
	cout << "Size of one element = " << sizeof yams[0];
	cout << " bytes.\n";
	cin.get();
	return 0;
}

int main8()
{
	using namespace std;
	double * p3 = new double[3]; // space for 3 doubles
	p3[0] = 0.2;                  // treat p3 like an array name
	p3[1] = 0.5;
	p3[2] = 0.8;
	p3[3] = 1.0;

	cout << "p3[0] is " << p3[0] << ".\n";
	cout << "p3[1] is " << p3[1] << ".\n";
	cout << "p3[2] is " << p3[2] << ".\n";
	cout << "p3[3] is " << p3[3] << ".\n";

	cout << p3 << endl;
	p3 = p3 + 1;
	cout << p3 << endl;

	// increment the pointer
	cout << "p3[0] is " << p3[0] << ".\n";
	cout << "p3[1] is " << p3[1] << ".\n";
	cout << "p3[2] is " << p3[2] << ".\n";
	cout << "p3[3] is " << p3[3] << ".\n";

	p3 = p3 - 1;                  // point back to beginning
	delete[] p3;                 // free the memory
								 // cin.get();
	system("pause");
	return 0;
}

int main7()
{
	using namespace std;
	cout << "\aOperation \"HyperHype\" is now activated!\n";
	cout << "Enter your agent code:________\b\b\b\b\b\b\b\b";
	long code;
	cin >> code;
	cout << "\aYou entered " << code << "...\n";
	cout << "\aCode verified! Proceed with Plan Z3!\n";
	// cin.get();
	cin.get();
	return 0;
}

int main6()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	float tree = 3;     // int converted to float
	int guess = 3.9832; // float converted to int
	int debt = 7.2E12;  // result not defined in C++
	cout << "tree = " << tree << endl;
	cout << "guess = " << guess << endl;
	cout << "debt = " << debt << endl;
	cin.get();
	return 0;
}

int main5()
{
	using namespace std;
	float hats, heads;

	cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
	cout << "Enter a number: ";
	cin >> hats;
	cout << "Enter another number: ";
	cin >> heads;

	cout << "hats = " << hats << "; heads = " << heads << endl;
	cout << "hats + heads = " << hats + heads << endl;
	cout << "hats - heads = " << hats - heads << endl;
	cout << "hats * heads = " << hats * heads << endl;
	cout << "hats / heads = " << hats / heads << endl;
	system("pause");
	return 0;
}

int main4()                                    // function header
{                                             // start of function body
	using namespace std;                      // make definitions visible
	cout << "Come up and C++ me some time.";  // message
	cout << endl;                             // start a new line
	cout << "You won't regret it!" << endl;   // more output
											  // If the output window closes before you can read it,
											  // add the following code:
	cout << "Press any key to continue." << endl;
	cin.get();
	return 0;                                  //terminate main()
}                                             // end of function body

int main3()
{
	using namespace std;

	int carrots;

	cout << "How many carrots do you have?" << endl;
	cin >> carrots;                // C++ input
	cout << "Here are two more. ";
	carrots = carrots + 2;
	// the next line concatenates output
	cout << "Now you have " << carrots << " carrots." << endl;
	// cin.get();
	// cin.get();
	return 0;
}

int stonetolb(int);
int stonetolb(int sts)
{
	return 14 * sts;
}
int main2()
{
	using namespace std;
	int stone;
	cout << "Enter the weight in stone: ";
	cin >> stone;
	int pounds = stonetolb(stone);
	cout << stone << " stone = ";
	cout << pounds << " pounds." << endl;
	cin.get();
	return 0;
}

DWORD dw = 1351432;
HANDLE hInst = &dw;
void main()
{
	cout << dw << endl;
	cout << hInst << endl;

	cout << "²âÊÔ" << endl;
	getchar();
}
