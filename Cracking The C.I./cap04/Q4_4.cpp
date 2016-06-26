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
	* Scan the tree with BFS - Breadth-First Search
	*/
	void printAll() {
		queue<int> depth;
		depth.push(0);

		queue<Node*> allNodes;
		allNodes.push(root);

		Node* curr = nullptr;
		int currDepth;
		while (!allNodes.empty()) {
			curr = allNodes.front();
			currDepth = depth.front();
			allNodes.pop();
			depth.pop();

			if (curr->left != nullptr) {
				//cout << "addL: " << curr->left->data << endl;
				allNodes.push(curr->left);
				depth.push(currDepth + 1); 
			}

			if (curr->right != nullptr) {
				//cout << "addR: " << curr->right->data << endl;
				allNodes.push(curr->right);
				depth.push(currDepth + 1);
			}

			cout << "Node[" << curr->data << "][" << currDepth << "]";
			cout << " L[" << (curr->left != nullptr ? "F]" : "null]");
			cout << " R[" << (curr->right != nullptr ? "F]" : "null]") << endl;
		}
	}

	vector<vector<Node*>> getTreeLevel() {
		vector<vector<Node*>> result;

		vector<Node*> current;
		current.push_back(root);
		while(!current.empty()) {
			result.push_back(current);
			auto temp = current;
			current = vector<Node*>();
			for(auto n : temp) {
				if (n->left != nullptr) {
					current.push_back(n->left);
				}

				if (n->right != nullptr) {
					current.push_back(n->right);
				}
			}
		}

		return result;
	}

};

void printAll(const vector<vector<Node*>>& v) {
	for(auto list : v) {
		for(auto elem: list) {
			cout << elem->data << ",";
		}
		cout << endl;
	}
}

int main() {
	Tree t(new Node(10));
	t.add(new Node(5));
	t.add(new Node(12));
	t.add(new Node(16));
	t.add(new Node(17));
	t.add(new Node(14));
	t.printAll();
	printAll(t.getTreeLevel());

	cout << "------" << endl;
	Tree t2(new Node(5));
	t2.add(new Node(2));
	t2.add(new Node(8));
	t2.add(new Node(1));
	t2.add(new Node(4));
	t2.add(new Node(7));
	t2.add(new Node(10));
	t2.add(new Node(0));
	t2.add(new Node(3));
	t2.add(new Node(6));
	t2.printAll();
	printAll(t2.getTreeLevel());

	return 0;
};








