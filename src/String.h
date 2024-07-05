#pragma once
#include <iostream> //for in/out functionality, cout and cin
#include <stdexcept> //to throw error codes
#include <cstring> //for cstring funcs
#include <algorithm> // for max() func

using namespace std;

#define SIZE_T_MAX ((size_t)-1)
#define MAX_CHAR_LENGTH 256

class String
{
public: // Constructors // 

	String();

	String(const char ch);
	
	String(const char* str);
	
	String(String& copy);
	String(const String& copy);

	~String();
	
public: // Overrides //

	bool operator==(const String& other);
	bool operator!=(const String& other);

	bool operator<(const String& str);

	String& operator+(const String& str);
	String& operator+=(const String& str);

	String& operator=(const char* str);
	String& operator=(const String& str);

	char& operator[](const size_t index);
	const char& operator[](const size_t index) const;

public: // Functions //

	const char* GetData() const;

	void SetData(char toSet);
	void SetData(const char* toSet);

	size_t len() const;
	
	char& CharAt(size_t index);
	const char& CharAt(size_t index) const;

	bool IsEqual(const String& other) const;
	
	//NOTE: Suffix and Prefix are Append and Prepend respectively,
	// renamed for my own readability
	String& Suffix(const String& str);
	String& Prefix(const String& str);

	//Minor redundancy, Cstr() is == to GetData() which is used for readability
	const char* Cstr() const;

	String& ToLower();
	String& ToUpper();

	size_t Find(const String& str);
	size_t Find(size_t startindex, const String& str);

	String& Replace(const String& find, const String& replace);
	String& Replace(const String& find, const String& replace, bool replaceAll);

	String& Input();
	String& Print();
	String& Print(char modifier);

private:

	//Clamp for capital letters in ASCII
	const int capBnds[2] = {65,90};

	//Clamp for lowercase letters in ASCII
	const int lwrBnds[2] = {97,122};

	//Case change +- offset
	const int asciiOffset = 32;

	//String variable contents
	char* data;

};