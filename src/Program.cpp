/*
 * Program.cpp
 *
 *  Created on: 7/2/2015
 *      Author: Adrian
 */
#include "Program.h"
using namespace std;

enum Code{LOAD=0,STORE,ADD,SUB,MULT,DIV,READ,WRITE,JUMP,JGTZ,JZERO,HALT};

Program::Program(){
	readFile();
}

Program::~Program() {
	// TODO Auto-generated destructor stub
}

void Program::readFile(){
	string miCadena;
	regex eInstruction("([a-z]+:|)([A-Z]+)([=\\*]?\\d*(?:[a-z]+)?)");
	smatch sm;
	stringProgram theStringInstruction;
	int i = 0;
	int iTag2= -1;
	int iCommand= -1;

	cout << "\nItroduce el fichero con el programa a ejecutar: ";
	cin>> myFile;
	string absoluteRoute = getcwd(NULL,0);
	string myRoute = absoluteRoute +"/tests/"+ myFile;

	ifstream fs(myRoute);
	getline(fs,miCadena);

	vInstruction.clear();
	vDesensamblador.clear();

	if(!fs.is_open()){
		cout << "Error al abrir el fichero."<< endl;
		exit(0);
	}

	while(!fs.eof()){
		cleanString(miCadena);
		if(regex_match (miCadena,sm,eInstruction)){
			string sTag1 = sm[1].str();
			string sCommand = sm[2].str();
			string sTag2 = sm[3].str();
			theStringInstruction.sTag = sTag1;
			theStringInstruction.sCommand = sCommand;
			theStringInstruction.sTag2 = sTag2;
			vDesensamblador.push_back(&theStringInstruction);

			iCommand= transformCommand(sCommand);
			iTag2 = transformTag(sTag2);

			vInstruction.push_back(new Instruction(i,iCommand,iTag2));               //ver si esto funciona.
			i++;
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

int Program::transformCommand(string &cm){

	if(cm == "LOAD"){
		return LOAD;
	}
	else if(cm == "STORE"){
		return STORE;
	}
	else if(cm == "ADD"){
		return ADD;
	}
	else if(cm == "SUB"){
		return SUB;
	}
	else if(cm == "MULT"){
		return MULT;
	}
	else if(cm == "DIV"){
		return DIV;
	}
	else if(cm == "READ"){
		return READ;
	}
	else if(cm == "WRITE"){
		return WRITE;
	}
	else if(cm == "JUMP"){
		return JUMP;
	}
	else if(cm == "JGTZ"){
		return JGTZ;
	}
	else if(cm == "JZERO"){
		return JZERO;
	}
	else if(cm == "HALT"){
		return HALT;
	}
	else{
		return -1;
	}
}

int Program::transformTag(string &tg){

	if(tg[0]== '='){
		return inmediateMode(tg);
	}
	else if(tg[0]== '*'){
		return indirectMode(tg);
	}
	else{
		return directMode(tg);
	}
}

int Program::inmediateMode(string tg){
	string auxTg = "1";
	if(tg[0]== '='){
		auxTg.append(tg.substr (1,1));
		return stoi(auxTg);
	}
	else{
		return -1;
	}
}

int Program::directMode(string tg){
	string auxTg = "2";
	if(tg[0]!= '=' || tg[0] != '*'){
		auxTg.append(tg);
		return stoi(auxTg);
	}
	else{
		return -1;
	}
}

int Program::indirectMode(string tg){
	if(tg[0]== '*'){
			tg.replace(0,1,"3");
			return stoi(tg);
		}
		else{
			return -1;
		}
}

int Program::instructionJump(string tg){
	string auxTg = tg;
	auxTg.append(":");
	return 0;
}

void Program::codeProgram(){
	cout << "===================================================================================\n";
	for(int i=0;i<vInstruction.size();i++){
		cout << "etiqueta: "<< vInstruction[i]->getTag()<<"\tcomando: "<< vInstruction[i]->getCommand()<<"\tetiqueta 2: "<<vInstruction[i]->getTag2()<<endl;
	}
}

void Program::desensamblar(){
	cout << "===================================================================================\n";

}

std::vector<Instruction*>& Program::getInstruction(){
	return vInstruction;
}

void Program::setInstruction(const std::vector<Instruction*>& instruction) {
	vInstruction = instruction;
}
