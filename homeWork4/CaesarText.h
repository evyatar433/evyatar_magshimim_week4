#include <string>
using namespace std; 
//inheritance from shiftText
class CaesarText : public ShiftText
{
public:
    CaesarText(const string& text);
    ~CaesarText();
    static string encrypt(string& text);
    static string decrypt(string& text);
    string encrypt();
    string decrypt();
};