#include <iostream>
#include <string>
using namespace std;

int main() {
	string toEdit = "Mr John Smith ";
	string result = "";
	for(int i=0; i<toEdit.size(); i++){
		if(toEdit[i] == ' ') {
			result += "%20";
		} else {
			result += toEdit[i];
		}
	}

	cout << toEdit << endl;
	cout << result << endl;

	return 0;
};