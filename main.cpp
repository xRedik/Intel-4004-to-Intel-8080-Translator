#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include <algorithm>
#include <cctype>
#include <string>

#include"file_operations.h"
#include "translator.h"

using namespace std;

int main(int argc, char **argv){
	if(argc<2){
		cout<<"No file was added as argument"<<endl;
		exit(EXIT_FAILURE);
	}

	Intel4004_file_op asm_file(argv[1]);

	asm_file.check_syntax_error();

//	for(auto v: asm_file.asm_code_4004){
//		for(int i=0;i<v.size();i++){
//			cout<<v[i]<<" < ";
//		}
//		cout<<endl;
//	}
//
	Translator program(asm_file.asm_code_4004,"new_assembly");
	program.translate_write_instructions();	
}
