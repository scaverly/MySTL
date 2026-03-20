#include "MyString.h"


int main() {
	setlocale(LC_ALL, "ru-RU");

	MyString b1 = "Million";

	char first = b1.front();

	char last = b1.back();

	std::cout << first << " " << last << '\n';

	MyString b2 = "Dolor";

	std::cout << b2.empty() << '\n';

	MyString b3 = "";

	std::cout << b3.empty() << '\n';

	return 0;
}