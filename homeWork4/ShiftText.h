#include <string>
using namespace std;
#include "PlainText.h"  // Assuming this is a valid header for PlainText

class ShiftText : public PlainText
{

protected:
    int _key;
    string _text;

public:
    // constructor to init _text and _key
    ShiftText(string& text, int key);

    // destructor
    ~ShiftText();


    static string encrypt(string& text, int key);

    static string decrypt(string& text, int key);


    // not static encryption function
    string encrypt(string& text, int key);

    // not static deryption function
    string decrypt(string& text, int key);
};