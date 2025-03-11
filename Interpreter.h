#pragma once

#include "Expressions.h"
#include "SymbolicMemory.h"
#include <vector>

namespace cereal {
class JSONOutputArchive;
}

namespace mysym {

struct SymbolicExecutionResult {
  SymbolicMemory memory;
  std::shared_ptr<BoolExpression> pc;
  std::shared_ptr<Expressions> result;

  void save(cereal::JSONOutputArchive &out) const;
};

std::vector<SymbolicExecutionResult> execute(std::shared_ptr<Function> function);

}
