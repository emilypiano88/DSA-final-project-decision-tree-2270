#ifndef DECISION_TREE_H__
#define DECISION_TREE_H__

#include <memory>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


struct student_profile{
    float underg_gpa; //underg_gpa range 2.5 to 4.0
    int stand_test;  //stand_test range 300 to 800
    int backgd_match; //backgd_match score on scale of 10
    bool self_funding;  //has their own source of funding
    bool strong_motiv; //strong motivation
    bool pos_recomend; //positive letter of recomendation
};

struct decision_node{
    bool is_leaf;
    bool (*func_name)(student_profile);
    decision_node* yes_node;
    decision_node* no_node;
    int outcome_yes;
    int outcome_no;
};


//class Decision_Tree {
//public:
//  Decision_Tree();
//  ~Decision_Tree();
      
    
  //init a decision node
    decision_node* init_node();
     
      
    int predict_outcome(decision_node* cursor, student_profile student);


    decision_node* get_root();
    
    int get_node_count();
  
    void set_node_count(int count);

    void set_root(decision_node** new_root);


#endif //DECISION_TREE_H__


//private:
//  decision_node** root;
//  string decision_outcome;
//  int count_of_node;
//};



//  void report(decision_node* top);


//void insert(decision_node* new_node);

  //void insert_data(int data);

  //void remove(int data);

  //bool contains(decision_node* subt, int data);

  //decision_node* get_node(decision_node* subt, int data);

  //int size(decision_node* subt);

  //void to_vector(decision_node* subt, vector<int>& vec);

  
  //decision_node* buddy(decision_node* remover);
    
  //decision_node* buddy_parent(decision_node* remover);

