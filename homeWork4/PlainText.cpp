#include "PlainText.h"

int PlainText::numOfTexts = 0;


// constructor
PlainText::PlainText(std::string text) : _text(text), _isEncrypted(false)
{
	numOfTexts++;
}


// destructor
PlainText::~PlainText()
{
	this->_text = "";
	this->_isEncrypted = false;
}

// check if text is encrypted
bool PlainText::isEncrypted() const
{
	return this->_isEncrypted;
}

// return the text 
std::string PlainText::getText() const
{
	return this->_text;
}



// Definition of the overloaded << operator
std::ostream& operator<<(std::ostream& os, const PlainText& pt) 
{
	os << pt._text; 
	return os;
}