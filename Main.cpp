#include "LangLexer.h"
#include "LangParser.h"
#include <iostream>
#include <filesystem>
#include "antlr4-runtime.h"

using namespace antlr4;

int main(int argc, const char **argv) {
    if (argc <= 1) {
        std::cerr << "please provide one argument: path to the source file\n";
        exit(1);
    }
    std::filesystem::path path(argv[1]);
    {
        std::ifstream istream(path);
        ANTLRInputStream input(istream);
        LangLexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        LangParser parser(&tokens);

        tree::ParseTree *tree = parser.function();

        if (lexer.getNumberOfSyntaxErrors() > 0 || parser.getNumberOfSyntaxErrors() > 0) {
            std::cerr << "fatal: encountered syntax errors\n";
            exit(1);
        }
        std::cout << tree->toStringTree(true) << std::endl;
    }
}
