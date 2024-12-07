#include <string>
using namespace std;

class PlainText
{
protected:
    string _text;
    bool _isEncrypt;
    static int numOfTexts;
public:
    PlainText(const std::string& str);
    ~PlainText();
   /* friend std::ostream& operator<<(std::ostream& text, const PlainText& key);*/
    bool isEncrypt() const;
    string getText() const;
};
 