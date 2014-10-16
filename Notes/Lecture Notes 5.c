typedef struct
{
	int year;
	char *name
} Person;


typedef struct //typedef allows the use of person instead of struct person.
{
	Person P;
	float GPA;
	char *school;
} student;


Person P;
P.name = malloc(...); // Add space for name
Person P2
P2.name = malloc(...);

/* Shallow copy - point to pointer and changing one changes everything ps = p;
 * 
 * Deep copy - individual copy strcpy(p2.name, p.name)
 */


Person *q;
q->name // Same as q[0].name


fwrite(pointer, sizeof(...),1.fptr); // Writes binary
