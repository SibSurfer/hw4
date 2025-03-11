#include "AST.h"
#include "ASTBuilder.h"
#include "LangLexer.h"
#include "LangParser.h"
#include "Interpreter.h"
#include "cereal/archives/json.hpp"
#include "cereal/types/vector.hpp"
#include "gtest/gtest.h"

using namespace antlr4;
using namespace mysym;

namespace rapidjson {

void PrintTo(const Document &doc, std::ostream *os) {
  OStreamWrapper osWrapper(*os);
  PrettyWriter<OStreamWrapper> writer(osWrapper);
  doc.Accept(writer);
}

} 

namespace {

class SymInterpreterTest : public ::testing::Test {
protected:
  SymInterpreterTest() : lexer(&inputStream), tokens(&lexer), parser(&tokens) {}

  void setSource(std::string sourceCode) {
    inputStream.load(std::move(sourceCode));
  }

  void act() {
    tree::ParseTree *tree = parser.function();
    ASSERT_EQ(0ULL, lexer.getNumberOfSyntaxErrors());
    ASSERT_EQ(0ULL, parser.getNumberOfSyntaxErrors());
    tree::ParseTreeWalker::DEFAULT.walk(builder.get(), tree);
    ast = builder->getFunction();
    executionResults = execute(ast);
  }

  rapidjson::Document getResults() {
    std::stringstream stream;
    {
      cereal::JSONOutputArchive archive(stream);
      cereal::save(archive, executionResults);
    }
    rapidjson::Document document;
    document.Parse(stream.str().c_str());
    return document;
  }

  ANTLRInputStream inputStream;
  LangLexer lexer;
  CommonTokenStream tokens;
  LangParser parser;
  std::shared_ptr<IASTBuilder> builder = IASTBuilder::create();
  std::shared_ptr<Function> ast;
  std::vector<SymbolicExecutionResult> executionResults;
};

} 

TEST_F(SymInterpreterTest, IntConst) {
  setSource(R"(
f(): int {
  return 1
}
)");
  act();
  rapidjson::Document results = getResults();
  rapidjson::Document expected;
  expected.Parse(R"json(
[
  {
    "values": [],
    "pc": "true",
    "result": "1"
  }
]
)json");
  EXPECT_EQ(expected, results);
}

TEST_F(SymInterpreterTest, BoolConst) {
  setSource(R"(
f(): bool {
  return false
}
)");
  act();
  rapidjson::Document results = getResults();
  rapidjson::Document expected;
  expected.Parse(R"json(
[
  {
    "values": [],
    "pc": "true",
    "result": "false"
  }
]
)json");
  EXPECT_EQ(expected, results);
}

TEST_F(SymInterpreterTest, IntSymbol) {
  setSource(R"(
f(int x): int {
  return x
}
)");
  act();
  rapidjson::Document results = getResults();
  rapidjson::Document expected;
  expected.Parse(R"json(
[
  {
    "values": [
      {
        "name": "x",
        "value": "x"
      }
    ],
    "pc": "true",
    "result": "x"
  }
]
)json");
  EXPECT_EQ(expected, results);
}

TEST_F(SymInterpreterTest, IntAssignment) {
  setSource(R"(
f(int a, int b): int {
  a = b
  return a
}
)");
  act();
  rapidjson::Document results = getResults();
  rapidjson::Document expected;
  expected.Parse(R"json(
[
  {
    "values": [
      {
        "name": "a",
        "value": "b"
      },
      {
        "name": "b",
        "value": "b"
      }
    ],
    "pc": "true",
    "result": "b"
  }
]
)json");
  EXPECT_EQ(expected, results);
}

TEST_F(SymInterpreterTest, AssignmentToCmp) {
  setSource(R"(
f(int a, int b, bool c): bool {
  c = a < b
  return !c
}
)");
  act();
  rapidjson::Document results = getResults();
  rapidjson::Document expected;
  expected.Parse(R"json(
[
  {
    "values": [
      {
        "name": "a",
        "value": "a"
      },
      {
        "name": "b",
        "value": "b"
      },
      {
        "name": "c",
        "value": "(a < b)"
      }
    ],
    "pc": "true",
    "result": "!(a < b)"
  }
]
)json");
  EXPECT_EQ(expected, results);
}

TEST_F(SymInterpreterTest, AssignmentSwap) {
  setSource(R"(
f(int a, int b, int c): int {
  c = a
  a = b
  b = c
  c = 0
  return 1
}
)");
  act();
  rapidjson::Document results = getResults();
  rapidjson::Document expected;
  expected.Parse(R"json(
[
  {
    "values": [
      {
        "name": "a",
        "value": "b"
      },
      {
        "name": "b",
        "value": "a"
      },
      {
        "name": "c",
        "value": "0"
      }
    ],
    "pc": "true",
    "result": "1"
  }
]
)json");
  EXPECT_EQ(expected, results);
}

TEST_F(SymInterpreterTest, IfSelectOneOfTwo) {
  setSource(R"(
f(bool cond, int a, int b, int temp): int {
  if (cond) {
    temp = a
  } else {
    temp = b
  }
  return temp
}
)");
  act();
  rapidjson::Document results = getResults();
  rapidjson::Document expected;
  expected.Parse(R"json(
[
  {
    "values": [
      {
        "name": "cond",
        "value": "cond"
      },
      {
        "name": "a",
        "value": "a"
      },
      {
        "name": "b",
        "value": "b"
      },
      {
        "name": "temp",
        "value": "a"
      }
    ],
    "pc": "cond",
    "result": "a"
  },
  {
    "values": [
      {
        "name": "cond",
        "value": "cond"
      },
      {
        "name": "a",
        "value": "a"
      },
      {
        "name": "b",
        "value": "b"
      },
      {
        "name": "temp",
        "value": "b"
      }
    ],
    "pc": "!cond",
    "result": "b"
  }
]
)json");
  EXPECT_EQ(expected, results);
}

TEST_F(SymInterpreterTest, SlidesExample) {
  setSource(R"(
f(int x, int y): int {
  if (x < 0) {
    y = x + y + x - 42
    x = y + x
  } else {
    y = y - x - x + 42
    x = y - x
  }
  return y
}
)");
  act();
  rapidjson::Document results = getResults();
  rapidjson::Document expected;
  expected.Parse(R"json(
[
  {
    "values": [
      {
        "name": "x",
        "value": "((x + (y + (x - 42))) + x)"
      },
      {
        "name": "y",
        "value": "(x + (y + (x - 42)))"
      }
    ],
    "pc": "(x < 0)",
    "result": "(x + (y + (x - 42)))"
  },
  {
    "values": [
      {
        "name": "x",
        "value": "((y - (x - (x + 42))) - x)"
      },
      {
        "name": "y",
        "value": "(y - (x - (x + 42)))"
      }
    ],
    "pc": "!(x < 0)",
    "result": "(y - (x - (x + 42)))"
  }
]
)json");
  EXPECT_EQ(expected, results);
}