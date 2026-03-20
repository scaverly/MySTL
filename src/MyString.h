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
	// Методы
	size_t strlen(const char* str);
	void Print();
private:
	// Переменные
	char* str;
	size_t length;
};