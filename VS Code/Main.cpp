#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

void question(int n) {
	cout << "num";

}

void question(char n) {

	cout << "char";

}

int main() {
	string s = "";
	int n, i;
	char c;

	cout << "Please enter the assignment: ";
	//s = cin.peek();
	cin >> s;
	cout << "\n";
	//cout << cin.peek();
	cout << s.length();
	cout << s[1];

	for (i=0; i < s.length(); i++) {
		if (isdigit(s[i])){
			n = static_cast<int>(s[i]);
			cout << "You entered the number: " << n << '\n';
			//question(n);
		}
		else
		{
			c = static_cast<char>(s[i]);
			cout << "You entered the word: " << c << '\n';
			//question(c);
		}

	}

	return 0;
}