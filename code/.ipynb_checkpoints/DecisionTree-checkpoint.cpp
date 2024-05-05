#include "DecisionTree.h"


//init a decision node
//Decision_Tree::Decision_Tree() {
//  root = new decision_node*;
//  *root = NULL;
//}

//Decision_Tree::~Decision_Tree() {}

//int Decision_Tree::get_node_count(){
//  return count_of_node;
//}

//void Decision_Tree::set_node_count(int count){
//   count_of_node = count;
//}




//init a decision tree Decision_Tree::
decision_node* init_node(){ 
    decision_node* node (new decision_node);
    node->is_leaf = true;
    node->func_name = nullptr;
    node->yes_node = nullptr;
    node->no_node = nullptr;
    int outcome_yes = 0;
    int outcome_no = 0;
    return node; 
}



//travers a decision tree to land on a outcome
int predict_outcome(decision_node* cursor, student_profile student){
    if (cursor->func_name(student) == true){
        if (cursor->is_leaf == true) return cursor->outcome_yes;
        else predict_outcome(cursor->yes_node, student); 
    }
    else{
        if (cursor->is_leaf == true){
            return cursor->outcome_no;
        }
        else predict_outcome(cursor->no_node, student); 
    }
    
}