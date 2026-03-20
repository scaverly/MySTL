#include "MyString.h"

// Конструктуры
MyString::MyString() {
	str = new char[1] {'\0'};
	length = 0;
}

MyString::MyString(const char* str) {
	this->length = strlen(str);
	this->str = new char[length + 1];
	for (size_t i = 0; i <= length; i++) {
		this->str[i] = str[i];
	}
}

MyString::MyString(size_t n, char c) {
	length = n;
	str = new char[length + 1];
	for (size_t i = 0; i < length; ++i) {
		str[i] = c;
	}
	str[length] = '\0';
}

MyString::MyString(char c) {
	length = 1;
	str = new char[length + 1] {c, '\0'};
}

MyString::MyString(const MyString& S, size_t start, size_t len) {
	if (start >= S.length) {
		this->length = 0;
		this->str = new char[length + 1] {'\0'};
	}
	else {
		size_t available_length = S.length - start;
		if (len > available_length) len = available_length;
		this->length = len;
		this->str = new char[length + 1];
		for (size_t i = 0; i < length; ++i) {
			str[i] = S[start + i];
		}
		this->str[length] = '\0';
	}
}

// Конструктор копирования
MyString::MyString(const MyString& other)
	: length(other.str ? other.length : 0)
{
	if (other.str) {
		str = new char[length + 1];
		for (size_t i = 0; i <= length; i++) {
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
MyString& MyString::operator=(const MyString& other)
{
	if (this == &other) {
		return *this;
	}

	char* newBuffer = new char[other.length + 1];
	for (size_t i = 0; i < other.length; i++) {
		newBuffer[i] = other.str[i];
	}
	newBuffer[other.length] = '\0';

	delete[] this->str;

	this->str = newBuffer;
	this->length = other.length;

	return *this;
}

MyString& MyString::operator +=(const MyString& other) {
	size_t newLength = this->length + other.length;
	char* newBuffer = new char[newLength + 1];
	for (size_t i = 0; i < this->length; i++) {
		newBuffer[i] = this->str[i];
	}
	for (size_t i = 0; i < other.length; i++) {
		newBuffer[this->length + i] = other.str[i];
	}
	newBuffer[newLength] = '\0';

	// Очищаем старую память и обновляем поля
	delete[] this->str;
	this->str = newBuffer;
	this->length = newLength;

	return *this;
}

bool MyString::operator !=(const MyString& other)
{
	return !(*this == other);
}

bool MyString::operator ==(const MyString& other)
{
	if (this->length != other.length) {
		return false;
	}
	for (size_t i = 0; i < length; ++i) {
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
	if (index >= length) throw std::out_of_range("Out of range");
	return str[index];
}

// Доступ к символу (Для чтения)
char MyString::at(size_t index) const
{
	if (index >= length) throw std::out_of_range("Out of range");
	return str[index];
}

// Проверка на пустую строку
bool MyString::empty() const {
	return this->length == 0;
}

// Ссылка на первый элемент (Изменение)
char& MyString::front() { 
	return this->str[0];
}

// Ссылка на первый элемент (Чтение)
char MyString::front() const {
	return this->str[0];
}

// Ссылка на последний элемент (Изменение)
char& MyString::back() {
	return this->str[length-1];
}

// Ссылка на последний элемент (Чтение)
char MyString::back() const {
	return this->str[length - 1];
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