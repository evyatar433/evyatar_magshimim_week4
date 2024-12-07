#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "PlainText.h"
#include "SubstitutionText.h"
using namespace std;

// constructor
SubstitutionText::SubstitutionText(const string& text, const string& dictionaryFileName)
    : PlainText(text), _dictionaryFileName(dictionaryFileName)
{
    encrypt(text, dictionaryFileName);  
}

// destructor
SubstitutionText::~SubstitutionText() {}

// Static decrypt function
string SubstitutionText::decrypt(const string& encryptedText, const string& dictionaryFileName)
{
    unordered_map<char, char> substitutionMap;
    ifstream myfile(dictionaryFileName);
    string line;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            char originalChar = line[0];
            char substituteChar = line[2];
            substitutionMap[substituteChar] = originalChar; // reverse the substitution
        }
        myfile.close();
    }
    else
    {
        cerr << "Error: Could not open file" << endl;
        return "";
    }

    string decryptedText;
    for (char oneChar : encryptedText)
    {
        if (isalpha(oneChar))
        {
            char lowerChar = tolower(oneChar);
            if (substitutionMap.find(lowerChar) != substitutionMap.end())
            {
                decryptedText += substitutionMap[lowerChar];
            }
        }
        else
        {
            decryptedText += oneChar;  // symbols not change
        }
    }

    return decryptedText;
}

// static encrypt function
string SubstitutionText::encrypt(const string& text, const string& dictionaryFileName)
{
    unordered_map<char, char> substitutionMap;
    ifstream myfile(dictionaryFileName);
    string line;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            char originalChar = line[0];
            char substituteChar = line[2];
            substitutionMap[originalChar] = substituteChar; // store the substitution
        }
        myfile.close();
    }
    else
    {
        cerr << "Error: Could not open file" << endl;
        return "";
    }

    string encryptedText;
    for (char oneChar : text)
    {
        if (isalpha(oneChar))
        {
            char lowerChar = tolower(oneChar);
            if (substitutionMap.find(lowerChar) != substitutionMap.end())
            {
                encryptedText += substitutionMap[lowerChar];
            }
        }
        else
        {
            encryptedText += oneChar; // symbols not change
        }
    }

    return encryptedText;
}

// not static encrypt function
string SubstitutionText::encrypt()
{
    return encrypt(_text, _dictionaryFileName);  // Use the instance's text
}

// not static decrypt function
string SubstitutionText::decrypt()
{
    return decrypt(_text, _dictionaryFileName);  
}
