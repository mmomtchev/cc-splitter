#include "clang/AST/AST.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/PrettyPrinter.h"
#include "clang/AST/RecordLayout.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/Path.h"
#include "llvm/Support/Timer.h"
#include "llvm/Support/raw_ostream.h"

using namespace clang;

class ASTSplitter : public ASTConsumer, public RecursiveASTVisitor<ASTSplitter> {
  typedef RecursiveASTVisitor<ASTSplitter> base;

public:
  ASTSplitter(clang::CompilerInstance &);

  void HandleTranslationUnit(ASTContext &Context) override;
  bool TraverseDecl(Decl *D);

private:
  clang::CompilerInstance &CI;
  clang::SourceManager &SM;

  std::string getName(Decl *D);
  void print(Decl *D);
};
