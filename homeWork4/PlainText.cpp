#include <iostream>
#include <string>
#include "PlainText.h"

PlainText::PlainText(const std::string& str) : _text(str), _isEncrypt(false) {}

PlainText::~PlainText() {}

// return if text is encrypted
bool PlainText::isEncrypt() const
{
    return _isEncrypt;
}

// return the text
string PlainText::getText() const
{
    return _text;
}
