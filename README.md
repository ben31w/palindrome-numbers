# Natural numbers can become palindromes!
All natural numbers can reach a palindrome (a number that is read the same from left-to-right and 
right-to-left) by repeatedly adding the number to its reverse.

# Example
Given any natural number, we can calculate how many "reverse additions" it takes to reach a palindrome.
Given the number 1089, apply the reverse addition algorithm:
1089 + 9801 = 10890.
              10890 + 09801 = 20691.
                              20691 + 19602= 40293.
                                             40293 + 39204 = 79497 (a palindrome!)

In this case, it took 4 operations to reach the palindrome 79497.

# The program
This program receives a C-style string of space-separated natural numbers, and it
returns another string indicating for each input number (a) the iterations (i.e., number of
additions) it took to calculate the palindrome and (b) the resulting palindrome number.

For example, given the input “1089 1091 1099” 
return “4 79497 1 2992 2 11011” 
(4 and 79497 correspond to 1089, 1 and 2992 correspond to 1091, 1 and 1089 correspond to 1099).

This function is implemented in `solutin.cpp` as `char* process(const char* numbers)`.
