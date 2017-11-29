#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "scores.hpp"
using namespace std;

int score_simple(const string data) {
	int retval=0;
	for(unsigned int i=0; i<data.size(); i++) {
		retval+=score_single_char[(unsigned)(data[i])];
	}
	return retval;
}

int score_text(const string data) {
	int retval=0;
	for(unsigned int i=0; i<data.size(); i++) {
		retval+=is_text_char[(unsigned)(data[i])];
	}
	return retval;
}

bool bump_key(string& k) {
	if(k=="zzz") return false;
	k[2]++;
	if(k[2]>122) {
		k[2]=97;
		k[1]++;
		if(k[1]>122) {
			k[1]=97;
			k[0]++;
		}
	}
	return true;
}

string XOR(string txt, string key) {
	unsigned pos_txt = 0, pos_key = 0; string retval = "";
	while (pos_txt < txt.size()) {
		retval+=txt[pos_txt]^key[pos_key];
		pos_txt++;
		pos_key++;
		if(pos_key==key.size()) pos_key = 0;
	}
	return retval;
}

int main(int argc, char* argv[]) {
	string line; string data="";
	ifstream myfile ("/home/cbarnett/git/euler/p059_cipher.txt");
	if(myfile.is_open())
	{
		while (getline (myfile,line,',')) data+=(char)(stoi(line));
		myfile.close();
	} else {
		cout << "Unable to open file";
		return 1;
	}
	
	string key="aaa", text=""; int max=-10000;
	do {
		string tmp=XOR(data, key);
		int score = score_simple(tmp);
		if(score > max) {
			text = tmp;
			max = score;
		}
	} while (bump_key(key));
	
	unsigned retval = 0;
	for(unsigned i = 0; i<text.size(); i++) retval += (unsigned)(text[i]);
	cout << retval << "\n";
	
	return 0;
}