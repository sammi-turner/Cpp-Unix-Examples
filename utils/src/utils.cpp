#include "utils.h"

string utils::userInput()
{
    string s;
    std::getline(std::cin, s);
    return s;
}

string utils::trimmedUserInput()
{
    string s;
    std::getline(std::cin >> std::ws, s);
    return s;
}

string utils::trimWhiteSpace(const string arg)
{
    string dest = "";
    string src = arg;
    int words = sliceCount(arg, ' ');
    int count = 1;
    while (count < words)
    {
        dest += firstSlice(src, ' ');
        dest += " ";
        src = otherSlices(src, ' ');
        count++;
    }
    dest += firstSlice(src, ' ');
    return dest;
}

void utils::shell(const string arg)
{
    system(arg.c_str());
}

int utils::pseudo(const int arg) {
    int result = 0;
    if (arg > 1)
    {
        result = (rand() % arg) + 1;
    }
    return result;
}

void utils::seed() 
{
    srand((int)time(0));
}

bool utils::isCharDigit(const char arg)
{
    return (isdigit(arg) > 0);
}

bool utils::isCharHexDigit(const char arg)
{
    return (isxdigit(arg) > 0);
}

bool utils::isCharAlphaNumeric(const char arg)
{
    return (isalnum(arg) > 0);
}

bool utils::isCharLetter(const char arg)
{
    return (isalpha(arg) > 0);
}

bool utils::isCharLowerCase(const char arg)
{
    return (islower(arg) > 0);
}

bool utils::isCharUpperCase(const char arg)
{
    return (isupper(arg) > 0);
}

bool utils::isCharPunct(const char arg)
{
    return (ispunct(arg) > 0);
}

bool utils::isCharWhiteSpace(const char arg)
{
    return (isspace(arg) > 0);
}

bool utils::isCharGraphical(const char arg)
{
    return (isgraph(arg) > 0);
}

bool utils::isLowerCase(const string arg)
{
    bool result = true;
    int size = arg.length();
    for (int i = 0; i < size; i++)
    {
        if (!isCharLowerCase(arg[i]))
        {
            result = false;
        }
    }
    return result;
}

bool utils::isUpperCase(const string arg)
{
    bool result = true;
    int size = arg.length();
    for (int i = 0; i < size; i++)
    {
        if (!isCharUpperCase(arg[i]))
        {
            result = false;
        }
    }
    return result;
}

bool utils::isAlphabetic(const string arg)
{
    bool result = true;
    int size = arg.length();
    for (int i = 0; i < size; i++)
    {
        if (!isCharLowerCase(arg[i]) && !isCharUpperCase(arg[i]))
        {
            result = false;
        }
    }
    return result;
}

bool utils::isPosInt(const string arg)
{
    if (isInt(arg))
    {
        int n = toInt(arg);
        return n > 0;
    }
    return false;
}

bool utils::isNegInt(const string arg)
{
    if (isInt(arg))
    {
        int n = toInt(arg);
        return n < 0;
    }
    return false;
}

bool utils::isInt(const string arg)
{
    std::stringstream ss(arg);
    int n;
    ss >> n;
    return !ss.fail() && ss.eof(); 
}

bool utils::isFloat(const string arg)
{
    float f;
    std::istringstream iss(arg);
    iss >> std::noskipws >> f;
    return iss.eof() && !iss.fail();
}

int utils::toInt(const string arg)
{
    return std::stoi(arg);
}

float utils::toFloat(const string arg)
{
    return std::stof(arg);
}

bool utils::fileExists(const string name)
{
    bool value = false;
    std::ifstream f(name);
    if (f)
    {
        value = true;
    }
    return value;
}

int utils::fileWrite(const string name, const string text)
{
    std::ofstream myfile;
    myfile.open(name);
    if (myfile.is_open())
    {
        myfile << text;
        myfile.close();
        return 0;
    }
    else
    {
        return 1;
    }
}

void utils::fileAppend(const string name, const string text)
{
    std::ofstream outfile;
    outfile.open(name, std::ios_base::app);
    outfile << text;
}

string utils::fileRead(const string name)
{
    std::ifstream f(name);
    string value;
    if(f) 
    {
        std::ostringstream ss;
        ss << f.rdbuf();
        value = ss.str();
    }
    return value;
}

void utils::fileDelete(const string arg)
{
    system(arg.c_str());
}

int utils::charCount(const string arg, const char ch)
{
    int count = 0;
    int len = arg.length();
    for (int i = 0; i < len; i++)
    {
        if (arg[i] == ch)
        {
            count++;
        }
    }
    return count;
}

string utils::replaceChar(const string arg, const char oldChar, const char newChar)
{
    int len = arg.length();
    string result = arg;
    for (int i = 0; i < len; i++)
    {
        if (arg[i] == oldChar)
        {
            result[i] = newChar;
        }
    }
    return result;
}

bool utils::isSubString(const string arg1, const string arg2)
{
    bool value;
    if (arg2.find(arg1) != string::npos)
    {
        value = true;
    }
    else
    {
        value = false;
    }
    return value;
}

string utils::firstSlice(const string arg, const char delim)
{
    string result = arg;
    while (result[0] == delim)
    {
        result = result.substr(1, result.length());
    }
    int index = result.find(delim);
    result = result.substr(0, index);
    return result;
}

string utils::firstWord(const string arg)
{
    return firstSlice(arg, ' ');
}

string utils::firstLine(const string arg)
{
    return firstSlice(arg, '\n');
}

string utils::otherSlices(const string arg, const char delim)
{
    string result = arg;
    while (result[0] == delim)
    {
        result = result.substr(1, result.length());
    }
    int index = result.find(delim);
    result = result.substr((index + 1), result.length());
    return result;
}

string utils::otherWords(const string arg)
{
    return otherSlices(arg, ' ');
}

string utils::otherLines(const string arg)
{
    return otherSlices(arg, '\n');
}

int utils::sliceCount(const string arg, const char delim)
{
    string first = firstSlice(arg, delim);
    string final = otherSlices(arg, delim);
    int count = 0;
    while (first != final)
    {
        count++;
        first = firstSlice(final, delim);
        final = otherSlices(final, delim);
    }
    count += (final != "");
    return count;
}

int utils::wordCount(const string arg)
{
    return sliceCount(arg, ' ');
}

int utils::lineCount(const string arg)
{
    return sliceCount(arg, '\n');
}

string utils::nthSlice(const string arg, const char delim, const int num)
{
    string trim = trimWhiteSpace(arg);
    int count = 0;
    while (count < num)
    {
        count++;
        trim = otherSlices(trim, delim);
    }
    return firstSlice(trim, delim);
}

string utils::nthWord(const string arg, const int num)
{
    return nthSlice(arg, ' ', num);
}

string utils::nthLine(const string arg, const int num)
{
    return nthSlice(arg, '\n', num);
}

string utils::removeNthSlice(const string arg, const char delim, const int num)
{
    string trim = trimWhiteSpace(arg);
    string result = "";
    int max = sliceCount(arg, delim);
    for (int i = 0; i < num; i++)
    {
        if (i < num)
        {
            result += firstSlice(trim, delim) + delim;
            trim = otherSlices(trim, delim);
        }
        else
        {
            trim = otherSlices(trim, delim);
        }
    }
    if (num < max)
    {
        result += trim;
    }
    return result;
}

string utils::removeNthWord(const string arg, const int num)
{
    return removeNthSlice(arg, ' ', num);
}

string utils::removeNthLine(const string arg, const int num)
{
    return removeNthSlice(arg, '\n', num);
}

string utils::removeLastSlice(const string arg, const char delim)
{
    int num = sliceCount(arg, delim);
    return removeNthSlice(arg, delim, num);
}

string utils::removeLastWord(const string arg)
{
    int num = sliceCount(arg, ' ');
    return removeNthSlice(arg, ' ', num);
}

string utils::removeLastLine(const string arg)
{
    int num = sliceCount(arg, '\n');
    return removeNthSlice(arg, '\n', num);
}

string utils::insertSliceAt(const string arg, const string ins, const char delim, const int num)
{
    string trim = trimWhiteSpace(arg);
    string result;
    int count = 1;
    while (count < num)
    {
        count++;
        result += firstSlice(trim, delim);
        result += delim;
        trim = otherSlices(trim, delim);
    }
    return (result + ins + delim + trim);
}

string utils::insertLineAt(const string arg, const string ins, const int num)
{
    return insertSliceAt(arg, ins, '\n', num);
}

string utils::insertWordAt(const string arg, const string ins, const int num)
{
    return insertSliceAt(arg, ins, ' ', num);
}

string utils::replaceSliceAt(const string arg, const string ins, const char delim, const int num)
{
    string start = insertSliceAt(arg, ins, delim, num);
    string value = removeNthSlice(start, delim, (num + 1));
    return value;
}

string utils::replaceWordAt(const string arg, const string ins, const int num)
{
    string start = insertSliceAt(arg, ins, ' ', num);
    string value = removeNthSlice(start, ' ', (num + 1));
    return value;
}

string utils::replaceLineAt(const string arg, const string ins, const int num)
{
    string start = insertSliceAt(arg, ins, '\n', num);
    string value = removeNthSlice(start, '\n', (num + 1));
    return value;
}

void utils::appendVectorToFile(const string fileName, const vector<string> v)
{
    string current = "";
    int len = v.size();
    for (int i = 0; i < len; i++)
    {
        current = v[i] + "\n";
        fileAppend(fileName, current);
    }
}

int utils::stringPosition(const string arg, const vector<string> v)
{
    int value = -1;
    int len = v.size();
    for (int i = 0; i < len; i++)
    {
        if (arg == v[i])
        {
            value = i;
        }
    }
    return value;
}

vector<string> utils::splitStringByChar(const string s, const char delim) 
{
    int slices = sliceCount(s, delim);
    vector<string> result;
    string currentSlice;
    for (int i = 0; i < slices; i++)
    {
        currentSlice = nthSlice(s, '|', i);
        result.push_back(currentSlice);
    }
    return result;
}

vector<string> utils::splitStringBySpace(const string s) 
{
    int words = wordCount(s);
    vector<string> result;
    string currentWord;
    for (int i = 0; i < words; i++)
    {
        currentWord = nthWord(s, i);
        result.push_back(currentWord);
    }
    return result;
}

vector<string> utils::splitStringByNewline(const string s) 
{
    int lines = lineCount(s);
    vector<string> result;
    string currentLine;
    for (int i = 0; i < lines; i++)
    {
        currentLine = nthLine(s, i);
        result.push_back(currentLine);
    }
    return result;
}

vector<string> utils::removeEmptyStrings(const vector<string> v)
{
    int size = v.size();
    vector<string> result;
    for (int i = 0; i < size; i++)
    {
        if (v[i] != "")
        {
            result.push_back(v[i]);
        }
    }
    return result;
}

vector<string> utils::concatStringVectors(const vector<string> v1, const vector<string> v2)
{
    vector<string> result = v1;
    result.insert(result.end(), v2.begin(), v2.end());
    return result;
}

vector<string> utils::reverseStringVector(const vector<string> v)
{
    vector<string> result;
    int size = v.size();
    for (int i = 1; i <= size; i++)
    {
        result.push_back(v[size - i]);
    }
    return result;
}