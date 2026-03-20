#include "MyString.h"


int main() {
	setlocale(LC_ALL, "ru-RU");

	MyString b1 = "Million";

	MyString a = "Dolor";

	a[2] = 'Z';

	std::cout << a;

	return 0;
}