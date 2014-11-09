#include "answer09.h"

int main(void)
{
	void print_tree2(BusinessNode * tree,int i);
	printf("\e[1;1H\e[2J"); // clears screen
	BusinessNode *Node,*Node1, *Node2, *Node3, *Node4, *Holder;
	
	Node = create_node("4.5","Awesome Business","Purdue");
	Node1 = create_node("3.2","Yummy","here");
	Node2 = create_node("3.9","K","There");
	Node3 = create_node("5.0","La sta","DC");
	Node4 = create_node("0.9","App","Gary");
	
	
	print_node(Node);
	print_node(Node1);
	print_node(Node2);
	print_node(Node3);
	print_node(Node4);
	printf("\n------------\n");

	Holder = tree_insert(Node1,Node);
	Holder = tree_insert(Node2,Node);
	Holder = tree_insert(Node3,Node);
	Holder = tree_insert(Node4,Node);
	print_tree2(Holder,0);
	destroy_tree(Holder);
	
	return EXIT_SUCCESS;
}
