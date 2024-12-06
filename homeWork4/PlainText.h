#include <string>

using namespace std;

class PlainText
{
protected:
    string _text;
    bool _isEncrypt;

public:
    PlainText(std::string& str);

    ~PlainText();

    bool isEncrypt() const;
    string getText() const;
};