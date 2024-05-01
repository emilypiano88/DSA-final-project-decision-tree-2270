#ifndef BTREE_H__
#define BTREE_H__

#include <memory>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct decision_node{
    string decision_function;
    bool decision;
    bool is_leaf;
    decision_tree* yes;
    decision_tree* no;    
};

struct decision_tree{
    int node_count;
    vector<*decision_node>
    
};

bool (*decision_func)(string);
bool dec_func_1(string key);
bool dec_func_2(string key);
bool dec_func_3(string key);



//----------------Helper Functions-----------------//

btree* init_node_helper();

btree* build_node_helper(int size, int* keys);

btree* build_semifull_helper();

btree* build_full_leaf_root_helper();

btree* build_small_helper();


//---------------End of Helper Functions-----------//



// insert adds the given key into a b-tree rooted at 'root'.  If the
// key is already contained in the btree this should do nothing.
//
// On exit:
// -- the 'root' pointer should refer to the root of the tree. (the root may
//    change when we insert or remove - that is why it is a reference parameter)
// -- the btree pointed to by 'root' is valid.


void insert(btree*& root, int key);

// remove deletes the given key from a b-tree rooted at 'root'. If the key is
// not in the btree this should do nothing.
//
// On exit:
// -- the 'root' pointer should refer to the root of the tree. (the root may
//    change when we insert or delete. Again it is a reference param so you can
//    change the root node if it is necessary.)
// -- the btree pointed to by 'root' is valid.
void remove(btree*& root, int key);

// find locates the node that either: (a) currently contains this key, or (b)
// the node that would contain it if we were to try to insert it.  Note that
// this always returns a non-null node.
btree* find(btree* root, int key);

// count_nodes returns the number of nodes referenced by this btree. If this
// node is NULL, count_nodes returns zero; if it just a single root node with no
// children, it returns 1; otherwise it returns 1 plus however many nodes are
// accessable via any valid child links.
int count_nodes(btree* root);

// count_keys returns the total number of keys stored in this btree. If the root
// node is null it returns zero; otherwise it returns the number of keys in the
// root plus however many keys are contained in valid child links.
int count_keys(btree* root);

#endif // BTREE_H__