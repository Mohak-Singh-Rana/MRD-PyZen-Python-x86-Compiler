%{  
    /*definitions*/
    #include <bits/stdc++.h>
    #include "data.h"
//     #include "data.cpp"
//     #include "symbol_table.h"
    #include "symbol_table.cpp"
    using namespace std;

    extern int yylex();
    extern int yyparse();
    extern void yyrestart(FILE* file);
    extern FILE* yyin;
    extern int yylineno;
    extern char* yytext;
    void yyerror(string str);
    extern stack<int> indent_stack;

    int instCount;
    vector<vector<string>> instructions;
    vector<int> makelist(int i);
    void backpatch(vector<int> p, int i);
    void create_ins(int type,string i,string op,string arg1,string arg2);
    vector<int> merge(vector<int> p1, vector<int> p2);
    string newTemp();
    char* str_to_ch(string s);
    int tempCount;
    fstream code_out;

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
    struct node *elem;
}

%start file

%type<elem> M N file snippet stmt simple_stmt small_stmt_list small_stmt expr_stmt annassign eq_testlist_star_expr_plus flow_stmt break_stmt continue_stmt return_stmt global_stmt compound_stmt funcdef parameters typedargslist typedarg tfpdef if_stmt while_stmt for_stmt suite nts_star test or_test and_test not_test comparison comp_op expr xor_expr and_expr shift_expr arith_expr term term_choice factor factor_choice power atom_expr atom STRING_PLUS trailer classdef arglist argument_list argument testlist testlist_list comma_name_star and_test_star not_test_star func_body_suite stmt_plus
%token<elem> NEWLINE
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


M: %empty{
        $$ = create_node(1, "Marker Non-terminal M");
        $$->ins = instCount+1;
}
;

N: %empty{
        $$ = create_node(1, "Marker Non-terminal N");
        $$->nextlist = makelist(instCount+1);
        create_ins(0, "goto", "", "", "");
}
;

file: snippet {
                $$ = $1;
 }
         ;

snippet: NEWLINE {
       
    }
    | stmt  { 
        $$=$1;
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
        | tfpdef EQUAL test {  
            
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
             $$=$1; 
        }
        ;

simple_stmt: small_stmt_list SEMI_COLON NEWLINE {  
            $$=$1;
        }
        | small_stmt_list  NEWLINE {  
            $$=$1;
        }
        ; 

small_stmt_list: small_stmt     {   
            $$=$1;
        }
        | small_stmt_list SEMI_COLON small_stmt      {  
           
        }
        ;

small_stmt: expr_stmt       {  
           $$=$1;
        }
        | flow_stmt     {  
           
        }
        | global_stmt       {  
            
        }
        ;

expr_stmt: test annassign {

        }
        | test ASSIGN_OPERATOR test {

        }
        | testlist {

        }
        | test EQUAL eq_testlist_star_expr_plus{
                create_node(4, "eq_testlist_star_expr_plus", $1, $2, $3);
		$$->ins = $1->ins;
		create_ins(0, $1->addr, $2->addr, $3->addr, "");
        }
        ;

eq_testlist_star_expr_plus: test {
                $$=$1;
        }
        | test EQUAL eq_testlist_star_expr_plus{
                create_node(4, "eq_testlist_star_expr_plus", $1, $2, $3);
		$$->ins = $1->ins;
		create_ins(0, $1->addr, $2->addr, $3->addr, "");
        }
        ;

annassign: COLON test {

        }
        | COLON test EQUAL test{
                
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
        | RETURN test     {  
           
        }
        ;   

global_stmt: GLOBAL NAME    {  
            
        }
        | GLOBAL NAME comma_name_star {   
            
        }
        ;

comma_name_star: COMMA NAME    {  
           
        }
        | COMMA NAME comma_name_star    {  
            
        }
        ;
compound_stmt: if_stmt      { 
            $$=$1;  
        }
        | while_stmt   {  
           
        }
        | for_stmt     {  
            
        }
        | funcdef      {  
            
        }
        | classdef     {  
           
        }
        ;  

if_stmt: IF test COLON M suite     {  
           $$=create_node(6, "if_stmt", $1, $2, $3, $4, $5);
           $$->ins = $2->ins;
           backpatch($2->truelist, $4->ins);
           $$->nextlist = merge($2->falselist, $5->nextlist);
        }
        | IF test COLON M suite N ELSE COLON M suite   {  
            $$ = create_node(11, "if_else_stmt", $1, $2, $3, $4, $5, $6, $7, $8, $9, $10);
            backpatch($2->truelist, $4->ins);
            backpatch($2->falselist, $9->ins);
            vector<int> temp = merge($5->nextlist, $6->nextlist);
            $$->nextlist = merge(temp, $10->nextlist);
        }
        | IF test COLON M suite N nts_star    {  
            $$ = create_node(8, "if_elif_stmt", $1, $2, $3, $4, $5, $6, $7);
            backpatch($2->truelist, $4->ins);
            backpatch($2->falselist, $7->ins);     
            vector<int> temp = merge($5->nextlist, $6->nextlist);
            $$->nextlist = merge(temp, $7->nextlist);
        }
        ;
while_stmt: WHILE M test COLON M suite   {  
            $$ = create_node(7, "while_stmt", $1, $2, $3, $4, $5, $6);
            $$->ins = $2->ins;
            backpatch($6->nextlist, $2->ins);
            backpatch($3->truelist, $5->ins);
            $$->nextlist = $3->falselist;
            create_ins(0, "goto", to_string($2->ins), "", "");
        }
		| WHILE M test COLON M suite N ELSE COLON M suite  {   
			$$ = create_node(12, "while_else_stmt", $1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11);
			$$->ins = $2->ins;
			backpatch($7->nextlist, $2->ins);
			backpatch($6->nextlist, $2->ins);
			backpatch($3->truelist, $5->ins);
			backpatch($3->falselist, $10->ins);
			$$->nextlist = merge($7->nextlist, $11->nextlist); //verify
        }
        ;
for_stmt: FOR expr IN testlist COLON suite    { 
            $$ = create_node(7, "for_stmt", $1, $2, $3, $4, $5, $6);
            $$->ins = $2->ins;

        }
        | FOR expr IN testlist COLON suite ELSE COLON suite   { 
            
        }
        ;
suite: simple_stmt  { 
            $$=$1;
        }
        | NEWLINE INDENT stmt_plus DEDENT   { 
            $$=$3;
        }
        | NEWLINE INDENT stmt_plus NEWLINE DEDENT   { 
            $$=$3;
        }
        ;

nts_star : ELIF test COLON M suite  {  
            $$=create_node(6, "elif_stmt", $1, $2, $3, $4, $5);
            $$->ins = $2->ins;
            backpatch($2->truelist, $4->ins);
            $$->nextlist = merge($2->falselist, $5->nextlist);
        }
        | ELIF test COLON M suite N nts_star  {  
            $$ = create_node(8, "elif_stmt", $1, $2, $3, $4, $5, $6, $7);
            $$->ins = $2->ins;
            backpatch($2->truelist, $4->ins);
            backpatch($2->falselist, $7->ins);
            $$->nextlist = merge($5->nextlist, merge($6->nextlist, $7->nextlist));
        }
        | ELIF test COLON M suite N ELSE COLON M suite  {  
            $$ = create_node(11, "elif_else_stmt", $1, $2, $3, $4, $5, $6, $7, $8, $9, $10);
            $$->ins = $2->ins;
            backpatch($2->truelist, $4->ins);
            backpatch($2->falselist, $9->ins);
            $$->nextlist = merge($5->nextlist, merge($6->nextlist,$10->nextlist));
        }
        ;

test: or_test   { 
            $$=$1;
        }
        /* | or_test IF or_test ELSE test  {  
            
        } */
        ;
or_test: and_test    { 
            $$=$1;
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
            $$=$1;
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
            $$=$1;
            
        }
;

comparison: expr  {
            $$=$1;
        }
        | expr comp_op comparison  { 
            $$=create_node(4, "comparison", $1, $2, $3);
            $$->ins = $1->ins;
            $$->addr = str_to_ch(newTemp());
            create_ins(1, $$->addr, $2->addr, $1->addr, $3->addr);
            $$->truelist = makelist(instCount+1);
            $$->falselist = makelist(instCount+2);
            create_ins(0, "if", $$->addr, "goto", "");
            create_ins(0, "goto", "", "", "");
            
        }
;

comp_op: LESS_THAN  {
        $$ = $1;
    }
    | GREATER_THAN  { 
       $$ = $1;
     }
    | EQUAL_EQUAL   { 
        $$ = $1;
     }
    | GREATER_THAN_EQUAL    { 
        $$ = $1;
     }
    | LESS_THAN_EQUAL   {
        $$ = $1;
     }
    | NOT_EQUAL_ARROW   {
        $$ = $1;
      }
    | NOT_EQUAL    {
       $$ = $1;
     }
    | IN    {  
        $$ = $1;
    }
    | NOT IN    { 
        $$ = create_node(3, "NOT IN", $1, $2);
     }
    | IS    { 
        $$ = $1;
     }
    | IS NOT    { 
        $$ = create_node(3, "IS NOT", $1, $2);
     }
    ;

expr: xor_expr    { 
            $$=$1;
        }
        | xor_expr BIT_OR expr    {  
            
        }
        ;

xor_expr: and_expr { 
            $$ = $1;
        }
        | and_expr BIT_XOR xor_expr    {  
            
        }
        ;

and_expr: shift_expr   { 
            $$ = $1;
            
        }
        | shift_expr BIT_AND and_expr   {  
            
        }
        ;

shift_expr: arith_expr   { 
            $$ = $1;
                
            }
            | arith_expr SHIFT_OPER shift_expr   { 
                
             }
        ;

arith_expr: term { 
            $$ = $1;
                
            }
            | arith_expr PLUS term { 
                
            }
            | arith_expr MINUS term { 
                
             }
        ;
term: factor {
            $$ = $1;
            
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
            $$ = $1;
            
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
            $$ = $1;
            
        }
        | atom_expr POWER_OPERATOR factor   { 
            
        }
        ;

atom_expr: atom {  
            $$ = $1;
            
        }
        | atom_expr trailer {  
            
        }
        | atom_expr DOT NAME { 
            
        }
        ;

atom: OPEN_BRACKET testlist CLOSE_BRACKET  { 
        $$=$2;
    }
    | OPEN_BRACKET CLOSE_BRACKET    {
        
    }
    | SQUARE_OPEN testlist SQUARE_CLOSE    { 
        
    }
    | SQUARE_OPEN SQUARE_CLOSE  {
        
     }
    | CURLY_OPEN CURLY_CLOSE    { 
        
     }
    | NAME      {
        $$ = $1;
        $$->ins = instCount+1;
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

trailer: OPEN_BRACKET CLOSE_BRACKET  { 
            
        }
        | OPEN_BRACKET arglist CLOSE_BRACKET  {
            
        }
        | SQUARE_OPEN test SQUARE_CLOSE{

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
        | test EQUAL test   { 
            
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
            $$=$1;
        }
        | stmt stmt_plus    { 
            $$=create_node(3,"stmt_plus",$1,$2);
			$$->ins = $1 -> ins;
        }

%%

void yyerror(string str){
    fprintf(stderr, "Error: %s at line number %d offending token: %s\n", str.c_str(), yylineno, yytext);
    exit(1);
}

char* str_to_ch(string s)
{
	char* result_chr = new char[s.size()+1];
	strcpy(result_chr,s.c_str());
	return result_chr;
}

vector<int> makelist(int i){
	return vector<int>{i};
}

void create_ins(int type,string i,string op,string arg1,string arg2){
	vector<string> instruction{to_string(type),i,op,arg1,arg2};
	instructions.push_back(instruction);
	instCount++;
}

void backpatch(vector<int>p, int i){
	for(int j=0;j<p.size();j++)
		instructions[p[j]-1].push_back(to_string(i));
}

vector<int> merge(vector<int> p1, vector<int> p2){
        vector<int> merged;
        merged.reserve(p1.size() + p2.size());
        merged.insert(merged.end(), p1.begin(), p1.end());
        merged.insert(merged.end(), p2.begin(), p2.end());
	return merged;
}

string newTemp(){
	return "t"+to_string(tempCount++);
}

void MakeIRFile()
{
	int tabs=0;
	for(int i=0;i<instructions.size();i++)
	{
		if(instructions[i][1]=="EndFunc") tabs--;
		cout << i+1 << "\t" << string(tabs,'\t');
		code_out << i+1 << "\t" << string(tabs,'\t');
		if(instructions[i][0]=="0")
		{
			for(int j=1;j<instructions[i].size();j++)
			{
				cout << instructions[i][j] << (instructions[i][j].length()?" ":"");
				code_out << instructions[i][j] << (instructions[i][j].length()?" ":"");
			}
			if(instructions[i][1]=="BeginFunc") tabs++;
		}
		else
		{
			cout << instructions[i][1] << " = " << instructions[i][3] << " " << instructions[i][2] << " " << instructions[i][4];
			code_out << instructions[i][1] << " = " << instructions[i][3] << " " << instructions[i][2] << " " << instructions[i][4];
		}
		cout << endl;
		code_out << endl;
	}
}

int main(int argc, char* argv[]){    
    /* cout<<"Hello\n"; */
    FILE* yyin = fopen(argv[1],"r");
    yyrestart(yyin); 

    /* bool inset = false, outset = false; */
    indent_stack.push(0);

    /* for (int i=0; i< argc; i++){
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
    }  */

/*--------------------------------------------------------------*/

        // Open the output file
        /* fout.open(output_file.c_str(),ios::out); */
        code_out.open("./output/3AC.txt",ios::out);
        // Get the DOT file template from the file
        /* ifstream infile("./DOT_Template.txt"); */
        /* string line; */
        /* while (getline(infile, line)) */
                /* fout << line << endl; */

/*--------------------------------------------------------------*/

    instCount=0;
    tempCount=0;
    yydebug=1;
    /* cout<<"Parsing Started\n"; */
    yyparse();
    fclose(yyin); 

/*--------------------------------------------------------------*/

// Create 3AC file
    MakeIRFile();

// Close the output file
    code_out.close();

/*--------------------------------------------------------------*/
    return 0;

}