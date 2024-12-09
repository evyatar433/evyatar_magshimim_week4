#include "SubstitutionText.h"

SubstitutionText::SubstitutionText(std::string text, std::string dictionaryFileName) : PlainText(encrypt(text, dictionaryFileName)), dictionaryFileName(dictionaryFileName)
{
	this->_isEncrypted = true;
}

SubstitutionText::~SubstitutionText()
{
	this->dictionaryFileName = "";
}

std::string SubstitutionText::encrypt(std::string text, std::string dictionaryFileName)
{
	int length = text.size();
	int i = 0;
	int j = 0;
	std::string fileName = dictionaryFileName;
	std::string line;
	std::ifstream MyReadFile(fileName);

	for (i = 0; i < length; i++)
	{
		if (isalpha(text[i]))
		{
			while (getline(MyReadFile, line))
			{
				if (text[i] == line[0])
				{
					text[i] = line[2];
					MyReadFile.clear();
					MyReadFile.seekg(0);
					break;
				}
				else
				{
					continue;
				}
			}
		}
	}
	MyReadFile.close();
	return text;

}

std::string SubstitutionText::decrypt(std::string text, std::string dictionaryFileName)
{

	int length = text.size();
	int i = 0;
	int j = 0;
	std::string fileName = dictionaryFileName;
	std::string line;
	std::ifstream MyReadFile(fileName);

	for (i = 0; i < length; i++)
	{
		if (isalpha(text[i]))
		{
			while (getline(MyReadFile, line))
			{
				if (text[i] == line[2])
				{
					text[i] = line[0];
					MyReadFile.clear();
					MyReadFile.seekg(0);
					break;
				}
				else
				{
					continue;
				}
			}
		}
	}
	MyReadFile.close();
	return text;
}

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
