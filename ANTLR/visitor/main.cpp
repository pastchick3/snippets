#include <iostream>
#include <string>
#include <unordered_map>

#include "ExprBaseVisitor.h"
#include "ExprLexer.h"
#include "ExprParser.h"
#include "antlr4-runtime.h"

class EvalVisitor : public ExprBaseVisitor {
   public:
    antlrcpp::Any visitAssign(ExprParser::AssignContext *ctx) override {
        std::string id = ctx->ID()->getText();
        antlrcpp::Any box = visit(ctx->expr());
        memory.insert({id, box.as<int>()});
        return box;
    }

    antlrcpp::Any visitPrintExpr(ExprParser::PrintExprContext *ctx) override {
        antlrcpp::Any box = visit(ctx->expr());
        std::cout << box.as<int>() << std::endl;
        return box;
    }

    antlrcpp::Any visitInt(ExprParser::IntContext *ctx) override {
        return std::stoi(ctx->INT()->getText());
    }

    antlrcpp::Any visitId(ExprParser::IdContext *ctx) override {
        std::string id = ctx->ID()->getText();
        if (auto it = memory.find(id); it != memory.end()) {
            return it->second;
        } else {
            return {};
        }
    }

    antlrcpp::Any visitMulDiv(ExprParser::MulDivContext *ctx) override {
        int left = visit(ctx->expr(0)).as<int>();
        int right = visit(ctx->expr(1)).as<int>();
        if (ctx->op->getType() == ExprParser::MUL) {
            return left * right;
        } else {
            return left / right;
        }
    }

    antlrcpp::Any visitAddSub(ExprParser::AddSubContext *ctx) override {
        int left = visit(ctx->expr(0)).as<int>();
        int right = visit(ctx->expr(1)).as<int>();
        if (ctx->op->getType() == ExprParser::ADD) {
            return left + right;
        } else {
            return left - right;
        }
    }

    antlrcpp::Any visitParens(ExprParser::ParensContext *ctx) override {
        return visit(ctx->expr());
    }

   private:
    std::unordered_map<std::string, int> memory;
};

int main(int argc, const char *argv[]) {
    antlr4::ANTLRInputStream input(
        "1\n"        // 1
        "a=2\n"      // null
        "a\n"        // 2
        "2*3\n"      // 6
        "4/2\n"      // 2
        "2+3\n"      // 5
        "4-2\n"      // 2
        "4-2\n"      // 2
        "2*(3+4)\n"  // 14
    );

    ExprLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    ExprParser parser(&tokens);
    antlr4::tree::ParseTree *tree = parser.prog();

    EvalVisitor *eval = new EvalVisitor();
    eval->visit(tree);
    delete eval;

    return 0;
}
