typdef struct
{
	attributes...;
} MyType;

/*Shadow copy: if you copy attribute by attribute
* and if you copy a pointer they point to same location
* 
* div copy: if pointer make a copy of the value so they 
* don't point to same locationype MyType_copy(MyType t1)
*/
 
// Shadow copy
MyType t1;
t1.x = ...;
t1.y = ...;

t2 =t1; // Same as next two lines below
t2.x = t1.x;
tx.y = t1.y;

// If
MyType *t2; //Then must malloc MyType


//div copy:
MyType MyType_copy(MyType t1) // copy constructor
{
MyType t2;
t2 = t1;
t2.z = malloc(...);
strcpy(t2.z,t1.z);
// Could also replace above two lines with strdup (string dupplication)
return t2;
}
later()
{
free(t1.z);
free(t2.z);
}

