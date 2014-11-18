/* How many "+" used for integer partition*/
4 = 1 + 2 + 1		//twice
  = 1 + 3			// once
  = 1 + 1 + 1 + 1	// three
// There are 2^(n-1) lines to partition
// Let f(n) be number of "+" signs used to partition.
f(1) = 0
f(2) = 1

// Then
n = 1 + (n-1)
  = 1 + (n-1)
  = 1 + (n-1)
  ...
  = 2 + (n-2)
  ...
// Therefore
f(n-1) + 2^((n-1)-1) // and
f(n-2) + 2^((n-1)-2)

// Finally
f(n) = f(n-1)+2^(n-2) + f(n-2)+2^(n-3) + f(n-3)+2^(n-4) + f(1) + 1
f(n)= 2*f(n-1) + 2^(n-2)

// Closed form (not using f(n-x)) is
// take f(n) - f(n-1)
f(n)= 2*f(n-1) + 2^(n-2)	
f(n-1) = 2*f(n-2) + 2^(n-3)
2f(n-1) = 4f(n-2) + 2^(n-2)

2^(x)*f(n-k) = 2^(k+1)*f(n-k-1) + 2^(n-2)
// finally
f(n) = 2^(n-2) * (n-1)


/* Shapes of binary tree */
// Two trees have the same shape if they have the same number of nodes 
// on the left side and the right side

f(n) // number of shapes for binary tree with n nodes
f(1) = 1;
f(2) = 2;
f(3) = 5;

f(k) 		// nodes on left side
f(n-k-1)	// nodes on right side

// Sumation from k=0 to (n-1)
f(k) * f(n-k-1) // multiply together for total number of shapes

// some permutations will produce the same shape. So
f(n) < n!


/* Decimal Packing */
// one byte contains multiple digits

// shift left by 4
<< 4

// shift right by 4
>> 4






