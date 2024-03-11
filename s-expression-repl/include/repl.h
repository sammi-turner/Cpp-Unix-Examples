#ifndef REPL_H
#define REPL_H

namespace repl
{
    struct token 
    {
        string value{}; 
        string type{};
    };
    string padParens(const string arg);
    bool isFunction(const string arg);
    vector<token> tokenise(const string arg);
    string parse(const vector<token> arg);
    string evaluate(const vector<token> arg);
}

#endif