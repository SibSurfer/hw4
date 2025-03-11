#include "SymbolicMemory.h"
#include "AST.h"
#include "Expressions.h"
#include "cereal/archives/json.hpp"
#include "cereal/cereal.hpp"

using namespace mysym;

SymbolicMemory::SymbolicMemory() = default;

SymbolicMemory::SymbolicMemory(std::shared_ptr<const Function> function)
    : function(std::move(function)) {
  data.reserve(this->function->parameters.size());
  for (const Parameter &parameter : this->function->parameters) {
    size_t index = data.size();
    parameters.try_emplace(parameter.name, index);   
    switch (parameter.type) {
    case T_BOOL:
      data.emplace_back(std::make_shared<BoolSymbol>(parameter.name)); 
      break;
    case T_INT:
      data.emplace_back(std::make_shared<IntSymbol>(parameter.name));
      break;
    }
  }
}

void SymbolicMemory::save(cereal::JSONOutputArchive &out) const {
  out(cereal::make_size_tag(data.size()));
  for (size_t index = 0; index < data.size(); ++index) {
    out.startNode();
    out(cereal::make_nvp("name", function->parameters[index].name),
        cereal::make_nvp("value", *data[index]));
    out.finishNode();
  }
}

std::shared_ptr<Expressions> SymbolicMemory::get(const std::string &identifier) const {
  auto it = parameters.find(identifier);
  if (it == parameters.end()) {
    throw std::runtime_error("memory access fault: " + identifier);
  }
  return data[it->second];
}

void SymbolicMemory::set(const std::string &identifier, std::shared_ptr<Expressions> value) {
  auto it = parameters.find(identifier);
  if (it == parameters.end()) {
    throw std::runtime_error("memory assign fault: " + identifier);
  }
  data[it->second] = std::move(value);
}
