#include "String.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
						 // Constructors / Deconstructor //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


String::String()
{
	data = new char[1];
	data[0] = '\0';
}

String::String(const char ch) 
{
	SetData(ch);
}

String::String(const char* str)
{	
	SetData(str);
}

String::String(String& copy)
{
	SetData(copy.GetData());
}

String::String(const String& copy)
{
	SetData(const_cast<char*>(copy.GetData()));
}

String::~String()
{
	if (data != nullptr) {
		delete[] data;
	}
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
								  // Overrides //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


bool String::operator==(const String& other)
{
	//Returns IsEqual() (see function below)
	return IsEqual(other);
}

bool String::operator!=(const String& other)
{
	//Returns if the two string are NOT the same contents
	return (data != other.GetData());
}

bool String::operator<(const String& str)
{
	//NOTE returns true if LHS is first alphabetically, not case sensitive
	bool orderFound = false;
	int index = 0;

	String lhs = data;
	String rhs = str;

	//Sets both to lowercase since A == 65 and a == 97 in ASCII table
	rhs.ToLower();
	lhs.ToLower();

	while (orderFound == false) {
		if (lhs[index] < rhs[index]) { //if LHS is smaller (earlier) than RHS
			orderFound = true;
			return true; //LHS comes first in alphabet
		}
		else { //Else they are the same, check next index
			index++;
		} //Else it is greater (later) in the alphabet
		orderFound = true;	
		return true; // 
	} //If all indexes are checked returns false since they're the same order in alphabet
	return false;
}

String& String::operator+(const String& str)
{
	//Adds RHS to LHS
	return Suffix(str);
}

String& String::operator+=(const String& str)
{
	//Same as a = a + b; just different syntax
	return Suffix(str);
}

String& String::operator=(const char* str)
{
	//Runs SetData() to set data (LHS) to str (RHS)
	SetData(str);
	return *this;
}

String& String::operator=(const String& str)
{
	//Runs SetData() to set data (LHS) to str (RHS) with
	//a const cast since it takes a reference instead of a char*
	SetData(const_cast<char*>(str.GetData()));
	return *this;
}

char& String::operator[](const size_t index)
{
	//Throw error if index is out of range
	if (index >= len() || index < 0) { throw out_of_range("Out of range"); }
	//Otherwise returns contents of data at index
	return data[index];
}

const char& String::operator[](const size_t index) const
{
	//Throw error if index is out of range
	if (index >= len() || index < 0) { throw out_of_range("Out of range"); }
	//Otherwise returns contents of data at index
	return data[index];
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                  // Functions //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


const char* String::GetData() const
{
	//returns the contents of data
	return data;
}

void String::SetData(char toSet)
{
	//creates new data size to set it to one char and a '\0'
	data = new char[2];
	data[0] = toSet;
	data[1] = '\0';
}

void String::SetData(const char* toSet)
{
	//length of new string excluding '\0'
	int l = strlen(toSet);

	//sets data to be a new size of l + 1 to allow for '\0' at the end
	data = new char[l + 1];

	//For loop to set data to the new string
	for (int i = 0; i < l; i++) {

		data[i] = toSet[i];

	}
	//if there is no '\0' at the end. sets last item in array to '\0' to avoid overflow
	if (data[l - 1] != '\0') {
		data[l] = '\0';
	}
}

size_t String::len() const
{
	//strlen returns the length of data, excluding the '\0' character
	return strlen(data);

}

char& String::CharAt(size_t index)
{
	//Throw error if index is out of range
	if (index >= sizeof(*this) || index < 0) { throw out_of_range("Out of range"); }
	//If it's in range return the contents of data at index
	return data[index];
}

const char& String::CharAt(size_t index) const
{
	//same as previous, just a const
	if (index >= sizeof(*this) || index < 0) { throw out_of_range("Out of range"); }
	return data[index];
}

bool String::IsEqual(const String& other) const
{
	//lenght of data (LHS)
	int a = len();
	//length of other (RHS)
	int b = other.len();

	if (a != b) { // If the size of a and b are different, exits
		return false;
	}

	for (int i = 0; i < a; ++i) { //for each matching char at [i], continue
		if (data[i] == other[i]) {
			continue;
		}
		else { //if the char at [i] of both arrays it returns false
			return false;
		}
		//if the for loop finishes, returns true
	}	return true;
}

String& String::Suffix(const String& str) 
{	//Suffix is Append() function renamed for personal preference

	int strSize = str.len(); //Size of string to suffix to data
	int dataSize = strlen(data); //Size of data
	int newStrSize = dataSize + strSize; //Total size of chars (excl '\0')

	//Set new tmp object to size of data + 1 (for '\0'), then sets the contents of tmp
	String tmp = new char[dataSize + 1];
	tmp.SetData(data);

	//Once data has been copied, write new array size of newStrSize + 1 (for the '\0')
	delete[] data;
	data = new char[newStrSize + 1];

	int j = 0;
	int k = dataSize;

	//For loop sets data to be string before setting its data to be tmp at the end
	for (int i = 0; i < max(strSize, dataSize); ++i) {
		if (j < dataSize) {
			data[j] = tmp[i];
			j++;
		}
		if (k < newStrSize) {
			data[k] = str[i];
			k++;
		}

	}
	//For loop to set data at size greater than original string to new suffix contents
	
	//Checks if data has overrrun, and sets the end of data to be '\0'
	if (data[newStrSize] != '\0') {
		data[newStrSize] = '\0';
	}
	return *this;
}

String& String::Prefix(const String& str) //Renamed from Prepend()
{	// Similar to Suffix, just adds the string before data
	int strSize = str.len();
	int dataSize = strlen(data);
	int newStrSize = dataSize + strSize;

	String tmp;
	tmp.SetData(data);

	data = new char[newStrSize + 1];

	//Iterators for simultaneous writing of data[index]
	int j = 0; //Writes to left
	int k = strSize; //Writes to right

	//For loop sets data to be string before setting its data to be tmp at the end
	for (int i = 0; i <= max(strSize,dataSize); ++i) {
		if(j < strSize){
			data[j] = str[i];
			j++;
		}
		if (k < newStrSize) {
			data[k] = tmp[i];
			k++;
		}
	}
	//Checks if data has overrrun, and sets the end of data to be '\0'
	if (data[newStrSize] != '\0') {
		data[newStrSize] = '\0';
	}

	return *this;
}

const char* String::Cstr() const
{
	//Same as GetData() so it just calls GetData()
	return GetData();
}

String& String::ToLower()
{//Uses ASCII values to clamp ranges for casechanges - see private variables in string.h

	for (int i = 0; i < len(); ++i) {
		if (data[i] >= capBnds[0] && data[i] <= capBnds[1]) {
			data[i] += asciiOffset;
		}
	}
	return *this;
}

String& String::ToUpper()
{//Uses ASCII values to clamp ranges for casechanges - see private variables in string.h

	for (int i = 0; i < len(); ++i) {
		if (data[i] >= lwrBnds[0] && data[i] <= lwrBnds[1]) {
			data[i] -= asciiOffset;
		}
	}

	return *this;
}

size_t String::Find(const String& str)
{
	//Runs Find() at index 0, removed identical lines of code
	return Find(0, str);
}

size_t String::Find(size_t startindex, const String& str)
{
	//sets temp objects for readability and debug
	/*String phrase = str;*/
	String text = data;

	int x = 0; //Iterator
	int i = startindex; //Index in data to start from

	while (i < text.len()) { //Runs until word is found || until end of text, excluding last char
		if (text[i] == str[x]) { //If char is the same, check next
			x++;
			i++;

			if (x == str.len()) { //If x == phrase,len(), the string has been found and can exit
				return i - x; // i-x is index of phrase
			}
			continue;
		} // Else //
		i -= x-1;
		x = 0;
	}
	return SIZE_T_MAX; // == -1;
}

String& String::Replace(const String& find, const String& replace)
{	//Replaces first instance only by default
	return Replace(find, replace, false);
}

String& String::Replace(const String& find, const String& replace, bool replaceAll)
{	//Replaces string to find with replace, if replaceAll == false, replace only the first instance;

	int sizeReplace = replace.len(); //Size of substring replace
	int sizeFind = find.len(); //Size of substring find
	int diff = sizeReplace - sizeFind; //Difference between replace - find
	
	int newArraySize = strlen(data) + diff; //size of data + or - diff for new array sizing
	int leftSize = Find(find); //Finds index of substring 
	int rightSize = strlen(data) - leftSize - sizeFind; //Right hand side of the string exluding the text to be removed
	
	String temp; //temp for new size of string after replace
	temp.SetData(data);

	data = new char[newArraySize + 1]; //Sets data to new size

	if (leftSize == SIZE_T_MAX) { //If find returns -1, aborts since -1 == not found
		return *this;
	}
	
	int i = 0; //Iterator

	int l = 0; //left iterator
	int m = leftSize; //middle iterator (substring replace)
	int rtmp = leftSize + sizeFind; //right iterator 
	int r = leftSize + sizeReplace; //right iterator

	while (i < max(sizeReplace, max(leftSize,rightSize))) { //while i is less than the biggest size to write
		if (l < leftSize) { //and while i < left chunk of string
			data[i] = temp[i];
			l++;
		}
		if (m < leftSize + sizeReplace && replace[i] != '\0') { //m is middle of data
			data[m] = replace[i];
			m++;
		}
		if (r < newArraySize) { //puts the right side of data back together 
			data[r] = temp[rtmp];
			r++;
			rtmp++;
		}
		i++;
	}
	if (data[newArraySize] != '\0') { //if last char of data != '\0', sets to that to avoid mem leaks 
		data[newArraySize] = '\0';
	}
	if (replaceAll == true) { //If replaceAll is set to false, it only replaces the first instance
		if (Find(find) != SIZE_T_MAX) { //Checks if the substring find exists in next instance
			Replace(find, replace, true); //Recursive Replace();
		}
		else {
			return *this;
		}
	}
}

String& String::Input()
{
	//creates char array to read from console max number of chars
	//in input is 255 + '\0'
	char input[MAX_CHAR_LENGTH];

	//Input reads line from console, taking a max of 255 chars
	cin.getline(input, MAX_CHAR_LENGTH - 1, '\n');

	//Makes data fit the new string, and strlen(input) wont make it a 256 length,
	//only length of the input + 1 for '\0'
	SetData(input);

	return *this;
}

String& String::Print() //Just prints the data taking no modifier
{
	cout << data;
	return *this;
}

String& String::Print(char modifier)
{
	char mod = modifier;

	switch (mod) {

	case 'n': //returns data with a new line after
		return Suffix('\n');
		break;

	case 't': //returns data with a tab after it
		return Suffix('\t');
		break;

	case 'p': //returns data with a space before (p stands for prefix)
		return Prefix(" ");
		break;

	case's': //returns data with a space after (s stands for suffix)
		return Suffix(" ");
		break;

	default: //just returns data with no mods if the modifier param != valid mod
		return *this;
	} 
}
