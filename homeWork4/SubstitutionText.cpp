#include "SubstitutionText.h"

// constructor
SubstitutionText::SubstitutionText(std::string text, std::string dictionaryFileName) : PlainText(encrypt(text, dictionaryFileName)), dictionaryFileName(dictionaryFileName)
{
	this->_isEncrypted = true;
}
// destructor
SubstitutionText::~SubstitutionText()
{
	this->dictionaryFileName = "";
}


std::string SubstitutionText::encrypt(std::string inputText, std::string dictFileName)
{
	// get the length of the text
	int textLength = inputText.size();
	int charIndex = 0;
	int dictIndex = 0;
	std::string dictionaryFile = dictFileName;
	std::string dictionaryLine;

	// open the dictionary 
	std::ifstream dictionaryStream(dictionaryFile);

	// loop through each character of the text
	for (charIndex = 0; charIndex < textLength; charIndex++)
	{
		// check if the current character is an alphabet
		if (isalpha(inputText[charIndex]))
		{
			// loop through each line
			while (getline(dictionaryStream, dictionaryLine))
			{
				// if the character in the input text matches the first character of the line
				if (inputText[charIndex] == dictionaryLine[0])
				{
					inputText[charIndex] = dictionaryLine[2];

					dictionaryStream.clear();
					dictionaryStream.seekg(0);
					break;
				}
				else
				{
					continue;
				}
			}
		}
	}

	// close the dictionary 
	dictionaryStream.close();

	return inputText;
}

std::string SubstitutionText::decrypt(std::string text, std::string dictionaryFileName)
{
	int length = text.size();


	std::string fileName = dictionaryFileName;

	std::string line;

	// open the dictionary
	std::ifstream MyReadFile(fileName);

	if (!MyReadFile) {
		std::cerr << "Could not open the file " << fileName << std::endl;
		return text;
	}

	// loop through each character in the text
	for (int i = 0; i < length; i++) {
		// if the current character is alphabet
		if (isalpha(text[i])) 
		{
			MyReadFile.clear();
			MyReadFile.seekg(0);

			// loop through the dictionary file
			while (getline(MyReadFile, line)) {
				// if the current text character matches the character in the dictionary
				if (text[i] == line[2]) 
				{
					text[i] = line[0];
					break; 
				}
			}
		}
	}

	// close the dictionary file
	MyReadFile.close();

	return text;
}


// non static decrypt
std::string SubstitutionText::decrypt()
{
	if (this->_isEncrypted == false)
	{
		return this->_text;
	}
	std::string text = getText();
	this->_text = decrypt(text, this->dictionaryFileName);
	this->_isEncrypted = false;
	return this->_text;
}
// static decrypt
std::string SubstitutionText::encrypt()
{
	if (this->_isEncrypted == true)
	{
		return this->_text;
	}
	std::string text = getText();
	this->_text = encrypt(text, this->dictionaryFileName);
	this->_isEncrypted = true;
	return this->_text;
}
