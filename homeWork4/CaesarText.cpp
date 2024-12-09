#include "CaesarText.h"

// constructor
CaesarText::CaesarText(std::string text) : ShiftText(text, 3)
{

}

// destructor
CaesarText::~CaesarText()
{

}

std::string CaesarText::encrypt(std::string text)
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
				text[i] += 1;
				if (text[i] > 'z')
				{
					text[i] = 'a';
				}
			}
		}
	}
	return text;
}

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

