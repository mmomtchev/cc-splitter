#include "ast.h"
#include <iostream>

using namespace std;

ASTSplitter::ASTSplitter(clang::CompilerInstance &_CI): CI(_CI), SM(_CI.getSourceManager()) {}

void ASTSplitter::HandleTranslationUnit(ASTContext &Context) {
  TranslationUnitDecl *D = Context.getTranslationUnitDecl();
  TraverseDecl(D);
}

bool ASTSplitter::TraverseDecl(Decl *D) {
  if (D) {
    print(D);
  }
  return base::TraverseDecl(D);
}

std::string ASTSplitter::getName(Decl *D) {
  if (isa<NamedDecl>(D))
    return cast<NamedDecl>(D)->getQualifiedNameAsString();
  return "<anon>";
}

void ASTSplitter::print(Decl *D) {
  if (!D->isDefinedOutsideFunctionOrMethod())
    return;

  auto begin = D->getBeginLoc();
  auto file = SM.getFileEntryForID(SM.getFileID(begin));
  if (!file || !SM.isMainFile(*file)) {
    return;
  }

  cout << getName(D) << ": " << D->getKind() << " @ " << D->getBeginLoc().printToString(SM);
  cout << " body=" << D->hasBody();
  cout << endl;
}
