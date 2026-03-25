#include "MyString.h"


int main() {
    setlocale(LC_ALL, "ru-RU");

	MyString c = "hello dollar";

	MyString d = "CHUUUK";

	c.insert(6, d);

	std::cout << c << '\n';

	return 0;
}