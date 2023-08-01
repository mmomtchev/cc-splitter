#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/CommandLine.h"
#include "ast.h"

using namespace clang::tooling;
using namespace llvm;

static cl::OptionCategory MyToolCategory("cc-splitter");
static cl::extrahelp CommonHelp(CommonOptionsParser::HelpMessage);
static cl::extrahelp MoreHelp("\ncc-splitter options\n");

class ASTSplitAction : public clang::ASTFrontendAction {
protected:
  std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(clang::CompilerInstance &CI, StringRef InFile) override;
};

std::unique_ptr<clang::ASTConsumer> CreateSplitter(clang::CompilerInstance &CI) {
  return std::make_unique<ASTSplitter>(CI);
}

std::unique_ptr<clang::ASTConsumer> ASTSplitAction::CreateASTConsumer(clang::CompilerInstance &CI, StringRef InFile) {
  return CreateSplitter(CI);
}

int main(int argc, const char **argv) {
  CommonOptionsParser OptionsParser = std::move(*CommonOptionsParser::create(argc, argv, MyToolCategory));
  ClangTool Tool(OptionsParser.getCompilations(), OptionsParser.getSourcePathList());
  return Tool.run(newFrontendActionFactory<ASTSplitAction>().get());
}
