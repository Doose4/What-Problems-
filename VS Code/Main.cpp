#include <iostream>
#include <string>
#include <cctype> 

// do an array?

using namespace std;

int main() {
	string s = "", numbe;
	int n, i, lastnum;
	char c;

	cout << "Please enter the assignment: ";
	cin >> s;

	for (i=0; i < s.length(); i++) {
		if (isdigit(s[i])){
			n = static_cast<int>(s[i]);
			//cout << "You entered the number: " << n << '\n';
			lastnum = n;
		} else {
			c = static_cast<char>(s[i]);
		}

	}

	cout << "Do problems " << numbe << " and " << lastnum << " of " << c;

	return 0;
}