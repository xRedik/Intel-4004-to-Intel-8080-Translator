#include<bits/stdc++.h>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;


class Intel4004_file_op{

	private:
		unordered_map <string,int> umap_ins;

	public:
		vector <vector <string>> asm_code_4004;

	Intel4004_file_op(string filename){

		//initialize umap
		umap_ins = {{"nop",0},{"jcn",1},{"fim",1},{"jin",1},{"jun",1},
			    {"jms",1},{"inc",1},{"isz",1},{"add",1},{"sub",1},
			    {"ld",1},{"xch",1},{"bbl",1},{"ldm",1},{"wrm",1},
			    {"wmp",1},{"wrr",1},{"wr0",1},{"wr1",1},{"wr2",1},
			    {"wr3",1},{"sbm",1},{"rdm",1},{"rdr",1},{"adm",1},
			    {"rd0",1},{"rd1",1},{"rd2",1},{"rd3",1},{"clb",1},
			    {"clc",1},{"iac",1},{"cmc",1},{"cma",1},{"ral",1},
			    {"rar",1},{"tcc",1},{"dac",1},{"tcs",1},{"stc",1},
			    {"daa",1},{"kbp",1},{"dcl",1},{"src",1},{"fin",1},
		};

		ifstream intel4004_file(filename);

		if(!intel4004_file.is_open()){
			cerr<<"Error: "<< strerror(errno)<<endl;
			exit(EXIT_FAILURE);
		}
	
		string ins;
		while(getline(intel4004_file,ins)){
			transform(ins.begin(), ins.end(), ins.begin(),
    			[](unsigned char c){ return std::tolower(c); });
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
			if(!line_set.empty())
				asm_code_4004.push_back(line_set);
		}

	}

	void check_syntax_error(){
		for(auto ins: asm_code_4004){
			string check_ins = ins[0];
			if(ins[0].empty())
				check_ins= ins[1];
			if(check_ins[check_ins.size()-1]==',')
				continue;
			if(umap_ins.find(check_ins) == umap_ins.end()){
				cerr<<"Syntax Error: No instruction as "<<check_ins<<endl;
				cerr<<"Failed"<<endl;
				exit(EXIT_FAILURE);
			}
		}
	}
};



