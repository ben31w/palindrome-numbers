#include <cstring>
#include <iostream>

using namespace std;

// method headers
bool isPalindrome(long int num);
long int reverse(long int num);
pair<long int, long int> solve(long int &num);


/**
 * Get: C-string of numbers separated by spaces.
 * ex: "4 130031 9"
 *
 * Return: C-string with twice as many numbers separated by spaces
 * 		(two numbers for each number in the parameter string))
 * ex: "1 8 1 260062 2 99"
 */
char* process(const char* numbers) {
	// The result to return.
	string result = "";

	// Create a copy of 'numbers' to tokenize/modify.
	char copy[strlen(numbers)];
	strncpy( copy, numbers, strlen(numbers) );

	// Tokenize the copy. Loop through tokens.
	// Convert each token into a long integer, do the palindrome math,
	// and build the result string.
	const char delimiters[] = " ";
	char * token = strtok(copy, delimiters);
	while (token != NULL) {
		long int num;
		pair<long int, long int> answers;

		num = stol(token);
		answers = solve(num);

		result += to_string(answers.first) + " " + to_string(answers.second) + " ";
		token = strtok(NULL, delimiters); // gets next token
	}

	// Turn result into a c-string and return.
	// NOTE: we need to truncate the final space in the result string
	char * cresult = new char[result.length()];
	std::strcpy (cresult, result.substr(0, result.length() - 1).c_str());
	return cresult;
}


/**
 * Given an integer, return true if it is a palindrome.
 */
bool isPalindrome(long int num) {
	string str = to_string(num);
	for (long int i=0; i<str.length()/2; i++) {
		if (str[i] != str[str.length() - i - 1]) {
			return false;
		}
	}
	return true;
}


/**
 * Given an integer, return its reverse.
 * ex: reverse(1089) = 9081
 */
long int reverse(long int num) {
	string str = to_string(num);
	string reverse = "";
	for (long int i=str.length()-1; i>=0; i--) {
		reverse += str[i];
	}
	return stol(reverse);
}


/**
 * Given an integer, repeatedly add it and its reverse until a
 * palindrome number is reached; once this occurs, return the
 * palindrome number and the number of additions it took to reach
 * the palindrome.
 */
pair<long int, long int> solve(long int &num) {
	long int count = 1;
	long int rev = reverse(num);
	num += rev;

	// Repeat the num + reverse(num) process until we get a palindrome.
	while (!isPalindrome(num)) {
		++count;
		rev = reverse(num);
		num += rev;
	}

	return pair<long int, long int>(count, num);
}


