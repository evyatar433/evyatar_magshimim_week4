#include <iostream>
#include <string>
#include "ShiftText.h"
#include "CaesarText.h"
using namespace std;

//constructor 
CaesarText::CaesarText(const string& text) : ShiftText(text,3)
{
    encrypt(); 
}


//destructor
CaesarText::~CaesarText() {}



// static encryption function
string CaesarText::encrypt(string& text)
{
    for (char& oneChar : text)
    {
        if (isalpha(oneChar))
        {
            // convert to lower before shifting
            oneChar = tolower(oneChar);
            oneChar = (oneChar - 'a' + 3 ) % 26 + 'a'; // shift
        }
    }
    return text;
}



// static decryption function
string CaesarText::decrypt(string& text)
{
    for (char& oneChar : text)
    {
        if (isalpha(oneChar))
        {
            // convert to lower before shifting
            oneChar = tolower(oneChar);
            oneChar = (oneChar - 'a' - 3 + 26) % 26 + 'a';  // reverse shift 
        }
    }
    return text;
}

// not static encryption functione
string CaesarText::encrypt()
{
    for (char& oneChar : _text)
    {
        if (isalpha(oneChar))
        {
            // convert to lowercase before shifting
            oneChar = tolower(oneChar);
            oneChar = (oneChar - 'a' + 3) % 26 + 'a'; // shift 
        }
    }
    _isEncrypt = true;
    return _text;
}

// not static decryption function
string CaesarText::decrypt()
{
    for (char& oneChar : _text)
    {
        if (isalpha(oneChar))
        {
            // convert to lower before shifting
            oneChar = tolower(oneChar);
            oneChar = (oneChar - 'a' - 3 + 26) % 26 + 'a'; // reverse shift 
        }
    }
    _isEncrypt = false;
    return _text;
}
