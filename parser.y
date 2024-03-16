%{  
    /*definitions*/
    #include <bits/stdc++.h>
    #include "data.h"
	#include "symbol_table.cpp"
    using namespace std;

    extern int yylex();
    extern int yyparse();
    extern void yyrestart(FILE* file);
    extern FILE* yyin;
    extern int yylineno;
    extern char* yytext;

    char* numtochar( int num){
        string s="0";
        while(num>0){
            s.push_back(num%10+'0');
            num/=10;
        }
        reverse(s.begin(),s.end());
        int n=s.size();
        char* c= (char*)malloc(sizeof(char)*(n+1));
        for( int i=0;i<n;i++){  
            c[i]=s[i];
        }
        c[n]='\0';
        return c;
    }
    int chartonum(char * c){
        int i=0;
        int num=0;
        while(c[i]!='\0'){
            num*=10;
            num+=c[i]-'0';
            i++;
        }
        return num;
    } 
    string chartostring(char* c){
        string s;
        int i=0;
        while(c[i]!='\0'){
            s.push_back(c[i]);
            i++;
        }
        return s;
    }
%}

%union{
    NODE *elem;
}

%start file

%type<elem> file snippet stmt simple_stmt small_stmt_list small_stmt expr_stmt annassign eq_testlist_star_expr_plus flow_stmt break_stmt continue_stmt return_stmt global_stmt nonlocal_stmt assert_stmt compound_stmt funcdef parameters typedargslist typedarg tfpdef if_stmt while_stmt for_stmt suite nts_star test or_test and_test not_test comparison comp_op star_expr expr xor_expr and_expr shift_expr arith_expr term term_choice factor factor_choice power atom_expr atom STRING_PLUS testlist_comp named_or_star_list named_or_star trailer subscriptlist subscriptlist_list subscript exprlist expr_or_star_expr_list expr_or_star_expr dictorsetmaker A A_list B B_list classdef arglist argument_list argument testlist testlist_list testlist_star_expr expr_choice_list expr_choice augassign comma_name_star async_stmt async_choice and_test_star not_test_star comp_iter sync_comp_for comp_for comp_if func_body_suite stmt_plus comma_test
%token<elem> NEWLINE
%token<elem> ASYNC 
%token<elem> INDENT 
%token<elem> DEDENT
%token<elem> ASSIGN_OPERATOR 
%token <elem>POWER_OPERATOR
%token<elem> SHIFT_OPER
%token<elem> FLOOR_DIV_OPER 
%token<elem> ARROW_OPER 
%token<elem> TYPE_HINT
%token<elem> NAME 
%token<elem> IF 
%token<elem> ELSE 
%token<elem> ELIF 
%token<elem> WHILE 
%token<elem> FOR 
%token<elem> IN 
%token<elem> AND
%token<elem> OR 
%token<elem> NOT 
%token<elem> BREAK 
%token<elem> CONTINUE 
%token<elem> RETURN 
%token<elem> CLASS 
%token<elem> DEF 
%token<elem> GLOBAL 
%token<elem> NONLOCAL 
%token<elem> ASSERT 
%token<elem> ATOM_KEYWORDS 
%token<elem> STRING 
%token<elem> NUMBER 
%token<elem> OPEN_BRACKET
%token<elem> CLOSE_BRACKET
%token<elem> EQUAL
%token<elem> SEMI_COLON
%token<elem> COLON 
%token<elem> COMMA 
%token<elem> PLUS 
%token<elem> MINUS
%token<elem> MULTIPLY
%token<elem> DIVIDE
%token<elem> REMAINDER
%token<elem> ATTHERATE
%token<elem> NEGATION
%token<elem> BIT_AND
%token<elem> BIT_OR
%token<elem> BIT_XOR
%token<elem> DOT 
%token <elem>CURLY_OPEN
%token <elem>CURLY_CLOSE
%token<elem> SQUARE_OPEN
%token<elem> SQUARE_CLOSE
%token<elem> LESS_THAN
%token<elem> GREATER_THAN
%token<elem> EQUAL_EQUAL
%token<elem> GREATER_THAN_EQUAL
%token<elem> LESS_THAN_EQUAL
%token<elem> NOT_EQUAL_ARROW
%token<elem> NOT_EQUAL
%token<elem> IS
%%


file: snippet {
    
 }
         ;

snippet: NEWLINE {
       
    }
    | stmt  { 
        
    }
    | NEWLINE snippet  { 
        
    }
    | stmt snippet {  
        
    }
    ; 

funcdef: DEF NAME parameters COLON func_body_suite  {  
            

        }
        | DEF NAME parameters ARROW_OPER TYPE_HINT COLON func_body_suite {  
            
        }
        | DEF NAME OPEN_BRACKET CLOSE_BRACKET ARROW_OPER TYPE_HINT COLON func_body_suite {  
            
        }
        | DEF NAME OPEN_BRACKET CLOSE_BRACKET COLON func_body_suite {
            
        }
        ;

parameters: OPEN_BRACKET typedargslist CLOSE_BRACKET {  
            
            
        }
        ;

typedargslist:  typedarg    {  
            
        }
        | typedargslist COMMA  typedarg  {  
            
        }
        ;

typedarg: tfpdef   {  
            
        }
        | tfpdef COLON test {  
            
        }
        ;

tfpdef: NAME {  
            
        }
        | NAME COLON TYPE_HINT {  
            
        }
        ;

stmt: simple_stmt       { 
           
        }
        | compound_stmt     { 
            
        }
        ;

simple_stmt: small_stmt_list SEMI_COLON NEWLINE {  
            
        
        }
        | small_stmt_list  NEWLINE {  
            
        }
        ; 

small_stmt_list: small_stmt     {   
            
        }
        | small_stmt_list SEMI_COLON small_stmt      {  
           
        }
        ;

small_stmt: expr_stmt       {  
           
        }
        | flow_stmt     {  
           
        }
        | global_stmt       {  
            
        }
        | nonlocal_stmt     {  
            
        }
        | assert_stmt       {  
            
        }
        ;

expr_stmt:  testlist_star_expr annassign {   
           
        }
        | testlist_star_expr augassign testlist {  
            
        }
        | eq_testlist_star_expr_plus { 
           
        }
        ; 

eq_testlist_star_expr_plus: testlist_star_expr {  
            
        }
        | testlist_star_expr EQUAL eq_testlist_star_expr_plus {  
           
        }
        ;

annassign: COLON test   {  
            
        }
        | COLON test EQUAL testlist_star_expr   {  
            
        }
        ;

testlist_star_expr: expr_choice_list {  
          
        }
        | expr_choice_list COMMA  {   
            
        }
        ;

expr_choice_list : expr_choice  { 
            
        }
        | expr_choice_list COMMA expr_choice    { 
            
        }
        ;

expr_choice : test  {  
            
        }
        | star_expr   {  
            
        }
        ;

augassign: ASSIGN_OPERATOR  {  
           
        }
        ;

flow_stmt: break_stmt   {  
            
        }
        | continue_stmt     {  
            
        }
        | return_stmt    {  
            
        }
        ;

break_stmt: BREAK   {  
            
        }
        ;
continue_stmt: CONTINUE     {  
            
        }
        ;
return_stmt: RETURN     {  
            
        }
        | RETURN testlist_star_expr     {  
           
        }
        ;   

global_stmt: GLOBAL NAME    {  
            
        }
        | GLOBAL NAME comma_name_star {   
            
        }
        ;
nonlocal_stmt: NONLOCAL NAME     { 
            
            
        }
        | NONLOCAL NAME comma_name_star {  
            
        }
        ;    
        
assert_stmt: ASSERT test  {  
            
        }
        | ASSERT test comma_test  {  
           
        }
        ;
comma_name_star: COMMA NAME    {  
           
        }
        | COMMA NAME comma_name_star    {  
            
        }
        ;
compound_stmt: if_stmt      { 
            
        }
        | while_stmt   {  
           
        }
        | for_stmt     {  
            
        }
        | funcdef      {  
            
        }
        | classdef     {  
           
        }
        | async_stmt   {  
            
        }
        ;
async_stmt: ASYNC async_choice  {  
            
        }
        ;
async_choice : funcdef  { 
            
        }
        | for_stmt  {  
            
        }
        ;   

if_stmt: IF test COLON suite     {  
           
        }
        | IF test COLON suite ELSE COLON suite   {  
            
        }
        | IF test COLON suite nts_star    {  
            
        }
        | IF test COLON suite nts_star ELSE COLON suite   {
            
        }
        ;
while_stmt: WHILE test COLON suite   {  
            
        }
        | WHILE test COLON suite ELSE COLON suite  {   
           
        }
        ;
for_stmt: FOR exprlist IN testlist COLON suite    { 
            
        }
        | FOR exprlist IN testlist COLON suite ELSE COLON suite   { 
            
        }
        ;
suite: simple_stmt  { 
            
        }
        | NEWLINE INDENT stmt_plus DEDENT   { 
            
        }
        | NEWLINE INDENT stmt_plus NEWLINE DEDENT   { 
            
        }
        ;

nts_star : ELIF test COLON suite  {  
            
        }
        | ELIF test COLON suite nts_star  {  
            
        }
        ;
test: or_test   { 
            
        }
        | or_test IF or_test ELSE test  {  
            
        }
        ;
or_test: and_test    { 
            
        }
        | and_test_star OR and_test    {  
            
        }
        ;
and_test_star : and_test_star OR and_test {
            
        }
        | and_test   { 
            
        }
        ;

and_test: not_test  {
            
        }
        | not_test_star AND not_test    {  
            
        }
        ;
not_test_star : not_test_star AND not_test  { 
            
        }
        | not_test   { 
            
        }
        ;

not_test: NOT not_test   { 
            
        }
        | comparison    { 
            
        }
        ;

comparison: expr  {
            
        }
        | expr comp_op comparison  { 
            
        }
        ;

comp_op: LESS_THAN  {
        
    }
    | GREATER_THAN  { 
       
     }
    | EQUAL_EQUAL   { 
        
     }
    | GREATER_THAN_EQUAL    { 
        
     }
    | LESS_THAN_EQUAL   {
        
     }
    | NOT_EQUAL_ARROW   {
        
      }
    | NOT_EQUAL    {
       
     }
    | IN    {  
        
    }
    | NOT IN    { 
        
     }
    | IS    { 
        
     }
    | IS NOT    { 
        
     }
    ;

star_expr: MULTIPLY expr    { 
            
        }
        ;

expr: xor_expr    { 
            
        }
        | xor_expr BIT_OR expr    {  
            
        }
        ;

xor_expr: and_expr { 
            
        }
        | and_expr BIT_XOR xor_expr    {  
            
        }
        ;

and_expr: shift_expr   { 
            
        }
        | shift_expr BIT_AND and_expr   {  
            
        }
        ;

shift_expr: arith_expr   { 
                
            }
            | arith_expr SHIFT_OPER shift_expr   { 
                
             }
        ;

arith_expr: term { 
                
            }
            | arith_expr PLUS term { 
                
            }
            | arith_expr MINUS term { 
                
             }
        ;
term: factor {
            
        }
        | term term_choice factor {
            
         }
        ;

term_choice : MULTIPLY      { 
            
        }
        |ATTHERATE      { 
            
        }
        |DIVIDE         { 
            
        }
        |REMAINDER      { 
           
        }
        |FLOOR_DIV_OPER    { 
            
        }
        ;

factor: factor_choice factor        {  
            
        }
        | power     { 
            
        }
        ;
factor_choice : PLUS        {
            
        }
        | MINUS      { 
            
        }
        | NEGATION   { 
            
        }
        ;
power: atom_expr        { 
            
        }
        | atom_expr POWER_OPERATOR factor   { 
            
        }
        ;

atom_expr: atom {  
            
        }
        | atom_expr trailer {  
            
        }
        | atom_expr DOT NAME { 
            
        }
        ;

atom: OPEN_BRACKET testlist_comp CLOSE_BRACKET  { 
        
    }
    | OPEN_BRACKET CLOSE_BRACKET    {
        
    }
    | SQUARE_OPEN testlist_comp SQUARE_CLOSE    { 
        
    }
    | SQUARE_OPEN SQUARE_CLOSE  {
        
     }
    | CURLY_OPEN dictorsetmaker CURLY_CLOSE     { 
        
    }
    | CURLY_OPEN CURLY_CLOSE    { 
        
     }
    | NAME      {
        
     }
    | NUMBER        { 
        
    }
    | STRING_PLUS       { 
       
    }
    | ATOM_KEYWORDS     { 
        
    }
    | TYPE_HINT     { 
        
     }
    ;
STRING_PLUS: STRING     {
            
        }
        | STRING STRING_PLUS    { 
            
        }
        ;

testlist_comp: named_or_star comp_for       { 
            
        }
        | named_or_star_list    { 
            
        }
        | named_or_star_list COMMA      { 
            
        }
        ;
named_or_star_list : named_or_star      { 
            
        }
        | named_or_star_list COMMA named_or_star    { 
            
        }
        ; 
named_or_star : test    { 
            
        }
        | star_expr     { 
            
        }
        ;

trailer: OPEN_BRACKET CLOSE_BRACKET  { 
            
        }
        | OPEN_BRACKET arglist CLOSE_BRACKET  {
            
         }
        | SQUARE_OPEN subscriptlist SQUARE_CLOSE        {
            
         }
        ;

subscriptlist: subscriptlist_list      {
            
        }
        | subscriptlist_list COMMA     { 
            
        }
        ;
subscriptlist_list: subscript       { 
            
        }
        | subscriptlist_list COMMA subscript    { 
            
        }
        ;
subscript: test     { 
            
        }
        | COLON     {  
            
        }
        | COLON test     { 
            
        }
        | test COLON     { 
            
        }
        | test COLON test     {
            
        }
        ;
exprlist: expr_or_star_expr_list   {
            
        }
        | expr_or_star_expr_list COMMA  { 
            
        }
        ;
expr_or_star_expr_list: expr_or_star_expr   { 
            
        }
        | expr_or_star_expr_list COMMA expr_or_star_expr    { 
            
        }
        ;
expr_or_star_expr: expr         { 
            
        }
        | star_expr     { 
            
        }
        ;
testlist: testlist_list    { 
            
        }
        | testlist_list COMMA   {
            
         }
        ;
testlist_list: test         {
            
        }
        | testlist_list COMMA test  { 
            
        }
        ;   
dictorsetmaker: A comp_for   {
            
        }
        | A_list    { 
            
        }
        | A_list COMMA    { 
            
        }
        | B comp_for       {
           
        }
        | B_list       {
            
         }
        | B_list COMMA      { 
            
        }
        ;

A: test COLON test  { 
            
        }
    | POWER_OPERATOR expr   { 
            
        }
    ;
A_list: A    { 
            
        }
        | A_list COMMA A    { 
            
        }
        ;
B: test  {
                 
        }
        | star_expr     { 
               
        }
        ;
B_list: B   { 
            
        }
        | B_list COMMA B    { 
            
        }
        ;

classdef: CLASS NAME COLON suite      { 
            
        }
        | CLASS NAME OPEN_BRACKET CLOSE_BRACKET COLON suite      { 
            
        }
        | CLASS NAME OPEN_BRACKET arglist CLOSE_BRACKET COLON suite      { 
           
        }
        ;

arglist: argument_list     { 
            
        }
        | argument_list COMMA    { 
           
        }
        ;
argument_list: argument     { 
            
        }
        | argument_list COMMA argument  { 
            
        }
        ;

argument: test  {
               
        }
        | test comp_for     {
            
        }
        | test EQUAL test   { 
            
        }
        | POWER_OPERATOR test   { 
            
        }
        | MULTIPLY test     {  
            
        }
        ;

comp_iter: comp_for     { 
            
        }
        | comp_if   { 
            
        }
        ;
sync_comp_for: FOR exprlist IN or_test      {
           
        }
        | FOR exprlist IN or_test comp_iter     { 
            
        }
        ;
comp_for: sync_comp_for     {
            
        }
        | ASYNC sync_comp_for   { 
            
        }
        ;
comp_if: IF or_test         {
            
        }
        | IF or_test comp_iter  { 
           
        }
        ;
func_body_suite: simple_stmt    { 
            
        }
        | NEWLINE INDENT stmt_plus DEDENT   { 
            
        }
        | NEWLINE INDENT stmt_plus NEWLINE DEDENT   { 
            
        }
        ;

stmt_plus: stmt     {
            
        
        }
        | stmt stmt_plus    { 
            
        }

comma_test: COMMA test  {
            
        }
        ;
%%

void yyerror(string str){
    fprintf(stderr, "Error: %s at line number %d offending token: %s\n", str.c_str(), yylineno, yytext);
    print_ast();
    exit(1);
}

int main(int argc, char* argv[]){    
    yydebug=1;
    FILE* yyin; 
    bool inset = false, outset = false;
    indent_stack.push(0);

    for (int i=0; i< argc; i++){
        if (strcmp(argv[i], "-help") == 0){
            cerr<<"Usage: ./run.sh [-help] [-input <filename>] [-output <filename>] [-verbose]\n";
            cerr<< "Example: ./myASTGenerator -input input.txt -output output.txt\n";
        }
        else if (strcmp(argv[i], "-input") == 0){
            yyin = fopen(argv[i+1], "r");
            yyrestart(yyin);
            inset = true;
        }
        else if (strcmp(argv[i], "-output") == 0){
            freopen(argv[i+1], "w", stdout);
            outset = true;
        }
        else if (strcmp(argv[i], "-verbose") == 0){
            cerr<<"Verbose Output directed to parser.output\n";
        }
    }
    if (!inset){
        cerr<< "Input not set, see help\n";
        return 0;
    }
    if (!outset){
        cerr<< "Output not set, see help\n";
        return 0;
    } 
    yyparse();
    fclose(yyin); 
    return 0;

}