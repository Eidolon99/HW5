#include <iostream>
#include <fstream>

using namespace std;

bool isUpper(char character) {
    if (character >= 'A' and character <= 'Z'){
        return true;
    }
    else return false;
}
bool isLower(char character) {
    if (character >= 'a' and character <= 'z') {
        return true;
    }
    else return false;
}

char rotate(char character, int offset) {
    
     if (isLower(character)) {
        character += offset;
        if(character > 'z') {
            character -= 26;
        }
    }
    else if (isUpper(character)) {
        character += offset;
        if (character > 'Z') {
            character -= 26;
        }
    }
    
    return character;
}



int main(){
	//variables
	string alphabet = "";
	char c;
	ifstream fin;
	fin >> noskipws;
	//read in chars
	
	int offset = 0;
	while(offset < 26) {
	    fin.open("secretMessage.txt");
        alphabet = "";
    
	    while(!fin.eof()) {
		
		    fin >> c;
		
		    if (isalpha(c)) { 
		        c = rotate(c, offset);
		    }
		    
		    alphabet += c;
	    }
	    
	    cout << "===============================" << endl;
        cout << "Rotating by " << offset << " positions" << endl;
        cout << "===============================" << endl;
	    cout << alphabet << endl << endl;
	    
	    fin.close();
	    offset++;
    }
   
