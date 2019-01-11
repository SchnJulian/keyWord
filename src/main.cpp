/*
 * Author: Julian Schnabel (c) 2019
 *
 *
 *
 * */
#include "search.h"
#include <iostream>

int main(int argc, char **argv) {

	std::cout << "Please enter the word you want to search: ";
	std::string temp_param { };
	std::getline(std::cin, temp_param);
/*
 *	'Enclose' the word to search for with spaces to
 *	prevent retruning strings with thise paramer in the word
 *	E.g.:
 *	param = ' vest '
 *	inVESTigation vs. vest
 *
 * */
	if (temp_param.at(0) != ' ') {
		temp_param.insert(0, " ");
	}
	if (temp_param.back() != ' ') {
		temp_param.push_back(' ');

	}

	search(temp_param);
}
