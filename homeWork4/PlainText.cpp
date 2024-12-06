#include <iostream>
#include <string>
#include "PlainText.h"

PlainText::PlainText(std::string& str) : _text(str), _isEncrypt(false) {}

PlainText::~PlainText() {}

// return if text is encrypted
bool PlainText::isEncrypt() const
{
    return isEncrypt;
}

// return the text
string PlainText::getText() const
{
    return _text;
}


int main()
{
    std::cout << "Hello World!\n";
}

