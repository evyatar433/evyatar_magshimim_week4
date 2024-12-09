#include "ShiftText.h"

// constructor
ShiftText::ShiftText(std::string text, int key) : PlainText(encrypt(text, key)), _key(key)
{
	this->_isEncrypted = true;
}

// destructor
ShiftText::~ShiftText()
{

	this->_key = 0;

}

// static encrypt function that encrypts the text using Caesar cipher
std::string ShiftText::encrypt(std::string text, int key)
{
	int length = text.size(); 

	// loop through each character of the text
	for (int i = 0; i < length; i++)
	{
		// check if the character is an alphabet)
		if (isalpha(text[i]))
		{

			char letter = (isupper(text[i])) ? 'A' : 'a'; // change to lower
			text[i] = letter + (text[i] - letter + key) % 26;
		}
	}

	// return the encrypted text
	return text;
}


// static decrypt
std::string ShiftText::decrypt(std::string text, int key)
{
	int length = text.size();
	for (int i = 0; i < length; i++)
	{
		if (isalpha(text[i])) // check if the character is a letter
		{
			char base = (isupper(text[i])) ? 'A' : 'a'; // change to lower
			text[i] = (text[i] - base - key + 26) % 26 + base; 
		}
	}
	return text;
}

// non static encrypt
std::string ShiftText::encrypt()
{
	if (this->isEncrypted() == true)
	{
		return this->_text; // no change
	}
	// change
	std::string text = getText();
	this->_text = encrypt(text, _key);
	this->_isEncrypted = true;
	return this->_text;
}

// non static decrypt
std::string ShiftText::decrypt()
{
	if (this->isEncrypted() == false)
	{
		return this->_text; // no change
	}
	// change
	std::string text = getText();
	this->_text = decrypt(text, _key);
	this->_isEncrypted = false;
	return this->_text;
}
