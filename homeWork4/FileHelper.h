#include <string>
using namespace std;

class FileHelper
{
protected:
    string _text;
    bool _isEncrypt;

public:
    static string readFileToString(const string& fileName);
    static void writeWords(string& inputFileName, string& outputFileName);
    static void saveTextInFile(const string& text, const string& outputFileName);
};