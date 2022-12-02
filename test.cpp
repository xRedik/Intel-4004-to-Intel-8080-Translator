#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include <algorithm>
#include <cctype>
#include <string>

#include"file_operations.h"

using namespace std;

int main(int argc, char **argv){
	if(argc<2){
		cout<<"No file was added as argument"<<endl;
		exit(EXIT_FAILURE);
	}

	Intel4004_file_op asm_file(argv[1]);

	asm_file.check_syntax_error();
}
