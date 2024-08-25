#include<bits/stdc++.h>
#include "functions.h"
using namespace std;

void searchAST(NODE* node){
    if(node == NULL) return;
    


    for(int i = 0; i < node->children.size(); i++){
        string child_node_addr = node->children[i]->addr;
        if(child_node_addr == "Class"){
            
        }
        searchAST(node->children[i]);
    }

}

