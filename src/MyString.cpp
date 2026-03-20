#include "MyString.h"

// Конструктуры
MyString::MyString() {
	str = new char[1] {'\0'};
	length = 0;
}

MyString::MyString(const char* str) {
	this->length = strlen(str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->str[i] = str[i];
	}
	this->str[length] = '\0';
}

// Конструктор копирования
MyString::MyString(const MyString& other) {
	this->length = other.length;
	if (other.str != nullptr) {
		this->str = new char[length + 1];
		for (int i = 0; i <= length; i++) {
			this->str[i] = other.str[i];
		}
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

	delete[] str;

	this->length = other.length;
	this->str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		this->str[i] = other.str[i];
	}
	this->str[length] = '\0';
	return *this;
}

MyString MyString::operator+(const MyString& other)
{
	MyString result(*this);
	result += other;
	return result;
}

MyString& MyString::operator +=(const MyString& other) {
	int newLength = this->length + other.length;
	char* newBuffer = new char[newLength + 1];
	for (int i = 0; i < this->length; i++) {
		newBuffer[i] = this->str[i];
	}
	for (int i = 0; i < other.length; i++) {
		newBuffer[this->length + i] = other.str[i];
	}
	newBuffer[newLength] = '\0';

	// Очищаем старую память и обновляем поля
	delete[] this->str;
	this->str = newBuffer;
	this->length = newLength;

	return *this;
}

// Методы
int MyString::strlen(const char* str) {
	int len = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		++len;
	}
	return len;
}

void MyString::Print() {
	std::cout << str << '\n' << length << '\n';
}

