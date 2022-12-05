#include<iostream>
#include<fstream>
#include<algorithm>
#include<cctype>
#include<string>

#include"intel4004_file_op.h"
#include "translator.h"

using namespace std;

int main(int argc, char **argv){
	if(argc<2){
		cout<<"No file was added as argument"<<endl;
		exit(EXIT_FAILURE);
	}

	string newfilename = "translated_assembly";
	
	if(argc>2)
		newfilename = argv[2];	

	Intel4004_file_op asm_file(argv[1]);

	asm_file.check_syntax_error();

	Translator program(asm_file.asm_code_4004,newfilename);
	program.translate_write_instructions();	
}



