#include <iostream>
#include <bitset>
using namespace std;

int combineNumber(bitset<32> _N, bitset<32> _M, int j, int i) {
	int N = _N.to_ulong();
	int M = _M.to_ulong();
	cout << "N:     " << _N << endl;
	cout << "M:     " << _M << endl;

	// clear bits from j =< x <= i
	int allOnes = ~0;
	int leftPart = allOnes << (j+1);
	cout << "Left:  " << bitset<32>(leftPart) << endl;
	int rightPart = (1 << i) - 1;
	cout << "roght: " << bitset<32>(rightPart) << endl;
	int mask = leftPart | rightPart;
	cout << "mask:  " << bitset<32>(mask) << endl;

	N = N & mask;

	M = M << i;
	N = N | M;
	return N;
}

int main() {
	int result = combineNumber(
		bitset<32>("100000000000"), 
		bitset<32>("10011"),
		6,
		2);
	bitset<32> realResult(result);
	cout << "result:"<<realResult << endl;
	return 0;
};








