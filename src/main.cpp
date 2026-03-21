#include "MyString.h"


int main() {
    setlocale(LC_ALL, "ru-RU");
    MyString s("Hello");
    std::cout << "Строка: " << s << " Capacity: " << s.capacity() << '\n';

    s.reserve(100);
    std::cout << "После reserve: " << s.capacity() << '\n';

    s += " My Name Is TTTTTTTTTTTTTT";
    std::cout << "После +=: " << s << " Capacity " << s.capacity() << '\n';

    s.shrink_to_fit();
    std::cout << "После shrink: Capacity = " << s.capacity() << ", Length = " << s.length() << std::endl;

    MyString s2;
    s2 = s;
    std::cout << "Копия: " << s2 << std::endl;

    s.clear();

    std::cout << "Оригинал после clear " << s << '\n';

	return 0;
}