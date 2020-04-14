# push_swap

Push swap is a project that challenges the programmer to create an algorithm that sorts a list of numbers.

## Objective

To take an argument of integers (or string and convert to int) and sort them into ascending order using only 2 stacks and a restricted set of rules for sorting. Extra points are awarded for sorting with lower moves. There are two programs running simultaneously. Push_swap and Checker. Push_swap handles the algorithm and sends instructions to stdout where Checker picks up the instructions and performs those operations. Checker then returns OK or KO depending on if your list is sorted.

### Rules

PA - Put A - Puts the head of stack a to the head of stack b. Costs 1 move.
PB - Put B - Puts the head of stack b to the head of stack a. Costs 1 move.

SA - Swap A - Provided there are more than one integer in stack A, swap the head and head->next value. Costs 1 move.
SB - Swap B - Same as A but for stack B.
SS - Swaps both A and B but with a single move.

RA - Rotate A - Rotates list A. The head value becomes the tail value. Costs 1 move.
RB - Rotate B - Same as A but for stack B.
RR - Rotates A and B but with a single move.

RRA - Reverse Rotate A - The tail value becomes the head value. Costs 1 move.
RRB - Same as A but for stack B.
RRR - Reverse Rotates both A and B but costs a single move.

### How This Algorithm Functions

Assuming a valid integer set or string has been passed:

1.  A check against possible duplicates is performed.
2.  The median value is found.
3.  Stack A is pushed to B in two stages.
  * Excluding the min and max values, values lower than or equal to the median are pushed (PB) to stack B first. Others are rotated (RA).
  * Once the list len of A is less than the start / 2, the remaining values are pushed to stack B.
4.  
