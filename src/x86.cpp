#include "data.h"
#include "symbol_table.cpp"

extern ste* global_sym_table;
extern vector<vector<string>> instructions;
ste* curr_func_ste;
vector<vector<string>> x86_code;

void stack_pos1(string b){
    if(curr_func_ste->offset_map.find(b)!= curr_func_ste->offset_map.end()){
        curr_func_ste->offset_map[b];
        x86_code.push_back({"\tmovq", to_string(curr_func_ste->offset_map[b])+"(%rbp)", ",", "%rax"});
    }
    else if(b==""){
        x86_code.push_back({"\tmovq", "$0", ",", "%rax"});
    }
    else {  //as of now, we are considering onyl constant value here
        x86_code.push_back({"\tmovq", "$"+b, ",", "%rax"});
    }
}

void stack_pos2(string c){
    if(curr_func_ste->offset_map.find(c)!= curr_func_ste->offset_map.end()){
        curr_func_ste->offset_map[c];
        x86_code.push_back({"\tmovq", to_string(curr_func_ste->offset_map[c])+"(%rbp)", ",", "%rcx"});
    }
    else {  //as of now, we are considering onyl constant value here
        x86_code.push_back({"\tmovq", "$"+c, ",", "%rcx"});
    }
}

void create_x86(){
    
    x86_code.push_back({".section", ".rodata"});
    x86_code.push_back({".note0:"});
    x86_code.push_back({"\t.string", "\"%ld\\n\""});
    x86_code.push_back({"\t.text"});
    x86_code.push_back({"\t.globl", "main"});

    for(int i=0; i<instructions.size(); i++){    
        if(instructions[i][0]=="1"){   //type 1 instruction     // a = b op c
            x86_code.push_back({"L"+to_string(i)+":"+"\n\t"});
            string a = instructions[i][1];
            string op = instructions[i][2];
            string b = instructions[i][3];
            string c = instructions[i][4];

            stack_pos1(b);
            stack_pos2(c);

            if(op == "+"){
                x86_code.push_back({"\taddq", "%rcx", ",", "%rax"});
                x86_code.push_back({"\tmovq", "%rax", ",", to_string(curr_func_ste->offset_map[a])+"(%rbp)"});
            }
            else if(op == "-"){
                x86_code.push_back({"\tsubq", "%rcx", ",", "%rax"});
                x86_code.push_back({"\tmovq", "%rax", ",", to_string(curr_func_ste->offset_map[a])+"(%rbp)"});
            }
            else if(op == "*"){
                x86_code.push_back({"\timulq", "%rcx", ",", "%rax"});
                x86_code.push_back({"\tmovq", "%rax", ",", to_string(curr_func_ste->offset_map[a])+"(%rbp)"});
            }
            else if(op == "/"){
                x86_code.push_back({"\tmovq", "$0", ",", "%rdx"});
                x86_code.push_back({"\tdivq", "%rcx"});
                x86_code.push_back({"\tmovq", "%rax", ",", to_string(curr_func_ste->offset_map[a])+"(%rbp)"});
            }
            else if(op == "%"){
                x86_code.push_back({"\tmovq", "$0", ",", "%rdx"});
                x86_code.push_back({"\tdivq", "%rcx"});
                x86_code.push_back({"\tmovq", "%rdx", ",", to_string(curr_func_ste->offset_map[a])+"(%rbp)"});
            }
            else if(op == "//"){    //same as division because float need not to be done
                x86_code.push_back({"\tmovq", "$0", ",", "%rdx"});
                x86_code.push_back({"\tdivq", "%rcx"});
                x86_code.push_back({"\tmovq", "%rax", ",", to_string(curr_func_ste->offset_map[a])+"(%rbp)"});
            }
            else if(op == "**"){
                x86_code.push_back({"\tmovq", "$1", ",", "%rdx"});
                x86_code.push_back({"\tmovq", "%rcx", ",", "%rbx"});
                x86_code.push_back({"\tcmpq", "$0", ",", "%rbx"});
                x86_code.push_back({"\tje", "L"+to_string(i)+":M"+to_string(i+2)});
                x86_code.push_back({"L"+to_string(i)+":M"+to_string(i+1)+":"});
                x86_code.push_back({"\timulq", "%rax", ",", "%rdx"});
                x86_code.push_back({"\tdecq", "%rbx"});
                x86_code.push_back({"\tcmpq", "$0", ",", "%rbx"});
                x86_code.push_back({"\tjne", "L"+to_string(i)+":M"+to_string(i+1)});
                x86_code.push_back({"L"+to_string(i)+":M"+to_string(i+2)+":"});
                x86_code.push_back({"\tmovq", "%rdx", ",", to_string(curr_func_ste->offset_map[a])+"(%rbp)"});
            }
            else if(op == "<<"){
                x86_code.push_back({"\tmovq", "%rcx", ",", "%rbx"});
                x86_code.push_back({"\tmovq", "%rax", ",", "%rdx"});
                x86_code.push_back({"\tmovq", "$0", ",", "%rcx"});
                x86_code.push_back({"\tcmpq", "%rbx", ",", "%rcx"});
                x86_code.push_back({"\tje", "L"+to_string(i)+":M"+to_string(i+2)});
                x86_code.push_back({"L"+to_string(i)+":M"+to_string(i+1)+":"});
                x86_code.push_back({"\tshlq", "$1", ",", "%rdx"});
                x86_code.push_back({"\tincq", "%rcx"});
                x86_code.push_back({"\tcmpq", "%rbx", ",", "%rcx"});
                x86_code.push_back({"\tjne", "L"+to_string(i)+":M"+to_string(i+1)});
                x86_code.push_back({"L"+to_string(i)+":M"+to_string(i+2)+":"});
                x86_code.push_back({"\tmovq", "%rdx", ",", to_string(curr_func_ste->offset_map[a])+"(%rbp)"});
            }
            else if(op == ">>"){
                x86_code.push_back({"\tmovq", "%rcx", ",", "%rbx"});
                x86_code.push_back({"\tmovq", "%rax", ",", "%rdx"});
                x86_code.push_back({"\tmovq", "$0", ",", "%rcx"});
                x86_code.push_back({"\tcmpq", "%rbx", ",", "%rcx"});
                x86_code.push_back({"\tje", "L"+to_string(i)+":M"+to_string(i+2)});
                x86_code.push_back({"L"+to_string(i)+":M"+to_string(i+1)+":"});
                x86_code.push_back({"\tshrq", "$1", ",", "%rdx"});
                x86_code.push_back({"\tincq", "%rcx"});
                x86_code.push_back({"\tcmpq", "%rbx", ",", "%rcx"});
                x86_code.push_back({"\tjne", "L"+to_string(i)+":M"+to_string(i+1)});
                x86_code.push_back({"L"+to_string(i)+":M"+to_string(i+2)+":"});
                x86_code.push_back({"\tmovq", "%rdx", ",", to_string(curr_func_ste->offset_map[a])+"(%rbp)"});
            }
            else if(op == "<"){
                x86_code.push_back({"\tcmpq", "%rax", ",", "%rcx"});
                x86_code.push_back({"\tsetl", "%al"});
                x86_code.push_back({"\tmovzbq", "%al", ",", "%rax"});
                x86_code.push_back({"\tmovq", "%rax", ",", to_string(curr_func_ste->offset_map[a])+"(%rbp)"});
            }
            else if(op == ">"){
                x86_code.push_back({"\tcmpq", "%rax", ",", "%rcx"});
                x86_code.push_back({"\tsetg", "%al"});
                x86_code.push_back({"\tmovzbq", "%al", ",", "%rax"});
                x86_code.push_back({"\tmovq", "%rax", ",", to_string(curr_func_ste->offset_map[a])+"(%rbp)"});
            }
            else if(op == "<="){
                x86_code.push_back({"\tcmpq", "%rax", ",", "%rcx"});
                x86_code.push_back({"\tsetle", "%al"});
                x86_code.push_back({"\tmovzbq", "%al", ",", "%rax"});
                x86_code.push_back({"\tmovq", "%rax", ",", to_string(curr_func_ste->offset_map[a])+"(%rbp)"});
            }
            else if(op == ">="){
                x86_code.push_back({"\tcmpq", "%rax", ",", "%rcx"});
                x86_code.push_back({"\tsetge", "%al"});
                x86_code.push_back({"\tmovzbq", "%al", ",", "%rax"});
                x86_code.push_back({"\tmovq", "%rax", ",", to_string(curr_func_ste->offset_map[a])+"(%rbp)"});
            }
            else if(op == "=="){
                x86_code.push_back({"\tcmpq", "%rax", ",", "%rcx"});
                x86_code.push_back({"\tsete", "%al"});
                x86_code.push_back({"\tmovzbq", "%al", ",", "%rax"});
                x86_code.push_back({"\tmovq", "%rax", ",", to_string(curr_func_ste->offset_map[a])+"(%rbp)"});
            }
            else if(op == "!="){
                x86_code.push_back({"\tcmpq", "%rax", ",", "%rcx"});
                x86_code.push_back({"\tsetne", "%al"});
                x86_code.push_back({"\tmovzbq", "%al", ",", "%rax"});
                x86_code.push_back({"\tmovq", "%rax", ",", to_string(curr_func_ste->offset_map[a])+"(%rbp)"});
            }
            else if(op == "<>"){    //same as !=
                x86_code.push_back({"\tcmpq", "%rax", ",", "%rcx"});
                x86_code.push_back({"\tsetne", "%al"});
                x86_code.push_back({"\tmovzbq", "%al", ",", "%rax"});
                x86_code.push_back({"\tmovq", "%rax", ",", to_string(curr_func_ste->offset_map[a])+"(%rbp)"});
            }
            else if(op == "&"){
                x86_code.push_back({"\tandq", "%rcx", ",", "%rax"});
                x86_code.push_back({"\tmovq", "%rax", ",", to_string(curr_func_ste->offset_map[a])+"(%rbp)"});
            }
            else if(op == "|"){
                x86_code.push_back({"\torq", "%rcx", ",", "%rax"});
                x86_code.push_back({"\tmovq", "%rax", ",", to_string(curr_func_ste->offset_map[a])+"(%rbp)"});
            }
            else if(op == "^"){
                x86_code.push_back({"\txorq", "%rcx", ",", "%rax"});
                x86_code.push_back({"\tmovq", "%rax", ",", to_string(curr_func_ste->offset_map[a])+"(%rbp)"});
            }
        }
        else{   //type 0 instruction

            // to get if instruction is a start of function
            // once check here, class ke functions are like class.funcname and here this doesnt work now
            if(instructions[i][1][instructions[i][1].size()-1] == ':'){
                string func_name="";
                for(int l=0;l<instructions[i][1].size()-1;l++){
                    func_name.push_back(instructions[i][1][l]);
                }   
                curr_func_ste=single_rev_lookup(global_sym_table,func_name);
                x86_code.push_back({func_name+":\n"});
            }

            else if(instructions[i][1]=="BeginFunc"){
                //nothing needs to be done here
            }

            else if(instructions[i][2]=="RBP"){
                x86_code.push_back({"\tpush", "%rbp"});
                x86_code.push_back({"\tmovq", "%rsp", ",", "%rbp"}); 
                x86_code.push_back({"\tsubq", "$"+to_string(curr_func_ste->stack_width), ",", "%rsp"});
            }

            else if(instructions[i][3]=="PopParam"){
                //ignore
            }

            else if(instructions[i][1]=="StackPointer"){
                //ignore
            }

            else if(instructions[i][1]=="return"){  //handle return None
                stack_pos2(instructions[i][2]);
                x86_code.push_back({"\tmovq", "%rcx", ",", "%r8"}); //r8 register stores the return value
            }

            else if(instructions[i][1]=="goto" && instructions[i][2]=="ra"){
                x86_code.push_back({"\taddq", "$"+to_string(curr_func_ste->stack_width), ",", "%rsp"});
                x86_code.push_back({"\tpop", "%rbp"});
                x86_code.push_back({"\tret"});
            }

            else if(instructions[i][1]=="PopParamAll"){ 
                int num_params = stoi(instructions[i][2]);
                num_params = num_params*8;
                x86_code.push_back({"\taddq", "$"+to_string(num_params), ",", "%rsp"});
            }

            else if(instructions[i][1]=="PushParamra"){
                //nothing needs to be done, rip is counter register and it automatically updates
            }

            else if(instructions[i][1]=="PushParam"){
                stack_pos1(instructions[i][2]);
                x86_code.push_back({"\tpushq", "%rax"});
            }

            else if(instructions[i][1]=="PopParamra"){
                if(curr_func_ste!=NULL){
                    int this_offset = curr_func_ste->offset_map[instructions[i][2]];
                    x86_code.push_back({"\tmovq", "%r8", ",", to_string(this_offset)+"(%rbp)"});
                }
            }

            else if(instructions[i][2]=="print"){
                x86_code.push_back({"\tmovq", "16(%rbp)", ",", "%rsi"});
                x86_code.push_back({"\tlea", ".note0(%rip)",",", "%rax"});
                x86_code.push_back({"\tmovq", "%rax", ",", "%rdi"});
                x86_code.push_back({"\txor", "%rax", ",", "%rax"});
                x86_code.push_back({"\tcall", "printf@plt"}); 
            }

            else if(instructions[i][1]=="call"){
                x86_code.push_back({"\tcall", instructions[i][2]});
            }

            
            else if(instructions[i][2]=="="){
                //here also in if else you have to handle different types of c
                //handle swapped = false type
                stack_pos2(instructions[i][3]);
                x86_code.push_back({"\tmovq", "%rcx", ",", to_string(curr_func_ste->offset_map[instructions[i][1]])+"(%rbp)"});
            }

            //to see when funcends
            if(instructions[i][1]=="EndFunc"){
                curr_func_ste = NULL;
            }

            else if(instructions[i][1]=="EOF"){
                x86_code.push_back({"\t\tmov", "$60",",", "%rax"});
                x86_code.push_back({"\t\txor", "%rdi",",", "%rdi"});
                x86_code.push_back({"\t\tsyscall"});
            }
        }
    }


    x86_code.push_back({"format:\n\t.ascii", "\"%ld\\n\""});

    // Print the x86_code
    for(const auto& line : x86_code){
        for(const auto& part : line){
            cout << part << " ";
        }
        cout << endl;
    }

}