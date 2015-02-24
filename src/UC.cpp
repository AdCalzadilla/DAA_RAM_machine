/*
 * UC.cpp
 *
 *  Created on: 19/2/2015
 *      Author: Adrian
 */

#include "UC.h"

using namespace std;

enum Code{LOAD=0,STORE,ADD,SUB,MULT,DIV,READ,WRITE,JUMP,JGTZ,JZERO,HALT};

UC::UC() {
	// TODO Auto-generated constructor stub
	trace = false;
	into.resize(50);
	myRoute = "";

	programInstruction = myProgram.getInstruction();
	readInFile();
	createOutFile();
	menu();
}

UC::~UC() {
	// TODO Auto-generated destructor stub
}

bool UC::getTrace(){
	return trace;
}

void UC::setTrace(bool tr){
	trace = tr;
}

void UC::readInFile(){
	cout << "\nItroduce el fichero de la cinta de entrada: ";
	cin>> inFile;
	string absoluteRoute = getcwd(NULL,0);
	string myRoute = absoluteRoute +"/tests/"+ inFile;

	ifstream fe(myRoute);
	if(!fe.is_open()){
		cout << "Error al abrir el fichero que contiene la cinta de entrada."<< endl;
		exit(0);
	}

	int i=0;
	while(!fe.eof()){
		fe >> into[i];
		i++;
	}
	fe.close();
}

void UC::createOutFile(){
	cout << "Nombre del fichero de salida: ";
	cin >> myRoute;
	string absoluteRoute = getcwd(NULL,0);
	myRoute = absoluteRoute + "/tests/" + myRoute;
	ofstream fs(myRoute, ios::app );
	fs.close();
}

bool UC::checkRegister(int value){
	if(value < 0 || value > 99){
		cout<< "Desbordamiento en los registros de la memoria."<< value << endl;
		return false;
	}
	return true;
}

bool UC::checkPosition(int pos){
	if(pos >= myMemory.size() || pos < 0){
		cout<< "Accediendo a posición inexistente de memoria. "<< pos << endl;
		return false;
	}
	return true;
}

void UC::printMemory(){
	cout << "=========== The Memory ==========="<< endl;
	for(int i= 0; i< myMemory.size();i++){
		if(i == 0){
			cout<< "[AC]->\t"<< myMemory.getMemory(i)<<endl;
		}
		else{
			cout<< "["<<i<<"]->\t"<< myMemory.getMemory(i)<<endl;
		}
	}
}

void UC::run(){
	int i = 0;
	char wait = 'w';

	while(i < programInstruction.size() && i >= 0){
		if(programInstruction[i]->getCommand()== LOAD){
			funcLOAD(i);
		}
		else if(programInstruction[i]->getCommand()== STORE){
			funcSTORE(i);
		}
		else if(programInstruction[i]->getCommand()== ADD){
			funcADD(i);
		}
		else if(programInstruction[i]->getCommand()== SUB){
			funcSUB(i);
		}
		else if(programInstruction[i]->getCommand()== MULT){
			funcMULT(i);
		}
		else if(programInstruction[i]->getCommand()== DIV){
			funcDIV(i);
		}
		else if(programInstruction[i]->getCommand()== JUMP){
			i = funcJUMP(i);
		}
		else if(programInstruction[i]->getCommand()== JGTZ){
			i =funcJGTZ(i);
		}
		else if(programInstruction[i]->getCommand()== JZERO){
			i = funcJZERO(i);
		}
		else if(programInstruction[i]->getCommand()== READ){
			funcREAD(i);
		}
		else if(programInstruction[i]->getCommand()== WRITE){
			funcWRITE(i);
		}
		else if(programInstruction[i]->getCommand()== HALT){
			i = funcHALT();
		}
		//Traza activada.
		if(getTrace()){
			printMemory();
			cout<<"\nPusle cualquier tecla para continuar."<<endl;
			cin >> wait;
		}
		i++;
	}
	//printMemory();
}

void UC::funcLOAD(int instruc){
	int auxInt = -1;
	if(programInstruction[instruc]->getTag2() >= 10 && programInstruction[instruc]->getTag2() < 20){
		auxInt = programInstruction[instruc]->getTag2() -10;
		if(checkRegister(auxInt)){
			myMemory.setMemory(0,auxInt);
		}
	}
	else if(programInstruction[instruc]->getTag2() < 30){
		auxInt = programInstruction[instruc]->getTag2() - 20;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			if(checkRegister(auxInt)){
				myMemory.setMemory(0,auxInt);
			}
		}
	}
	else if(programInstruction[instruc]->getTag2() < 40){
		auxInt = programInstruction[instruc]->getTag2() - 30;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			if(checkPosition(auxInt)){
				auxInt = myMemory.getMemory(auxInt);
				if(checkRegister(auxInt)){
					myMemory.setMemory(0,auxInt);
				}
			}
		}
	}

	else if(programInstruction[instruc]->getTag2() > 99 && programInstruction[instruc]->getTag2() < 200){
		auxInt = programInstruction[instruc]->getTag2() -100;
		if(checkRegister(auxInt)){
			myMemory.setMemory(0,auxInt);
		}
	}
	else if(programInstruction[instruc]->getTag2() < 300){
		auxInt = programInstruction[instruc]->getTag2() - 200;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			if(checkRegister(auxInt)){
				myMemory.setMemory(0,auxInt);
			}
		}
	}
	else if(programInstruction[instruc]->getTag2() < 400){
		auxInt = programInstruction[instruc]->getTag2() - 300;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			if(checkPosition(auxInt)){
				auxInt = myMemory.getMemory(auxInt);
				if(checkRegister(auxInt)){
					myMemory.setMemory(0,auxInt);
				}
			}
		}
	}

}

void UC::funcSTORE(int instruc){
	int auxInt = -1;
	int value = -1;

	if(programInstruction[instruc]->getTag2() >= 20 && programInstruction[instruc]->getTag2() < 30){
		auxInt = programInstruction[instruc]->getTag2() - 20;
		if(checkPosition(auxInt)){
			value = myMemory.getMemory(0);
			myMemory.setMemory(auxInt,value);
		}
	}
	else if(programInstruction[instruc]->getTag2() < 40){
		auxInt = programInstruction[instruc]->getTag2() - 30;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			if(checkPosition(auxInt)){
				value = myMemory.getMemory(0);
				myMemory.setMemory(auxInt,value);
			}
		}
	}
	else if(programInstruction[instruc]->getTag2() >= 200 && programInstruction[instruc]->getTag2() < 300){
		auxInt = programInstruction[instruc]->getTag2() - 200;
		if(checkPosition(auxInt)){
			value = myMemory.getMemory(0);
			myMemory.setMemory(auxInt,value);
		}
	}
	else if(programInstruction[instruc]->getTag2() < 400){
		auxInt = programInstruction[instruc]->getTag2() - 300;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			if(checkPosition(auxInt)){
				value = myMemory.getMemory(0);
				myMemory.setMemory(auxInt,value);
			}
		}
	}
}

void UC::funcADD(int instruc){
	int auxInt = -1;
	if(programInstruction[instruc]->getTag2() >= 10 && programInstruction[instruc]->getTag2() < 20){
		auxInt = programInstruction[instruc]->getTag2() -10;
		auxInt = auxInt + myMemory.getMemory(0);
		if(checkRegister(auxInt)){
			myMemory.setMemory(0,auxInt);
		}
	}
	else if(programInstruction[instruc]->getTag2() < 30){
		auxInt = programInstruction[instruc]->getTag2() - 20;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(auxInt) + myMemory.getMemory(0);
		}
		if(checkRegister(auxInt)){
			myMemory.setMemory(0,auxInt);
		}
	}
	else if(programInstruction[instruc]->getTag2() < 40){
		auxInt = programInstruction[instruc]->getTag2() - 30;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			if(checkPosition(auxInt)){
				auxInt = myMemory.getMemory(auxInt);
				auxInt = auxInt + myMemory.getMemory(0);
				if(checkRegister(auxInt)){
					myMemory.setMemory(0,auxInt);
				}
			}
		}
	}
	else if(programInstruction[instruc]->getTag2() >= 100 && programInstruction[instruc]->getTag2() < 200){
		auxInt = programInstruction[instruc]->getTag2() -100;
		auxInt = auxInt + myMemory.getMemory(0);
		if(checkRegister(auxInt)){
			myMemory.setMemory(0,auxInt);
		}
	}
	else if(programInstruction[instruc]->getTag2() < 300){
		auxInt = programInstruction[instruc]->getTag2() - 200;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(auxInt) + myMemory.getMemory(0);
		}
		if(checkRegister(auxInt)){
			myMemory.setMemory(0,auxInt);
		}
	}
	else if(programInstruction[instruc]->getTag2() < 400){
		auxInt = programInstruction[instruc]->getTag2() - 300;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			if(checkPosition(auxInt)){
				auxInt = myMemory.getMemory(auxInt);
				auxInt = auxInt + myMemory.getMemory(0);
				if(checkRegister(auxInt)){
					myMemory.setMemory(0,auxInt);
				}
			}
		}
	}
}

void UC::funcSUB(int instruc){
	int auxInt = -1;
	if(programInstruction[instruc]->getTag2() >= 10 && programInstruction[instruc]->getTag2() < 20){
		auxInt = programInstruction[instruc]->getTag2() -10;
		auxInt = myMemory.getMemory(0)- auxInt;
		if(checkRegister(auxInt)){
			myMemory.setMemory(0,auxInt);
		}
	}
	else if(programInstruction[instruc]->getTag2() < 30){
		auxInt = programInstruction[instruc]->getTag2() - 20;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(0) - myMemory.getMemory(auxInt);
			if(checkRegister(auxInt)){
				myMemory.setMemory(0,auxInt);
			}
		}
	}
	else if(programInstruction[instruc]->getTag2() < 40){
		auxInt = programInstruction[instruc]->getTag2() - 30;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			if(checkPosition(auxInt)){
				auxInt = myMemory.getMemory(auxInt);
				auxInt = myMemory.getMemory(0) - auxInt;
				if(checkRegister(auxInt)){
					myMemory.setMemory(0,auxInt);
				}
			}
		}
	}
	else if(programInstruction[instruc]->getTag2() >= 100 && programInstruction[instruc]->getTag2() < 200){
		auxInt = programInstruction[instruc]->getTag2() -100;
		auxInt = myMemory.getMemory(0)- auxInt;
		if(checkRegister(auxInt)){
			myMemory.setMemory(0,auxInt);
		}
	}
	else if(programInstruction[instruc]->getTag2() < 300){
		auxInt = programInstruction[instruc]->getTag2() - 200;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(0) - myMemory.getMemory(auxInt);
			if(checkRegister(auxInt)){
				myMemory.setMemory(0,auxInt);
			}
		}
	}
	else if(programInstruction[instruc]->getTag2() < 400){
		auxInt = programInstruction[instruc]->getTag2() - 300;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			if(checkPosition(auxInt)){
				auxInt = myMemory.getMemory(auxInt);
				auxInt = myMemory.getMemory(0) - auxInt;
				if(checkRegister(auxInt)){
					myMemory.setMemory(0,auxInt);
				}
			}
		}
	}
}

void UC::funcMULT(int instruc){
	int auxInt = -1;
	if(programInstruction[instruc]->getTag2() >= 10 && programInstruction[instruc]->getTag2() < 20){
		auxInt = programInstruction[instruc]->getTag2() -10;
		auxInt = auxInt * myMemory.getMemory(0);
		if(checkRegister(auxInt)){
			myMemory.setMemory(0,auxInt);
		}
	}
	else if(programInstruction[instruc]->getTag2() < 30){
		auxInt = programInstruction[instruc]->getTag2() - 20;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(auxInt) * myMemory.getMemory(0);
			if(checkRegister(auxInt)){
				myMemory.setMemory(0,auxInt);
			}
		}
	}
	else if(programInstruction[instruc]->getTag2() < 40){
		auxInt = programInstruction[instruc]->getTag2() - 30;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			if(checkPosition(auxInt)){
				auxInt = myMemory.getMemory(auxInt);
				auxInt = auxInt * myMemory.getMemory(0);
				if(checkRegister(auxInt)){
					myMemory.setMemory(0,auxInt);
				}
			}
		}
	}
	else if(programInstruction[instruc]->getTag2() >= 100 && programInstruction[instruc]->getTag2() < 200){
		auxInt = programInstruction[instruc]->getTag2() -100;
		auxInt = auxInt * myMemory.getMemory(0);
		if(checkRegister(auxInt)){
			myMemory.setMemory(0,auxInt);
		}
	}
	else if(programInstruction[instruc]->getTag2() < 300){
		auxInt = programInstruction[instruc]->getTag2() - 200;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(auxInt) * myMemory.getMemory(0);
			if(checkRegister(auxInt)){
				myMemory.setMemory(0,auxInt);
			}
		}
	}
	else if(programInstruction[instruc]->getTag2() < 400){
		auxInt = programInstruction[instruc]->getTag2() - 300;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			if(checkPosition(auxInt)){
				auxInt = myMemory.getMemory(auxInt);
				auxInt = auxInt * myMemory.getMemory(0);
				if(checkRegister(auxInt)){
					myMemory.setMemory(0,auxInt);
				}
			}
		}
	}
}

void UC::funcDIV(int instruc){     //DIVISION POR 0.
	int auxInt = -1;
	if(programInstruction[instruc]->getTag2() >= 10 && programInstruction[instruc]->getTag2() < 20){
		auxInt = programInstruction[instruc]->getTag2() -10;
		if(auxInt == 0){
			cout << "ERROR al dividir por 0."<<endl;
		}
		auxInt = myMemory.getMemory(0)/auxInt;
		if(checkRegister(auxInt)){
			myMemory.setMemory(0,auxInt);
		}
	}
	else if(programInstruction[instruc]->getTag2() < 30){
		auxInt = programInstruction[instruc]->getTag2() - 20;
		if(checkPosition(auxInt)){
			if(myMemory.getMemory(auxInt)== 0){
				cout << "ERROR al dividir por 0."<< endl;
			}
			auxInt = myMemory.getMemory(0) / myMemory.getMemory(auxInt);
			if(checkRegister(auxInt)){
				myMemory.setMemory(0,auxInt);
			}
		}
	}
	else if(programInstruction[instruc]->getTag2() < 40){
		auxInt = programInstruction[instruc]->getTag2() - 30;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			if(checkPosition(auxInt)){
				auxInt = myMemory.getMemory(auxInt);
				if(auxInt == 0){
					cout << "ERROR al dividir por 0."<<endl;
				}
				auxInt = myMemory.getMemory(0)/auxInt;
				if(checkRegister(auxInt)){
					myMemory.setMemory(0,auxInt);
				}
			}
		}
	}
	else if(programInstruction[instruc]->getTag2() >= 100 && programInstruction[instruc]->getTag2() < 200){
		auxInt = programInstruction[instruc]->getTag2() -100;
		if(auxInt == 0){
			cout << "ERROR al dividir por 0."<<endl;
		}
		auxInt = myMemory.getMemory(0)/auxInt;
		if(checkRegister(auxInt)){
			myMemory.setMemory(0,auxInt);
		}
	}
	else if(programInstruction[instruc]->getTag2() < 300){
		auxInt = programInstruction[instruc]->getTag2() - 200;
		if(checkPosition(auxInt)){
			if(myMemory.getMemory(auxInt)== 0){
				cout << "ERROR al dividir por 0."<< endl;
			}
			auxInt = myMemory.getMemory(0) / myMemory.getMemory(auxInt);
			if(checkRegister(auxInt)){
				myMemory.setMemory(0,auxInt);
			}
		}
	}
	else if(programInstruction[instruc]->getTag2() < 400){
		auxInt = programInstruction[instruc]->getTag2() - 300;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			if(checkPosition(auxInt)){
				auxInt = myMemory.getMemory(auxInt);
				if(auxInt == 0){
					cout << "ERROR al dividir por 0."<<endl;
				}
				auxInt = myMemory.getMemory(0)/auxInt;
				if(checkRegister(auxInt)){
					myMemory.setMemory(0,auxInt);
				}
			}
		}
	}
}

void UC::funcREAD(int instruc){
	int auxInt = -1;
	int value = into[0];
	into.erase(into.begin());
	if(programInstruction[instruc]->getTag2() >= 20 && programInstruction[instruc]->getTag2() < 30){
		auxInt = programInstruction[instruc]->getTag2()-20;
		if(checkPosition(auxInt) && checkRegister(value)){
			myMemory.setMemory(auxInt,value);
		}
	}
	else if(programInstruction[instruc]->getTag2() < 40){
		auxInt = programInstruction[instruc]->getTag2() - 30;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			if(checkPosition(auxInt)){
				auxInt = myMemory.getMemory(auxInt);
				if(checkRegister(value)){
					myMemory.setMemory(auxInt,value);
				}
			}
		}
	}
	else if(programInstruction[instruc]->getTag2() >= 200 && programInstruction[instruc]->getTag2() < 300){
		auxInt = programInstruction[instruc]->getTag2()-20;
		if(checkPosition(auxInt) && checkRegister(value)){
			myMemory.setMemory(auxInt,value);
		}
	}
	else if(programInstruction[instruc]->getTag2() < 400){
		auxInt = programInstruction[instruc]->getTag2() - 300;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			if(checkPosition(auxInt)){
				auxInt = myMemory.getMemory(auxInt);
				if(checkRegister(value)){
					myMemory.setMemory(auxInt,value);
				}
			}
		}
	}

}

void UC::funcWRITE(int instruc){
	ofstream fs(myRoute, ios::app );
	int auxInt = -1;
	if(programInstruction[instruc]->getTag2() >= 10 && programInstruction[instruc]->getTag2() < 20){
		auxInt = programInstruction[instruc]->getTag2()-10;
		if(checkRegister(auxInt)){
			fs << auxInt<< endl;
			vOut.push_back(auxInt);
		}
	}
	if(programInstruction[instruc]->getTag2() >= 100 && programInstruction[instruc]->getTag2() < 200){
		auxInt = programInstruction[instruc]->getTag2()-100;
		if(checkRegister(auxInt)){
			fs << auxInt<< endl;
			vOut.push_back(auxInt);
		}
	}
	/*else if(programInstruction[instruc]->getTag2() < 40){
		auxInt = programInstruction[instruc]->getTag2() - 30;
		if(checkPosition(auxInt)){
			auxInt = myMemory.getMemory(auxInt);
			if(checkRegister(auxInt)){
				fs << auxInt <<endl;
			}
		}
	}*/
	fs.close();
}

int UC::funcJUMP(int instruc){
	return programInstruction[instruc]->getTag2()-1;
}

int UC::funcJGTZ(int instruc){
	if(myMemory.getMemory(0) > 0){
		return programInstruction[instruc]->getTag2() -1; //Para que al sumar 1 de la posición correspondiente.
	}
	else{
		return instruc;
	}
}

int UC::funcJZERO(int instruc){
	if(myMemory.getMemory(0)== 0){
		return programInstruction[instruc]->getTag2() -1;
	}
	else{
		return instruc;
	}
}

int UC::funcHALT(){
	return -2;
}

void UC::printTapeIn(){
	cout << " =============== Cinta de entrada. ============ \n"<< endl;
		for(int i=0;i< into.size(); i++){
			cout <<" "<<into[i] << endl;
		}
}

void UC::printTapeOut(){
	cout << " =============== Cinta de salida. ============ \n"<< endl;
	for(int i=0;i< vOut.size(); i++){
		cout <<" "<<vOut[i] << endl;
	};
}

void UC::printMenu(){

	string myMenu [8] = { "[ r ]: ver los registros.",
			"[ t ]: traza.",
			"[ g ]: go.",
			"[ s ]: ver desemsamblador.",
			"[ i ]: ver cinta de entrada.",
			"[ o ]: ver cinta de salida.",
			"[ h ]: ayuda.",
			"[ x ]: salir."
	};

	cout << " ==================================================== "<< endl;
	cout << " =============== Práctica 1: Maquina RAM ============ \n"<< endl;
	for(int i=0;i< 8; i++){
		cout <<" "<<myMenu[i] << endl;
	}
	cout << "\nopcion: ";

}

void UC::menu(){
	char op= 'a';
	char wait= 'w';
	printMenu();
	cin >> op;
	while(op != 'x'){
		switch (op){
		case 'r':
			printMemory();
			cout<<"\nPusle cualquier tecla para continuar."<<endl;
			cin >> wait;
			break;
		case 't':
			setTrace(true);
			run();
			cout<<"\nPusle cualquier tecla para continuar."<<endl;
			cin >> wait;
			break;
		case 'g':
			setTrace(false);
			run();
			cout<<"\nPusle cualquier tecla para continuar."<<endl;
			cin >> wait;
			break;
		case 's':
			myProgram.desensamblar();
			cout<<"\nPusle cualquier tecla para continuar."<<endl;
			cin >> wait;
			break;
		case 'i':
			printTapeIn();
			cout<<"\nPusle cualquier tecla para continuar."<<endl;
			cin >> wait;
			break;
		case 'o':
			printTapeOut();
			cout<<"\nPusle cualquier tecla para continuar."<<endl;
			cin >> wait;
			break;
		case 'h':
			//ayuda.
			cout << "Practica realizada para la asignatura Disenio y analisis de algoritmos.\n";
			cout<<"\nPusle cualquier tecla para continuar."<<endl;
			cin >> wait;
			break;
		case 'x':
			cout << "Ha decidio salir del programa.\n... Cerrando maquina ..."<< endl;
			cout<<"\nPusle cualquier tecla para continuar."<<endl;
			cin >> wait;
			break;
		default:
			cout<<"Accion no permitida."<< endl;
			cout<<"\nPusle cualquier tecla para continuar."<<endl;
			cin >> wait;
			break;
		}
	printMenu();
	cin >> op;
	}
}



