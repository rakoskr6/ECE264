#include "answer09.h"

int main(void)
{
	printf("\e[1;1H\e[2J"); // clears screen
	char stars[] = "4.5";
	char name[] = "Awesome Business";
	char address[] = "Purdue Road, Purdue";
	BusinessNode *Node;
	
	Node = create_node(stars,name,address);
	Node1 = create_node("3.2","Yummy","here");
	Node2 = create_node("3.9","K","There");
	Node3 = create_node("5.0","La sta","DC");
	Node4 = create_node("0.9","App","Gary");
	
	
	printf("The name is %s, address is %s with %s stars\n",Node->name,Node->address,Node->stars);
	printf("The name is %s, address is %s with %s stars\n",Node1->name,Node1->address,Node1->stars);
	printf("The name is %s, address is %s with %s stars\n",Node2->name,Node2->address,Node2->stars);
	printf("The name is %s, address is %s with %s stars\n",Node3->name,Node3->address,Node3->stars);
	printf("The name is %s, address is %s with %s stars\n",Node4->name,Node4->address,Node4->stars);
	return EXIT_SUCCESS;
}
