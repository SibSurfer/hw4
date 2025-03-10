#pragma once

#include "LangBaseListener.h"

namespace mysym {

struct Function;

class IASTBuilder : public LangBaseListener {
public:
  static std::shared_ptr<IASTBuilder> create();

  virtual std::shared_ptr<Function> getFunction() = 0;

  virtual bool hasErrors() const = 0;
};

} // namespace mysym