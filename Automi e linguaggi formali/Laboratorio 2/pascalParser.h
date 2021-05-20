
// Generated from pascal.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  pascalParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, EQ = 26, 
    LT = 27, LEQ = 28, GT = 29, GEQ = 30, NEQ = 31, OR = 32, AND = 33, NOT = 34, 
    ID = 35, NUMBER = 36, R_COMMENT = 37, C_COMMENT = 38, LINE_COMMENT = 39, 
    WS = 40, ErrorChar = 41
  };

  enum {
    RuleStart = 0, RuleDecl_list = 1, RuleDecl = 2, RuleConcat_decl = 3, 
    RuleMain_code = 4, RuleCode_block = 5, RuleSt_list = 6, RuleRepeat_block = 7, 
    RuleStatement = 8, RuleAssign = 9, RuleOut = 10, RuleIn = 11, RuleBranch = 12, 
    RuleContent_out = 13, RuleString = 14, RuleExpr = 15, RuleArit = 16, 
    RuleRelation_block = 17, RuleRelation = 18
  };

  pascalParser(antlr4::TokenStream *input);
  ~pascalParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class StartContext;
  class Decl_listContext;
  class DeclContext;
  class Concat_declContext;
  class Main_codeContext;
  class Code_blockContext;
  class St_listContext;
  class Repeat_blockContext;
  class StatementContext;
  class AssignContext;
  class OutContext;
  class InContext;
  class BranchContext;
  class Content_outContext;
  class StringContext;
  class ExprContext;
  class AritContext;
  class Relation_blockContext;
  class RelationContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    Decl_listContext *decl_list();
    Main_codeContext *main_code();
    antlr4::tree::TerminalNode *EOF();

   
  };

  StartContext* start();

  class  Decl_listContext : public antlr4::ParserRuleContext {
  public:
    Decl_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclContext *decl();
    Decl_listContext *decl_list();

   
  };

  Decl_listContext* decl_list();

  class  DeclContext : public antlr4::ParserRuleContext {
  public:
    DeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    Concat_declContext *concat_decl();

   
  };

  DeclContext* decl();

  class  Concat_declContext : public antlr4::ParserRuleContext {
  public:
    Concat_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    Concat_declContext *concat_decl();

   
  };

  Concat_declContext* concat_decl();

  class  Main_codeContext : public antlr4::ParserRuleContext {
  public:
    Main_codeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    St_listContext *st_list();

   
  };

  Main_codeContext* main_code();

  class  Code_blockContext : public antlr4::ParserRuleContext {
  public:
    Code_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    St_listContext *st_list();

   
  };

  Code_blockContext* code_block();

  class  St_listContext : public antlr4::ParserRuleContext {
  public:
    St_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    St_listContext *st_list();

   
  };

  St_listContext* st_list();

  class  Repeat_blockContext : public antlr4::ParserRuleContext {
  public:
    Repeat_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    St_listContext *st_list();
    Relation_blockContext *relation_block();

   
  };

  Repeat_blockContext* repeat_block();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignContext *assign();
    BranchContext *branch();
    OutContext *out();
    InContext *in();
    Repeat_blockContext *repeat_block();

   
  };

  StatementContext* statement();

  class  AssignContext : public antlr4::ParserRuleContext {
  public:
    AssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    AritContext *arit();

   
  };

  AssignContext* assign();

  class  OutContext : public antlr4::ParserRuleContext {
  public:
    OutContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Content_outContext *content_out();

   
  };

  OutContext* out();

  class  InContext : public antlr4::ParserRuleContext {
  public:
    InContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

   
  };

  InContext* in();

  class  BranchContext : public antlr4::ParserRuleContext {
  public:
    BranchContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Relation_blockContext *relation_block();
    std::vector<Code_blockContext *> code_block();
    Code_blockContext* code_block(size_t i);

   
  };

  BranchContext* branch();

  class  Content_outContext : public antlr4::ParserRuleContext {
  public:
    Content_outContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StringContext *string();
    ExprContext *expr();

   
  };

  Content_outContext* content_out();

  class  StringContext : public antlr4::ParserRuleContext {
  public:
    StringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  StringContext* string();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *ID();

   
  };

  ExprContext* expr();

  class  AritContext : public antlr4::ParserRuleContext {
  public:
    AritContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    AritContext *arit();

   
  };

  AritContext* arit();

  class  Relation_blockContext : public antlr4::ParserRuleContext {
  public:
    Relation_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOT();
    std::vector<Relation_blockContext *> relation_block();
    Relation_blockContext* relation_block(size_t i);
    RelationContext *relation();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *AND();

   
  };

  Relation_blockContext* relation_block();
  Relation_blockContext* relation_block(int precedence);
  class  RelationContext : public antlr4::ParserRuleContext {
  public:
    RelationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *LEQ();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NEQ();
    antlr4::tree::TerminalNode *GEQ();
    antlr4::tree::TerminalNode *GT();

   
  };

  RelationContext* relation();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool relation_blockSempred(Relation_blockContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

