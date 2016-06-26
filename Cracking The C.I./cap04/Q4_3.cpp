#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

typedef int T;

class Node {
public:
	T data;
	Node* left;
	Node* right;

	Node(T _data): data(_data) {
		left = nullptr;
		right = nullptr;
	}

	void setLeft(Node* n) {
		left = n;
	}

	void setRight(Node* n) {
		right = n;
	}

};

class Tree {
protected:
	Node* root;

public:
	Tree() {
		root = nullptr;
	}

	Tree(Node* n) {
		root = n;
	}

	void add(Node* elem) {
		add(elem, root);
	}

	//N.B.
	//Node*& means a reference to a pointer to an Node. 
	//In other words, the function can change the parameter to point to something else.
	void add(Node* elem, Node*& curr) {
		if(curr == nullptr) {
			curr = elem;
			//cout << "end " << elem->data << endl;
		} else if (curr->data >= elem->data) {
			//cout << "L: " << curr->data << endl;
			add(elem, curr->left);
			//cout << "L: " << curr->left->data << endl;
		} else {
			//cout << "R: " << curr->data << endl;
			add(elem, curr->right);
		}
	}

	/**
	* Print by levels (BFS: Breadth-First Search)
	*/
	void printAll() {
		queue<Node*> allNodes;
		allNodes.push(root);
		Node* curr = nullptr;
		while (!allNodes.empty()) {
			curr = allNodes.front();
			allNodes.pop();

			if (curr->left != nullptr) {
				//cout << "addL: " << curr->left->data << endl;
				allNodes.push(curr->left);
			}

			if (curr->right != nullptr) {
				//cout << "addR: " << curr->right->data << endl;
				allNodes.push(curr->right);
			}

			cout << "Node[" << curr->data << "]";
			cout << " L[" << (curr->left != nullptr ? "F]" : "null]");
			cout << " R[" << (curr->right != nullptr ? "F]" : "null]") << endl;
		}
	}

};

void printAll(const vector<int>& v) {
	for(int i=0; i<v.size(); i++) {
		cout << v[i] << ",";
	}
	cout << endl;
}

/**
*	The code complexity is O(N* log N)
* 	Because every time we insert a new Node the "add" function traverse all the Tree
*/
void minimalHeight(const vector<int>& v, Tree* t) {
	if(v.empty()) {
		return;
	}

	if (v.size() > 1) {
		printAll(v);
		int middle = v.size() / 2;
		cout << "-add: " << v[middle] << endl;
		t->add(new Node(v[middle]));

		//Right 
		minimalHeight(vector<int> (v.begin()+middle+1, v.end()), t);

		//Left
		minimalHeight(vector<int> (v.begin(), v.begin()+middle), t);
	} else {
		cout << "#add: " << v[0] << endl;
		t->add(new Node(v[0]));
	}
}


int main() {
	std::vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	v.push_back(10);

	Tree t;

	minimalHeight(v, &t);
	t.printAll();

	return 0;
};








