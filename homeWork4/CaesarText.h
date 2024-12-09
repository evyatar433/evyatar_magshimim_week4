#ifndef _CAESARTEXT_H_
#define _CAESARTEXT_H_
#include <iostream>
#include "ShiftText.h"

class CaesarText : public ShiftText
{
public:
	CaesarText(std::string text);
	~CaesarText();
	static std::string encrypt(std::string text);
	static std::string decrypt(std::string text);
	std::string decrypt();
	std::string encrypt();
};

#endif
