#include <string>
using namespace std;
#include "PlainText.h"

// inheritance from PlainText
class ShiftText : public PlainText
{
private:
    int _key;

public:
    // constructor
    ShiftText(const string& text, int key);

    // destructor
    ~ShiftText();

    // static encryption function
    static string encrypt(const string& text, int key);

    // static decryption function
    static string decrypt(const string& text, int key);

    // not static encryption function (operates on _text)
    string encrypt();

    // not static decryption function (operates on _text)
    string decrypt();
};