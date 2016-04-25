#include <iostream>
using namespace std;

void reverse(char* str) {
	if (!str) {
		return;
	}

	int size = 0;
	while (str[size]) {
		size++;
	}

	int half = size / 2;
	size--;//Last char is '\0'
	char temp;

	for (int i = 0; i < half; i++) {
		temp = str[i];
		str[i] = str[size - i];
		str[size - i] = temp;
	}
}

void reverse2(char* str) {
	if (str) {
		char *ptrEnd = str;
		char temp;

		while (*ptrEnd) {
			ptrEnd++;
		}
		ptrEnd--;

		while (str < ptrEnd) {
			temp = *str;
			*str++ = *ptrEnd;
			*ptrEnd-- = temp;
		}
	}
}

int main() {
	//char str[] = "abcde";
	char str[] = "abcde";
	reverse(str);
	reverse2(str);
	cout << "END: " << str << endl;

	return 0;
};