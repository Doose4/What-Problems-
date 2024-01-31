#include <iostream>
#include <string>
#include <vector>
#include <cctype> 

// do an array?

using namespace std;

int main() {
	vector<int> numbe;
	string s = "", nums = "";
	int n, i, lastnum;
	char c;

	cout << "Please enter the assignment: ";
	cin >> s;



	for (i=0; i < s.length()-1; i++) {
		if (isdigit(s[i])){
			n = static_cast<int>(s[i]);
			//cout << "You entered the number: " << n << '\n';
			numbe.push_back(n);
		} else {
			c = static_cast<char>(s[i]);
			switch (c) {
			case '-':
				for (int i = n + 1; i <= static_cast<int>(s[i + 1]); i++) {
					numbe.push_back(n);
				}
				break;
			case ',':
				break;
			default:
				char chap = c;
				break;
			}
			
		}

	}

	for (auto k = numbe.begin(); k < numbe.end(); k++) {
		nums = nums + static_cast<char>(*k) + ", ";
	}
		nums = nums + " and " + static_cast<char>(n);

	cout << "Do problems " << nums << " of " << c;

	return 0;
}