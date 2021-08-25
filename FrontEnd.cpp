#include "FrontEnd.h" 
#include <string>
using namespace std;

string command;
string commandType;
string commandName;
string commandToSplit;
string params[5];

void getCommandType(string command) {
	if (command.rfind("create", 0) == 0) { 
		commandType = "create";
	}
}

void splitParams(string command, int paramCount) {
	int j = 0;
	int pos = 0;
	// params 1 and 3 must be keywords
	for (int i = 0; i < command.length(); i++) {
		if (command[i] == ' ') {
			params[j] = commandToSplit;
			commandToSplit = "";
			j++;
			continue;
		}
		else {
			commandToSplit += putchar(tolower(command[i]));
		}
	}		
}
