#include "MyString.h"

// Конструктуры
MyString::MyString() {
	str = nullptr;
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
	else {
		this->str = nullptr;
	}
}

// Деструктор
MyString::~MyString() {
	delete[] this->str;
}

// Операторы
MyString& MyString::operator=(const MyString& other)
{
	// Если мы присваеваем a = a
	if (this == &other) {
		return *this;
	}
	if (this->str != nullptr) {
		delete[] str;
	}

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
	MyString newStr;
	newStr.length = this->length + other.length;
	newStr.str = new char[newStr.length + 1];

	int i = 0;
	for (; i < this->length; i++)
	{
		newStr.str[i] = this->str[i];
	}
	for (int j = 0; j < other.length; j++, i++)
	{
		newStr.str[i] = other.str[j];
	}
	newStr.str[i] = '\0';

	return newStr;
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

