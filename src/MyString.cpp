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

// Методы
size_t MyString::strlen(const char* str) {
	size_t len = 0;
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		++len;
	}
	return len;
}

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