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
    /*_numOfTexts += 1;*/
    encrypt(text, dictionaryFileName);
}



// destructor
SubstitutionText::~SubstitutionText() {}




// static decryption function
string SubstitutionText::decrypt(const string& text, const string& dictionaryFileName)
{
    return "o";
}







// static encrypt 
string SubstitutionText::encrypt(const string& text, const string& dictionaryFileName)
{
    unordered_map<char, char> substitutionMap; 
    ifstream myfile(dictionaryFileName); 
    string line;

    // load substitution dictionary
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            // extract characters from each line
            char originalChar = line[0];
            char substituteChar = line[2];
            substitutionMap[originalChar] = substituteChar; //store it in map
        }
        myfile.close(); // close the file
    }
    else
    {
        // error 
        cerr << "error: could not open file" << endl;
        return "";
    }


    // encrypt the input text
    string encryptedText;
    for (char oneChar : text)
    {
        if (isalpha(oneChar))
        {
            char lowerChar = tolower(oneChar);
            if (substitutionMap.find(lowerChar) != substitutionMap.end())
            {
                char encryptedChar = substitutionMap[lowerChar]; 
                // add the lower character
                encryptedText += encryptedChar;
               
            }
        }
        else
        {
            // symbols not change
            encryptedText += oneChar;
        }
    }

    return encryptedText;
}









// static encrypt 
string SubstitutionText::decrypt(const string& encryptedText, const string& dictionaryFileName)
{
    unordered_map<char, char> substitutionMap;
    ifstream myfile(dictionaryFileName);
    string line;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            // extract characters from each line
            char originalChar = line[0];
            char substituteChar = line[2];
            substitutionMap[substituteChar] = originalChar; // reverse
        }
        myfile.close();
    }
    else
    {
        // error
        cerr << "error: could not open file" << endl;
        return "";
    }

    // decrypt the input text
    string decryptedText;
    for (char oneChar : encryptedText)
    {
        if (isalpha(oneChar))
        {
            char lowerChar = tolower(oneChar);
            if (substitutionMap.find(lowerChar) != substitutionMap.end())
            {
                char decryptedChar = substitutionMap[lowerChar];
                decryptedText += decryptedChar;
            }
        }
        else
        {
            // Symbols remain unchanged
            decryptedText += oneChar;
        }
    }

    return decryptedText;
}










// not static encrypt 
string SubstitutionText::encrypt() 
{
    unordered_map<char, char> substitutionMap;
    ifstream myfile(_dictionaryFileName);
    string line;

    // load substitution dictionary
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            // extract characters from each line
            char originalChar = line[0];
            char substituteChar = line[2];
            substitutionMap[originalChar] = substituteChar; //store it in map
        }
        myfile.close(); // close the file
    }
    else
    {
        // error 
        cerr << "Error: Could not open the dictionary file." << endl;
        return "";
    }


    // encrypt the input text
    string encryptedText;
    for (char oneChar : _text)
    {
        if (isalpha(oneChar))
        {
            char lowerChar = tolower(oneChar);
            if (substitutionMap.find(lowerChar) != substitutionMap.end())
            {
                char encryptedChar = substitutionMap[lowerChar];
                // add the lower character
                encryptedText += encryptedChar;

            }
        }
        else
        {
            // symbols not change
            encryptedText += oneChar;
        }
    }

    return encryptedText;
}














// not static encrypt 
string SubstitutionText::decrypt()
{
    unordered_map<char, char> substitutionMap;
    ifstream myfile(_dictionaryFileName);
    string line;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            // extract characters from each line
            char originalChar = line[0];
            char substituteChar = line[2];
            substitutionMap[substituteChar] = originalChar; // reverse
        }
        myfile.close();
    }
    else
    {
        // error
        cerr << "error: could not open file" << endl;
        return "";
    }

    // decrypt the input text
    string decryptedText;
    for (char oneChar : _text)
    {
        if (isalpha(oneChar))
        {
            char lowerChar = tolower(oneChar);
            if (substitutionMap.find(lowerChar) != substitutionMap.end())
            {
                char decryptedChar = substitutionMap[lowerChar];
                decryptedText += decryptedChar;
            }
        }
        else
        {
            // Symbols remain unchanged
            decryptedText += oneChar;
        }
    }

    return decryptedText;
}
