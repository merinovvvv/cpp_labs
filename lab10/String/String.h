#ifndef STRING_H_
#define STRING_H_
#include <cstring>

class String {
public:
	String();
	String(const char* other);
	String(int count, char ch);
	String(const String& other);
	String(String&& other) noexcept;
	String operator=(const String& other);
	String operator=(String&& other) noexcept;
	~String();
	int length();
	bool empty();
	const char* c_str();
	char& operator[](int index);
	const char& operator[](int index) const;
	char& front();
	char& back();
	const char& front() const;
	const char& back() const;
	void reserve(int capacity);
	void push_back(char ch);
	void pop_back();
	void clear();
	void insert(int index, const String& str);
	void insert(int index, const char* str, int count);
	void erase(int index, int count = 1);
	String operator+ (const String& other);
	String operator+= (const String& other);
	int compare(const String& str) const;
	int compare(const char* str) const;
	bool operator< (const String& other) const;
	bool operator<= (const String& other) const;
	bool operator> (const String& other) const;
	bool operator>= (const String& other) const;
	bool operator== (const String& other) const;
	bool operator!= (const String& other) const;
	bool operator< (const char* other) const;
	bool operator<= (const char* other) const;
	bool operator> (const char* other) const;
	bool operator>= (const char* other) const;
	bool operator== (const char* other) const;
	bool operator!= (const char* other) const;
	friend bool operator==(const char* str, const String& other);
	friend bool operator!=(const char* str, const String& other);
	friend bool operator<(const char* str, const String& other);
	friend bool operator<=(const char* str, const String& other);
	friend bool operator>(const char* str, const String& other);
	friend bool operator>=(const char* str, const String& other);
private:
	char* str;
	int size;
	int capacity = size;
};

#endif //STRING_H_
