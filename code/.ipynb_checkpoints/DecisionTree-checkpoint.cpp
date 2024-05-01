#include "DecisionTree.h"
//#include ".../tests/BTreeTestHelp.h"


//----------------Helper Functions-----------------//

btree* init_node_helper() {
  btree* ret = new btree;
  ret->num_keys = 0;
  ret->is_leaf = true;
  for (int i = 0; i <= BTREE_ORDER; i++) {
    ret->children[i] = NULL;
  }
  return ret;
}

btree* build_node_helper(int size, int* keys) {
  btree* node = init_node_helper();
  node->num_keys = size;
  for (int i = 0; i < node->num_keys; i++) {
    node->keys[i] = keys[i];
  }
  return node;
}

btree* build_semifull_helper() {
  int vals[] = {10, 30};
  btree* root = build_node_helper(2, vals);
  root->num_keys = 2;
  return root;
}    

btree* build_full_leaf_root_helper() {
  int vals[] = {10, 20, 30, 40};
  btree* root = build_node_helper(4, vals);
  root->num_keys = 4;
  return root;
}

btree* build_small_helper(){
    int vals[] = {10, 20};
    btree* root = build_node_helper(2, vals);
    // now we need three children
    int vals2[] = {2, 8};
    btree* left = build_node_helper(2, vals2);
    int vals3[] = {13, 17};
    btree* mid = build_node_helper(2, vals3);
    int vals4[] = {24, 28};
    btree* right = build_node_helper(2, vals4);
    root->is_leaf = false;
    root->children[0] = left;
    root->children[1] = mid;
    root->children[2] = right;
    return root;
    
}

//---------------End of Helper Functions-----------//


void insert(btree*& root, int key) {
    //leaf root
    if (root->is_leaf == true){
        //empty root
        int count = root->num_keys;
        if (count == 0){
            root->keys[count] = key;
            root->num_keys++;
            return;
        }

        //insert the key to non-empty root
        for (int i = 0; i < count; i++) if (key == root->keys[i]) return;
        root->keys[count] = key;
        root->num_keys++;
        // need to do insertion sort
        for (int i = count; i > 0; i--){
            if (root->keys[i] < root->keys[i-1]){
                int temp = root->keys[i];
                root->keys[i] = root->keys[i-1];
                root->keys[i-1] = temp;
            }
        }
        
        //semifull root
        if (root->num_keys <5) return;
                
        //full root - need to add a layer
        else{

            int child0[2] = {root->keys[0], root->keys[1]};
            int child1[2] = {root->keys[3], root->keys[4]};
            root->children[0] = build_node_helper(2, child0);
            root->children[1] = build_node_helper(2, child1);
            root->keys[0] = root->keys[2];
            root->num_keys = 1;
            root->is_leaf = false;
            for (int i = 1; i < 5; i++) root->keys[i] = 0;
            return;
        }
    }
    
    //InsertKeyIntoSemifullLeafNode
    
    
}

void remove(btree*& root, int key) {}

btree* find(btree* root, int key) { 
    insert(root, key);
    
    //present key in root
    for (int i = 0; i < root->num_keys; i++) if (key == root->keys[i]) return root;
    
    //not present key in root
    for (int i = 0; i < root->num_keys + 1; i++){
        for (int j = 0; j < root->children[i]->num_keys; j++){
            if (key == root->children[i]->keys[j]) return root->children[i];
        }
        
    }
        
}

int count_nodes(btree* root) { 
    
    if (root->is_leaf == true) return 1;
    else{
        int sum = 1;
        for (int i = 0; i < root-> num_keys + 1; i++){
            sum = sum + count_nodes(root->children[i]);
        }
        return sum;
    }
}

int count_keys(btree* root) { 
    
    if (root->is_leaf == true) return root->num_keys;
    else{
        int sum = root->num_keys;
        for (int i = 0; i < root-> num_keys + 1; i++){
            sum = sum + count_keys(root->children[i]);
        }
        return sum;
        
    }
    
    return 0; 

}