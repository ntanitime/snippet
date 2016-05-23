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

class MyQueue {
protected:
	Stack A;
	Stack B;

public:

	MyQueue(): A(), B() {}

	void push(int elem) {
		A.push(elem);
	}

	int pop() {
		if(B.getSize() == 0) {
			while(A.getSize() != 0) {
				B.push(A.pop());
			}
		}
		return B.pop();
	}

	void printAll() {
		cout << "--------------" << endl;
		cout << "A: ";
		A.printAll();
		
		cout << "B: ";
		B.printAll();
		cout << "--------------" << endl;
	}

};

int main() {
	MyQueue myQ;
	myQ.push(1);
	myQ.push(2);
	myQ.push(3);
	myQ.push(4);
	myQ.push(5);

	myQ.printAll();

	cout << "pop: " << myQ.pop() << endl;
	cout << "pop: " << myQ.pop() << endl;

	myQ.printAll();

	myQ.push(6);
	myQ.push(7);
	myQ.push(8);

	myQ.printAll();

	cout << "pop: " << myQ.pop() << endl;
	cout << "pop: " << myQ.pop() << endl;

	myQ.printAll();

	return 0;
};









