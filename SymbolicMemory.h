#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace cereal {
class JSONOutputArchive;
}

namespace mysym {

struct Expressions;
struct Function;

class SymbolicMemory {
public:
  SymbolicMemory();
  explicit SymbolicMemory(std::shared_ptr<const Function> function);
  ~SymbolicMemory() = default; 

  void save(cereal::JSONOutputArchive &out) const;

  
  std::shared_ptr<Expressions> get(const std::string &identifier) const;
  
  void set(const std::string &identifier, std::shared_ptr<Expressions> value);

private:
  std::shared_ptr<const Function> function;
  std::vector<std::shared_ptr<Expressions>> data;
  std::unordered_map<std::string, size_t> parameters;
};

} 
