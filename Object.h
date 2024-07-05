#pragma once
#include "String.h"

class Object
{
public:

	Object();

	Object(const char* name, const char* description);
	Object(const char* name, String& description);
	Object(String& name,const char* description);
	Object(String& name, String& description);

	~Object();

public:

	void Name() const;
	void Description() const;
	void Use() const;

private:

	String name;
	String desc;

};

