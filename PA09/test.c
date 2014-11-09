#include "answer09.h"

int main(void)
{
	void print_tree2(BusinessNode * tree);
	printf("\e[1;1H\e[2J"); // clears screen
	BusinessNode *Node,*Node1, *Node2, *Node3, *Node4;
	
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
	
	return EXIT_SUCCESS;
}
