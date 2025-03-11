#include "Expressions.h"
#include <sstream>

using namespace mysym;

std::string Expressions::save_minimal(const cereal::JSONOutputArchive &) const {
    return render(*this);
}

std::shared_ptr<BoolExpression> mysym::conjunction(
    const std::vector<std::shared_ptr<BoolExpression>> &expressions) {
    if (expressions.empty())
        return std::make_shared<BoolConst>(true);
    std::shared_ptr<BoolExpression> current = expressions.front();
    for (size_t index = 1; index < expressions.size(); ++index)
        current = std::make_shared<BoolAnd>(current, expressions[index]);
    return current;
}

namespace {

class RecursiveRenderer : public IExpressionsVisitor {
public:
    void render(const Expressions &expr) {
        expr.accept(*this);
    }

    std::string getString() const { return oss.str(); }

    void visitBoolConst(const BoolConst &expr) override { oss << (expr.value ? "true" : "false"); }
    void visitBoolSymbol(const BoolSymbol &expr) override { oss << expr.identifier; }
    void visitBoolNeg(const BoolNeg &expr) override { oss << '!'; render(*expr.subExpr); }
    void visitBoolAnd(const BoolAnd &expr) override { oss << '('; render(*expr.lhs); oss << " & "; render(*expr.rhs); oss << ')'; }
    void visitBoolOr(const BoolOr &expr) override { oss << '('; render(*expr.lhs); oss << " | "; render(*expr.rhs); oss << ')'; }

    void visitIntLess(const IntLess &expr) override { oss << '('; render(*expr.lhs); oss << " < "; render(*expr.rhs); oss << ')'; }
    void visitIntGreater(const IntGreater &expr) override { oss << '('; render(*expr.lhs); oss << " > "; render(*expr.rhs); oss << ')'; }
    void visitIntConst(const IntConst &expr) override { oss << expr.value; }
    void visitIntSymbol(const IntSymbol &expr) override { oss << expr.identifier; }
    void visitIntAdd(const IntAdd &expr) override { oss << '('; render(*expr.lhs); oss << " + "; render(*expr.rhs); oss << ')'; }
    void visitIntSub(const IntSub &expr) override { oss << '('; render(*expr.lhs); oss << " - "; render(*expr.rhs); oss << ')'; }

private:
    std::ostringstream oss;
};

} 

std::string mysym::render(const Expressions &expr) {
    RecursiveRenderer renderer;
    renderer.render(expr);
    return renderer.getString();
}
