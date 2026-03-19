#include "MyString.h"


int main() {

	MyString a = "Hello       ";
	MyString b = "World!!!!!!";

	MyString result = a + b;

	result.Print();

	return 0;
}