#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <cstdio>
using namespace std;

void fileOpen(fstream&, string, char);
void keyGen(string keyFile);
void toBlock(string PTFile);
char encrypt(char ch, int key);
char decrypt(char ch, int key);
int keyRead(string keyFile);
//Is this a global variable?
const string BKfile = "BKfile.txt";

int main(int argc, char* argv[]){
    switch(atoi(argv[2]))
    {
    case(0):
        keyGen(argv[2]);
        
    case(1):
        toBlock(argv[3]);
        int key = keyRead(argv[2]);

        fstream fin; 
        fileOpen(fin, BKfile, 'r');
        fstream fout;
        fileOpen(fout, argv[4], 'w');

        char current;
        while(fin.peek() != EOF){
            if(fin.peek() != '\n'){
            current = fin.get();
            current = encrypt(current, key);
            fout << current;
            }
            fin.get();
        }
        


        //read keyfile to int.
        //read ptFile, send ptfile to blocktext maker 50char blocks.
        //send blocktext to encrypt one char at a time.
        //send output to file
    }
    //maybe call the fileopen thing?
    //fstream fin;
    //fileOpen(fin, keyFile, 'w');
    return 0;
}

//Tested, does make a rand and put it in a keyfile. only does 9????
void keyGen(string keyFile){
    srand(time(NULL));
    int shift = (rand() % 25) + 1;
    fstream fout;
    fileOpen(fout, keyFile, 'w');
    fout << shift;
    fout.close();
}

int keyRead(string keyFile){
    fstream fin;
    fileOpen(fin, keyFile, 'r');
    string temp;
    getline(fin, temp);
    int key = stoi(temp);
    fin.close();
    return key;
}

//Tested, encrpyts
char encrypt(char ch, int key){
    int pos = ch - 'A';
    pos = ((pos + key) % 26);
    ch = pos + 'A';
    return ch;
}

//Tested, decrypts
char decrypt(char ch, int key){
    int pos = ch - 'A';
    pos = ((pos - key + 26) % 26);
    ch = pos + 'A';
    return ch;
}

void toBlock(string PTfile){
    fstream fin;
    fileOpen(fin, PTfile, 'r');
    fstream fout;
    fileOpen(fout, BKfile, 'w');
    string charBlock;
    char current;
    int i;
    //string tempLine;
    //\n kinda thing

    while(fin.peek() != EOF){
        //getline(fin, tempLine);
        //need to go through each char in the line.
        for(i = 0; i < 50; i++){
            current = fin.get();
            if(isalpha(current) && (current != '\n')){
                i++;
                charBlock += toupper(current);
            }
        }
        fout << charBlock << endl;
        i = 0;
    }
    fout.close();
    fin.close();
    //opens plaintext file and removes punctuation. then sends
    //50 char chunks to CONST BKfile.
}

/*
Description: function opens a file 
Input: file stream object reference, name of the file, mode of open
Output: void function, but at exit, file stream object is tied to 
the input file name because 'file' is a reference variable 
*/ 
void fileOpen(fstream& file, string name, char mode)
//void fileOpen(fstream& file, char name[], char mode)
{
 string fileType;

 if (mode == 'r')
  fileType = "input";
 if (mode == 'w')
  fileType = "output";

 if (mode == 'r')
  file.open(name, ios::in);  //available thorugh fstream
 else
  if (mode == 'w')
   file.open(name, ios::out);  //available through fstream;

 if (file.fail()) //error condition 
 {
  cout << "Error opening " << fileType << " file" << endl; 
  exit(EXIT_FAILURE);
 }
}
