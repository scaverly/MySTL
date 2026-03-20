#include "MyString.h"


int main() {

	MyString a = "Hello world!";

	MyString result = a;

	MyString b1;
	MyString b2 = "Hello";

	MyString b3 = b1;

	b3.Print();

	return 0;
}