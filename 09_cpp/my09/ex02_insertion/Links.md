## BOOKS

"The Art of Computer Programming Books"
 https://github.com/manjunath5496/The-Art-of-Computer-Programming-Books

"Sorting: A Distribution Theory"
https://books.google.es/books?id=kM5v2YqMVuoC&pg=PA286&redir_esc=y#v=onepage&q&f=false				

Ford-Johnson-algorithm
https://warwick.ac.uk/fac/sci/dcs/teaching/material-archive/cs341/fj.pdf

## Best links
/nerraou/Ford-Johnson-algorithm
https://github.com/nerraou/Ford-Johnson-algorithm


"CPP09 — School42"
https://medium.com/@sofia.huppertz/cpp09-school42-1efa42df7803

sofiahuppertz/CPP09
https://github.com/sofiahuppertz/CPP09

## LINKS

 "Merge Insertion Sort"  
 https://iq.opengenus.org/merge-insertion-sort/

 "Ford-Johnson merge-insertion sort"
 https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort

 "Merge-insertion sort" or "Ford–Johnson algorithm"
 https://en.wikipedia.org/wiki/Merge-insertion_sort

 "Insertion sort"
 https://en.wikipedia.org/wiki/Insertion_sort

 "Ordenamiento por inserción"
 https://es.wikipedia.org/wiki/Ordenamiento_por_inserci%C3%B3n

 "Binary search"
 https://en.wikipedia.org/wiki/Binary_search

"Jacobsthal number"
https://en.wikipedia.org/wiki/Jacobsthal_number


 https://github.com/sofiahuppertz/CPP09

 ford-johnson-merge-insertion-sort
 https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort
  
 42 Seoul - CPP09
https://woongtech.tistory.com/entry/42SEOUL-CPP-Module-09#Ex02-1 
	Traduccion
	https://woongtech-tistory-com.translate.goog/entry/42SEOUL-CPP-Module-09?_x_tr_sl=auto&_x_tr_tl=es&_x_tr_hl=es&_x_tr_pto=wapp#Ex02-1

"Human explanation and step-by-step visualisation of the Ford-Johnson algorithm¨
https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91	

## Algorithm 

 https://en.wikipedia.org/wiki/Merge-insertion_sort
 Merge-insertion sort performs the following steps, on an input X  of n  elements

1- Group the elements of X into ⌊ n / 2 ⌋pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.
2- Perform ⌊ n / 2 ⌋ comparisons, one per pair, to determine the larger of the two elements in each pair.
3- Recursively sort the ⌊ n / 2 ⌋ larger elements from each pair, creating a sorted sequence S of ⌊ n / 2 ⌋  of the input elements, in ascending order, using the merge-insertion sort.
4- Insert at the start of S the element that was paired with the first and smallest element of S.
5- Insert the remaining ⌈ n / 2 ⌉ − 1  elements of X ∖ S into S one at a time, with a specially chosen insertion ordering described below. Use binary search in subsequences of S (as described below) to determine the position at which each element should be inserted.



 ford-johnson-merge-insertion-sort
 https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort
 
 Implementation:

The implementation of FJMI sort accompanying this paper was written in Python and follows the following steps:

    Determine if the array is even or odd numbered in length. If odd, remove the last number, designate it as a ‘straggler’ and insert it later into the sorted array.
    Arbitrarily divide the sequence to sort into pairs of two values.
    Sort the pairs bitwise, so the order is always [less, greater].
    Sort the sequence recursively by the value of it’s largest pair.
    Create a new sequence ‘S’, by pulling out the [highest] value of each pair and inserting it into ‘S’.
    The remaining values form a temporary ‘pend’ array.
    Based on the length of ‘pend’, build the optimal insertion sequence using relevant Jacobsthal numbers.
    Loop through the elements in ‘pend’, and using the insertion sequence built in the previous step, use binary search to insert each ‘pend’ element into ‘S’.
    If a ‘straggler’ was found, do a leftover loop and insertion to complete the list.

Step 1: ‘Straggler’ Catching

In order to determine if the given array is even or odd, the operation requires a simple modulo calculation. This is performed within the body of ‘merge_insertion_sort’ against the incoming array and is saved as a boolean value.

If the operation proves it’s an odd-number length array, we ‘pop’ the last value from the incoming array arbitrarily and save it into a local value. If we find it’s even, we set the value to ‘False’. We’ll use this value later during ‘create_s’ as an optional parameter where it will be placed in the ultimately sorted array.
Step 2: Creating Pairs

In order to structure the data to follow FJMI, the values in the array need to be arbitrarily sorted into pairs. We do this by using ‘create_pairs’, which loops through the value, and using temporary array stores, creates ‘pairs’ with two element arrays which are inserted into a larger array that is returned.
Step 3: Sorting each pair

Once the array we need to sort is paired, we use ‘sort_each_pair’ and pass in the paired array. This function loops through the pairs, and does a simple bitwise comparison placing the smaller number on the left and the larger on the right, and returns the array to the user.
Step 4: Sort the Pair Sequence by its greater value

The next step in FJMI is to recursively sort all the pairs by their largest element. In this implementation, we use ‘sort_by_larger_value’, which receives the array (which has already been split into pairs, and each pair sorted itself) and uses a modified recursive insertion sort (using functions ‘insertion_sort_pairs’ and ‘insert’) that perform this action. This leaves the array sorted by the greater value in each pair.
Steps 5-9: Creating sorted ‘S’ sequence

The following steps contain the most complex aspects of FJMI. In this implementation, these steps are housed in ‘create_s’, which takes the array output by ‘sort_by_larger_value’ and the previous steps, as well as the ‘straggler’ value mentioned in step one if applicable, and returns the completed sorted sequence.

The function first creates the ‘main’ array (we call it ‘S’) which we will eventually return, as well as ‘pend’, which will be a temporary hold used during FJMI. After creating both empty arrays,, it loops through the incoming paired array, placing the larger values (which have been sorted) into ‘S’, and the remaining smaller elements into ‘pend’.

Immediately, since we know the first element in ‘pend’ ( we call it: ‘p1’) is smaller than the first element in the ‘S’ array (‘s1’), we insert it in the ‘0’ index of S.

After this step, we have to create the sequence in which we can optimally insert the remaining ‘pend’ elements in a sequence that leverages the fact that in a worst-case scenario, binary search performs best when the sub-sequence searched is one-less than the power of two. As Knuth discovered, the pattern here corresponds with Jacobsthal numbers -- a sequence we’ll build with ‘build_jacob_insertion_sequence’.

This function takes the ‘pend’ array, and using it’s length, leverages a recursive Jacobsthal generation function ‘jacobsthal’, builds and returns an array of the relevant Jacobsthal numbers which will be used to build the full insertion sequence.

The sequence commences by looping through the ‘pend’ array, dynamically determining the full sequence (it must use the Jacobsthal numbers, filled in with the remaining values depending on context), subsequently determining the exact insertion point and finally inserting each value into S, taking advantage of the above key efficiency in FJMI. This sequence begins to look like [1, 3, 2, 5, 4, 11…], continuing on with depending on the length on the ‘pend’ array.

Finally, if a ‘straggler’ was passed into this function, we perform a binary search against the entire ‘S’ sequence and insert it into S as well, before returning the final sorted array.

