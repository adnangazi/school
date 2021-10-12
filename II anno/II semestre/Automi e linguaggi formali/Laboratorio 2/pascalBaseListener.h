
// Generated from pascal.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "pascalListener.h"


/**
 * This class provides an empty implementation of pascalListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  pascalBaseListener : public pascalListener {
public:

  virtual void enterStart(pascalParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(pascalParser::StartContext * /*ctx*/) override { }

  virtual void enterDecl_list(pascalParser::Decl_listContext * /*ctx*/) override { }
  virtual void exitDecl_list(pascalParser::Decl_listContext * /*ctx*/) override { }

  virtual void enterDecl(pascalParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(pascalParser::DeclContext * /*ctx*/) override { }

  virtual void enterMain_code(pascalParser::Main_codeContext * /*ctx*/) override { }
  virtual void exitMain_code(pascalParser::Main_codeContext * /*ctx*/) override { }

  virtual void enterCode_block(pascalParser::Code_blockContext * /*ctx*/) override { }
  virtual void exitCode_block(pascalParser::Code_blockContext * /*ctx*/) override { }

  virtual void enterSt_list(pascalParser::St_listContext * /*ctx*/) override { }
  virtual void exitSt_list(pascalParser::St_listContext * /*ctx*/) override { }

  virtual void enterStatement(pascalParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(pascalParser::StatementContext * /*ctx*/) override { }

  virtual void enterAssign(pascalParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(pascalParser::AssignContext * /*ctx*/) override { }

  virtual void enterOut(pascalParser::OutContext * /*ctx*/) override { }
  virtual void exitOut(pascalParser::OutContext * /*ctx*/) override { }

  virtual void enterBranch(pascalParser::BranchContext * /*ctx*/) override { }
  virtual void exitBranch(pascalParser::BranchContext * /*ctx*/) override { }

  virtual void enterExpr(pascalParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(pascalParser::ExprContext * /*ctx*/) override { }

  virtual void enterRelation(pascalParser::RelationContext * /*ctx*/) override { }
  virtual void exitRelation(pascalParser::RelationContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

