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

std::string PlainText::getText() const
{
    return _text;
}

//std::ostream& operator<<(std::ostream& os, const PlainText& p)
//{
//    std::string a = p.getText();
//    std::string encryptedText = ShiftText::encrypt(a);
//    os << encryptedText;  // Print the encrypted text
//    return os;
//}
