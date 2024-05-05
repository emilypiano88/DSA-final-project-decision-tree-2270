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

student_profile init_profile(float gpa, int test_score, int match_score, bool funding, bool motiv, bool recom){
    student_profile student = *(new student_profile);
    student.underg_gpa = gpa;
    student.stand_test = test_score;
    student.match_score = match_score;
    student.self_funding = funding;
    student.strong_motiv = motiv;
    student.pos_recomend = recom;
        
    return student;
}




//init a decision tree Decision_Tree::
decision_node* init_node(int yes, int no){ 
    decision_node* node (new decision_node);
    //node->is_leaf = leaf;
    node->yes_outcome = yes;
    node->no_outcome = no;
    node->func_name = nullptr;
    node->yes_node = nullptr;
    node->no_node = nullptr;
    return node; 
}







//re-write travers a decision tree to land on a outcome
int predict_outcome(decision_node* cursor, student_profile student){
    if (cursor->func_name(student) == true){
        if (cursor->yes_node == nullptr) return cursor->yes_outcome;
        else predict_outcome(cursor->yes_node, student); 
    }
    else{
        if (cursor->no_node == nullptr) return cursor->no_outcome;        
        else predict_outcome(cursor->no_node, student);
    }    
}




//travers a decision tree to land on a outcome
//int predict_outcome(decision_node* cursor, student_profile student){
//    if (cursor->func_name(student) == true){
  //      if (cursor->is_leaf == true) {
    //        return cursor->yes_outcome;
      //  }
        //else{
          //  predict_outcome(cursor->yes_node, student); 
        //}
    //}
//    else{
  //      cout << "I'm here" << endl;
    //    if (cursor->is_leaf == true){
      //      cout << "it's leaf" << endl;
        //    return cursor->no_outcome;
        //}
//        else{
  //          cout << "not a leaf" << endl;
    //        predict_outcome(cursor->no_node, student);  
      //  }
//    }
    
//}