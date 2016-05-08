#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Stack {

protected:
	int dataIdx;
	vector<int> data;
	int minIdx;
	vector<int> minData;


public:
	Stack(int _size = 10): dataIdx(-1), data(_size, 0), minIdx(-1), minData(_size, INT_MAX){}

	void push(int elem) {
		data[++dataIdx] = elem;
		if(elem <= minData[minIdx]) {
			minData[++minIdx] = elem;
		}
	}

	int pop() {
		int res = data[dataIdx--];
		if(res == minData[minIdx]) {
			minIdx--;
		}
		return res;
	}

	int minValue() {
		return minData[minIdx];
	}

	void printAll() {
		for (int i = 0; i < data.size(); i++) {
			cout << "[" << data[i] << "]";
		}
		cout << endl;

		for (int i = 0; i < minData.size(); i++) {
			cout << "[" << minData[i] << "]";
		}
		cout << endl;
	}

};

int main() {
	Stack s(5);
	s.push(10);
	s.push(3);
	cout << "MIN: " <<s.minValue() << endl;
	s.push(12);
	s.push(1);
	s.push(1);
	cout << "MIN: " <<s.minValue() << endl;
	cout << "OUT: " <<s.pop() << endl;
	cout << "OUT: " <<s.pop() << endl;
	cout << "MIN: " <<s.minValue() << endl;


	s.printAll();
	return 0;
};