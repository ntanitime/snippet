#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Stack {

protected:
	int size;
	vector<int> data;
	vector<int> stackIndex;

	int getNormalizedPosition(int stackId) {
		return size * stackId + stackIndex[stackId];
	}

	void testEmpty(int stackId) {
		if (stackIndex[stackId] <= -1) {
			throw "EMPTY";
		}
	}

public:
	Stack(int _size): size(_size), data(_size * 3, 0) {
		stackIndex = { -1, -1, -1};
	}

	void push(int stackId, int elem) {
		if (stackIndex[stackId] + 1 >= size) {
			throw "TO BIG";
		}
		stackIndex[stackId]++;
		data[getNormalizedPosition(stackId)] = elem;
	}

	int pop(int stackId) {
		testEmpty(stackId);

		int res = data[getNormalizedPosition(stackId)];
		data[getNormalizedPosition(stackId)] = 0;
		stackIndex[stackId]--;
		return res;
	}

	int top(int stackId) {
		testEmpty(stackId);
		return data[getNormalizedPosition(stackId)];
	}

	void printAll() {
		for (int i = 0; i < data.size(); i++) {
			cout << "[" << data[i] << "]";
			if (i % size == size - 1) {
				cout << endl;
			}
		}
		cout << endl;
		for (int i = 0; i < data.size(); i++) {
			cout << "[" << data[i] << "]";
		}
		cout << endl;
	}

};

class StackDynamic : public Stack {

protected:

	int getStackStartPosition(int stackId, int _size) {
		return _size * stackId;
	}

public:

	StackDynamic(int _size): Stack(_size) { }

	//Supposition: size is growing only
	void changeSize(int _size) {
		if (size > _size) {
			throw "TOO SMALL";
		}
		std::vector<int> temp(_size * 3, 0);

		for (int i = 0; i < stackIndex.size(); i++) {
			int tempStackStart = getStackStartPosition(i, _size);
			int oldStackStart = getStackStartPosition(i, size);

			for (int j = 0; j <= stackIndex[i]; j++) {
				temp[tempStackStart + j] = data[oldStackStart + j];
			}
		}
		data = temp;
		size = _size;
	}

};


int main() {
	StackDynamic s(5);
	//cout << s.top(0) << endl; //Exception

	s.push(0, 5);
	s.push(0, 6);
	s.push(0, 7);
	s.push(0, 8);
	s.push(0, 9);

	s.push(1, 1);
	s.push(1, 2);
	s.push(1, 3);

	cout << s.pop(1) << endl;
	cout << s.pop(1) << endl;
	cout << s.top(0) << endl;

	s.push(2, 4);
	s.push(2, 5);
	s.push(2, 6);

	s.printAll();
	cout << "---" << endl;
	s.changeSize(10);

	s.push(2, 7);
	s.push(2, 8);
	s.push(2, 9);

	s.printAll();
	return 0;
};