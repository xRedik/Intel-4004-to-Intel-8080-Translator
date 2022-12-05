#include<bits/stdc++.h>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;


class Translator{

	private:
		unordered_map <string,int> umap_ins;
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
		string new_filename;

	Translator(vector <vector <string>> asm_code,string filename){
		new_filename = filename;
		new_filename+=".asm";
		asm_code_4004 = asm_code;
		if(asm_code.empty()){
			cerr<<"File is empty"<<endl;
			exit(EXIT_FAILURE);
		}
	}

	void translate_write_instructions(){
		ofstream intel8080_file(new_filename);
		string t_ins;
		for(auto ins: asm_code_4004){
			int index = 0;
			string comment = " ";
			t_ins = ins[index];
			if(t_ins.empty()){
				intel8080_file << " ";
				t_ins = ins[++index];
			} 
			// first same ins, then different
			if(!t_ins.compare("cmc"))
				intel8080_file << "CMC";
			else if(!t_ins.compare("stc"))
				intel8080_file << "STC";
			else if(!t_ins.compare("cma"))
				intel8080_file << "CMA";
			else if(!t_ins.compare("nop"))
				intel8080_file << "NOP";
			else if(!t_ins.compare("daa"))
				intel8080_file << "DAA";
			else if(!t_ins.compare("rar"))
				intel8080_file << "RAR";
			else if(!t_ins.compare("ral"))
				intel8080_file << "RAL";
			else if(!t_ins.compare("iac"))
				intel8080_file << "INR a";
			else if(!t_ins.compare("dac"))
				intel8080_file << "DCR a";
			else if(!t_ins.compare("clb"))
				intel8080_file << "XRA a";
			else if(!t_ins.compare("ldm")){
				intel8080_file << "MVI a, ";
				if(ins.size()>index+1){
					string data = ins[++index]+"h";
					intel8080_file << data;
				}
				else{
					cerr<<"There is no second argument for ldm"<<endl;
					exit(EXIT_FAILURE);
				}
			}
			else if(!t_ins.compare("inc")){
				intel8080_file << "INR ";
				if(ins.size()>index+1){
					string reg = ins[++index];
					if(!reg.compare("0p") || !reg.compare("1p"))
						intel8080_file << "b";
					else if(!reg.compare("2p") || !reg.compare("3p"))
						intel8080_file << "c";
					else if(!reg.compare("4p") || !reg.compare("5p"))
						intel8080_file << "d";
					else if(!reg.compare("6p") || !reg.compare("7p"))
						intel8080_file << "e";
					else if(!reg.compare("8p") || !reg.compare("9p"))
						intel8080_file << "h";
					else if(!reg.compare("10p") || !reg.compare("11p"))
						intel8080_file << "l";
					else if(!reg.compare("12p") || !reg.compare("13p") || 
					 	!reg.compare("14p") || !reg.compare("15p")){
						cerr<<"The register 12p, 13p, 14p and 15p is not supported"<<endl;
						exit(EXIT_FAILURE);
					}
					else{
						cerr<<"There is an error while checking the register name"<<endl;
						cerr<<"The register name "<<reg<<"is incorrect"<<endl;
						exit(EXIT_FAILURE);
					}
				}
				else{
					cerr<<"There is no second argument for inc"<<endl;
				}
			}


			if(ins.size() > index+1){
				if(ins[index+1][0]==';')
				{
					for(int i=index+1;i<ins.size();i++)
							comment+=ins[i]+" ";
					intel8080_file << comment;
				}
				else{
					cerr<<"There is an error while translating program. Please check the program"<<endl;
					exit(EXIT_FAILURE);
				}
			}
			intel8080_file << "\n";
		}
		cout<<"Program is successfully translated" <<endl;
		intel8080_file.close();
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
