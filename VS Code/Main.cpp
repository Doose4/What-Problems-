#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cassert>
using namespace std;

//global variables
vector<int> Vec1{}, Vec2{}, Vec3{}; 
string chap = "";

void takestr(string s) {
	bool ky = 0, ky2 = 0;
	int i = 0;
//fills out vector with numbers listed

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
			case ';':
				i = i++;
				c = ' ';
				break;
			case '.':
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
//sorts out vector
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

	//creates the string
		k = k--;
		sort(Vec3.begin(), Vec3.end());
		Vec3.erase(unique(Vec3.begin(), Vec3.end()), Vec3.end());
		for (k = 0; k < Vec3.size() - 1; k++) {
			//if (int(k % 6) == 0) (outpt = outpt + "\n");
			outpt = outpt + to_string(Vec3[k]) + ", ";
		}
		break;
	}
	outpt = outpt + to_string(Vec3[k]) + " of " + chap;
	return outpt;
}

void cleanvec() {
	//cleans the vectors for new outputs
	Vec1.clear();
	Vec2.clear();
	Vec3.clear();
}

void driver() {
//runs tests for different scenerios
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
//b
	takestr("J1-4,3");
	assert(SortVect() == "1, 2, 3, 4 of J");
	cleanvec();
//i
	takestr("J1-4,9-12");
	assert(SortVect() == "1, 2, 3, 4, 9, 10, 11, 12 of J");
	cleanvec();
//e
	takestr("J1-4,6");
	assert(SortVect() == "1, 2, 3, 4, 6 of J");
	cleanvec();
//s
	takestr("J1-4,14,9-12,8-10");
	assert(SortVect() == "1, 2, 3, 4, 8, 9, 10, 11, 12, 14 of J");
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