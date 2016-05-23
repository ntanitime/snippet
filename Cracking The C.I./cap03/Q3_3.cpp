#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Stack {

protected:
	vector<int> data;

public:
	Stack(): data() {}

	void push(int elem) {
		data.push_back(elem);
	}

	int pop() {
		int res = -1;
		if (!data.empty()) {
			res = data.back();
			data.pop_back();
		}
		return res;
	}

	void printAll() {
		for (int i = 0; i < data.size(); i++) {
			cout << "[" << data[i] << "]";
		}
		cout << endl;
	}

	int getSize() {
		return data.size();
	}

};

class SetOfStacks {
protected:
	int maxSize;
	vector<Stack> v;

public:
	SetOfStacks(int _maxSize = 3): maxSize(_maxSize), v() {}

	void push(int elem) {
		if (v.empty() || v.back().getSize() >= maxSize) {
			v.push_back(Stack());
		}

		v.back().push(elem);
	}

	int pop() {
		int res = -1;
		while(!v.empty()) {
			if (v.back().getSize() != 0) {
				break;
			}
			v.pop_back();
		}

		if (v.empty()) {
			return res;
		}

		if (v.back().getSize() == 1) {
			res = v.back().pop();
			v.pop_back();
		} else {
			res = v.back().pop();
		}

		return res;
	}

	int popAt(int index) {
		int res = -1;
		if (v.size() > index && v[index].getSize() > 0) {
			res = v[index].pop();
		}

		return res;
	}

	void printAll() {
		for (int i = 0; i < v.size(); i++) {
			v[i].printAll();
		}
	}
};

int main() {
	SetOfStacks s(3);
	s.push(1);
	s.push(1);
	s.push(1);
	s.push(2);
	s.push(2);
	s.push(2);
	s.push(3);
	s.push(3);
	s.push(3);
	//s.pop();
	//s.pop();
	//s.pop();
	s.pop();

	s.printAll();
	cout << "Removed at 0: " << s.popAt(0) << endl;
	cout << "Removed at 0: " << s.popAt(0) << endl;
	cout << "Removed at 0: " << s.popAt(0) << endl;
	cout << "Removed at 0: " << s.popAt(0) << endl;
	cout << "Removed at 1: " << s.popAt(1) << endl;
	cout << "Removed at 2: " << s.popAt(2) << endl;
	cout << "Removed at 3: " << s.popAt(3) << endl;
	s.printAll();

	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	cout << "No more elem " << s.pop() << endl;

	s.printAll();
	return 0;
};