#include <iostream>
#include "Backend.h"
#include "FrontEnd.h"

int main()
{
	cout << "Please enter a command or type help for a list of commands" << endl;
	bool exit = false;
	while (exit != true)
	{
		command = "";
		commandType = "";
		getline(cin, command, '\n');
		command += ' ';
		getCommandType(command);
		if (commandType == "create") {
			splitParams(command, 5);
			cout << endl << "Split" << endl;
			if (params[1] == "key" && params[2] != " " && params[3] == "value" && params[4] != " ") {
				cout << "You made it";
				//create(stoi(params[2]), params[4]);
				//cout << "inserted";
				//TraverseSearchTree();
			}
		}
	}
}