#include <iostream>
#include <string>
#include "PlainText.h"
#include "ShiftText.h"

using namespace std;

// constructor
ShiftText::ShiftText(const string& text, int key) : PlainText(text), _key(key) 
{
 
    encrypt(text, key);

}

// destructor
ShiftText::~ShiftText() {}

// static encryption function
string ShiftText::encrypt(const string& text, int key)
{
    string result = text; 
    for (char& oneChar : result)
    {
        if (isalpha(oneChar))
        {
            oneChar = tolower(oneChar);
            oneChar = (oneChar - 'a' + key) % 26 + 'a'; // shift
        }
    }
    return result;
}

// static decryption function
string ShiftText::decrypt(const string& text, int key)
{
    string result = text;
    for (char& oneChar : result)
    {
        if (isalpha(oneChar))
        {
            oneChar = tolower(oneChar);
            oneChar = (oneChar - 'a' - key + 26) % 26 + 'a'; // reverse shift
        }
    }
    return result;
}

// not static encryption function (operates on _text)
string ShiftText::encrypt()
{
    for (char& oneChar : _text)
    {
        if (isalpha(oneChar))
        {
            oneChar = tolower(oneChar);
            oneChar = (oneChar - 'a' + _key) % 26 + 'a'; // shift
        }
    }
    _isEncrypt = true;
    return _text;
}

// not static decryption function (operates on _text)
string ShiftText::decrypt()
{
    for (char& oneChar : _text)
    {
        if (isalpha(oneChar))
        {
            oneChar = tolower(oneChar);
            oneChar = (oneChar - 'a' - _key + 26) % 26 + 'a'; // reverse shift
        }
    }
    _isEncrypt = false;
    return _text;
}