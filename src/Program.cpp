/*
 * Program.cpp
 *
 *  Created on: 7/2/2015
 *      Author: Adrian
 */
#include "Program.h"
using namespace std;

Program::Program(){
	readFile();
}

Program::~Program() {
	// TODO Auto-generated destructor stub
}

void Program::readFile(){
	string miCadena;
	regex eInstruction("([a-z]+:|)([A-Z]+[=\\*]?\\d*)([a-z]+|)");
	smatch sm;

	cout << "\nItroduce el fichero con el programa a ejecutar: ";
	cin>> myFile;
	string absoluteRoute = getcwd(NULL,0);
	string myRoute = absoluteRoute +"/tests/"+ myFile;

	ifstream fs(myRoute);
	getline(fs,miCadena);

	vInstruction.clear();

	if(!fs.is_open()){
		cout << "Error al abrir el fichero."<< endl;
		exit(0);
	}

	while(!fs.eof()){
		cleanString(miCadena);
		if(regex_match (miCadena,sm,eInstruction)){
			string sTag1 = sm[1].str();
			string command = sm[2].str();
			string sTag2 = sm[3].str();
			vInstruction.push_back(new Instruction(sTag1,command,sTag2));
		}
		getline(fs,miCadena);
	}
	//_______ Comentar al final, solo se usa para pruebas.____________
	printProgram();
}

void Program::cleanString(string &miCadena){
	int position = miCadena.length();
	while((position = miCadena.find(' ')) != string::npos){
		miCadena.replace(position, 1, "");
	}
	while((position = miCadena.find('\t')) != string::npos){
		miCadena.replace(position, 1, "");
	}
	while((position = miCadena.find('\r')) != string::npos){
		miCadena.replace(position, 1, "");
	}
	while((position = miCadena.find(';')) != string::npos){
		miCadena.erase(position,miCadena.length()- position);
	}
}

void Program::printProgram(){
	cout << "===================================================================================\n";
	for(int i=0;i<vInstruction.size();i++){
		cout << "etiqueta: "<< vInstruction[i]->getTag()<<"\tcomando: "<< vInstruction[i]->getCommand()<<"\tetiqueta 2: "<<vInstruction[i]->getTag2()<<endl;
	}
}
