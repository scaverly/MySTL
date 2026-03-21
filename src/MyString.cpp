#include "MyString.h"

// Конструктуры
MyString::MyString() {
	str = new char[1] {'\0'};
	_length = 0;
	_capacity = _length + 1;
}

MyString::MyString(const char* str) {
	this->_length = strlen(str);
	this->_capacity = _length + 1;
	this->str = new char[_capacity];
	for (size_t i = 0; i <= _length; i++) {
		this->str[i] = str[i];
	}
}

MyString::MyString(size_t n, char c) {
	_length = n;
	_capacity = _length + 1;
	str = new char[_capacity];
	for (size_t i = 0; i < _length; ++i) {
		str[i] = c;
	}
	str[_length] = '\0';
}

MyString::MyString(char c) {
	_length = 1;
	_capacity = _length + 1;
	str = new char[_capacity] {c, '\0'};
}

MyString::MyString(const MyString& S, size_t start, size_t len) {
	if (start >= S._length) {
		this->_length = 0;
		this->_capacity = _length + 1;
		this->str = new char[_capacity] {'\0'};
	}
	else {
		size_t available__length = S._length - start;
		if (len > available__length) len = available__length;
		this->_length = len;
		this->_capacity = _length + 1;
		this->str = new char[_capacity];
		for (size_t i = 0; i < _length; ++i) {
			str[i] = S[start + i];
		}
		this->str[_length] = '\0';
	}
}

// Конструктор копирования
MyString::MyString(const MyString& other)
	: _length(other.str ? other._length : 0) {
	_capacity = _length + 1;
	if (other.str) {
		str = new char[_capacity];
		for (size_t i = 0; i <= _length; i++) {
			str[i] = other.str[i];
		}
	}
	else {
		str = new char[1] {'\0'};
	}
}

// Деструктор
MyString::~MyString() {
	delete[] this->str;
}

// Операторы
MyString& MyString::operator=(const MyString& other) {
	if (this == &other) {
		return *this;
	}

	char* newBuffer = new char[other._length + 1];
	for (size_t i = 0; i < other._length; i++) {
		newBuffer[i] = other.str[i];
	}
	newBuffer[other._length] = '\0';

	delete[] this->str;

	this->str = newBuffer;
	this->_length = other._length;
	this->_capacity = _length + 1;

	return *this;
}

MyString& MyString::operator +=(const MyString& other) {
	size_t new_length = this->_length + other._length;

	// Если места не хватает
	if (new_length + 1 > this->_capacity) {
		reserve(new_length * 2 + 1);
	}

	// Копирование данных в конец текущего str
	for (size_t i = 0; i < other._length; i++) {
		this->str[this->_length + i] = other.str[i];
	}

	this->_length = new_length;
	this->str[this->_length] = '\0';

	return *this;
}

bool MyString::operator !=(const MyString& other) {
	return !(*this == other);
}

bool MyString::operator ==(const MyString& other) {
	if (this->_length != other._length) {
		return false;
	}
	for (size_t i = 0; i < _length; ++i) {
		if (this->str[i] != other.str[i]) {
			return false;
		}
	}
	return true;
}

MyString MyString::operator+(const MyString& other)
{
	MyString result(*this);
	result += other;
	return result;
}

// Для записи
char& MyString::operator[](size_t index) {
	return this->str[index];
}

// Для чтения
char MyString::operator [](size_t index) const {
	return str[index];
}

// Методы
// Длина строки
size_t MyString::strlen(const char* str) {
	size_t len = 0;
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		++len;
	}
	return len;
}

// Доступ к символу (Для изменения)
char& MyString::at(size_t index)
{
	if (index >= _length) throw std::out_of_range("Out of range");
	return str[index];
}

// Доступ к символу (Для чтения)
char MyString::at(size_t index) const
{
	if (index >= _length) throw std::out_of_range("Out of range");
	return str[index];
}

// Проверка на пустую строку
bool MyString::empty() const {
	return this->_length == 0;
}

// Ссылка на первый элемент (Изменение)
char& MyString::front() { 
	if (empty()) throw std::out_of_range("Empty()");
	return this->str[0];
}

// Чтение первого элемент (Чтение)
char MyString::front() const {
	if (empty()) throw std::out_of_range("Empty()");
	return this->str[0];
}

// Ссылка на последний элемент (Изменение)
char& MyString::back() {
	if (empty()) throw std::out_of_range("Empty()");
	return this->str[_length-1];
}

// Чтение последнего элемент (Чтение)
char MyString::back() const {
	if (empty()) throw std::out_of_range("Empty()");
	return this->str[_length - 1];
}

// Кол-во символов в строке _length(), size()
size_t MyString::length() const
{
	return this->_length;
}

size_t MyString::size() const {
	return this->_length;
}

// Кол-во выделенной памяти
size_t MyString::capacity() const {
	return _capacity;
}

// Резервирование памяти
void MyString::reserve(size_t n) {
	if (n <= _capacity) return;

	char* newBuffer = new char[n];

	for (size_t i = 0; i <= _length; i++) {
		newBuffer[i] = str[i];
	}

	delete[] str;

	str = newBuffer;
	_capacity = n;
}

// Освобождение неиспользованной зарезервированной памяти
void MyString::shrink_to_fit() {
	if (_capacity <= _length + 1) return;

	size_t new_capacity = _length + 1;
	char* newBuffer = new char[new_capacity];

	for (size_t i = 0; i <= _length; i++) {
		newBuffer[i] = str[i];
	}
	delete[] str;
	str = newBuffer;
	_capacity = new_capacity;
}

// Очистка строки
void MyString::clear() {
	_length = 0;
	if (str) {
		str[0] = '\0';
	}
}

// Операторы std::cout, std::cin
std::ostream& operator<<(std::ostream& os, const MyString& obj) {
	os << obj.str;
	return os;
}

std::istream& operator>>(std::istream& is, MyString& obj) {
	char buffer[1024]; // Временный буфер для чтения
	is >> buffer;

	obj = buffer; // перегруженный оператор =

	return is;
}