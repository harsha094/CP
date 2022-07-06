#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
    node(int d){
        this->data = d;
        this->left= NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<<data << endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of "<< data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(temp == NULL){//purana level complete traverse ho chuka hai
            cout<< endl;
            if(!q.empty()){// queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout<< temp -> data << " ";
            if(temp->left){
            q.push(temp->left);
            }
            if(temp->right){
            q.push(temp->right);
            }
        }
    }
    
}

void inorder(node* root){
    //base case
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<< root-> data << " ";
    inorder(root->right);
}

void preorder(node* root){
    //base case
    if(root == NULL){
        return;
    }

    cout<< root-> data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    //base case
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<< root-> data << " ";
}

int main(){
    node* root = NULL;
    //creating a tree
    root = buildTree(root);

    //level order
    cout<< "Printing the level order traversal output" << endl;
    levelOrderTraversal(root);

    cout<< " Inorder traversal is ";
    inorder(root);

    cout<< "\n Preorder traversal is ";
    preorder(root);

    cout<< "\n Postorder traversal is ";
    postorder(root);

    return 0;
}

/* Output - 
Enter the data: 
1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
Enter data for inserting in left of 1
Enter the data:
Enter data for inserting in left of 3
Enter the data:
Enter data for inserting in left of 7
Enter the data:
Enter data for inserting in right of 7
Enter the data:
Enter data for inserting in right of 3
Enter the data:
Enter data for inserting in left of 11
Enter the data: 
Enter data for inserting in right of 11
Enter the data:
Enter data for inserting in right of 1
Enter the data:
Enter data for inserting in left of 5
Enter the data:
Enter data for inserting in left of 17
Enter the data:
Enter data for inserting in right of 17
Enter the data:
Enter data for inserting in right of 5
Enter the data:
Printing the level order traversal output
1
3 5
7 11 17
 Inorder traversal is 7 3 11 1 17 5
 Preorder traversal is 1 3 7 11 5 17
 Postorder traversal is 7 11 3 17 5 1
*/
