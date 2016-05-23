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

};

class Tree {
protected:
	Node* root;

public:
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

	int getHeight(Node* n) {
		if (n == nullptr) {
			return 0; //Exit condition
		}

		int left = getHeight(n->left);
		if (left == -1) {
			return -1;
		}

		int right = getHeight(n->right);
		if (right == -1) {
			return -1;
		}

		int res = left - right;
		if (abs(res) > 1) {
			return -1;
		} else {
			return max(left, right) + 1;
		}
	}

	bool isBalanced() {
		return getHeight(root) != -1;
	}
};

int main() {
	Tree t(new Node(10));
	t.add(new Node(5));
	t.add(new Node(12));
	t.add(new Node(16));
	t.add(new Node(17));
	t.add(new Node(14));
	t.printAll();

	cout << "Is balanced: " << t.isBalanced() << endl;
	return 0;
};








