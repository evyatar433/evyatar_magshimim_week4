#include "CaesarText.h"

// constructor
CaesarText::CaesarText(std::string text) : ShiftText(text, 3)
{

}

// destructor
CaesarText::~CaesarText()
{

}

// static encrypt function that encrypts the text with caesar cipher
std::string CaesarText::encrypt(std::string text)
{
	int length = text.size();

	for (int i = 0; i < length; i++)
	{
		if (isalpha(text[i]))
		{
			// chhange lowercase letters
			if (islower(text[i]))
			{
				text[i] = (text[i] - 'a' + 3) % 26 + 'a';
			}
			// change lowercase letters
			else if (isupper(text[i]))
			{
				text[i] = (text[i] - 'A' + 3) % 26 + 'A';
			}
		}
	}
	return text;
}

// static decrypt function that decrypts the text with caesar cipher
std::string CaesarText::decrypt(std::string text)
{
	int i = 0;
	int j = 0;
	int length = text.size();
	for (i = 0; i < length; i++)
	{
		if (isalpha(text[i]))
		{
			for (j = 0; j < 3; j++)
			{
				text[i] -= 1;
				if (text[i] < 'a')
				{
					text[i] = 'z';
				}
			}
		}
	}
	return text;
}



// non stantic encrypt
std::string CaesarText::encrypt()
{
	if (this->_isEncrypted == true)
	{
		return this->_text;
	}
	std::string text = getText();
	this->_isEncrypted = true;
	this->_text = encrypt(text);
	return this->_text;
}


// non static decrypt
std::string CaesarText::decrypt()
{
	if (this->_isEncrypted == false)
	{
		return this->_text;
	}
	std::string text = getText();
	this->_isEncrypted = false;
	this->_text = decrypt(text);
	return this->_text;
}


