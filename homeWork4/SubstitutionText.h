#include <string>
using namespace std;
#include "PlainText.h"

class SubstitutionText : public PlainText
{
private:
    string _dictionaryFileName;

public:
    // constructor
    SubstitutionText(const string& text, const string& dictionaryFileName);

    // destructor
    ~SubstitutionText();

    // static decryption function
    static string decrypt(const string& text, const string& dictionaryFileName);

    // static encryption function
    static string encrypt(const string& text, const string& dictionaryFileName);

    // not static  encrypt method
    string encrypt();

    // not static decrypt method
    string decrypt();
};
