/*****************************************************
 *  Implementation of "WhileStmt".
 *
 *  Please refer to ast/ast.hpp for the definition.
 *
 *  Keltin Leung 
 */

#include "ast/ast.hpp"
#include "ast/visitor.hpp"
#include "config.hpp"

using namespace mind;
using namespace mind::ast;

/* Creates a new WhileStmt node.
 *
 * PARAMETERS:
 *   cond    - the test expression
 *   body    - the loop body
 *   l       - position in the source text
 */
WhileStmt::WhileStmt(Expr *cond, Statement *body, Location *l) {

    setBasicInfo(WHILE_STMT, l);

    condition = cond;
    loop_body = body;
}

/* Visits the current node.
 *
 * PARAMETERS:
 *   v       - the visitor
 */
void WhileStmt::accept(Visitor *v) { v->visit(this); }

/* Prints the current AST node.
 *
 * PARAMETERS:
 *   os      - the output stream
 */
void WhileStmt::dumpTo(std::ostream &os) {
    ASTNode::dumpTo(os);
    newLine(os);
    os << condition;

    newLine(os);
    os << loop_body << ")";
    decIndent(os);
}

//-------------------------------------------------------------------------------
/* Creates a new DoWhileStmt node.
 *
 * PARAMETERS:
 *   cond    - the test expression
 *   body    - the loop body
 *   l       - position in the source text
 */
DoWhileStmt::DoWhileStmt(Expr *cond, Statement *body, Location *l) {
    setBasicInfo(DO_WHILE_STMT, l);
    condition = cond;
    loop_body = body;
}

/* Visits the current node.
 *
 * PARAMETERS:
 *   v       - the visitor
 */
void DoWhileStmt::accept(Visitor *v) { v->visit(this); }

/* Prints the current AST node.
 *
 * PARAMETERS:
 *   os      - the output stream
 */
void DoWhileStmt::dumpTo(std::ostream &os) {
    ASTNode::dumpTo(os);
    newLine(os);
    os << condition;

    newLine(os);
    os << loop_body << ")";
    decIndent(os);
}

//-------------------------------------------------------------------------------
/* Creates a new ForStmt node.
 *
 * PARAMETERS:
 *   init    - the init expression or declaration
 *   cond    - the test expression
 *   uodate  - the update expression
 *   body    - the loop body
 *   l       - position in the source text
 */
ForStmt::ForStmt(Expr* _init, Expr* _condition, Expr* _update, Statement* _body, Location* l) {
    setBasicInfo(FOR_STMT, l);
    exprInit = _init;
    varDeclInit = nullptr;
    condition = _condition;
    update = _update;
    loop_body = _body;
}
ForStmt::ForStmt(VarDecl* _init, Expr* _condition, Expr* _update, Statement* _body, Location* l, int dumy){
    setBasicInfo(FOR_STMT, l);
    exprInit = nullptr;
    varDeclInit = _init;
    condition = _condition;
    update = _update;
    loop_body = _body;
}
    
/* Visits the current node.
 *
 * PARAMETERS:
 *   v       - the visitor
 */
void ForStmt::accept(Visitor *v) { v->visit(this); }

/* Prints the current AST node.
 *
 * PARAMETERS:
 *   os      - the output stream
 */
void ForStmt::dumpTo(std::ostream &os) {
    ASTNode::dumpTo(os);
    newLine(os);
    os << condition;

    newLine(os);
    os << loop_body << ")";
    decIndent(os);
}

//-----------------------------------------------------------------------------------------
/* Creates a new BreakStmt node.
 *
 * PARAMETERS:
 *   l       - position in the source text
 */
BreakStmt::BreakStmt(Location *l) { setBasicInfo(BREAK_STMT, l); }

/* Visits the current node.
 *
 * PARAMETERS:
 *   v       - the visitor
 */
void BreakStmt::accept(Visitor *v) { v->visit(this); }

/* Prints the current AST node.
 *
 * PARAMETERS:
 *   os      - the output stream
 */
void BreakStmt::dumpTo(std::ostream &os) {
    ASTNode::dumpTo(os);
    newLine(os);
    decIndent(os);
}

//----------------------------------------------------------------------------------------------
/* Creates a new ContStmt node.
 *
 * PARAMETERS:
 *   l       - position in the source text
 */
ContStmt::ContStmt(Location *l) { setBasicInfo(CONTINUE_STMT, l); }

/* Visits the current node.
 *
 * PARAMETERS:
 *   v       - the visitor
 */
void ContStmt::accept(Visitor *v) { v->visit(this); }

/* Prints the current AST node.
 *
 * PARAMETERS:
 *   os      - the output stream
 */
void ContStmt::dumpTo(std::ostream &os) {
    ASTNode::dumpTo(os);
    newLine(os);
    decIndent(os);
}