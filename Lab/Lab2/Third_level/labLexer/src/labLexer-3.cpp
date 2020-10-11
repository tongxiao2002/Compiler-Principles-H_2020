#include <iostream>

#include "antlr4-runtime.h"
#include "relop.h"
#define MAX_LENGTH 100

using namespace antlr4;

int main(int argc, const char* argv[])
{
    char Input[MAX_LENGTH];
    fgets(Input, MAX_LENGTH, stdin);
    ANTLRInputStream input(Input);
    relop lexer(&input);
    CommonTokenStream tokens(&lexer);

    tokens.fill();
//    for (auto token : tokens.getTokens()) {
//        std::cout << token->toString() << std::endl;
//    }

    return 0;
}
