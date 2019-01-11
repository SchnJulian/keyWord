#include "search.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
constexpr auto GREEN = "\x1B[32m";
constexpr auto NORMAL = "\x1B[0m";

bool search(std::string &param) {

	/*
	 * Opening the input-file
	 * */

	std::ifstream input_file { };
	std::cout << "Enter the name of the file you want to read: ";
	std::string filename { };
	std::getline(std::cin, filename);
	/*
	 * If the filename entered by the user does not contain the file suffix '.txt'
	 * it is appendes to the end of the string. If the user already added '.txt'
	 * the program continues
	 * */
	if (filename.find(".txt") == std::string::npos) {
		filename.append(".txt");
	}
	input_file.open(filename);
	if (input_file.is_open() == false) {
		std::cerr << "\nError opening the input-file\n";
	}

	/*
		 * Creating the output-file
		 * */

		std::ofstream output_file { };
		output_file.open("output.txt");

		if (!output_file.good()) {
			std::cerr << "\nError creating output file!\n";
			return false;
		}


	std::string temp {};
	while(!input_file.eof()){
		std::getline(input_file, temp, '.');
		if(temp.find(param) != std::string::npos){
			output_file << temp << '.' << std::endl;
		}
	}
	credits(output_file,param);
input_file.close();
output_file.close();

std::cout << GREEN << "File successfully processed! Have a great day!\n\n" << NORMAL;
	return true;
}


void credits(std::ofstream& stream, std::string &param){
	stream << "\n\n\n List of sentences containing the word" << param << ".\n Composed using keyWord by Julian Schnabel\n NO guarantee of completeness or accuracy!";
}























