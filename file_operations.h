#include<bits/stdc++.h>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;


class Intel4004_file_op{

	private:
		vector <string> arr_ins{
			"nop","jcn","fim","jin","jun","jms","inc","isz",
			"add","sub","ld","xch","bbl","ldm","wrm","wmp",
			"wrr","wr0","wr1","wr2","wr3","sbm","rdm","rdr",
			"adm","rd0","rd1","rd2","rd3","clb","clc","iac",
			"cmc","cma","ral","rar","tcc","dac","tcs","stc",
			"daa","kbp","dcl","src","fin"
		};

	public:
		vector <vector <string>> asm_code_4004;

	Intel4004_file_op(string filename){


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
			if(find(arr_ins.begin(),arr_ins.end(),check_ins) == arr_ins.end()){
				cerr<<"Syntax Error: No instruction as "<<check_ins<<endl;
				cout<<"Did you mean "<<help_provider(check_ins)<<"?"<<endl;
				cerr<<"Status: Failed to translate program"<<endl;
				exit(EXIT_FAILURE);
			}
		}
	}

	string help_provider(string check_ins){
		int min = 999;
		string close_ins;
		for(int i=0;i<arr_ins.size();i++){
			int equality=0;
			for(int c=0;c<arr_ins[i].size();c++)
				if(arr_ins[i][c]!=check_ins[c])
					equality++;
			if(equality<min){
				min = equality;
				close_ins = arr_ins[i];
			}
		}
		return close_ins;
	}
};
