#include <iostream>
#include <math.h>

#ifndef CLASS_H
#define CLASS_H

using namespace std;

struct Node {
  std::string key;
  Node* left;
  Node* right;
  Node(string s){ key = s;};
  ~Node(){};

};
class BST {
  private:
    Node *root{};

    void _clear(Node*& root){
      if(root != NULL) {
        _clear(root -> left);
        _clear(root -> right);
        delete root;
        root = NULL;
      }
    }

    void _printPostOrder(Node* root){
      if(root != NULL){
        _printPostOrder(root -> left);
        _printPostOrder(root -> right);
        cout << root -> key << endl;
      }
    }

    void _printInOrder(Node* root){
      if(root != NULL){
        _printPostOrder(root -> left);
        cout << root -> key << endl;
        _printPostOrder(root -> right);
      }
    }

    Node* _suche(std::string d, Node *root) {
      if(root != NULL) {
        if(d == root -> key){
          return root;
        }
        if(d < root -> key){
          return _suche(d, root -> left);
        }else{
          return _suche(d, root -> right);
        }
      }
    }

    void _add(Node* &p, string k) {
      if (!p) p = new Node(k);
      else {
        if (k < p -> key)
        _add(p -> left, k);
        else if (k > p -> key)_add(p -> right, k);
        else cout << "key exists already" << endl;
      }
    }

    int _knoten(Node *root) {
        if (!root) return 0;
        else return 1 + _knoten(root->left) + _knoten(root->right);
    }

    unsigned int _blaetter(Node* root)
    {
      if(root == NULL)
        return 0;
        if(root ->left == NULL && root->right==NULL)
        return 1;
        else
        return _blaetter(root->left)+ _blaetter(root->right);
    }

    int _hoehe(Node *root) {
        if (!root) return 0;
        else return 1 + max(_hoehe(root->left), _hoehe(root->right));
    }

    public:
      void add(string a) {
        if (root){
          _add(root, a);
        }else{
           root = new Node(a);
        }
      }

      void clear(){
        _clear(root);
      }

      void search(string d){
        _suche(d, root);
      }

      void printPostOrder(){
        _printPostOrder(root);
      }

      void printInOrder(){
        _printInOrder(root);
      }

      int knoten() {
      	if(root == NULL) return 0;
      	else return _knoten(root);
      }

      int blaetter() {
      	if(root == NULL) return 0;
      	else return _blaetter(root);
      }

      int hoehe() {
      	return _hoehe(root);
      }
};
#endif
