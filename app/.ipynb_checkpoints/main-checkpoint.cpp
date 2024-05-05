#include "../code/DecisionTree.h"

#include <iostream>

using namespace std;

int predict_admission(student_profile student){
   int outcome;
    if (student.strong_motiv == 1){
        if(student.underg_gpa >= 3.4){
            if (student.pos_recomend == 1) outcome = 1;
            else{
                if (student.self_funding == 1) outcome = 1;
                else outcome = 2;
            }
        }
        else{
           if (student.stand_test > 650){
               if(student.backgd_match >=7) outcome = 1;
               else outcome = 3;
           }
           else outcome = 3;
        }
    }
    else outcome = 3;
    
    
    return outcome; //1 = admitted, 2 = waitlisted, 3 = not admitted
}

//void decision_function(string func_name, student_profile Bob){
//    func_name(Bob);
//}

bool test(student_profile student){
    cout <<"Aha!" << endl;
    return false;
}


bool gpa(student_profile student){
        if (student.underg_gpa >=3.4) return true;
        return false;
    }
    
bool recom(student_profile student){
        if (student.pos_recomend == true) return true;
        return false;
    }
    
bool std_test(student_profile student){
        if (student.stand_test >= 650) return true;
        return false;
    }

vector<string> decision_outcome = {"no decision","admitted!:)", "waitlisted :0", "not admitted :("};

int main() {  
    
    cout << "my term project - admission prediction" << endl;
    //Step 1: define a student's profile
    student_profile Bob;
    Bob.underg_gpa = 3.1;
    Bob.stand_test = 600;  
    Bob.backgd_match = 8;
    Bob.self_funding = 1;
    Bob.strong_motiv = 1;
    Bob.pos_recomend = 0;
    cout << predict_admission(Bob) << endl;
    
    //Step 2: init root node
    decision_node* my_root = init_node();
    my_root->func_name = gpa; //bool (*funcptr)(student_profile) = test;
    my_root->outcome_yes = 1;
    my_root->outcome_no = 0;
    my_root->is_leaf = false;
    
    //Step 3: init other nodes
    decision_node* std_test_node = init_node();
    std_test_node->func_name = std_test;
    std_test_node->outcome_yes = 2;
    std_test_node->outcome_no = 3;
    
    
    //Step 4: link all decision nodes
    my_root->no_node = std_test_node;
    
    
    
    //Step 5: predict admission outcome
    int x = predict_outcome(my_root, Bob);
    cout << "admission outcome: " << decision_outcome[x] << endl;
    
    
    
    
    return 0;
}




    //Decision_Tree Admission_Tree;    
    //Admission_Tree.set_node_count(6);
    