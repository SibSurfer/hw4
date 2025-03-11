#include "ASTBuilder.h"
#include "LangLexer.h"
#include "LangParser.h"
#include "Interpreter.h"
#include "cereal/archives/json.hpp"
#include "cereal/types/vector.hpp"
#include <filesystem>
#include <iostream>

using namespace antlr4;
using namespace mysym;

int main(int argc, const char **argv) {
  if (argc <= 1) {
    std::cerr << "print path to .txt\n";
    std::exit(1);
  }
  std::filesystem::path path(argv[1]);
  std::ifstream istream(path);
  ANTLRInputStream input(istream);
  LangLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  LangParser parser(&tokens);

  tree::ParseTree *tree = parser.function();
  if (lexer.getNumberOfSyntaxErrors() > 0 ||
      parser.getNumberOfSyntaxErrors() > 0) {
    std::cerr << "syntax errors\n";
    std::exit(1);
  }

  auto builder = IASTBuilder::create();
  tree::ParseTreeWalker::DEFAULT.walk(builder.get(), tree);
  if (builder->hasErrors()) {
    std::cerr << "semantic errors\n";
    std::exit(1);
  }

  auto function = builder->getFunction();
  auto executionResults = execute(function);
  {
    cereal::JSONOutputArchive archive(std::cout);
    cereal::save(archive, executionResults);
  }
  std::cout << std::endl;
}