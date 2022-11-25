#include "FileHelpers.h"
#include <stdlib.h>

vector<string> GetLinesFromFile(const string &path, bool ignore_comments)
{
    fstream file;
    vector<string> ret = vector<string>();
    file.open(path.c_str(), ios::in);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            bool isComment = false;

            if (ignore_comments && line.size() > 1)
            {
                string lineStart = line.substr(0, 2);
                if (lineStart == "//")
                    isComment = true;
            }
            if (!isComment)
                ret.push_back(line);
        }
    }
    file.close();
    return ret;
}

string ExtractBetween(const string &target, const string &start, const string &end)
{
    string ret = "";
    size_t p_start, p_end;
    p_start = target.find(start);
    if (p_start != string::npos)
    {
        if (end == "\n")
        {
            p_end = target.size();
        }
        else
            p_end = target.find(end, p_start);

        if (p_end != string::npos)
            ret = target.substr(p_start + start.size(), p_end - p_start - start.size());
    }
    return ret;
}

string ExtractBetween(const string &target, const size_t &p_start, const string &end)
{
    string ret = "";
    size_t p_end;
    if (p_start != string::npos)
    {
        if (end == "\n")
        {
            p_end = target.size();
        }
        else
            p_end = target.find(end, p_start);

        if (p_end != string::npos)
            ret = target.substr(p_start, p_end - p_start);
    }
    return ret;
}

vector<string> TokenizeBetween(const string &input, const string &tokens)
{
    vector<string> ret = vector<string>();
    auto pos = input.find_first_of(tokens);
    if (pos != string::npos)
    {
        while (pos != string::npos && pos < input.size())
        {
            auto pos_n = input.find_first_of(tokens, pos + 1);
            if (pos_n != string::npos)
                ret.push_back(input.substr(pos + 1, pos_n - pos - 1));
            pos = pos_n;
        }
    }
    return ret;
}

void warn(const string &warning)
{
    ofstream warningfile;
    warningfile.open("warnings.txt", ios::app);
    warningfile << warning << '\n';
    warningfile.close();
}

bool toInt(const string &str, int &out)
{
    bool success = true;
    int val;

    try
    {
        val = stoi(str);
    }
    catch (std::exception *e)
    {
        warn("Caught Failure in toInt while converting  " + str);
        success = false;
    }
    if (success)
    {
        out = val;
    }
    return success;
}

void ClearPreviousWarnings()
{
    ofstream warningfile;
    warningfile.open("warnings.txt", ios::in | ios::out);
    warningfile << "Meengi encountered following warning: " << '\n';
    warningfile.close();
}
void ClearPreviousFiles()
{
    system("rm -r site/*html");
    ClearPreviousWarnings();
}

void ReadTemplateTitle(const string &iLine, string &templateName, vector<string> &argsList)
{
    templateName = ExtractBetween(iLine, "$", "(");
    argsList = TokenizeBetween(iLine, ",()");
}
void ReadTemplateText(const string &input, const vector<string> &argsList, vector<int> &argsOrder, vector<string> &salamiSlices)
{
    auto pos = input.find("$$");
    size_t pos_last = 0;
    while (pos != string::npos)
    {
        auto pos_arg_end = input.find("$$", pos + 1);
        if (pos_arg_end != string::npos)
        {
            string arg = input.substr(pos + 2, pos_arg_end - pos - 2);

            for (size_t i = 0; i < argsList.size(); i++)
            {
                if (arg == argsList[i])
                {
                    argsOrder.push_back(i);
                    salamiSlices.push_back(ExtractBetween(input, pos_last, "$$"));
                    pos_last = pos_arg_end + 2;
                    break;
                }
            }
            pos = input.find("$$", pos_arg_end + 1);
        }
        else
            pos = input.find("$$", pos + 1);
    }
    salamiSlices.push_back(input.substr(pos_last));
}

// Need this to find out how many arguments do we have in a template
size_t Max(const vector<int> &vec)
{
    int ret = -1;

    for (auto val : vec)
    {
        if (val > ret)
            ret = val;
    }
    return ret + 1;
}