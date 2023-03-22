#  																							Hashing and Collisions 



#														 HASHING 


The proceses of mapping a key value to a position in a table.

A hash function maps key values to positionss. It is denoted by [red] h

A hash table is an array that hodls the records. It is denoted by [green] T

The has table has [red] M slots, indexed from 0 to M-1.


For any value [red] K in the key range and some hash function [red] h.

[example]

[blue] h(K) = i; 0 <= i < M, sucj that key T[i]) = K

[bold] Load factor

The ration of the number of items in the table to the table size

[example]

[blue] Load factor = Number of items in the table / Table size



## Direct Address Tables

	* If we have a collection og n elements whose keys are unique integers in (1...m), where m >= n, then we can store the items in a [red] direct address table, where  [red] T[i] is either empty or contains one of the elements of our collections


[src] [image]  direct access image



	* Searching a direct address table operation for a particular key [red] K, we can access [red] T[K]; if it contains an element, return it, if it dowsnt then return a NULL


[blue] There are two constraints here:

	* 	the keys must be unique
  	* the range of the key must be severely bounded 


[image] 

The range of the key determines the size of the direct address table and may be too long to be practical

[blue] Therefore...
	Direct addressing is easily generalized to the case where there is a function,


[example-red] h(k) => (1,m)

which maps each value of the key, k to the range (1,m). In this case, we place the element in T[h(k)] rather than T(k)



The range of the key function determines the size that the function h(k), is a one-to-one from each k to integers in (1,m) 