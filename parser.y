%{  
    /*definitions*/
    #include <bits/stdc++.h>
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
    struct label{
        int num;
        string l;
        bool terminal;
    } ;
    struct edge{
        int a;
        int b;
        string l;
    };
    vector<int> remove_label;
    vector<label> labels;
    vector<edge> edges;
    extern char* addlabel(string c, bool term = false){  
        int n=labels.size()+1;
        label q;
        q.num=n*10;
        q.l=c;
        q.terminal=term;
        if(c=="TRAILER1" || c=="ATOM1"){
                remove_label.push_back(n*10);
        }
        labels.push_back(q);
        return numtochar(n);
    }
    extern void addedge(char* a, char* b, string l=""){ 
        edge q;
        q.a=chartonum(a);
        q.b=chartonum(b);
        q.l=l;
        edges.push_back(q);
        
    }
    extern stack<int> indent_stack;

    void yyerror(string str);

    void print_ast(){
        cout << "digraph ASTVisual {\n ordering = out ;\n";
        for(auto e: labels){
            string s;
            for( auto e1: e.l){
                if(e1=='\"' || e1=='\\'  ){
                    s.push_back('\\');
                }
                s.push_back(e1);
            } 
            if(s!="ATOM1" && s!="TRAILER1" && e.terminal == false) cout<<e.num<<" [ label=\""<<s<<"\"]\n";
            else if(s!="ATOM1" && s!="TRAILER1" && e.terminal==true) cout<<e.num<<" [ label=\""<<s<<"\", color = \"red\", shape=\"box\"]\n";
        }
        for(auto e: edges){
            string s;

            for( auto e1: e.l){
                if(e1=='\"' || e1=='\\'){
                    s.push_back('\\');
                }
                s.push_back(e1);
            } 
            if(find(remove_label.begin(),remove_label.end(),e.b)==remove_label.end()) cout<<e.a<< " -> "<<e.b << "[ label=\""<<s<<"\"]\n";
        }
        cout << "  }\n";
    }
    
%}

%union{
    char* val;
    struct node* treenode;
}

%start file

%type<treenode> file snippet stmt simple_stmt small_stmt_list small_stmt expr_stmt annassign eq_testlist_star_expr_plus flow_stmt break_stmt continue_stmt return_stmt global_stmt nonlocal_stmt assert_stmt compound_stmt funcdef parameters typedargslist typedarg tfpdef if_stmt while_stmt for_stmt suite nts_star test or_test and_test not_test comparison comp_op star_expr expr xor_expr and_expr shift_expr arith_expr term term_choice factor factor_choice power atom_expr atom STRING_PLUS testlist_comp named_or_star_list named_or_star trailer subscriptlist subscriptlist_list subscript exprlist expr_or_star_expr_list expr_or_star_expr dictorsetmaker A A_list B B_list classdef arglist argument_list argument testlist testlist_list testlist_star_expr expr_choice_list expr_choice augassign comma_name_star async_stmt async_choice and_test_star not_test_star comp_iter sync_comp_for comp_for comp_if func_body_suite stmt_plus comma_test
%token<val> NEWLINE
%token<val> ASYNC 
%token<val> INDENT 
%token<val> DEDENT
%token<val> ASSIGN_OPERATOR 
%token <val>POWER_OPERATOR
%token<val> SHIFT_OPER
%token<val> FLOOR_DIV_OPER 
%token<val> ARROW_OPER 
%token<val> TYPE_HINT
%token<val> NAME 
%token<val> IF 
%token<val> ELSE 
%token<val> ELIF 
%token<val> WHILE 
%token<val> FOR 
%token<val> IN 
%token<val> AND
%token<val> OR 
%token<val> NOT 
%token<val> BREAK 
%token<val> CONTINUE 
%token<val> RETURN 
%token<val> CLASS 
%token<val> DEF 
%token<val> GLOBAL 
%token<val> NONLOCAL 
%token<val> ASSERT 
%token<val> ATOM_KEYWORDS 
%token<val> STRING 
%token<val> NUMBER 
%token<val> OPEN_BRACKET
%token<val> CLOSE_BRACKET
%token<val> EQUAL
%token<val> SEMI_COLON
%token<val> COLON 
%token<val> COMMA 
%token<val> PLUS 
%token<val> MINUS
%token<val> MULTIPLY
%token<val> DIVIDE
%token<val> REMAINDER
%token<val> ATTHERATE
%token<val> NEGATION
%token<val> BIT_AND
%token<val> BIT_OR
%token<val> BIT_XOR
%token<val> DOT 
%token <val>CURLY_OPEN
%token <val>CURLY_CLOSE
%token<val> SQUARE_OPEN
%token<val> SQUARE_CLOSE
%token<val> LESS_THAN
%token<val> GREATER_THAN
%token<val> EQUAL_EQUAL
%token<val> GREATER_THAN_EQUAL
%token<val> LESS_THAN_EQUAL
%token<val> NOT_EQUAL_ARROW
%token<val> NOT_EQUAL
%token<val> IS
%%


file: snippet {
    node* tempnode;
    $$ = new node("file");
    $$->add_child($1);
 }
         ;

snippet: NEWLINE {
        $$= new node("snippet");
        node* tempnode;
        tempnode= new node("newline",true,"newline");
        $$->add_child(tempnode);
    }
    | stmt  { 
        node* tempnode;
        $$ = new node("snippet");
        $$->add_child($1);
    }
    | NEWLINE snippet  { 
        $$= new node("snippet");
        node* tempnode;
        tempnode= new node("newline",true,"newline");
        $$->add_child(tempnode);
        $$->add_child($2);
    }
    | stmt snippet {  
        $$= new node("snippet");
        $$->add_child($1);
        $$->add_child($2);
    }
    ; 

funcdef: DEF NAME parameters COLON func_body_suite  {  
            $$ = new node("funcdef");
            node* tempnode;
            tempnode= new node("def",true,"Keyword");
            $$->add_child(tempnode);
            string s($2);
            tempnode= new node(s,true,"ID");
            $$->add_child(tempnode);
            $$->add_child($3);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($5);

        }
        | DEF NAME parameters ARROW_OPER TYPE_HINT COLON func_body_suite {  
            $$ = new node("funcdef");
            node* tempnode;
            tempnode= new node("def",true,"KEYWORD");
            $$->add_child(tempnode);
            string s($2);
            tempnode= new node(s,true,"ID");
            $$->add_child(tempnode);
            $$->add_child($3);
            tempnode= new node("->",true,"DELIMITER");
            $$->add_child(tempnode);
            string s($5);
            tempnode= new node(s,true,"TYPE_HINT");
            $$->add_child(tempnode);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($7);
        }
        | DEF NAME OPEN_BRACKET CLOSE_BRACKET ARROW_OPER TYPE_HINT COLON func_body_suite {  
            $$ = new node("funcdef");
            node* tempnode;
            tempnode= new node("def",true,"KEYWORD");
            $$->add_child(tempnode);
            string s($2);
            tempnode= new node(s,true,"ID");
            $$->add_child(tempnode);
            tempnode= new node("(",true,"DELIMITER");
            $$->add_child(tempnode);
            tempnode= new node(")",true,"DELIMITER");
            $$->add_child(tempnode);
            tempnode= new node("->",true,"DELIMITER");
            $$->add_child(tempnode);
            string s($6);
            tempnode= new node(s,true,"TYPE_HINT");
            $$->add_child(tempnode);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($8);
        }
        | DEF NAME OPEN_BRACKET CLOSE_BRACKET COLON func_body_suite {
            $$ = new node("funcdef");
            node* tempnode;
            tempnode= new node("def",true,"KEYWORD");
            $$->add_child(tempnode);
            string s($2);
            tempnode= new node(s,true,"ID");
            $$->add_child(tempnode);
            tempnode= new node("(",true,"DELIMITER");
            $$->add_child(tempnode);
            tempnode= new node(")",true,"DELIMITER");
            $$->add_child(tempnode);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($6);
        }
        ;

parameters: OPEN_BRACKET typedargslist CLOSE_BRACKET {  
            $$ = new node("parameters");
            node* tempnode;
            tempnode= new node("(",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($2);
            tempnode= new node(")",true,"DELIMITER");
            $$->add_child(tempnode);
            
        }
        ;

typedargslist:  typedarg    {  
            $$ = new node("typedargslist");
            $$->add_child($1);
        }
        | typedargslist COMMA  typedarg  {  
            $$ = new node("typedargslist");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(",",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ;

typedarg: tfpdef   {  
            $$ = new node("typedarg");
            $$->add_child($1);
        }
        | tfpdef COLON test {  
            $$ = new node("typedarg");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ;

tfpdef: NAME {  
            $$ = new node("tfpdef");
            string s($1);
            node* tempnode;
            tempnode= new node(s,true,"ID");
            $$->add_child(tempnode);
        }
        | NAME COLON TYPE_HINT {  
            $$ = new node("tfpdef");
            string s($1);
            node* tempnode;
            tempnode= new node(s,true,"ID");
            $$->add_child(tempnode);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            string s($3);
            tempnode= new node(s,true,"TYPE_HINT");
            $$->add_child(tempnode);
        }
        ;

stmt: simple_stmt       { 
            $$ = new node("stmt");
            $$->add_child($1);
        }
        | compound_stmt     { 
            $$ = new node("stmt");
            $$->add_child($1);
        }
        ;

simple_stmt: small_stmt_list SEMI_COLON NEWLINE {  
            $$ = new node("simple_stmt");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(";",true,"DELIMITER");
            $$->add_child(tempnode);
            tempnode= new node("newline",true,"newline");
            $$->add_child(tempnode);
        
        }
        | small_stmt_list  NEWLINE {  
            $$ = new node("simple_stmt");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node("newline",true,"newline");
            $$->add_child(tempnode);
        }
        ; 

small_stmt_list: small_stmt     {   
            $$ = new node("small_stmt_list");
            $$->add_child($1);
        }
        | small_stmt_list SEMI_COLON small_stmt      {  
            $$ = new node("small_stmt_list");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(";",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ;

small_stmt: expr_stmt       {  
            $$ = new node("small_stmt");
            $$->add_child($1);
        }
        | flow_stmt     {  
            $$ = new node("small_stmt");
            $$->add_child($1);
        }
        | global_stmt       {  
            $$ = new node("small_stmt");
            $$->add_child($1);
        }
        | nonlocal_stmt     {  
            $$ = new node("small_stmt");
            $$->add_child($1);
        }
        | assert_stmt       {  
            $$ = new node("small_stmt");
            $$->add_child($1);
        }
        ;

expr_stmt:  testlist_star_expr annassign {   
            $$ = new node("expr_stmt");
            $$->add_child($1);
            $$->add_child($2);
        }
        | testlist_star_expr augassign testlist {  
            $$ = new node("expr_stmt");
            $$->add_child($1);
            $$->add_child($2);
            $$->add_child($3);
        }
        | eq_testlist_star_expr_plus { 
            $$ = new node("expr_stmt");
            $$->add_child($1);
        }
        ; 

eq_testlist_star_expr_plus: testlist_star_expr {  
            $$ = new node("eq_testlist_star_expr_plus");
            $$->add_child($1);
        }
        | testlist_star_expr EQUAL eq_testlist_star_expr_plus {  
            $$ = new node("eq_testlist_star_expr_plus");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node("=",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ;

annassign: COLON test   {  
            $$ = new node("annassign");
            node* tempnode;
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($2);
        }
        | COLON test EQUAL testlist_star_expr   {  
            $$ = new node("annassign");
            node* tempnode;
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($2);
            tempnode= new node("=",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($4);
        }
        ;

testlist_star_expr: expr_choice_list {  
            $$ = new node("testlist_star_expr");
            $$->add_child($1);
        }
        | expr_choice_list COMMA  {   
            $$ = new node("testlist_star_expr");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(",",true,"DELIMITER");
            $$->add_child(tempnode);
        }
        ;

expr_choice_list : expr_choice  { 
            $$ = new node("expr_choice_list");
            $$->add_child($1);
        }
        | expr_choice_list COMMA expr_choice    { 
            $$ = new node("expr_choice_list");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(",",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ;

expr_choice : test  {  
            $$ = new node("expr_choice");
            $$->add_child($1);
        }
        | star_expr   {  
            $$ = new node("expr_choice");
            $$->add_child($1);
        }
        ;

augassign: ASSIGN_OPERATOR  {  
            $$ = new node("augassign");
            node* tempnode;
            string s($1);
            tempnode= new node(s,true,"DELIMITER");
            $$->add_child(tempnode);
        }
        ;

flow_stmt: break_stmt   {  
            $$ = new node("flow_stmt");
            $$->add_child($1);
        }
        | continue_stmt     {  
            $$ = new node("flow_stmt");
            $$->add_child($1);
        }
        | return_stmt    {  
            $$ = new node("flow_stmt");
            $$->add_child($1);
        }
        ;

break_stmt: BREAK   {  
            $$ = new node("break_stmt");
            node* tempnode;
            tempnode= new node("break",true,"KEYWORD");
            $$->add_child(tempnode);
        }
        ;
continue_stmt: CONTINUE     {  
            $$ = new node("continue_stmt");
            node* tempnode;
            tempnode= new node("continue",true,"KEYWORD");
            $$->add_child(tempnode);
        }
        ;
return_stmt: RETURN     {  
            $$ = new node("return_stmt");
            node* tempnode;
            tempnode= new node("return",true,"KEYWORD");
            $$->add_child(tempnode);
        }
        | RETURN testlist_star_expr     {  
            $$ = new node("return_stmt");
            node* tempnode;
            tempnode= new node("return",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($2);
        }
        ;   

global_stmt: GLOBAL NAME    {  
            $$ = new node("global_stmt");
            node* tempnode;
            tempnode= new node("global",true,"KEYWORD");
            $$->add_child(tempnode);
            string s($2);
            tempnode= new node(s,true,"ID");
            $$->add_child(tempnode);
        }
        | GLOBAL NAME comma_name_star {   
            $$ = new node("global_stmt");
            node* tempnode;
            tempnode= new node("global",true,"KEYWORD");
            $$->add_child(tempnode);
            string s($2);
            tempnode= new node(s,true,"ID");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ;
nonlocal_stmt: NONLOCAL NAME     { 
            $$ = new node("nonlocal_stmt");
            node* tempnode;
            tempnode= new node("nonlocal",true,"KEYWORD");
            $$->add_child(tempnode);
            string s($2);
            tempnode= new node(s,true,"ID");
            $$->add_child(tempnode);
            
        }
        | NONLOCAL NAME comma_name_star {  
            $$ = new node("nonlocal_stmt");
            node* tempnode;
            tempnode= new node("nonlocal",true,"KEYWORD");
            $$->add_child(tempnode);
            string s($2);
            tempnode= new node(s,true,"ID");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ;    
        
assert_stmt: ASSERT test  {  
            $$ = new node("assert_stmt");
            node* tempnode;
            tempnode= new node("assert",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($2);
        }
        | ASSERT test comma_test  {  
            $$ = new node("assert_stmt");
            node* tempnode;
            tempnode= new node("assert",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($2);
            $$->add_child($3);
        }
        ;
comma_name_star: COMMA NAME    {  
            $$ = new node("comma_name_star");
            node* tempnode;
            tempnode= new node(",",true,"DELIMITER");
            $$->add_child(tempnode);
            string s($2);
            tempnode= new node(s,true,"ID");
            $$->add_child(tempnode);
        }
        | COMMA NAME comma_name_star    {  
            $$ = new node("comma_name_star");
            node* tempnode;
            tempnode= new node(",",true,"DELIMITER");
            $$->add_child(tempnode);
            string s($2);
            tempnode= new node(s,true,"ID");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ;
compound_stmt: if_stmt      { 
            $$ = new node("compound_stmt");
            $$->add_child($1);
        }
        | while_stmt   {  
            $$ = new node("compound_stmt");
            $$->add_child($1);
        }
        | for_stmt     {  
            $$ = new node("compound_stmt");
            $$->add_child($1);
        }
        | funcdef      {  
            $$ = new node("compound_stmt");
            $$->add_child($1);
        }
        | classdef     {  
            $$ = new node("compound_stmt");
            $$->add_child($1);
        }
        | async_stmt   {  
            $$ = new node("compound_stmt");
            $$->add_child($1);
        }
        ;
async_stmt: ASYNC async_choice  {  
            $$ = new node("async_stmt");
            node* tempnode;
            tempnode= new node("async",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($2);
        }
        ;
async_choice : funcdef  { 
            $$ = new node("async_choice");
            $$->add_child($1);
        }
        | for_stmt  {  
            $$ = new node("async_choice");
            $$->add_child($1);
        }
        ;   

if_stmt: IF test COLON suite     {  
            $$ = new node("if_stmt");
            node* tempnode;
            tempnode= new node("if",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($2);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($4);
        }
        | IF test COLON suite ELSE COLON suite   {  
            $$ = new node("if_stmt");
            node* tempnode;
            tempnode= new node("if",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($2);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($4);
            tempnode= new node("else",true,"KEYWORD");
            $$->add_child(tempnode);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($7);
        }
        | IF test COLON suite nts_star    {  
            $$ = new node("if_stmt");
            node* tempnode;
            tempnode= new node("if",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($2);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($4);
            $$->add_child($5);
        }
        | IF test COLON suite nts_star ELSE COLON suite   {
            $$ = new node("if_stmt");
            node* tempnode;
            tempnode= new node("if",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($2);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($4);
            $$->add_child($5);
            tempnode= new node("else",true,"KEYWORD");
            $$->add_child(tempnode);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($8);
        }
        ;
while_stmt: WHILE test COLON suite   {  
            $$ = new node("while_stmt");
            node* tempnode;
            tempnode= new node("while",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($2);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($4);
        }
        | WHILE test COLON suite ELSE COLON suite  {   
            $$ = new node("while_stmt");
            node* tempnode;
            tempnode= new node("while",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($2);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($4);
            tempnode= new node("else",true,"KEYWORD");
            $$->add_child(tempnode);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($7);
        }
        ;
for_stmt: FOR exprlist IN testlist COLON suite    { 
            $$ = new node("for_stmt");
            node* tempnode;
            tempnode= new node("for",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($2);
            tempnode= new node("in",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($4);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($6);
        }
        | FOR exprlist IN testlist COLON suite ELSE COLON suite   { 
            $$ = new node("for_stmt");
            node* tempnode;
            tempnode= new node("for",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($2);
            tempnode= new node("in",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($4);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($6);
            tempnode= new node("else",true,"KEYWORD");
            $$->add_child(tempnode);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($9);
        }
        ;
suite: simple_stmt  { 
            $$ = new node("suite");
            $$->add_child($1);
        }
        | NEWLINE INDENT stmt_plus DEDENT   { 
            $$ = new node("suite");
            node* tempnode;
            tempnode= new node("newline",true,"newline");
            $$->add_child(tempnode);
            tempnode= new node("indent",true,"indent");
            $$->add_child(tempnode);
            $$->add_child($3);
            tempnode= new node("dedent",true,"dedent");
            $$->add_child(tempnode);
        }
        | NEWLINE INDENT stmt_plus NEWLINE DEDENT   { 
            $$ = new node("suite");
            node* tempnode;
            tempnode= new node("newline",true,"newline");
            $$->add_child(tempnode);
            tempnode= new node("indent",true,"indent");
            $$->add_child(tempnode);
            $$->add_child($3);
            tempnode= new node("newline",true,"newline");
            $$->add_child(tempnode);
            tempnode= new node("dedent",true,"dedent");
            $$->add_child(tempnode);
        }
        ;

nts_star : ELIF test COLON suite  {  
            $$ = new node("nts_star");
            node* tempnode;
            tempnode= new node("elif",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($2);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($4);
        }
        | ELIF test COLON suite nts_star  {  
            $$ = new node("nts_star");
            node* tempnode;
            tempnode= new node("elif",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($2);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($4);
            $$->add_child($5);
        }
        ;
test: or_test   { 
            $$ = new node("test");
            $$->add_child($1);
        }
        | or_test IF or_test ELSE test  {  
            $$ = new node("test");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node("if",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($3);
            tempnode= new node("else",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($5);
        }
        ;
or_test: and_test    { 
            $$ = new node("or_test");
            $$->add_child($1);
        }
        | and_test_star OR and_test    {  
            $$ = new node("or_test");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node("or",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ;
and_test_star : and_test_star OR and_test {
            $$ = new node("and_test_star");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node("or",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        | and_test   { 
            $$ = new node("and_test_star");
            $$->add_child($1);
        }
        ;

and_test: not_test  {
            $$ = new node("and_test");
            $$->add_child($1);
        }
        | not_test_star AND not_test    {  
            $$ = new node("and_test");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node("and",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ;
not_test_star : not_test_star AND not_test  { 
            $$ = new node("not_test_star");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node("and",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        | not_test   { 
            $$ = new node("not_test_star");
            $$->add_child($1);
        }
        ;

not_test: NOT not_test   { 
            $$ = new node("not_test");
            node* tempnode;
            tempnode= new node("not",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($2);
        }
        | comparison    { 
            $$ = new node("not_test");
            $$->add_child($1);
        }
        ;

comparison: expr  {
            $$ = new node("comparison");
            $$->add_child($1);
        }
        | expr comp_op comparison  { 
            $$ = new node("comparison");
            $$->add_child($1);
            $$->add_child($2);
            $$->add_child($3);
        }
        ;

comp_op: LESS_THAN  {
        $$ = new node("comp_op");
        node* tempnode;
        tempnode= new node("<",true,"DELIMITER");
        $$->add_child(tempnode);
    }
    | GREATER_THAN  { 
        $$ = new node("comp_op");
        node* tempnode;
        tempnode= new node(">",true,"DELIMITER");
        $$->add_child(tempnode);
     }
    | EQUAL_EQUAL   { 
        $$ = new node("comp_op");
        node* tempnode;
        tempnode= new node("==",true,"DELIMITER");
        $$->add_child(tempnode);
     }
    | GREATER_THAN_EQUAL    { 
        $$ = new node("comp_op");
        node* tempnode;
        tempnode= new node(">=",true,"DELIMITER");
        $$->add_child(tempnode);
     }
    | LESS_THAN_EQUAL   {
        $$ = new node("comp_op");
        node* tempnode;
        tempnode= new node("<=",true,"DELIMITER");
        $$->add_child(tempnode);
     }
    | NOT_EQUAL_ARROW   {
        $$ = new node("comp_op");
        node* tempnode;
        tempnode= new node("<>",true,"DELIMITER");
        $$->add_child(tempnode);
      }
    | NOT_EQUAL    {
        $$ = new node("comp_op");
        node* tempnode;
        tempnode= new node("!=",true,"DELIMITER");
        $$->add_child(tempnode);
     }
    | IN    {  
        $$ = new node("comp_op");
        node* tempnode;
        tempnode= new node("in",true,"KEYWORD");
        $$->add_child(tempnode);
    }
    | NOT IN    { 
        $$ = new node("comp_op");
        node* tempnode;
        tempnode= new node("not",true,"KEYWORD");
        $$->add_child(tempnode);
        tempnode= new node("in",true,"KEYWORD");
        $$->add_child(tempnode);
     }
    | IS    { 
        $$ = new node("comp_op");
        node* tempnode;
        tempnode= new node("is",true,"KEYWORD");
        $$->add_child(tempnode);
     }
    | IS NOT    { 
        $$ = new node("comp_op");
        node* tempnode;
        tempnode= new node("is",true,"KEYWORD");
        $$->add_child(tempnode);
        tempnode= new node("not",true,"KEYWORD");
        $$->add_child(tempnode);
     }
    ;

star_expr: MULTIPLY expr    { 
            $$ = new node("star_expr");
            node* tempnode;
            tempnode= new node("*",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($2);
        }
        ;

expr: xor_expr    { 
            $$ = new node("expr");
            $$->add_child($1);
        }
        | xor_expr BIT_OR expr    {  
            $$ = new node("expr");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node("|",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ;

xor_expr: and_expr { 
            $$ = new node("xor_expr");
            $$->add_child($1);
        }
        | and_expr BIT_XOR xor_expr    {  
            $$ = new node("xor_expr");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node("^",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ;

and_expr: shift_expr   { 
            $$ = new node("and_expr");
            $$->add_child($1);
        }
        | shift_expr BIT_AND and_expr   {  
            $$ = new node("and_expr");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node("&",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ;

shift_expr: arith_expr   { 
                $$ = new node("shift_expr");
                $$->add_child($1);
            }
            | arith_expr SHIFT_OPER shift_expr   { 
                $$ = new node("shift_expr");
                $$->add_child($1);
                node* tempnode;
                string s($2);
                tempnode= new node(s,true,"DELIMITER");
                $$->add_child(tempnode);
                $$->add_child($3);
             }
        ;

arith_expr: term { 
                $$ = new node("arith_expr");
                $$->add_child($1);
            }
            | arith_expr PLUS term { 
                $$ = new node("arith_expr");
                $$->add_child($1);
                node* tempnode;
                tempnode= new node("+",true,"DELIMITER");
                $$->add_child(tempnode);
                $$->add_child($3);
            }
            | arith_expr MINUS term { 
                $$ = new node("arith_expr");
                $$->add_child($1);
                node* tempnode;
                tempnode= new node("-",true,"DELIMITER");
                $$->add_child(tempnode);
                $$->add_child($3);
             }
        ;
term: factor {
            $$ = new node("term");
            $$->add_child($1);
        }
        | term term_choice factor {
            $$ = new node("term");
            $$->add_child($1);
            $$->add_child($2);
            $$->add_child($3);
         }
        ;

term_choice : MULTIPLY      { 
            $$ = new node("term_choice");
            node* tempnode;
            tempnode= new node("*",true,"DELIMITER");
            $$->add_child(tempnode);
        }
        |ATTHERATE      { 
            $$ = new node("term_choice");
            node* tempnode;
            tempnode= new node("@",true,"DELIMITER");
            $$->add_child(tempnode);
        }
        |DIVIDE         { 
            $$ = new node("term_choice");
            node* tempnode;
            tempnode= new node("/",true,"DELIMITER");
            $$->add_child(tempnode);
        }
        |REMAINDER      { 
            $$ = new node("term_choice");
            node* tempnode;
            tempnode= new node("%",true,"DELIMITER");
            $$->add_child(tempnode);
        }
        |FLOOR_DIV_OPER    { 
            $$ = new node("term_choice");
            node* tempnode;
            tempnode= new node("//",true,"DELIMITER");
            $$->add_child(tempnode);
        }
        ;

factor: factor_choice factor        {  
            $$ = new node("factor");
            $$->add_child($1);
            $$->add_child($2);
        }
        | power     { 
            $$ = new node("factor");
            $$->add_child($1);
        }
        ;
factor_choice : PLUS        {
            $$ = new node("factor_choice");
            node* tempnode;
            tempnode= new node("+",true,"DELIMITER");
            $$->add_child(tempnode);
        }
        | MINUS      { 
            $$ = new node("factor_choice");
            node* tempnode;
            tempnode= new node("-",true,"DELIMITER");
            $$->add_child(tempnode);
        }
        | NEGATION   { 
            $$ = new node("factor_choice");
            node* tempnode;
            tempnode= new node("~",true,"DELIMITER");
            $$->add_child(tempnode);
        }
        ;
power: atom_expr        { 
            $$ = new node("power");
            $$->add_child($1);
        }
        | atom_expr POWER_OPERATOR factor   { 
            $$ = new node("power");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node("**",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ;

atom_expr: atom {  
            $$ = new node("atom_expr");
            $$->add_child($1);
        }
        | atom_expr trailer {  
            $$ = new node("atom_expr");
            $$->add_child($1);
            $$->add_child($2);
        }
        | atom_expr DOT NAME { 
            $$ = new node("atom_expr");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(".",true,"DELIMITER");
            $$->add_child(tempnode);
            string s($3);
            tempnode= new node(s,true,"ID");
            $$->add_child(tempnode);
        }
        ;

atom: OPEN_BRACKET testlist_comp CLOSE_BRACKET  { 
        $$ = new node("atom");
        node* tempnode;
        tempnode= new node("(",true,"DELIMITER");
        $$->add_child(tempnode);
        $$->add_child($2);
        tempnode= new node(")",true,"DELIMITER");
        $$->add_child(tempnode);
    }
    | OPEN_BRACKET CLOSE_BRACKET    {
        $$ = new node("atom");
        node* tempnode;
        tempnode= new node("(",true,"DELIMITER");
        $$->add_child(tempnode);
        tempnode= new node(")",true,"DELIMITER");
        $$->add_child(tempnode);
    }
    | SQUARE_OPEN testlist_comp SQUARE_CLOSE    { 
        $$ = new node("atom");
        node* tempnode;
        tempnode= new node("[",true,"DELIMITER");
        $$->add_child(tempnode);
        $$->add_child($2);
        tempnode= new node("]",true,"DELIMITER");
        $$->add_child(tempnode);
    }
    | SQUARE_OPEN SQUARE_CLOSE  {
        $$ = new node("atom");
        node* tempnode;
        tempnode= new node("[",true,"DELIMITER");
        $$->add_child(tempnode);
        tempnode= new node("]",true,"DELIMITER");
        $$->add_child(tempnode);
     }
    | CURLY_OPEN dictorsetmaker CURLY_CLOSE     { 
        $$ = new node("atom");
        node* tempnode;
        tempnode= new node("{",true,"DELIMITER");
        $$->add_child(tempnode);
        $$->add_child($2);
        tempnode= new node("}",true,"DELIMITER");
        $$->add_child(tempnode);
    }
    | CURLY_OPEN CURLY_CLOSE    { 
        $$ = new node("atom");
        node* tempnode;
        tempnode= new node("{",true,"DELIMITER");
        $$->add_child(tempnode);
        tempnode= new node("}",true,"DELIMITER");
        $$->add_child(tempnode);
     }
    | NAME      {
        $$ = new node("atom");
        node* tempnode;
        string s($1);
        tempnode= new node(s,true,"ID");
        $$->add_child(tempnode);
     }
    | NUMBER        { 
        $$ = new node("atom");
        node* tempnode;
        string s($1);
        tempnode= new node(s,true,"NUMBER");
        $$->add_child(tempnode);
    }
    | STRING_PLUS       { 
        $$ = new node("atom");
        $$->add_child($1);
    }
    | ATOM_KEYWORDS     { 
        $$ = new node("atom");
        node* tempnode;
        string s($1);
        tempnode= new node(s,true,"KEYWORD");
        $$->add_child(tempnode);
    }
    | TYPE_HINT     { 
        $$ = new node("atom");
        node* tempnode;
        string s($1);
        tempnode= new node(s,true,"TYPE_HINT");
        $$->add_child(tempnode);
     }
    ;
STRING_PLUS: STRING     {
            $$ = new node("STRING_PLUS");
            node* tempnode;
            string s($1);
            tempnode= new node(s,true,"STRING");
            $$->add_child(tempnode);
        }
        | STRING STRING_PLUS    { 
            $$ = new node("STRING_PLUS");
            node* tempnode;
            string s($1);
            tempnode= new node(s,true,"STRING");
            $$->add_child(tempnode);
            $$->add_child($2);
        }
        ;

testlist_comp: named_or_star comp_for       { 
            $$ = new node("testlist_comp");
            $$->add_child($1);
            $$->add_child($2);
        }
        | named_or_star_list    { 
            $$ = new node("testlist_comp");
            $$->add_child($1);
        }
        | named_or_star_list COMMA      { 
            $$ = new node("testlist_comp");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(",",true,"DELIMITER");
            $$->add_child(tempnode);
        }
        ;
named_or_star_list : named_or_star      { 
            $$ = new node("named_or_star_list");
            $$->add_child($1);
        }
        | named_or_star_list COMMA named_or_star    { 
            $$ = new node("named_or_star_list");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(",",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ; 
named_or_star : test    { 
            $$ = new node("named_or_star");
            $$->add_child($1);
        }
        | star_expr     { 
            $$ = new node("named_or_star");
            $$->add_child($1);
        }
        ;

trailer: OPEN_BRACKET CLOSE_BRACKET  { 
            $$ = new node("trailer");
            node* tempnode;
            tempnode= new node("(",true,"DELIMITER");
            $$->add_child(tempnode);
            tempnode= new node(")",true,"DELIMITER");
            $$->add_child(tempnode);
        }
        | OPEN_BRACKET arglist CLOSE_BRACKET  {
            $$ = new node("trailer");
            node* tempnode;
            tempnode= new node("(",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($2);
            tempnode= new node(")",true,"DELIMITER");
            $$->add_child(tempnode);
         }
        | SQUARE_OPEN subscriptlist SQUARE_CLOSE        {
            $$ = new node("trailer");
            node* tempnode;
            tempnode= new node("[",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($2);
            tempnode= new node("]",true,"DELIMITER");
            $$->add_child(tempnode);
         }
        ;

subscriptlist: subscriptlist_list      {
            $$ = new node("subscriptlist");
            $$->add_child($1);
        }
        | subscriptlist_list COMMA     { 
            $$ = new node("subscriptlist");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(",",true,"DELIMITER");
            $$->add_child(tempnode);
        }
        ;
subscriptlist_list: subscript       { 
            $$ = new node("subscriptlist_list");
            $$->add_child($1);
        }
        | subscriptlist_list COMMA subscript    { 
            $$ = new node("subscriptlist_list");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(",",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ;
subscript: test     { 
            $$ = new node("subscript");
            $$->add_child($1);
        }
        | COLON     {  
            $$ = new node("subscript");
            node* tempnode;
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
        }
        | COLON test     { 
            $$ = new node("subscript");
            node* tempnode;
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($2);
        }
        | test COLON     { 
            $$ = new node("subscript");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
        }
        | test COLON test     {
            $$ = new node("subscript");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ;
exprlist: expr_or_star_expr_list   {
            $$ = new node("exprlist");
            $$->add_child($1);
        }
        | expr_or_star_expr_list COMMA  { 
            $$ = new node("exprlist");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(",",true,"DELIMITER");
            $$->add_child(tempnode);
        }
        ;
expr_or_star_expr_list: expr_or_star_expr   { 
            $$ = new node("expr_or_star_expr_list");
            $$->add_child($1);
        }
        | expr_or_star_expr_list COMMA expr_or_star_expr    { 
            $$ = new node("expr_or_star_expr_list");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(",",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ;
expr_or_star_expr: expr         { 
            $$ = new node("expr_or_star_expr");
            $$->add_child($1);
        }
        | star_expr     { 
            $$ = new node("expr_or_star_expr");
            $$->add_child($1);
        }
        ;
testlist: testlist_list    { 
            $$ = new node("testlist");
            $$->add_child($1);
        }
        | testlist_list COMMA   {
            $$ = new node("testlist");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(",",true,"DELIMITER");
            $$->add_child(tempnode);
         }
        ;
testlist_list: test         {
            $$ = new node("testlist_list");
            $$->add_child($1);
        }
        | testlist_list COMMA test  { 
            $$ = new node("testlist_list");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(",",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ;   
dictorsetmaker: A comp_for   {
            $$ = new node("dictorsetmaker");
            $$->add_child($1);
            $$->add_child($2);
        }
        | A_list    { 
            $$ = new node("dictorsetmaker");
            $$->add_child($1);
        }
        | A_list COMMA    { 
            $$ = new node("dictorsetmaker");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(",",true,"DELIMITER");
            $$->add_child(tempnode);
        }
        | B comp_for       {
            $$ = new node("dictorsetmaker");
            $$->add_child($1);
            $$->add_child($2);
        }
        | B_list       {
            $$ = new node("dictorsetmaker");
            $$->add_child($1);
         }
        | B_list COMMA      { 
            $$ = new node("dictorsetmaker");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(",",true,"DELIMITER");
            $$->add_child(tempnode);
        }
        ;

A: test COLON test  { 
            $$ = new node("A");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
    | POWER_OPERATOR expr   { 
            $$ = new node("A");
            node* tempnode;
            tempnode= new node("**",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($2);
        }
    ;
A_list: A    { 
            $$ = new node("A_list");
            $$->add_child($1);
        }
        | A_list COMMA A    { 
            $$ = new node("A_list");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(",",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ;
B: test  {
            $$ = new node("B");
            $$->add_child($1);     
        }
        | star_expr     { 
            $$ = new node("B");
            $$->add_child($1);    
        }
        ;
B_list: B   { 
            $$ = new node("B_list");
            $$->add_child($1);
        }
        | B_list COMMA B    { 
            $$ = new node("B_list");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(",",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ;

classdef: CLASS NAME COLON suite      { 
            $$ = new node("classdef");
            node* tempnode;
            tempnode= new node("class",true,"KEYWORD");
            $$->add_child(tempnode);
            string s($2);
            tempnode= new node(s,true,"ID");
            $$->add_child(tempnode);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($4);
        }
        | CLASS NAME OPEN_BRACKET CLOSE_BRACKET COLON suite      { 
            $$ = new node("classdef");
            node* tempnode;
            tempnode= new node("class",true,"KEYWORD");
            $$->add_child(tempnode);
            string s($2);
            tempnode= new node(s,true,"ID");
            $$->add_child(tempnode);
            tempnode= new node("(",true,"DELIMITER");
            $$->add_child(tempnode);
            tempnode= new node(")",true,"DELIMITER");
            $$->add_child(tempnode);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($6);
        }
        | CLASS NAME OPEN_BRACKET arglist CLOSE_BRACKET COLON suite      { 
            $$ = new node("classdef");
            node* tempnode;
            tempnode= new node("class",true,"KEYWORD");
            $$->add_child(tempnode);
            string s($2);
            tempnode= new node(s,true,"ID");
            $$->add_child(tempnode);
            tempnode= new node("(",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($4);
            tempnode= new node(")",true,"DELIMITER");
            $$->add_child(tempnode);
            tempnode= new node(":",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($7);
        }
        ;

arglist: argument_list     { 
            $$ = new node("arglist");
            $$->add_child($1);
        }
        | argument_list COMMA    { 
            $$ = new node("arglist");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(",",true,"DELIMITER");
            $$->add_child(tempnode);
        }
        ;
argument_list: argument     { 
            $$ = new node("argument_list");
            $$->add_child($1);
        }
        | argument_list COMMA argument  { 
            $$ = new node("argument_list");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node(",",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        ;

argument: test  {
            $$ = new node("argument");
            $$->add_child($1);    
        }
        | test comp_for     {
            $$ = new node("argument");
            $$->add_child($1);
            $$->add_child($2);
        }
        | test EQUAL test   { 
            $$ = new node("argument");
            $$->add_child($1);
            node* tempnode;
            tempnode= new node("=",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($3);
        }
        | POWER_OPERATOR test   { 
            $$ = new node("argument");
            node* tempnode;
            tempnode= new node("**",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($2);
        }
        | MULTIPLY test     {  
            $$ = new node("argument");
            node* tempnode;
            tempnode= new node("*",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($2);
        }
        ;

comp_iter: comp_for     { 
            $$ = new node("comp_iter");
            $$->add_child($1);
        }
        | comp_if   { 
            $$ = new node("comp_iter");
            $$->add_child($1);
        }
        ;
sync_comp_for: FOR exprlist IN or_test      {
            $$ = new node("sync_comp_for");
            node* tempnode;
            tempnode= new node("for",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($2);
            tempnode= new node("in",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($4);
        }
        | FOR exprlist IN or_test comp_iter     { 
            $$ = new node("sync_comp_for");
            node* tempnode;
            tempnode= new node("for",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($2);
            tempnode= new node("in",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($4);
            $$->add_child($5);
        }
        ;
comp_for: sync_comp_for     {
            $$ = new node("comp_for");
            $$->add_child($1);
        }
        | ASYNC sync_comp_for   { 
            $$ = new node("comp_for");
            node* tempnode;
            tempnode= new node("async",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($2);
        }
        ;
comp_if: IF or_test         {
            $$ = new node("comp_if");
            node* tempnode;
            tempnode= new node("if",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($2);
        }
        | IF or_test comp_iter  { 
            $$ = new node("comp_if");
            node* tempnode;
            tempnode= new node("if",true,"KEYWORD");
            $$->add_child(tempnode);
            $$->add_child($2);
            $$->add_child($3);
        }
        ;
func_body_suite: simple_stmt    { 
            $$ = new node("func_body_suite");
            $$->add_child($1);
        }
        | NEWLINE INDENT stmt_plus DEDENT   { 
            $$ = new node("func_body_suite");
            node* tempnode;
            tempnode= new node("newline",true,"newline");
            $$->add_child(tempnode);
            tempnode= new node("indent",true,"indent");
            $$->add_child(tempnode);
            $$->add_child($3);
            tempnode= new node("dedent",true,"dedent");
            $$->add_child(tempnode);
        }
        | NEWLINE INDENT stmt_plus NEWLINE DEDENT   { 
            $$ = new node("func_body_suite");
            node* tempnode;
            tempnode= new node("newline",true,"newline");
            $$->add_child(tempnode);
            tempnode= new node("indent",true,"indent");
            $$->add_child(tempnode);
            $$->add_child($3);
            tempnode= new node("newline",true,"newline");
            $$->add_child(tempnode);
            tempnode= new node("dedent",true,"dedent");
            $$->add_child(tempnode);
        }
        ;

stmt_plus: stmt     {
            $$ = new node("stmt_plus");
            $$->add_child($1);
        
        }
        | stmt stmt_plus    { 
            $$ = new node("stmt_plus");
            $$->add_child($1);
            $$->add_child($2);
        }

comma_test: COMMA test  {
            $$ = new node("comma_test");
            node* tempnode;
            tempnode= new node(",",true,"DELIMITER");
            $$->add_child(tempnode);
            $$->add_child($2);
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
    print_ast();
    fclose(yyin); 
    return 0;

}