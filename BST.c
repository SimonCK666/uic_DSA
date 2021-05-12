#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"


Node* insertNode(Node** proot, int x){
    // create all nodes
    Node *par = NULL;
    Node* currNode = *proot;

    if(*proot == NULL){
        // There is no root node so create one
        Node* nroot = (Node*)malloc(sizeof(Node));

        //initialize the value
	    nroot->key = x;
        nroot->left = NULL;
        nroot->right = NULL;

        *proot = nroot;

        return nroot;
    }

    // the position is to insert
    while (currNode){
        // set the node
        par = currNode;

        if(currNode->key > x){
            currNode = currNode->left;
        }else if (currNode->key < x){
            currNode = currNode->right;
        }
    }

    // the key is larger than key
    if(par->key > x){
        Node* nroot = (Node*)malloc(sizeof(Node));
        // set the pre values for nodes
	    nroot->key = x;
        nroot->left = NULL;
        nroot->right = NULL;
        par->left = nroot;
        return nroot;
    }else{
        // the key is less than x 
        Node* nroot = (Node*)malloc(sizeof(Node));

        // set the pre values
	    nroot->key = x;
        nroot->left = NULL;
        nroot->right = NULL;
        par->right = nroot;

        return nroot;
    }
}

Node *findNode(Node *root, int x){
    while (root){

        // find the value
        if(root->key == x){
            return root;
        }else if (root->key > x){
            // the key is larger than x
            root = root->left;
        }else{
            // key is less than x
            root = root->right;
        }

    }
    
    // return if value equal to NULL
    return NULL;
}

Node *deleteNode(Node **proot, int x){
    // set the pre nodes
    Node *currNode = *proot;
    Node *par = *proot;
    Node *delete = NULL;
    Node *tem = NULL;

    while(currNode){
        if(currNode->key > x){
            // key is more than x
            par = currNode;
            currNode = currNode->left;
        }else if(currNode->key < x){
            // key is less than x
            par = currNode;
            currNode = currNode->right;
        }else{
            // the node which to delete
            delete = currNode;
            if(currNode->left == NULL){

                if(par->left == currNode){
                    // find the position
                    par->left = currNode->right;
                }else if(par->right == currNode){
                    // find the position
                    par->right = currNode->right;
                }
            }else if(currNode->right == NULL){

                if(par->left == currNode){
                    // find the position
                    par->left = currNode->left;
                }else if(par->right == currNode){
                    // find the position
                    par->right = currNode->left;
                }

            }else{
                // if has two children
                int i = 0;
                tem = currNode->right;

                while(tem->left){
                    par = tem;
                    tem = tem->left;
                    i++;

                }
                delete = tem;
                currNode->key = tem->key;

                if(i >=1){
                    // the par is up the currNode
                    if(par->left == tem){
                        // find the position
                        par->left = tem->right;
                    }else{
                        par->right = tem->right;
                    }

                }else{
                    // the par is below the currNode
                    if(currNode->left == tem){
                        // find the position
                        currNode->left = tem->right;
                    }else if(currNode->right == tem){
                        currNode->right = tem->right;
                    }

                }

            }

            // return the delete node
            return delete;
        }
    }
}


//delete all nodes
void destroyTree(Node *root){

    if(root != NULL){
        if(root->left != NULL){
            // use the destroy function
            destroyTree(root->left);
        }else if(root->right != NULL){
            // use the destroy function
            destroyTree(root->right);
        }else{
            // free space
            free(deleteNode(&root, root->key));
        }

    }
    
}