
// Generated from pascal.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "pascalParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by pascalParser.
 */
class  pascalListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStart(pascalParser::StartContext *ctx) = 0;
  virtual void exitStart(pascalParser::StartContext *ctx) = 0;

  virtual void enterDecl_list(pascalParser::Decl_listContext *ctx) = 0;
  virtual void exitDecl_list(pascalParser::Decl_listContext *ctx) = 0;

  virtual void enterDecl(pascalParser::DeclContext *ctx) = 0;
  virtual void exitDecl(pascalParser::DeclContext *ctx) = 0;

  virtual void enterMain_code(pascalParser::Main_codeContext *ctx) = 0;
  virtual void exitMain_code(pascalParser::Main_codeContext *ctx) = 0;

  virtual void enterCode_block(pascalParser::Code_blockContext *ctx) = 0;
  virtual void exitCode_block(pascalParser::Code_blockContext *ctx) = 0;

  virtual void enterSt_list(pascalParser::St_listContext *ctx) = 0;
  virtual void exitSt_list(pascalParser::St_listContext *ctx) = 0;

  virtual void enterStatement(pascalParser::StatementContext *ctx) = 0;
  virtual void exitStatement(pascalParser::StatementContext *ctx) = 0;

  virtual void enterAssign(pascalParser::AssignContext *ctx) = 0;
  virtual void exitAssign(pascalParser::AssignContext *ctx) = 0;

  virtual void enterOut(pascalParser::OutContext *ctx) = 0;
  virtual void exitOut(pascalParser::OutContext *ctx) = 0;

  virtual void enterBranch(pascalParser::BranchContext *ctx) = 0;
  virtual void exitBranch(pascalParser::BranchContext *ctx) = 0;

  virtual void enterExpr(pascalParser::ExprContext *ctx) = 0;
  virtual void exitExpr(pascalParser::ExprContext *ctx) = 0;

  virtual void enterRelation(pascalParser::RelationContext *ctx) = 0;
  virtual void exitRelation(pascalParser::RelationContext *ctx) = 0;


};

