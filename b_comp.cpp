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
	vector <string> asm_code_4004;
	while(getline(intel4004_file,ins))
		asm_code_4004.push_back(ins);

	intel4004_file.close();

	for(auto i: asm_code_4004){
			cout<<i<<endl;
	}
	
	cout<<"********************************"<<endl;

	vector <vector<string>> instruction_set;
	for(auto v: asm_code_4004){

		vector <string> line_set;
	        string	s = "";
		for(int i=0;i<v.size();i++){
			if(v[i]==' ' || i==v.size()-1){
				if(i==v.size()-1 && v[i]!=' ')
					s+=v[i];
				line_set.push_back(s);
				s="";
			}
			else
				s+=v[i];
		}
		instruction_set.push_back(line_set);
	}

	for(int i=0;i<instruction_set.size();i++){
		for(auto j: instruction_set[i]){
			cout<<j<<" | ";
		}
		cout<<endl;
	}
	cout<<endl;
}
