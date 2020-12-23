#include <iostream>

#include "ArrayInitBaseListener.h"
#include "ArrayInitLexer.h"
#include "ArrayInitParser.h"
#include "antlr4-runtime.h"

class EchoListener : public ArrayInitBaseListener {
   public:
    void enterValue(ArrayInitParser::ValueContext *ctx) override {
        std::cout << "enter: " << ctx->getText() << std::endl;
    }
};

int main(int argc, const char *argv[]) {
    // std::ifstream stream;
    // stream.open(argv[1]);
    // antlr4::ANTLRInputStream input(stream);
    antlr4::ANTLRInputStream input("{ 1 }");

    ArrayInitLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    ArrayInitParser parser(&tokens);
    antlr4::tree::ParseTree *tree = parser.init();

    // EchoListener listener;
    // antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
    std::cout << tree->toStringTree(&parser) << std::endl;

    return 0;
}
