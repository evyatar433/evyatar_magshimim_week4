//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <string>
//#include "FileHelper.h"
//#include "PlainText.h"
//using namespace std;
//
//
//
//string FileHelper::readFileToString(string& fileName)
//{
//    std::ifstream file(fileName);
//    if (!file.is_open())
//    {
//        return "";
//    }
//
//    std::stringstream buffer;
//    buffer << file.rdbuf();
//
//}
//
//
//
//
//void FileHelper::writeWordsToFile(string& inputFileName, string& outputFileName)
//{
//
//    ifstream inputFile(inputFileName);  
//    ofstream outputFile(outputFileName);
//
//    if (!inputFile.is_open()) 
//    {
//        cerr << "error" << endl;
//        return;
//    }
//
//    if (!outputFile.is_open()) 
//    {
//        cerr << "error" << endl;
//        return;
//    }
//
//    string word;
//    while (inputFile >> word) 
//    { 
//
//        outputFile << word << endl;  
//
//    }
//
//    inputFile.close();  
//    outputFile.close();
//
//}
//
//
//void FileHelper::saveTextInFile(const string& text, const string& outputFileName)
//{
//    ofstream outFile(outputFileName);
//    if (outFile.is_open()) 
//    {
//        outFile << text;
//        outFile.close();
//    }
//}