#include <iostream>
#include <string>
#include <limits>
#include <cmath>
using std::string;
using std::cout;
using std::cin;
using std::endl;

struct node{
    int val;
    node* left = nullptr;
    node* right = nullptr;
};
    //Node structure for BST

struct branch{
	branch *prev;
	string str;
};
    //Helper structure for printing the BST
void menu(node* root);
    //Menu function for manipulation of a BST givin a node.
    //POST:
    //  BST will be emptied and reverted back to a null pointer.

int userInInt();
    // Requests and int from the user and then verifies it is an int.
    // The validated user input is then returned
    // NOTE: NO OUTPUT TO USER UNLESS INVALID INPUT
bool search(node* root, int num);
    //Search the given BST for a node with data value of key. Returns true if found.
node* insert(node* root, int num);
    //Insert node into tree.
node* delNode(node* root, int num);
    //delete node from tree. will cout if no item is found
void printSorted(node* root);
    //print the items in the node sorted greatest to least.
int bigCost(node* root);
    // prints the largest cost of the tree.
void printBranch(branch *last);
    //helper function for print tree
void printTree(node *root, branch *last, bool isLeft);
    //print BST, will cout nothing if empty.
void deleteTree(node *root);
    // function to delete every node in the given BST. Must be 'new' allocated nodes.
int main(){
    //Root of BST
    node *root = nullptr;
    menu(root);
    return 0;
}

bool search(node* root, int num){
    if(root == nullptr){
        //if no match
        return false;
    }
    if(root->val == num){
        //if match
        return true;
    }
    if(root->val < num){
        //If less than current node, go to left
        return search(root->left, num);
    }
    else if(root->val > num){
        //if greater than current node, go right
        return search(root->right, num);
    }
    return false;
} //done
node* insert(node* root, int num){
    if(root == nullptr){
        //if found location to add new node,
        //creates new temp node and returns its pointer, setting it to the parent node by returning it.
        node* temp = new node;
        temp->val = num;
        root = temp;
        cout << "Node inserted!\n"  << endl;
        return root;
    }
    if(root->val == num){
        //if the node is already in the tree
        cout << "Number already in Tree!\n";
        return root;
    }
    if(root->val < num){
        root->left = insert(root->left, num);
    }
    else if(root->val > num){
        root->right = insert(root->right, num);
    }
    return root;
}
node* delNode(node* root, int num){
    if(root == nullptr){
        //if  nullptr, already deleted.
        return root;
    }
    if(root->val < num){
        root->left = delNode(root->left, num);
    }
    else if(root->val > num){
        root->right = delNode(root->right, num);
    }
    else{
        //if right child is empty, move left child to parent.
        if(root->right == nullptr){
            cout << "Here!";
            node *temp = root->left;
            free(root);
            return temp;
        }
        else if(root->left == nullptr){
            //if left child empty, move child to parent.
            node *temp = root->right;
            free(root);
            return temp;
        }
        else{
            //if both children, fight the left most child of the right child, and move up.
            node *temp = root;
            temp = temp->right;
            //finding most left child of right child
            while(temp->left!= nullptr){
                temp = temp->left;
            }
            root->val = temp->val;
            root->right = delNode(root->right, root->val);

        }
    }
    return root;
}
void printSorted(node* root){
    //prints out the sorted BST nodes
    if(root != nullptr){
        printSorted(root->left);
        cout << root->val << "  ";
        printSorted(root->right);
    }
}
int bigCost(node* root){
    //finds largest cost.
    if(root == nullptr){
        return 0;
    }
    else{
        //compares the cost by finding the largest cost of path recursivly.
        int right_childcost = bigCost(root->right) + root->val;
        int left_childcost = bigCost(root->left) + root->val;
        if(right_childcost > left_childcost) return right_childcost;
        return left_childcost;
    }
}
void printBranch(branch *last){
	if (last == nullptr)
		return;
        //recursivly prints branches
	printBranch(last->prev);

	cout << last->str;
}
void printTree(node *root, branch *last, bool isLeft){
    //prints tree
	if (root == nullptr)
		return;

	string lastStr = "    ";
	branch *stick = new branch;
    stick->prev = last;
    stick->str = lastStr;

	printTree(root->left, stick, true);

    //making of branches
	if(!last)
		stick->str = "---";
	else if(isLeft){
		stick->str = ".---";
		lastStr = "    |";
	}
	else{
		stick->str = "`---";
		last->str = lastStr;
	}

    //print branch
	printBranch(stick);
    if(root->val < 0){
        cout << '(' << root->val << ')' << endl;
    }
    else{
        cout << root->val << endl;
    }
	if (last) last->str = lastStr;
	stick->str = "    |";

	printTree(root->right, stick, false);
}
void menu(node* root){
    int choice = 0;
    int val;
    while(choice != 7){
        cout << "----------------------------------------------\n";
        cout << "Please select what you would like to do:\n";
        cout << "1) Search for a node\n";
        cout << "2) Insert a new node\n";
        cout << "3) Delete a node\n";
        cout << "4) Display all nodes in tree format\n";
        cout << "5) Print keys for BST in order\n";
        cout << "6) Return highest cost of BST\n";
        cout << "7) Exit program\n";
        choice = userInInt();
        switch (choice) {
            case 1:
                cout << "Please enter a number to search\n>> ";
                val = userInInt();
                if(search(root, val)) cout << "Found in tree!\n";
                else{
                    cout << "Not in tree!\n";
                }
                break;
            case 2:
                cout << "Please enter a number to insert\n>> ";
                val = userInInt();
                root = insert(root, val);
                break;
            case 3:
                cout << "Please enter a number to delete\n>> ";
                val = userInInt();
                root = delNode(root, val);
                cout << "Node deleted!\n";
                break;
            case 4:
                printTree(root, nullptr, false);
                break;
            case 5:
                printSorted(root);
                cout << endl;
                break;
            case 6:
                cout << "Largest cost is: " << bigCost(root) << endl;
                break;
            case 7:
                //cout << "Goodbye!";
                deleteTree(root);
                root = nullptr;
        }
    }
}
int userInInt(){
    //input verification
	int temp;
	cin >> temp;
	while(cin.fail()){
		cout << "That was not a number! Please enter a number\n>> ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> temp;
	}
	return temp;
}
void deleteTree(node *root){
    if(root == nullptr){
        return;
    }
    //deletes every node of a tree.
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
