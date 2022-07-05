
// Generated from pascal.g4 by ANTLR 4.7.2



#include "pascalParser.h"


using namespace antlrcpp;
using namespace antlr4;

pascalParser::pascalParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

pascalParser::~pascalParser() {
  delete _interpreter;
}

std::string pascalParser::getGrammarFileName() const {
  return "pascal.g4";
}

const std::vector<std::string>& pascalParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& pascalParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StartContext ------------------------------------------------------------------

pascalParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::StartContext::ID() {
  return getToken(pascalParser::ID, 0);
}

pascalParser::Decl_listContext* pascalParser::StartContext::decl_list() {
  return getRuleContext<pascalParser::Decl_listContext>(0);
}

pascalParser::Main_codeContext* pascalParser::StartContext::main_code() {
  return getRuleContext<pascalParser::Main_codeContext>(0);
}

tree::TerminalNode* pascalParser::StartContext::EOF() {
  return getToken(pascalParser::EOF, 0);
}


size_t pascalParser::StartContext::getRuleIndex() const {
  return pascalParser::RuleStart;
}


pascalParser::StartContext* pascalParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, pascalParser::RuleStart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(38);
    match(pascalParser::T__0);
    setState(39);
    match(pascalParser::ID);
    setState(40);
    match(pascalParser::T__1);
    setState(41);
    match(pascalParser::T__2);
    setState(42);
    decl_list();
    setState(43);
    main_code();
    setState(44);
    match(pascalParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Decl_listContext ------------------------------------------------------------------

pascalParser::Decl_listContext::Decl_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::DeclContext* pascalParser::Decl_listContext::decl() {
  return getRuleContext<pascalParser::DeclContext>(0);
}

pascalParser::Decl_listContext* pascalParser::Decl_listContext::decl_list() {
  return getRuleContext<pascalParser::Decl_listContext>(0);
}


size_t pascalParser::Decl_listContext::getRuleIndex() const {
  return pascalParser::RuleDecl_list;
}


pascalParser::Decl_listContext* pascalParser::decl_list() {
  Decl_listContext *_localctx = _tracker.createInstance<Decl_listContext>(_ctx, getState());
  enterRule(_localctx, 2, pascalParser::RuleDecl_list);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(50);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(46);
      decl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(47);
      decl();
      setState(48);
      decl_list();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

pascalParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::DeclContext::ID() {
  return getToken(pascalParser::ID, 0);
}

pascalParser::Concat_declContext* pascalParser::DeclContext::concat_decl() {
  return getRuleContext<pascalParser::Concat_declContext>(0);
}


size_t pascalParser::DeclContext::getRuleIndex() const {
  return pascalParser::RuleDecl;
}


pascalParser::DeclContext* pascalParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 4, pascalParser::RuleDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    match(pascalParser::ID);
    setState(53);
    concat_decl();
    setState(54);
    match(pascalParser::T__3);
    setState(55);
    match(pascalParser::T__4);
    setState(56);
    match(pascalParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Concat_declContext ------------------------------------------------------------------

pascalParser::Concat_declContext::Concat_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::Concat_declContext::ID() {
  return getToken(pascalParser::ID, 0);
}

pascalParser::Concat_declContext* pascalParser::Concat_declContext::concat_decl() {
  return getRuleContext<pascalParser::Concat_declContext>(0);
}


size_t pascalParser::Concat_declContext::getRuleIndex() const {
  return pascalParser::RuleConcat_decl;
}


pascalParser::Concat_declContext* pascalParser::concat_decl() {
  Concat_declContext *_localctx = _tracker.createInstance<Concat_declContext>(_ctx, getState());
  enterRule(_localctx, 6, pascalParser::RuleConcat_decl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(62);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case pascalParser::T__5: {
        enterOuterAlt(_localctx, 1);
        setState(58);
        match(pascalParser::T__5);
        setState(59);
        match(pascalParser::ID);
        setState(60);
        concat_decl();
        break;
      }

      case pascalParser::T__3: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Main_codeContext ------------------------------------------------------------------

pascalParser::Main_codeContext::Main_codeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::St_listContext* pascalParser::Main_codeContext::st_list() {
  return getRuleContext<pascalParser::St_listContext>(0);
}


size_t pascalParser::Main_codeContext::getRuleIndex() const {
  return pascalParser::RuleMain_code;
}


pascalParser::Main_codeContext* pascalParser::main_code() {
  Main_codeContext *_localctx = _tracker.createInstance<Main_codeContext>(_ctx, getState());
  enterRule(_localctx, 8, pascalParser::RuleMain_code);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    match(pascalParser::T__6);
    setState(65);
    st_list();
    setState(66);
    match(pascalParser::T__7);
    setState(67);
    match(pascalParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Code_blockContext ------------------------------------------------------------------

pascalParser::Code_blockContext::Code_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::StatementContext* pascalParser::Code_blockContext::statement() {
  return getRuleContext<pascalParser::StatementContext>(0);
}

pascalParser::St_listContext* pascalParser::Code_blockContext::st_list() {
  return getRuleContext<pascalParser::St_listContext>(0);
}


size_t pascalParser::Code_blockContext::getRuleIndex() const {
  return pascalParser::RuleCode_block;
}


pascalParser::Code_blockContext* pascalParser::code_block() {
  Code_blockContext *_localctx = _tracker.createInstance<Code_blockContext>(_ctx, getState());
  enterRule(_localctx, 10, pascalParser::RuleCode_block);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(74);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case pascalParser::T__9:
      case pascalParser::T__12:
      case pascalParser::T__15:
      case pascalParser::T__16:
      case pascalParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(69);
        statement();
        break;
      }

      case pascalParser::T__6: {
        enterOuterAlt(_localctx, 2);
        setState(70);
        match(pascalParser::T__6);
        setState(71);
        st_list();
        setState(72);
        match(pascalParser::T__7);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- St_listContext ------------------------------------------------------------------

pascalParser::St_listContext::St_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::StatementContext* pascalParser::St_listContext::statement() {
  return getRuleContext<pascalParser::StatementContext>(0);
}

pascalParser::St_listContext* pascalParser::St_listContext::st_list() {
  return getRuleContext<pascalParser::St_listContext>(0);
}


size_t pascalParser::St_listContext::getRuleIndex() const {
  return pascalParser::RuleSt_list;
}


pascalParser::St_listContext* pascalParser::st_list() {
  St_listContext *_localctx = _tracker.createInstance<St_listContext>(_ctx, getState());
  enterRule(_localctx, 12, pascalParser::RuleSt_list);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(83);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(76);
      statement();
      setState(77);
      match(pascalParser::T__1);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(79);
      statement();
      setState(80);
      match(pascalParser::T__1);
      setState(81);
      st_list();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Repeat_blockContext ------------------------------------------------------------------

pascalParser::Repeat_blockContext::Repeat_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::St_listContext* pascalParser::Repeat_blockContext::st_list() {
  return getRuleContext<pascalParser::St_listContext>(0);
}

pascalParser::Relation_blockContext* pascalParser::Repeat_blockContext::relation_block() {
  return getRuleContext<pascalParser::Relation_blockContext>(0);
}


size_t pascalParser::Repeat_blockContext::getRuleIndex() const {
  return pascalParser::RuleRepeat_block;
}


pascalParser::Repeat_blockContext* pascalParser::repeat_block() {
  Repeat_blockContext *_localctx = _tracker.createInstance<Repeat_blockContext>(_ctx, getState());
  enterRule(_localctx, 14, pascalParser::RuleRepeat_block);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    match(pascalParser::T__9);
    setState(86);
    st_list();
    setState(87);
    match(pascalParser::T__10);
    setState(88);
    relation_block(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

pascalParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::AssignContext* pascalParser::StatementContext::assign() {
  return getRuleContext<pascalParser::AssignContext>(0);
}

pascalParser::BranchContext* pascalParser::StatementContext::branch() {
  return getRuleContext<pascalParser::BranchContext>(0);
}

pascalParser::OutContext* pascalParser::StatementContext::out() {
  return getRuleContext<pascalParser::OutContext>(0);
}

pascalParser::InContext* pascalParser::StatementContext::in() {
  return getRuleContext<pascalParser::InContext>(0);
}

pascalParser::Repeat_blockContext* pascalParser::StatementContext::repeat_block() {
  return getRuleContext<pascalParser::Repeat_blockContext>(0);
}


size_t pascalParser::StatementContext::getRuleIndex() const {
  return pascalParser::RuleStatement;
}


pascalParser::StatementContext* pascalParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 16, pascalParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(95);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case pascalParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(90);
        assign();
        break;
      }

      case pascalParser::T__16: {
        enterOuterAlt(_localctx, 2);
        setState(91);
        branch();
        break;
      }

      case pascalParser::T__12: {
        enterOuterAlt(_localctx, 3);
        setState(92);
        out();
        break;
      }

      case pascalParser::T__15: {
        enterOuterAlt(_localctx, 4);
        setState(93);
        in();
        break;
      }

      case pascalParser::T__9: {
        enterOuterAlt(_localctx, 5);
        setState(94);
        repeat_block();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignContext ------------------------------------------------------------------

pascalParser::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::AssignContext::ID() {
  return getToken(pascalParser::ID, 0);
}

pascalParser::AritContext* pascalParser::AssignContext::arit() {
  return getRuleContext<pascalParser::AritContext>(0);
}


size_t pascalParser::AssignContext::getRuleIndex() const {
  return pascalParser::RuleAssign;
}


pascalParser::AssignContext* pascalParser::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 18, pascalParser::RuleAssign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97);
    match(pascalParser::ID);
    setState(98);
    match(pascalParser::T__11);
    setState(99);
    arit();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OutContext ------------------------------------------------------------------

pascalParser::OutContext::OutContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::Content_outContext* pascalParser::OutContext::content_out() {
  return getRuleContext<pascalParser::Content_outContext>(0);
}


size_t pascalParser::OutContext::getRuleIndex() const {
  return pascalParser::RuleOut;
}


pascalParser::OutContext* pascalParser::out() {
  OutContext *_localctx = _tracker.createInstance<OutContext>(_ctx, getState());
  enterRule(_localctx, 20, pascalParser::RuleOut);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    match(pascalParser::T__12);
    setState(102);
    match(pascalParser::T__13);
    setState(103);
    content_out();
    setState(104);
    match(pascalParser::T__14);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InContext ------------------------------------------------------------------

pascalParser::InContext::InContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::InContext::ID() {
  return getToken(pascalParser::ID, 0);
}


size_t pascalParser::InContext::getRuleIndex() const {
  return pascalParser::RuleIn;
}


pascalParser::InContext* pascalParser::in() {
  InContext *_localctx = _tracker.createInstance<InContext>(_ctx, getState());
  enterRule(_localctx, 22, pascalParser::RuleIn);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(106);
    match(pascalParser::T__15);
    setState(107);
    match(pascalParser::T__13);
    setState(108);
    match(pascalParser::ID);
    setState(109);
    match(pascalParser::T__14);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BranchContext ------------------------------------------------------------------

pascalParser::BranchContext::BranchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::Relation_blockContext* pascalParser::BranchContext::relation_block() {
  return getRuleContext<pascalParser::Relation_blockContext>(0);
}

std::vector<pascalParser::Code_blockContext *> pascalParser::BranchContext::code_block() {
  return getRuleContexts<pascalParser::Code_blockContext>();
}

pascalParser::Code_blockContext* pascalParser::BranchContext::code_block(size_t i) {
  return getRuleContext<pascalParser::Code_blockContext>(i);
}


size_t pascalParser::BranchContext::getRuleIndex() const {
  return pascalParser::RuleBranch;
}


pascalParser::BranchContext* pascalParser::branch() {
  BranchContext *_localctx = _tracker.createInstance<BranchContext>(_ctx, getState());
  enterRule(_localctx, 24, pascalParser::RuleBranch);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(123);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(111);
      match(pascalParser::T__16);
      setState(112);
      relation_block(0);
      setState(113);
      match(pascalParser::T__17);
      setState(114);
      code_block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(116);
      match(pascalParser::T__16);
      setState(117);
      relation_block(0);
      setState(118);
      match(pascalParser::T__17);
      setState(119);
      code_block();
      setState(120);
      match(pascalParser::T__18);
      setState(121);
      code_block();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Content_outContext ------------------------------------------------------------------

pascalParser::Content_outContext::Content_outContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pascalParser::StringContext* pascalParser::Content_outContext::string() {
  return getRuleContext<pascalParser::StringContext>(0);
}

pascalParser::ExprContext* pascalParser::Content_outContext::expr() {
  return getRuleContext<pascalParser::ExprContext>(0);
}


size_t pascalParser::Content_outContext::getRuleIndex() const {
  return pascalParser::RuleContent_out;
}


pascalParser::Content_outContext* pascalParser::content_out() {
  Content_outContext *_localctx = _tracker.createInstance<Content_outContext>(_ctx, getState());
  enterRule(_localctx, 26, pascalParser::RuleContent_out);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(127);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case pascalParser::T__19: {
        enterOuterAlt(_localctx, 1);
        setState(125);
        string();
        break;
      }

      case pascalParser::ID:
      case pascalParser::NUMBER: {
        enterOuterAlt(_localctx, 2);
        setState(126);
        expr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

pascalParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t pascalParser::StringContext::getRuleIndex() const {
  return pascalParser::RuleString;
}


pascalParser::StringContext* pascalParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 28, pascalParser::RuleString);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(129);
    match(pascalParser::T__19);
    setState(133);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(130);
        matchWildcard(); 
      }
      setState(135);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
    setState(136);
    match(pascalParser::T__19);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

pascalParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::ExprContext::NUMBER() {
  return getToken(pascalParser::NUMBER, 0);
}

tree::TerminalNode* pascalParser::ExprContext::ID() {
  return getToken(pascalParser::ID, 0);
}


size_t pascalParser::ExprContext::getRuleIndex() const {
  return pascalParser::RuleExpr;
}


pascalParser::ExprContext* pascalParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 30, pascalParser::RuleExpr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138);
    _la = _input->LA(1);
    if (!(_la == pascalParser::ID

    || _la == pascalParser::NUMBER)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AritContext ------------------------------------------------------------------

pascalParser::AritContext::AritContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::ExprContext *> pascalParser::AritContext::expr() {
  return getRuleContexts<pascalParser::ExprContext>();
}

pascalParser::ExprContext* pascalParser::AritContext::expr(size_t i) {
  return getRuleContext<pascalParser::ExprContext>(i);
}

pascalParser::AritContext* pascalParser::AritContext::arit() {
  return getRuleContext<pascalParser::AritContext>(0);
}


size_t pascalParser::AritContext::getRuleIndex() const {
  return pascalParser::RuleArit;
}


pascalParser::AritContext* pascalParser::arit() {
  AritContext *_localctx = _tracker.createInstance<AritContext>(_ctx, getState());
  enterRule(_localctx, 32, pascalParser::RuleArit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(165);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(140);
      expr();
      setState(141);
      match(pascalParser::T__20);
      setState(142);
      expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(144);
      expr();
      setState(145);
      match(pascalParser::T__21);
      setState(146);
      expr();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(148);
      expr();
      setState(149);
      match(pascalParser::T__22);
      setState(150);
      expr();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(152);
      expr();
      setState(153);
      match(pascalParser::T__23);
      setState(154);
      expr();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(156);
      expr();
      setState(157);
      match(pascalParser::T__24);
      setState(158);
      expr();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(160);
      match(pascalParser::T__13);
      setState(161);
      arit();
      setState(162);
      match(pascalParser::T__14);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(164);
      expr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Relation_blockContext ------------------------------------------------------------------

pascalParser::Relation_blockContext::Relation_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pascalParser::Relation_blockContext::NOT() {
  return getToken(pascalParser::NOT, 0);
}

std::vector<pascalParser::Relation_blockContext *> pascalParser::Relation_blockContext::relation_block() {
  return getRuleContexts<pascalParser::Relation_blockContext>();
}

pascalParser::Relation_blockContext* pascalParser::Relation_blockContext::relation_block(size_t i) {
  return getRuleContext<pascalParser::Relation_blockContext>(i);
}

pascalParser::RelationContext* pascalParser::Relation_blockContext::relation() {
  return getRuleContext<pascalParser::RelationContext>(0);
}

tree::TerminalNode* pascalParser::Relation_blockContext::OR() {
  return getToken(pascalParser::OR, 0);
}

tree::TerminalNode* pascalParser::Relation_blockContext::AND() {
  return getToken(pascalParser::AND, 0);
}


size_t pascalParser::Relation_blockContext::getRuleIndex() const {
  return pascalParser::RuleRelation_block;
}



pascalParser::Relation_blockContext* pascalParser::relation_block() {
   return relation_block(0);
}

pascalParser::Relation_blockContext* pascalParser::relation_block(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  pascalParser::Relation_blockContext *_localctx = _tracker.createInstance<Relation_blockContext>(_ctx, parentState);
  pascalParser::Relation_blockContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, pascalParser::RuleRelation_block, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(175);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case pascalParser::NOT: {
        setState(168);
        match(pascalParser::NOT);
        setState(169);
        relation_block(3);
        break;
      }

      case pascalParser::T__13: {
        setState(170);
        match(pascalParser::T__13);
        setState(171);
        relation_block(0);
        setState(172);
        match(pascalParser::T__14);
        break;
      }

      case pascalParser::ID:
      case pascalParser::NUMBER: {
        setState(174);
        relation();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(185);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(183);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Relation_blockContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelation_block);
          setState(177);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(178);
          match(pascalParser::OR);
          setState(179);
          relation_block(6);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Relation_blockContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelation_block);
          setState(180);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(181);
          match(pascalParser::AND);
          setState(182);
          relation_block(5);
          break;
        }

        } 
      }
      setState(187);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelationContext ------------------------------------------------------------------

pascalParser::RelationContext::RelationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pascalParser::ExprContext *> pascalParser::RelationContext::expr() {
  return getRuleContexts<pascalParser::ExprContext>();
}

pascalParser::ExprContext* pascalParser::RelationContext::expr(size_t i) {
  return getRuleContext<pascalParser::ExprContext>(i);
}

tree::TerminalNode* pascalParser::RelationContext::LT() {
  return getToken(pascalParser::LT, 0);
}

tree::TerminalNode* pascalParser::RelationContext::LEQ() {
  return getToken(pascalParser::LEQ, 0);
}

tree::TerminalNode* pascalParser::RelationContext::EQ() {
  return getToken(pascalParser::EQ, 0);
}

tree::TerminalNode* pascalParser::RelationContext::NEQ() {
  return getToken(pascalParser::NEQ, 0);
}

tree::TerminalNode* pascalParser::RelationContext::GEQ() {
  return getToken(pascalParser::GEQ, 0);
}

tree::TerminalNode* pascalParser::RelationContext::GT() {
  return getToken(pascalParser::GT, 0);
}


size_t pascalParser::RelationContext::getRuleIndex() const {
  return pascalParser::RuleRelation;
}


pascalParser::RelationContext* pascalParser::relation() {
  RelationContext *_localctx = _tracker.createInstance<RelationContext>(_ctx, getState());
  enterRule(_localctx, 36, pascalParser::RuleRelation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(212);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(188);
      expr();
      setState(189);
      match(pascalParser::LT);
      setState(190);
      expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(192);
      expr();
      setState(193);
      match(pascalParser::LEQ);
      setState(194);
      expr();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(196);
      expr();
      setState(197);
      match(pascalParser::EQ);
      setState(198);
      expr();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(200);
      expr();
      setState(201);
      match(pascalParser::NEQ);
      setState(202);
      expr();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(204);
      expr();
      setState(205);
      match(pascalParser::GEQ);
      setState(206);
      expr();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(208);
      expr();
      setState(209);
      match(pascalParser::GT);
      setState(210);
      expr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool pascalParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 17: return relation_blockSempred(dynamic_cast<Relation_blockContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool pascalParser::relation_blockSempred(Relation_blockContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> pascalParser::_decisionToDFA;
atn::PredictionContextCache pascalParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN pascalParser::_atn;
std::vector<uint16_t> pascalParser::_serializedATN;

std::vector<std::string> pascalParser::_ruleNames = {
  "start", "decl_list", "decl", "concat_decl", "main_code", "code_block", 
  "st_list", "repeat_block", "statement", "assign", "out", "in", "branch", 
  "content_out", "string", "expr", "arit", "relation_block", "relation"
};

std::vector<std::string> pascalParser::_literalNames = {
  "", "'program'", "';'", "'var'", "':'", "'integer'", "','", "'begin'", 
  "'end'", "'.'", "'repeat'", "'until'", "':='", "'writeln'", "'('", "')'", 
  "'readln'", "'if'", "'then'", "'else'", "'''", "'+'", "'-'", "'*'", "'/'", 
  "'%'", "'='", "'<'", "'<='", "'>'", "'>='", "'<>'"
};

std::vector<std::string> pascalParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "EQ", "LT", "LEQ", "GT", "GEQ", "NEQ", 
  "OR", "AND", "NOT", "ID", "NUMBER", "R_COMMENT", "C_COMMENT", "LINE_COMMENT", 
  "WS", "ErrorChar"
};

dfa::Vocabulary pascalParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> pascalParser::_tokenNames;

pascalParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2b, 0xd9, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x35, 0xa, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x41, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x5, 0x7, 0x4d, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x56, 0xa, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x5, 0xa, 0x62, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x7e, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x5, 
    0xf, 0x82, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x86, 0xa, 0x10, 
    0xc, 0x10, 0xe, 0x10, 0x89, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x5, 0x12, 0xa8, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0xb2, 0xa, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 
    0x13, 0xba, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0xbd, 0xb, 0x13, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xd7, 0xa, 0x14, 0x3, 
    0x14, 0x3, 0x87, 0x3, 0x24, 0x15, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
    0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 
    0x2, 0x3, 0x3, 0x2, 0x25, 0x26, 0x2, 0xdf, 0x2, 0x28, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x34, 0x3, 0x2, 0x2, 0x2, 0x6, 0x36, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x40, 0x3, 0x2, 0x2, 0x2, 0xa, 0x42, 0x3, 0x2, 0x2, 0x2, 0xc, 0x4c, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x55, 0x3, 0x2, 0x2, 0x2, 0x10, 0x57, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x61, 0x3, 0x2, 0x2, 0x2, 0x14, 0x63, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x67, 0x3, 0x2, 0x2, 0x2, 0x18, 0x6c, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x83, 0x3, 0x2, 0x2, 0x2, 0x20, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0xa7, 0x3, 0x2, 0x2, 0x2, 0x24, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x26, 0xd6, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x7, 0x3, 0x2, 0x2, 0x29, 0x2a, 0x7, 
    0x25, 0x2, 0x2, 0x2a, 0x2b, 0x7, 0x4, 0x2, 0x2, 0x2b, 0x2c, 0x7, 0x5, 
    0x2, 0x2, 0x2c, 0x2d, 0x5, 0x4, 0x3, 0x2, 0x2d, 0x2e, 0x5, 0xa, 0x6, 
    0x2, 0x2e, 0x2f, 0x7, 0x2, 0x2, 0x3, 0x2f, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x35, 0x5, 0x6, 0x4, 0x2, 0x31, 0x32, 0x5, 0x6, 0x4, 0x2, 0x32, 
    0x33, 0x5, 0x4, 0x3, 0x2, 0x33, 0x35, 0x3, 0x2, 0x2, 0x2, 0x34, 0x30, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0x31, 0x3, 0x2, 0x2, 0x2, 0x35, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x36, 0x37, 0x7, 0x25, 0x2, 0x2, 0x37, 0x38, 0x5, 0x8, 
    0x5, 0x2, 0x38, 0x39, 0x7, 0x6, 0x2, 0x2, 0x39, 0x3a, 0x7, 0x7, 0x2, 
    0x2, 0x3a, 0x3b, 0x7, 0x4, 0x2, 0x2, 0x3b, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x3d, 0x7, 0x8, 0x2, 0x2, 0x3d, 0x3e, 0x7, 0x25, 0x2, 0x2, 0x3e, 
    0x41, 0x5, 0x8, 0x5, 0x2, 0x3f, 0x41, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3c, 
    0x3, 0x2, 0x2, 0x2, 0x40, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x41, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0x42, 0x43, 0x7, 0x9, 0x2, 0x2, 0x43, 0x44, 0x5, 0xe, 
    0x8, 0x2, 0x44, 0x45, 0x7, 0xa, 0x2, 0x2, 0x45, 0x46, 0x7, 0xb, 0x2, 
    0x2, 0x46, 0xb, 0x3, 0x2, 0x2, 0x2, 0x47, 0x4d, 0x5, 0x12, 0xa, 0x2, 
    0x48, 0x49, 0x7, 0x9, 0x2, 0x2, 0x49, 0x4a, 0x5, 0xe, 0x8, 0x2, 0x4a, 
    0x4b, 0x7, 0xa, 0x2, 0x2, 0x4b, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x47, 
    0x3, 0x2, 0x2, 0x2, 0x4c, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4d, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0x4e, 0x4f, 0x5, 0x12, 0xa, 0x2, 0x4f, 0x50, 0x7, 0x4, 
    0x2, 0x2, 0x50, 0x56, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x5, 0x12, 0xa, 
    0x2, 0x52, 0x53, 0x7, 0x4, 0x2, 0x2, 0x53, 0x54, 0x5, 0xe, 0x8, 0x2, 
    0x54, 0x56, 0x3, 0x2, 0x2, 0x2, 0x55, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x55, 
    0x51, 0x3, 0x2, 0x2, 0x2, 0x56, 0xf, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 
    0x7, 0xc, 0x2, 0x2, 0x58, 0x59, 0x5, 0xe, 0x8, 0x2, 0x59, 0x5a, 0x7, 
    0xd, 0x2, 0x2, 0x5a, 0x5b, 0x5, 0x24, 0x13, 0x2, 0x5b, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0x62, 0x5, 0x14, 0xb, 0x2, 0x5d, 0x62, 0x5, 0x1a, 0xe, 
    0x2, 0x5e, 0x62, 0x5, 0x16, 0xc, 0x2, 0x5f, 0x62, 0x5, 0x18, 0xd, 0x2, 
    0x60, 0x62, 0x5, 0x10, 0x9, 0x2, 0x61, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x61, 
    0x5d, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5f, 
    0x3, 0x2, 0x2, 0x2, 0x61, 0x60, 0x3, 0x2, 0x2, 0x2, 0x62, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0x63, 0x64, 0x7, 0x25, 0x2, 0x2, 0x64, 0x65, 0x7, 0xe, 
    0x2, 0x2, 0x65, 0x66, 0x5, 0x22, 0x12, 0x2, 0x66, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x67, 0x68, 0x7, 0xf, 0x2, 0x2, 0x68, 0x69, 0x7, 0x10, 0x2, 0x2, 
    0x69, 0x6a, 0x5, 0x1c, 0xf, 0x2, 0x6a, 0x6b, 0x7, 0x11, 0x2, 0x2, 0x6b, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x12, 0x2, 0x2, 0x6d, 0x6e, 
    0x7, 0x10, 0x2, 0x2, 0x6e, 0x6f, 0x7, 0x25, 0x2, 0x2, 0x6f, 0x70, 0x7, 
    0x11, 0x2, 0x2, 0x70, 0x19, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x7, 0x13, 
    0x2, 0x2, 0x72, 0x73, 0x5, 0x24, 0x13, 0x2, 0x73, 0x74, 0x7, 0x14, 0x2, 
    0x2, 0x74, 0x75, 0x5, 0xc, 0x7, 0x2, 0x75, 0x7e, 0x3, 0x2, 0x2, 0x2, 
    0x76, 0x77, 0x7, 0x13, 0x2, 0x2, 0x77, 0x78, 0x5, 0x24, 0x13, 0x2, 0x78, 
    0x79, 0x7, 0x14, 0x2, 0x2, 0x79, 0x7a, 0x5, 0xc, 0x7, 0x2, 0x7a, 0x7b, 
    0x7, 0x15, 0x2, 0x2, 0x7b, 0x7c, 0x5, 0xc, 0x7, 0x2, 0x7c, 0x7e, 0x3, 
    0x2, 0x2, 0x2, 0x7d, 0x71, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x76, 0x3, 0x2, 
    0x2, 0x2, 0x7e, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x82, 0x5, 0x1e, 0x10, 
    0x2, 0x80, 0x82, 0x5, 0x20, 0x11, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 
    0x81, 0x80, 0x3, 0x2, 0x2, 0x2, 0x82, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x83, 
    0x87, 0x7, 0x16, 0x2, 0x2, 0x84, 0x86, 0xb, 0x2, 0x2, 0x2, 0x85, 0x84, 
    0x3, 0x2, 0x2, 0x2, 0x86, 0x89, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x3, 
    0x2, 0x2, 0x2, 0x87, 0x85, 0x3, 0x2, 0x2, 0x2, 0x88, 0x8a, 0x3, 0x2, 
    0x2, 0x2, 0x89, 0x87, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0x16, 0x2, 
    0x2, 0x8b, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x9, 0x2, 0x2, 0x2, 
    0x8d, 0x21, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x5, 0x20, 0x11, 0x2, 0x8f, 
    0x90, 0x7, 0x17, 0x2, 0x2, 0x90, 0x91, 0x5, 0x20, 0x11, 0x2, 0x91, 0xa8, 
    0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x5, 0x20, 0x11, 0x2, 0x93, 0x94, 0x7, 
    0x18, 0x2, 0x2, 0x94, 0x95, 0x5, 0x20, 0x11, 0x2, 0x95, 0xa8, 0x3, 0x2, 
    0x2, 0x2, 0x96, 0x97, 0x5, 0x20, 0x11, 0x2, 0x97, 0x98, 0x7, 0x19, 0x2, 
    0x2, 0x98, 0x99, 0x5, 0x20, 0x11, 0x2, 0x99, 0xa8, 0x3, 0x2, 0x2, 0x2, 
    0x9a, 0x9b, 0x5, 0x20, 0x11, 0x2, 0x9b, 0x9c, 0x7, 0x1a, 0x2, 0x2, 0x9c, 
    0x9d, 0x5, 0x20, 0x11, 0x2, 0x9d, 0xa8, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 
    0x5, 0x20, 0x11, 0x2, 0x9f, 0xa0, 0x7, 0x1b, 0x2, 0x2, 0xa0, 0xa1, 0x5, 
    0x20, 0x11, 0x2, 0xa1, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x7, 0x10, 
    0x2, 0x2, 0xa3, 0xa4, 0x5, 0x22, 0x12, 0x2, 0xa4, 0xa5, 0x7, 0x11, 0x2, 
    0x2, 0xa5, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa8, 0x5, 0x20, 0x11, 0x2, 
    0xa7, 0x8e, 0x3, 0x2, 0x2, 0x2, 0xa7, 0x92, 0x3, 0x2, 0x2, 0x2, 0xa7, 
    0x96, 0x3, 0x2, 0x2, 0x2, 0xa7, 0x9a, 0x3, 0x2, 0x2, 0x2, 0xa7, 0x9e, 
    0x3, 0x2, 0x2, 0x2, 0xa7, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa6, 0x3, 
    0x2, 0x2, 0x2, 0xa8, 0x23, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x8, 0x13, 
    0x1, 0x2, 0xaa, 0xab, 0x7, 0x24, 0x2, 0x2, 0xab, 0xb2, 0x5, 0x24, 0x13, 
    0x5, 0xac, 0xad, 0x7, 0x10, 0x2, 0x2, 0xad, 0xae, 0x5, 0x24, 0x13, 0x2, 
    0xae, 0xaf, 0x7, 0x11, 0x2, 0x2, 0xaf, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb0, 
    0xb2, 0x5, 0x26, 0x14, 0x2, 0xb1, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xac, 
    0x3, 0x2, 0x2, 0x2, 0xb1, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xbb, 0x3, 
    0x2, 0x2, 0x2, 0xb3, 0xb4, 0xc, 0x7, 0x2, 0x2, 0xb4, 0xb5, 0x7, 0x22, 
    0x2, 0x2, 0xb5, 0xba, 0x5, 0x24, 0x13, 0x8, 0xb6, 0xb7, 0xc, 0x6, 0x2, 
    0x2, 0xb7, 0xb8, 0x7, 0x23, 0x2, 0x2, 0xb8, 0xba, 0x5, 0x24, 0x13, 0x7, 
    0xb9, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xba, 
    0xbd, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 
    0x3, 0x2, 0x2, 0x2, 0xbc, 0x25, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbb, 0x3, 
    0x2, 0x2, 0x2, 0xbe, 0xbf, 0x5, 0x20, 0x11, 0x2, 0xbf, 0xc0, 0x7, 0x1d, 
    0x2, 0x2, 0xc0, 0xc1, 0x5, 0x20, 0x11, 0x2, 0xc1, 0xd7, 0x3, 0x2, 0x2, 
    0x2, 0xc2, 0xc3, 0x5, 0x20, 0x11, 0x2, 0xc3, 0xc4, 0x7, 0x1e, 0x2, 0x2, 
    0xc4, 0xc5, 0x5, 0x20, 0x11, 0x2, 0xc5, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xc6, 
    0xc7, 0x5, 0x20, 0x11, 0x2, 0xc7, 0xc8, 0x7, 0x1c, 0x2, 0x2, 0xc8, 0xc9, 
    0x5, 0x20, 0x11, 0x2, 0xc9, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x5, 
    0x20, 0x11, 0x2, 0xcb, 0xcc, 0x7, 0x21, 0x2, 0x2, 0xcc, 0xcd, 0x5, 0x20, 
    0x11, 0x2, 0xcd, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x5, 0x20, 0x11, 
    0x2, 0xcf, 0xd0, 0x7, 0x20, 0x2, 0x2, 0xd0, 0xd1, 0x5, 0x20, 0x11, 0x2, 
    0xd1, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x5, 0x20, 0x11, 0x2, 0xd3, 
    0xd4, 0x7, 0x1f, 0x2, 0x2, 0xd4, 0xd5, 0x5, 0x20, 0x11, 0x2, 0xd5, 0xd7, 
    0x3, 0x2, 0x2, 0x2, 0xd6, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xc2, 0x3, 
    0x2, 0x2, 0x2, 0xd6, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xca, 0x3, 0x2, 
    0x2, 0x2, 0xd6, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd2, 0x3, 0x2, 0x2, 
    0x2, 0xd7, 0x27, 0x3, 0x2, 0x2, 0x2, 0xf, 0x34, 0x40, 0x4c, 0x55, 0x61, 
    0x7d, 0x81, 0x87, 0xa7, 0xb1, 0xb9, 0xbb, 0xd6, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

pascalParser::Initializer pascalParser::_init;
