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
	char& operator[](size_t index);		// Для записи
	char operator[](size_t index) const;		// Для чтения
	// операторы <<, >>
	friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
	friend std::istream& operator>>(std::istream& is, MyString& obj);
	// Методы
	size_t strlen(const char* str);
	char& at(size_t index);              // Для изменения
	char at(size_t index) const;         // Для чтения
private:
	// Переменные
	char* str;
	size_t length;
};