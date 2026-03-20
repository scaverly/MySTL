#pragma once
#include <iostream>

class MyString {
public:
	// Конструкторы
	MyString();
	MyString(const char* str);
	// Конструктор копирования
	MyString(const MyString& other);
	// Деструктор
	~MyString();
	// Операторы
	MyString& operator =(const MyString& other);
	MyString operator +(const MyString& other);
	MyString& operator +=(const MyString& other);
	bool operator !=(const MyString& other);
	bool operator ==(const MyString& other);
	// операторы <<, >>
	friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
	friend std::istream& operator>>(std::istream& is, MyString& obj);
	// Методы
	size_t strlen(const char* str);
private:
	// Переменные
	char* str;
	size_t length;
};