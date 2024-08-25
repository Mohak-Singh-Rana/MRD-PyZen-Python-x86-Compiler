#include "data.h"
#include "symbol_table.cpp"

extern ste* global_sym_table;
extern vector<vector<string>> instructions;
ste* curr_func_ste;
vector<vector<string>> x86_code;
int str_cnt = 0;
int str_temp=0;
string str_name="";

map<string,string> str_map;


void stack_pos2(string c){  //r12
    if(curr_func_ste->offset_map.find(c)!= curr_func_ste->offset_map.end()){
        curr_func_ste->offset_map[c];
        x86_code.push_back({"\tmovq", to_string(curr_func_ste->offset_map[c])+"(%rbp)", ",", "%r12"});
    }
    else if(c=="True"){
        x86_code.push_back({"\tmovq", "$1", ",", "%r12"});
    }
    else if(c=="False"){
        x86_code.push_back({"\tmovq", "$0", ",", "%r12"});
    }
    else if(c.find('\"') != string::npos){
        string s = c.substr(1, c.size() - 2);  //removed the quotes
        str_cnt++;
        str_temp=1;
        str_name = s;      
    }
    else if(c==""){
        x86_code.push_back({"\tmovq", "$0", ",", "%r12"});
    }
    else if(c.find('[')!=string::npos){
        size_t pos = c.find('[');

        // Extract the array name and the index
        string arrayName = c.substr(0, pos);
        string index = c.substr(pos + 1, c.size() - pos - 2);

        stack_pos2(index);
        x86_code.push_back({"\taddq", "$8", ",", "%r12"});
        x86_code.push_back({"\tmovq", "%r12", ",", "%r10"}); 
        stack_pos2(arrayName);
        x86_code.push_back({"\taddq", "%r10", ",", "%r12"}); 
        x86_code.push_back({"\tmovq", "0(%r12)", ",", "%r12"}); 
    }
    else {  //as of now, we are considering onyl constant value here
        x86_code.push_back({"\tmovq", "$"+c, ",", "%r12"});
    }
}

void stack_pos1(string b){  //r11
    if(curr_func_ste->offset_map.find(b)!= curr_func_ste->offset_map.end()){
        curr_func_ste->offset_map[b];
        x86_code.push_back({"\tmovq", to_string(curr_func_ste->offset_map[b])+"(%rbp)", ",", "%r11"});
    }
    else if(b=="True"){
        x86_code.push_back({"\tmovq", "$1", ",", "%r12"});
    }
    else if(b=="False"){
        x86_code.push_back({"\tmovq", "$0", ",", "%r12"});
    }
    else if(b==""){
        x86_code.push_back({"\tmovq", "$0", ",", "%r11"});
    }
    else if(b.find('\"') != string::npos){
        string s = b.substr(1, b.size() - 2);  //removed the quotes
        str_cnt++;
        str_temp=1;
        str_name = s;      
    }
    else if(b.find('[')!=string::npos){
        size_t pos = b.find('[');

        // Extract the array name and the index
        string arrayName = b.substr(0, pos);
        string index = b.substr(pos + 1, b.size() - pos - 2);

        stack_pos1(index);
        x86_code.push_back({"\taddq", "$8", ",", "%r11"});
        x86_code.push_back({"\tmovq", "%r11", ",", "%r9"}); 
        stack_pos1(arrayName);
        x86_code.push_back({"\taddq", "%r9", ",", "%r11"});
        x86_code.push_back({"\tmovq", "0(%r11)", ",", "%r11"});
    }
    else {  //as of now, we are considering onyl constant value here
        x86_code.push_back({"\tmovq", "$"+b, ",", "%r11"});
    }
}

void stack_pos_lhs(string b){   //r13
    if(b.find(':')!=string::npos){
        //cerr<<"in stackposlhs of "<<b<<endl;
        size_t pos = b.find(':');

        // Extract the array name and the index
        string stringName = b.substr(0, pos);

        stack_pos1(stringName);
        //cerr<<stringName<<endl;
        x86_code.push_back({"\tmovq", "%r11", ",", "%r13"});
    }

    else if(curr_func_ste->offset_map.find(b)!= curr_func_ste->offset_map.end()){
        //cerr<<"gadbad "<<b<<endl;
        //cerr<<curr_func_ste->offset_map[b]<<" "<<b<<endl;
        x86_code.push_back({"\tmovq", "%rbp", ",", "%r13"}); 
        if(curr_func_ste->offset_map[b]>0){
            x86_code.push_back({"\taddq", "$"+to_string(curr_func_ste->offset_map[b]), ",","%r13"});
        }
        else{
            x86_code.push_back({"\tsubq", "$"+to_string(-1*curr_func_ste->offset_map[b]), ",", "%r13"});
        }
    }
    else if(b.find('[')!=string::npos){
        size_t pos = b.find('[');

        // Extract the array name and the index
        string arrayName = b.substr(0, pos);
        string index = b.substr(pos + 1, b.size() - pos - 2);

        stack_pos1(index);
        x86_code.push_back({"\taddq", "$8", ",", "%r11"});
        x86_code.push_back({"\tmovq", "%r11", ",", "%r14"}); 
        stack_pos1(arrayName);
        x86_code.push_back({"\taddq", "%r14", ",", "%r11"});
        x86_code.push_back({"\tmovq", "%r11", ",", "%r13"});
    }
    
}

void create_x86(){    
    x86_code.push_back({".section", ".rodata"});
    x86_code.push_back({".note0:"});
    x86_code.push_back({"\t.string", "\"%ld\\n\""});
    x86_code.push_back({"\t.text"});
    x86_code.push_back({"\t.globl", "main"});

    for(int i=0; i<instructions.size(); i++){
        if(str_temp){
            x86_code.push_back({".section", ".data"});
            x86_code.push_back({"string"+to_string(str_cnt)+":", ".string","\""+str_name+"\\n\""});
            x86_code.push_back({".section", ".text"});
            str_temp=0;
            str_name="";
        } 
        x86_code.push_back({"L"+to_string(i+1)+":"+"\n\t"});
        if(instructions[i][0]=="1"){   //type 1 instruction     // a = b op c
            string a = instructions[i][1];
            string op = instructions[i][2];
            string b = instructions[i][3];
            string c = instructions[i][4];

            stack_pos1(b);
            stack_pos2(c);
            stack_pos_lhs(a);

            if(op == "+"){
                x86_code.push_back({"\taddq", "%r12", ",", "%r11"});
                x86_code.push_back({"\tmovq", "%r11", ",", "0(%r13)"});
            }
            else if(op == "-"){
                x86_code.push_back({"\tsubq", "%r12", ",", "%r11"});
                x86_code.push_back({"\tmovq", "%r11", ",", "0(%r13)"});
            }
            else if(op == "*"){
                x86_code.push_back({"\timulq", "%r12", ",", "%r11"});
                x86_code.push_back({"\tmovq", "%r11", ",", "0(%r13)"});
            }
            else if(op == "/"){  //test these
                x86_code.push_back({"\tmovq", "$0", ",", "%rdx"});
                x86_code.push_back({"\tmovq", "%r11", ",", "%rax"});
                x86_code.push_back({"\tdivq", "%r12"});
                x86_code.push_back({"\tmovq", "%rax", ",", "0(%r13)"});
            }
            else if(op == "%"){
                x86_code.push_back({"\tmovq", "$0", ",", "%rdx"});
                x86_code.push_back({"\tmovq", "%r11", ",", "%rax"});
                x86_code.push_back({"\tdivq", "%r12"});
                x86_code.push_back({"\tmovq", "%rdx", ",", "0(%r13)"});
            }
            else if(op == "//"){    //same as division because float need not to be done
                x86_code.push_back({"\tmovq", "$0", ",", "%rdx"});
                x86_code.push_back({"\tmovq", "%r11", ",", "%rax"});
                x86_code.push_back({"\tdivq", "%r12"});
                x86_code.push_back({"\tmovq", "%rax", ",", "0(%r13)"});
            }
            else if(op == "**"){
                x86_code.push_back({"\tmovq", "$1", ",", "%rdx"});
                x86_code.push_back({"\tmovq", "%r12", ",", "%rbx"});
                x86_code.push_back({"\tcmpq", "$0", ",", "%rbx"});
                x86_code.push_back({"\tje", "L"+to_string(i)+":M"+to_string(i+2)});
                x86_code.push_back({"L"+to_string(i)+":M"+to_string(i+1)+":"});
                x86_code.push_back({"\timulq", "%r11", ",", "%rdx"});
                x86_code.push_back({"\tdecq", "%rbx"});
                x86_code.push_back({"\tcmpq", "$0", ",", "%rbx"});
                x86_code.push_back({"\tjne", "L"+to_string(i)+":M"+to_string(i+1)});
                x86_code.push_back({"L"+to_string(i)+":M"+to_string(i+2)+":"});
                x86_code.push_back({"\tmovq", "%rdx", ",", "0(%r13)"});
            }
            else if(op == "<<"){
                x86_code.push_back({"\tmovq", "%r12", ",", "%rbx"});
                x86_code.push_back({"\tmovq", "%r11", ",", "%rdx"});
                x86_code.push_back({"\tmovq", "$0", ",", "%r12"});
                x86_code.push_back({"\tcmpq", "%rbx", ",", "%r12"});
                x86_code.push_back({"\tje", "L"+to_string(i)+":M"+to_string(i+2)});
                x86_code.push_back({"L"+to_string(i)+":M"+to_string(i+1)+":"});
                x86_code.push_back({"\tshlq", "$1", ",", "%rdx"});
                x86_code.push_back({"\tincq", "%r12"});
                x86_code.push_back({"\tcmpq", "%rbx", ",", "%r12"});
                x86_code.push_back({"\tjne", "L"+to_string(i)+":M"+to_string(i+1)});
                x86_code.push_back({"L"+to_string(i)+":M"+to_string(i+2)+":"});
                x86_code.push_back({"\tmovq", "%rdx", ",", "0(%r13)"});
            }
            else if(op == ">>"){
                x86_code.push_back({"\tmovq", "%r12", ",", "%rbx"});
                x86_code.push_back({"\tmovq", "%r11", ",", "%rdx"});
                x86_code.push_back({"\tmovq", "$0", ",", "%r12"});
                x86_code.push_back({"\tcmpq", "%rbx", ",", "%r12"});
                x86_code.push_back({"\tje", "L"+to_string(i)+":M"+to_string(i+2)});
                x86_code.push_back({"L"+to_string(i)+":M"+to_string(i+1)+":"});
                x86_code.push_back({"\tshrq", "$1", ",", "%rdx"});
                x86_code.push_back({"\tincq", "%r12"});
                x86_code.push_back({"\tcmpq", "%rbx", ",", "%r12"});
                x86_code.push_back({"\tjne", "L"+to_string(i)+":M"+to_string(i+1)});
                x86_code.push_back({"L"+to_string(i)+":M"+to_string(i+2)+":"});
                x86_code.push_back({"\tmovq", "%rdx", ",", "0(%r13)"});
            }
            else if(op == "<"){  // if a<b then see wrt b
                x86_code.push_back({"\tcmpq", "%r11", ",", "%r12"});
                x86_code.push_back({"\tsetg", "%al"});
                x86_code.push_back({"\tmovzbq", "%al", ",", "%r11"});
                x86_code.push_back({"\tmovq", "%r11", ",", "0(%r13)"});
            }
            else if(op == ">"){
                x86_code.push_back({"\tcmpq", "%r11", ",", "%r12"});
                x86_code.push_back({"\tsetl", "%al"});
                x86_code.push_back({"\tmovzbq", "%al", ",", "%r11"});
                x86_code.push_back({"\tmovq", "%r11", ",", "0(%r13)"});
            }
            else if(op == "<="){
                x86_code.push_back({"\tcmpq", "%r11", ",", "%r12"});
                x86_code.push_back({"\tsetge", "%al"});
                x86_code.push_back({"\tmovzbq", "%al", ",", "%r11"});
                x86_code.push_back({"\tmovq", "%r11", ",", "0(%r13)"});
            }
            else if(op == ">="){
                x86_code.push_back({"\tcmpq", "%r11", ",", "%r12"});
                x86_code.push_back({"\tsetle", "%al"});
                x86_code.push_back({"\tmovzbq", "%al", ",", "%r11"});
                x86_code.push_back({"\tmovq", "%r11", ",", "0(%r13)"});
            }
            else if(op == "=="){
                x86_code.push_back({"\tcmpq", "%r11", ",", "%r12"});
                x86_code.push_back({"\tsete", "%al"});
                x86_code.push_back({"\tmovzbq", "%al", ",", "%r11"});
                x86_code.push_back({"\tmovq", "%r11", ",", "0(%r13)"});
            }
            else if(op == "!="){
                x86_code.push_back({"\tcmpq", "%r11", ",", "%r12"});
                x86_code.push_back({"\tsetne", "%al"});
                x86_code.push_back({"\tmovzbq", "%al", ",", "%r11"});
                x86_code.push_back({"\tmovq", "%r11", ",", "0(%r13)"});
            }
            else if(op == "<>"){    //same as !=
                x86_code.push_back({"\tcmpq", "%r11", ",", "%r12"});
                x86_code.push_back({"\tsetne", "%al"});
                x86_code.push_back({"\tmovzbq", "%al", ",", "%r11"});
                x86_code.push_back({"\tmovq", "%r11", ",", "0(%r13)"});
            }
            else if(op == "&"){
                x86_code.push_back({"\tandq", "%r12", ",", "%r11"});
                x86_code.push_back({"\tmovq", "%r11", ",", "0(%r13)"});
            }
            else if(op == "|"){
                x86_code.push_back({"\torq", "%r12", ",", "%r11"});
                x86_code.push_back({"\tmovq", "%r11", ",", "0(%r13)"});
            }
            else if(op == "^"){
                x86_code.push_back({"\txorq", "%r12", ",", "%r11"});
                x86_code.push_back({"\tmovq", "%r11", ",", "0(%r13)"});
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
                x86_code.push_back({"\tpushq", "%rbp"});
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
                x86_code.push_back({"\tmovq", "%r12", ",", "%r8"}); //r8 register stores the return value

                x86_code.push_back({"\taddq", "$"+to_string(curr_func_ste->stack_width), ",", "%rsp"});
                x86_code.push_back({"\tpopq", "%rbp"});
                x86_code.push_back({"\tret"});
            }

            else if(instructions[i][1]=="goto" && instructions[i][2]=="ra"){
                // x86_code.push_back({"\taddq", "$"+to_string(curr_func_ste->stack_width), ",", "%rsp"});
                // x86_code.push_back({"\tpop", "%rbp"});
                // x86_code.push_back({"\tret"});
            }

            else if(instructions[i][1]=="PopParamAll"){ 
                //cerr<<instructions[i][2]<<"here1"<<endl;
                int num_params = stoi(instructions[i][2]);
                num_params = num_params*8;
                x86_code.push_back({"\taddq", "$"+to_string(num_params), ",", "%rsp"});
            }

            else if(instructions[i][1]=="PushParamra"){
                //nothing needs to be done, rip is counter register and it automatically updates
            }

            else if(instructions[i][1]=="PushParam"){   //parameter push
                stack_pos1(instructions[i][2]);
                x86_code.push_back({"\tpushq", "%r11"});
            }

            else if(instructions[i][1]=="PopParamra"){
                if(curr_func_ste!=NULL){    // instruction[i][2] will always be a variable
                    int this_offset = curr_func_ste->offset_map[instructions[i][2]];
                    x86_code.push_back({"\tmovq", "%r8", ",", to_string(this_offset)+"(%rbp)"});
                }
            }

            else if(instructions[i][2] == "len"){
                stack_pos2(instructions[i][3]);
                x86_code.push_back({"\tmovq","0(%r12)",",","%r8"});
            }

            else if(instructions[i][2]=="print"){
                stack_pos2(instructions[i][3]);
                if(str_temp==0){
                    x86_code.push_back({"\tmovq", "%r12", ",", "%rsi"});
                    x86_code.push_back({"\tlea", ".note0(%rip)",",", "%rax"});
                    x86_code.push_back({"\tmovq", "%rax", ",", "%rdi"});
                    x86_code.push_back({"\txor", "%rax", ",", "%rax"});
                    x86_code.push_back({"\tcall", "printf@plt"}); 
                }
                if(str_temp==1){
                    string s = instructions[i][3].substr(1, instructions[i][3].size() - 2);  //removed the quotes
                    str_name = s;
                    x86_code.push_back({"\tmov", "$1", ",", "%rax"});
                    x86_code.push_back({"\tmov", "$1",",","%rdi"});
                    x86_code.push_back({"\tlea", "string"+to_string(str_cnt)+"(%rip)",",","%rsi"});
                    x86_code.push_back({"\tmov", "$"+to_string(s.size()+1),",","%rdx"});
                    x86_code.push_back({"\tsyscall"});
                }
            }

            else if(instructions[i][1]=="call"){
                if(instructions[i][2] != "main"){
                    x86_code.push_back({"\tcall", instructions[i][2]});
                }
            }

            //to see when funcends
            else if(instructions[i][1]=="EndFunc"){
                curr_func_ste = NULL;
            }

            else if(instructions[i][1]=="if"){ //True ke liye alag se
                stack_pos1(instructions[i][2]);
                x86_code.push_back({"\tcmpq", "$0", ",", "%r11"});
                x86_code.push_back({"\tjne", "L"+instructions[i][5]});
            }

            else if(instructions[i][1]=="goto"){
                if(instructions[i][2]!=""){
                    x86_code.push_back({"\tjmp","L"+instructions[i][2]});
                }
                else if(instructions[i][3]!=""){
                    x86_code.push_back({"\tjmp","L"+instructions[i][3]});
                }
                else if(instructions[i][4]!=""){
                    x86_code.push_back({"\tjmp","L"+instructions[i][4]});
                }
                else if(instructions[i][5]!=""){
                    x86_code.push_back({"\tjmp","L"+instructions[i][5]});
                }
            }

            else if(instructions[i][1] == "Heapalloc"){ //heapalloc numberofelements
                //cerr<<instructions[i][2]<<endl;
                x86_code.push_back({"\tmovq", "$"+to_string(stoi(instructions[i][2])*8+8), ",", "%rdi"});
                x86_code.push_back({"\tcall", "malloc"});
            }

            else if(instructions[i][3].size()!=0 && instructions[i][3][0]=='['){
                // cerr<<"here"<<endl;
                // there may be case like instructions[i][1] = self.array so handle that
                x86_code.push_back({"\tmovq", "%rax", ",", to_string(curr_func_ste->offset_map[instructions[i][1]])+"(%rbp)"});

                int array_index_bytes=0;
                string s = instructions[i][3];
                s = s.substr(1, s.size() - 2);  //removed the brackets

                stringstream ss(s);
                string item;
                vector<string> substrings;

                // Split by comma
                while (std::getline(ss, item, ',')) {
                    substrings.push_back(item);
                }

                int len=substrings.size();
                //x86_code.push_back({"\tmovq", "$"+to_string(substrings.size()), ",", to_string(array_index_bytes)+"(%rax)"});
                x86_code.push_back({"\tmovq", "$"+to_string(len), ",", "%r12"});
                x86_code.push_back({"\tmovq", "%r12", ",", to_string(array_index_bytes)+"(%rax)"});
                array_index_bytes+=8;
                

                // Now, substrings vector contains the substrings
                for (const auto element : substrings) {
                    // cerr<<element<<endl;
                    stack_pos2(element);
                    x86_code.push_back({"\tmovq", "%r12", ",", to_string(array_index_bytes)+"(%rax)"});
                    array_index_bytes+=8;
                }
            }

           else if(instructions[i][3].size()!=0 && instructions[i][3][0]=='\"'){

                x86_code.push_back({"\tmovq", "%rax", ",", to_string(curr_func_ste->offset_map[instructions[i][1]])+"(%rbp)"});
                string s = instructions[i][3].substr(1, instructions[i][3].size() - 2);  //removed the quotes

                str_map[instructions[i][1]] = s;

                int str_index_bytes=0;

                for(int j=0;j<s.size();j++){
                    stack_pos2(to_string((int)s[j]));
                    x86_code.push_back({"\tmovq", "%r12", ",", to_string(str_index_bytes)+"(%rax)"});
                    str_index_bytes+=8;
                }
            }

            else if(instructions[i][1].size()!=0 && instructions[i][1].find(':')!=string::npos){
                string s = instructions[i][1];
                //cerr<<s<<endl;
                size_t pos = s.find(':'); // Find the position of the first colon
                if (pos != std::string::npos) {
                    s = s.substr(0, pos); // Trim the string up to the first colon
                }
                
                x86_code.push_back({"\tmovq", "%rax", ",", to_string(curr_func_ste->offset_map[s])+"(%rbp)"});
                int len = str_map[instructions[i][3]].size();
                int str_index_bytes=0;
                x86_code.push_back({"\tmovq", "$"+to_string(len), ",", "%r12"});
                x86_code.push_back({"\tmovq", "%r12", ",", to_string(str_index_bytes)+"(%rax)"});
                str_index_bytes+=8;

                //cerr<<instructions[i][3]<<endl;
                stack_pos_lhs(instructions[i][3]);
                for(int j=0;j<len;j++){
                    x86_code.push_back({"\taddq", "$8", ",", "%r13"});
                    x86_code.push_back({"\taddq", "$8", ",", "%rax"});
                    x86_code.push_back({"\tmovq", "0(%r13)", ",", "%r15"});
                    x86_code.push_back({"\tmovq", "%r15", ",", "0(%rax)"});
                    //cerr<<"pushed char"<<j<<endl;
                }
            }

            else if(instructions[i][2]=="="){
                //here also in if else you have to handle different types of c
                //handle swapped = false type
                // cerr<<instructions[i][3]<<endl;
                if(str_map.find(instructions[i][3]) != str_map.end()){
                    //cerr<<"hello"<<endl;
                    str_map[instructions[i][i]] = str_map[instructions[i][3]];
                }
                else{
                    stack_pos_lhs(instructions[i][1]);
                    stack_pos2(instructions[i][3]);
                    x86_code.push_back({"\tmovq", "%r12", ",", "0(%r13)"});
                }
            }

            else if(instructions[i][1]=="EOF"){
                x86_code.push_back({"\t\tmov", "$60",",", "%rax"});
                x86_code.push_back({"\t\tmovq", "$0",",", "%rdi"});
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