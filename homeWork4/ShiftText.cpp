#include <iostream>
#include <string>
#include "ShiftText.h"
#include "PlainText.h"
using namespace std;

// constructor to init _text and _key
ShiftText::ShiftText(string& text, int key) : _text(text), _key(key) {}

// destructor
 ShiftText::~ShiftText() {}



// static encryption function
static string encrypt(string& text, int key)
{
    for (char& oneChar : text)
    {
        if (isalpha(oneChar))
        {
            if (isupper(oneChar))
                oneChar = (oneChar - 'A' + key) % 26 + 'A'; // shift for upper letters
            else
                oneChar = (oneChar - 'a' + key) % 26 + 'a'; // shift for lower letters
        }
    }
    return text;
}



// static decryption function
static string decrypt(string& text, int key)
{
    for (char& oneChar : text)
    {
        if (isalpha(oneChar))
        {
            if (isupper(oneChar))
                oneChar = (oneChar - 'A' - key + 26) % 26 + 'A';  // reverse shift for uppe letters
            else
                oneChar = (oneChar - 'a' - key + 26) % 26 + 'a';  // reverse shift for lower letters
        }
    }
    return text;
}




// encryption function
string ShiftText::encrypt(string& text, int key)
{
    for (char& oneChar : text)
    {
        if (isalpha(oneChar))
        {
            if (isupper(oneChar))
                oneChar = (oneChar - 'A' + key) % 26 + 'A'; // shift for upper letters
            else
                oneChar = (oneChar - 'a' + key) % 26 + 'a'; // shift for lower letters
        }
        // _isEncrypt(parent class member) = true;
    }
    _isEncrypt = true;
    return text;
}



// decryption function
string ShiftText::decrypt(string& text, int key)
{
    for (char& oneChar : text)
    {
        if (isalpha(oneChar))
        {
            if (isupper(oneChar))
                oneChar = (oneChar - 'A' - key + 26) % 26 + 'A';  // reverse shift for uppercase letters
            else
                oneChar = (oneChar - 'a' - key + 26) % 26 + 'a';  // reverse shift for lowercase letters
        }
    }
    _isEncrypt = false;
    return text;
}