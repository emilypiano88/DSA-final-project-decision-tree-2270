#include "../code/DecisionTree.h"

#include <iostream>

using namespace std;

//=+=+=+=+=+=+=+=+=+=+=+=+=+=+   hard-coded decisioning  =+=+=+=+=+=+=+=+=+=+=+=+=+=+//
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
               if(student.match_score >=7) outcome = 2;
               else outcome = 3;
           }
           else outcome = 3;
        }
    }
    else outcome = 3;
    
    
    return outcome; //1 = admitted, 2 = waitlisted, 3 = not admitted
}


//=+=+=+=+=+=+=+=+=+=+=+=+=+=+   tree-based decisioning  =+=+=+=+=+=+=+=+=+=+=+=+=+=+//

//---------Step 0: define each criteiria as decision function---------//
//#1
bool gpa(student_profile student){
        if (student.underg_gpa >=3.4) return true;
        return false;
    }
//#2    
bool std_test(student_profile student){
        if (student.stand_test >= 650) return true;
        return false;
    }
//#3
bool motiv(student_profile student){
        if (student.strong_motiv == true) return true;
        return false;
    }
    
//#4
bool recom(student_profile student){
        if (student.pos_recomend == true) return true;
        return false;
    }
    
//#5
bool funding(student_profile student){
        if (student.self_funding == true) return true;
        return false;
    }
//#6    
bool backgd_match(student_profile student){
        if (student.match_score >=7) return true;
        return false;
    }


int main() {  
    
    cout << "my term project - admission prediction" << endl;
    //---------Step 1: define a student's profile---------//
    student_profile Bob;
    Bob.underg_gpa = 2.8;
    Bob.stand_test = 800;  
    Bob.match_score = 8;
    Bob.self_funding = 0;
    Bob.strong_motiv = 1;
    Bob.pos_recomend = 0;
    
    //parameter order: gpa, test_score, match_score, funding, motiv, recom
    student_profile Alice = init_profile(3.2, 700, 8, 0, 1, 0); 
    

    
    //---------Step 2: define all nodes---------//
    //Outcome value: 0 = "no decision",100 = "admitted!:)", 200 = "waitlisted :o", 300 = "not admitted :("
    
    //#1
    decision_node* gpa_node = init_node(0,0);
    gpa_node->func_name = gpa; 
    //#2
    decision_node* std_test_node = init_node(0,300);
    std_test_node->func_name = std_test;
    //#3
    decision_node* motiv_node = init_node(0,300);
    motiv_node->func_name = motiv;
    //#4    
    decision_node* recommend_node = init_node(100,0);
    recommend_node->func_name = recom;
    //#5    
    decision_node* funding_node = init_node(100,200);
    funding_node->func_name = funding;
    //#6   
    decision_node* match_node = init_node(200,300);
    match_node->func_name = backgd_match;
    
    //---------Step 4: link nodes---------//
    //small-scale tree:
    //gpa_node->no_node = std_test_node;

    
    //full-scale tree:
    motiv_node->yes_node = gpa_node;
    
    gpa_node->yes_node = recommend_node;
    gpa_node->no_node = std_test_node;

    recommend_node->no_node = funding_node;
    
    std_test_node->yes_node = match_node;
    
    //---------Step 3: Define root nodes---------//
    //decision_node* my_root = gpa_node;
    decision_node* my_root = motiv_node;
    
    
    
    //---------Step 5: predict admission outcome---------//
    int x = predict_outcome(my_root, Alice);
    int y = predict_admission(Alice);
    
    //---------Step 6: print out decision outcome---------//
    vector<string> decision_outcome = {"no decision","admitted!:)", "waitlisted :o", "not admitted :("};
    cout << "Tree-based admission outcome: " << decision_outcome[x/100] << endl;
    cout << "Hard-coded outcome: " << decision_outcome[y] << endl;

    
    
    
    return 0;
}



//Ignore Below
//void decision_function(string func_name, student_profile Bob){
//    func_name(Bob);
//}


    //Decision_Tree Admission_Tree;    
    //Admission_Tree.set_node_count(6);
    //bool (*funcptr)(student_profile) = test;


//bool test(student_profile student){
//    cout <<"Aha!" << endl;
//    return false;
//}