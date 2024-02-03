#include <iostream>
//#include <string>
#include <vector>
//#include <cctype> 
#include <sstream>
#include <algorithm>
#include <cassert>
using namespace std;

vector<int> Vec1{}, Vec2{}, Vec3{}; // Vectooooorrrrssss
string chap = "";

void takestr(string s) {
	bool ky = 0, ky2 = 0;
	int i = 0;

	for (char& c : s) {
		if (!isdigit(c)) {
			switch (c) {
			case '-':
				ky = 1;
				c = ' ';
				break;
			case ',':
				i = i++;
				c = ' ';
				break;
			case ' ':
				c = ' ';
				break;
			default:
				chap = toupper(c);
				c = ' ';
				break;
			}
			ky2 = 0;
		}
		else {
			if (ky2 == 0) {
				if (ky == 1) {
					Vec1.push_back(i);
					ky = 0;
					ky2 = 1;
				}
				else {
					Vec1.push_back(i);
				}
				ky2 = 1;
			}
			else {
				ky2 = 0;
			}
		}
	}

	int v;
	stringstream ss(s);
	while (ss >> v) Vec2.push_back(v);;
}

string SortVect() {
	int k = 0;
	string outpt = "";
	switch (Vec2.size()) {
	case 0:
		return "\nYou did not enter a proper input...\n";
		break;
	case 1:
		Vec3.push_back(Vec2[0]);
		break;
	case 2:
		if (Vec1[k] == Vec1[int(k + 1)]) {
			for (int j = Vec2[k]; j <= Vec2[int(int(k + 1))]; j++) {
				Vec3.push_back(j);
			}
			sort(Vec3.begin(), Vec3.end());
			Vec3.erase(unique(Vec3.begin(), Vec3.end()), Vec3.end());
			for (k = 0; k < Vec3.size() - 1; k++) {
				outpt = outpt + to_string(Vec3[k]) + ", ";
			}


		}
		else {
			Vec3.push_back(Vec2[k]);
			Vec3.push_back(Vec2[k + 1]);
			sort(Vec3.begin(), Vec3.end());
			Vec3.erase(unique(Vec3.begin(), Vec3.end()), Vec3.end());
			for (k = 0; k < Vec3.size() - 1; k++) {
				//cout << Vec3[k] << ", ";
				outpt = outpt + to_string(Vec3[k]) + ", ";
			}
		}
		break;
	default:
		for (k = 1; k < Vec2.size(); k++) {
			if (Vec1[int(k - 1)] == Vec1[int(k)] && (k != Vec2.size())) {
				for (int j = Vec2[k - 1]; j < Vec2[int(k)]; j++) {
					Vec3.push_back(j);
				}
				Vec3.push_back(Vec2[k]);
				k = k++;
				if (k == Vec2.size()-1) (Vec3.push_back(Vec2[k]));
				
			}
			else {
				Vec3.push_back(Vec2[k]);
				Vec3.push_back(Vec2[int(k - 1)]);
			}
		}
		

		k = k--;
		sort(Vec3.begin(), Vec3.end());
		Vec3.erase(unique(Vec3.begin(), Vec3.end()), Vec3.end());
		for (k = 0; k < Vec3.size() - 1; k++) {
			if (k % 5 == 0) (outpt = outpt + "\n") ;
			//cout << Vec3[k] << ", ";
			outpt = outpt + to_string(Vec3[k]) + ", ";
		}
		break;
	}

	//cout << Vec3[k] << " of " << chap;
	outpt = outpt + to_string(Vec3[k]) + " of " + chap;
	return outpt;
}

void cleanvec() {
	Vec1.clear();
	Vec2.clear();
	Vec3.clear();
}

void driver() {
	cout << "Testing Start...\n";

//z
	takestr("J");
	assert(SortVect() == "\nYou did not enter a proper input...\n");
	cleanvec();
//o
	takestr("J1");
	assert(SortVect() == "1 of J");
	cleanvec();
//m
	takestr("J1,2");
	assert(SortVect() == "1, 2 of J");
	cleanvec();
	
	takestr("J1-4");
	assert(SortVect() == "1, 2, 3, 4 of J");
	cleanvec();

	cout << "\nTesting Passed!!\n";
}

int main() {
	string str = "";

	cout << "Please enter the assignment: \n";
	getline(cin, str);

	if (str == "test") {
		driver();
	}
	else {
		takestr(str);

		cout << "The problems are: ";

		cout << SortVect();
	}

	return 0;
}