#include <iostream>
#include <vector>
using namespace std;

void print(const vector<vector<int> >& m) {
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m[i].size(); j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<int> > notInPlace(const vector<vector<int> >& m) {
	int N = m.size();
	vector<vector<int> > destiantion(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		vector<int> temp(N);
		int reverse = N - 1;
		for (int j = 0; j < N; j++) {
			temp[reverse--] = m[j][i];
		}
		destiantion[i] = temp;
	}

	return destiantion;
}

void InPlace(vector<vector<int> >* matrix) {
	int N = matrix->size();

	for (int layer = 0; layer < N / 2; layer++) {
		int first = layer;
		int last = (N - 1) - layer;

		cout << first << " " << last << endl;

		for (int i = first; i < last; i++) {
			int offset = i - first;
			int top = (*matrix)[first][i]; // save top

			// left -> top
			(*matrix)[first][i] = (*matrix)[last - offset][first];

			// bottom -> left
			(*matrix)[last - offset][first] = (*matrix)[last][last - offset];

			// right -> bottom
			(*matrix)[last][last - offset] = (*matrix)[i][last];

			// top -> right
			(*matrix)[i][last] = top; // right <- saved top
		}
	}
}

int main() {
	int N = 4;
	vector<vector<int> > source(N, vector<int>(N));

	for (int i = 0; i < N; i++) { //Initialization to see result
		for (int j = 0; j < N; j++) {
			source[i][j] = i;
		}
	}

	print(source);
	cout << endl;
	print(notInPlace(source));
	cout << endl;
	InPlace(&source);
	print(source);

	return 0;
};