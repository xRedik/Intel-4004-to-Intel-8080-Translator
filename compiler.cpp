#include<bits/stdc++.h>
#include<iostream>
#include<fstream>

using namespace std;

int main(int argc, char **argv){
	if(argc<2){
		cout<<"No file was added as argument"<<endl;
		return -1;
	}

	vector <string> arg_list(argv+1, argv+argc);
	
	ifstream intel4004_file(arg_list[0]);

	if(!intel4004_file.is_open()){
		cerr << "Error: " << strerror(errno)<<endl;
		return -1;
	}

	string ins;
	vector <vector<string>> instruction_set;
	while(getline(intel4004_file,ins)){
		vector <string> line_set;
	        string	s = "";
		for(int i=0;i<ins.size();i++){
			if(ins[i]==' ' || i==ins.size()-1){
				if(i==ins.size()-1 && ins[i]!=' ')
					s+=ins[i];
				line_set.push_back(s);
				s="";
			}
			else
				s+=ins[i];
		}
		instruction_set.push_back(line_set);
	}

	
	intel4004_file.close();
//		asm_code_4004.push_back(ins);
	cout<<"********************************"<<endl;


	for(int i=0;i<instruction_set.size();i++){
		for(auto j: instruction_set[i]){
			cout<<j<<" | ";
		}
		cout<<endl;
	}
	cout<<endl;
}
