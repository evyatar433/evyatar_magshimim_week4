#ifndef _PLAINTEXT_H_
#define _PLAINTEXT_H_
#include <iostream>

class PlainText
{
protected:
	std::string _text;
	bool _isEncrypted;

public:
	static int numOfTexts;
	PlainText(std::string text);
	~PlainText();
	bool isEncrypted() const;
	std::string getText() const;
};

#endif