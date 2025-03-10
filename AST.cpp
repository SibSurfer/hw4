#include "AST.h"
#include "fmt/format.h"
#include <cassert>

using namespace mysym;

std::string mysym::toString(Type type) {
  switch (type) {
  case T_BOOL:
    return "bool";
  case T_INT:
    return "int";
  }
  assert(false && "invalid type");
}

std::string Parameter::toString() const {
  return fmt::format("{type} {name}", fmt::arg("type", mysym::toString(type)),
                     fmt::arg("name", name));
}

std::string mysym::toString(BinOpKind kind) {
  switch (kind) {
  case BO_Add:
    return "+";
  case BO_Sub:
    return "-";
  case BO_Lt:
    return "<";
  case BO_Gt:
    return ">";
  case BO_LAnd:
    return "&";
  case BO_LOr:
    return "|";
  }
  assert(false && "invalid binop");
}