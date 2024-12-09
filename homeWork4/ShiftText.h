#ifndef _SHIFTTEXT_H_
#define _SHIFTTEXT_H_
#include <iostream>
#include "PlainText.h"

class ShiftText : public PlainText
{
private:
	int _key;

public:
	ShiftText(std::string text, int key);
	~ShiftText();
	static std::string encrypt(std::string text, int key);
	static std::string decrypt(std::string text, int key);
	std::string decrypt();
	std::string encrypt();
};

#endif
