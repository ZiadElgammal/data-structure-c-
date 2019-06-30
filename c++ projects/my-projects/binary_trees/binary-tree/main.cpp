#include <iostream>
#include <cstdlib>

class Node
{
  public:
    Node *left;
    Node *right;
    int data;
};

using namespace std;

class BinaryTree
{
  public:
    BinaryTree();             //constructor
    ~BinaryTree();            //destructor
    void newNode(int key);    //add new element to the tree
    void searchNode(int key); //search for an element in the the tree
    void preorder_print();    //print elements in preorder form (root left right)
    int leavesCount();        //return the number of leafs in a tree
    void getMin();
    void contains(int key);

  private:
    Node *root;
    int leavesNum = 0;

    void insert(int key, Node *leaf); //insert in binary search tree
    void preorder_print(Node *leaf);
    void search(int key, Node *leaf);
    int leavesCount(Node *leaf);
    void getMin(Node *leaf);
    bool contains(int key ,Node *leaf);
};


BinaryTree::BinaryTree()
{
    Node *root = NULL;
}
void BinaryTree::contains(int key)
{
    cout<<contains(key, root);
}
bool BinaryTree::contains(int key ,Node *leaf)
{
    bool found =false ;
    if(this->root==NULL)
    {
        found = false;
    }else 
    {  Node *current = this->root;
       while(current !=NULL && !found)
       {
           if(current->data == key)found = true;
           else if(current->data >key) current = current->left;
           else current = current->right;
       }
    
    }
    return found;
}


void BinaryTree::newNode(int key)
{
    if (root != NULL)
    {
        insert(key, root);
    }
    else
    {
        Node *temp = new Node();
        temp->data = key;
        root = temp;
        root->left = root->right = NULL;
    }
}

void BinaryTree::insert(int key, Node *leaf)
{
    if (key < leaf->data) //if data is smaller than the node, go to left side
    {
        if (leaf->left != NULL) //if the left child of the node isn't empty
        {
            insert(key, leaf->left); //call the function again by sending the left child node
        }
        else //if data is smaller than root and left leaf is empty
        {
            leaf->left = new Node;
            leaf->left->data = key;
            leaf->left->left = leaf->left->right = NULL;
        }
    }
    else if (key > leaf->data) //if data is bigger than root ,go right
    {
        if (leaf->right != NULL) //if right leaf isn't empty
        {
            insert(key, leaf->right);
        } //call function again by sending the right child node

        else
        {
            leaf->right = new Node;
            leaf->right->data = key;
            leaf->right->left = leaf->right->right = NULL;
        }
    }
}
void BinaryTree::preorder_print()
{
    preorder_print(root);
    cout << "\n";
}
void BinaryTree::preorder_print(Node *leaf)
{
    if (leaf != NULL)
    {
        cout << leaf->data << "\n";
        preorder_print(leaf->left);
        preorder_print(leaf->right);
    }
}
void BinaryTree::searchNode(int key)
{
    return search(key, root);
}

void BinaryTree::search(int key, Node *leaf) //root
{
    cout << "searching for " << key << " in the tree \n";
    if (leaf != NULL) //if root node is not empty
    { 
        if (key == leaf->data)
        {
            cout << key << " found at root node ";
        }
    }
}

int BinaryTree::leavesCount()
{
    leavesCount(root);
}

int BinaryTree::leavesCount(Node *leaf)
{
    if (leaf == NULL) //if there isn't any elemnets in the tree
        return 0;
    if (leaf->left == NULL && leaf->right == NULL) //if node is leaf
        return 1;
    else //if node has left or right child
        return leavesCount(leaf->left) + leavesCount(leaf->right);
}
void BinaryTree::getMin()
{
    getMin(root);
}

void BinaryTree::getMin(Node *leaf)
{
    if (leaf != NULL)
    {
        while (leaf->left != NULL)
        {
            leaf = leaf->left;
        }
        cout << "minimum value is " << leaf->data << "\n";
    }
    else
    {
        cout << "tree is empty \n";
    }
}
////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
int main()
{

    BinaryTree *t1 = new BinaryTree();
    t1->newNode(100);
    t1->newNode(5);
    t1->newNode(3);
    t1->newNode(1);
    t1->newNode(16);
    t1->newNode(25);
    t1->newNode(11);
    t1->newNode(150);
    t1->newNode(145);
    t1->newNode(170);
    t1->newNode(171);
    t1->newNode(165);
    t1->preorder_print();
    //t1->getMin();
    //t1->searchNode(11);
  // cout << "Leaf count of the tree is : " << t1->leavesCount() << endl;
    // cout << "Hello world!" << endl;
    t1->contains(25);
    return 0;
}
