#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "FileHelper.h"
#include "PlainText.h"

string FileHelper::readFileToString(const string& fileName)
{
    std::ifstream file(fileName); 
    if (!file.is_open()) 
    {
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str(); 
}
 
void FileHelper::writeWords(string& inputFileName, string& outputFileName)
{
    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);

    if (!inputFile.is_open()) 
    {
        std::cerr << "Error: Unable to open input file: " << inputFileName << std::endl;
        return;
    }

    if (!outputFile.is_open()) 
    {
        std::cerr << "Error: Unable to open output file: " << outputFileName << std::endl;
        return;
    }

    std::string word;
    while (inputFile >> word) 
    {
        outputFile << word << std::endl;
    }
}

void FileHelper::saveTextInFile(const string& text, const string& outputFileName)
{
    std::ofstream outFile(outputFileName);
    if (!outFile.is_open()) 
    {
        std::cerr << "Error: Unable to open output file: " << outputFileName << std::endl;
        return;
    }
    outFile << text;
}
