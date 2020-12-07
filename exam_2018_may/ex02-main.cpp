#include <iostream>
#include "ex02-library.h"
using namespace std;

void experimentLeafNodes(Node * n){
	//Initialize the empty set of leaf nodes
	set<string> leaves;
	//Navigate the tree starting from node n, and add to leaves all nodes that have no children
	computeLeaves(n,leaves);
	cout<<"Leaf nodes starting from " << n->name << ":\n";
	printSet(leaves);
}

void experimentDescendants(Node * n){
	//Compute the number of descendants of n.
	int descendants = countDescendants(n);
	cout<< n->name << "'s descendants:"
			<< descendants << "\n";
}

int testMain() {
	/* Create the following family tree
	 * 			Alice
	 * 			/  \
	 * 		  Bob  Carl
	 * 		  /       \
	 * 	   Daisy      Emma
	 */
	Node *Alice = new Node;
	Alice->name="Alice";
	Node *Bob = new Node;
	Bob->name="Bob";
	Node *Carl = new Node;
	Carl->name="Carl";
	Node *Daisy = new Node;
	Daisy->name="Daisy";
	Node *Emma = new Node;
	Emma->name="Emma";
	Alice->left=Bob;
	Alice->right=Carl;
	Bob->left=Daisy;
	Bob->right=nullptr;
	Carl->right=Emma;
	Carl->left=nullptr;
	Daisy->left=nullptr;
	Daisy->right=nullptr;
	Emma->left=nullptr;
	Emma->right=nullptr;

	cout << "Experiments about leaf nodes\n";
	experimentLeafNodes(Alice);
	experimentLeafNodes(Bob);
	experimentLeafNodes(Carl);
	experimentLeafNodes(Daisy);
	experimentLeafNodes(Emma);


	cout << "Experiments about descendants\n";
	experimentDescendants(Alice);
	experimentDescendants(Bob);
	experimentDescendants(Carl);
	experimentDescendants(Daisy);
	experimentDescendants(Emma);
	return 0;
}

int main() {
	return testMain();
}