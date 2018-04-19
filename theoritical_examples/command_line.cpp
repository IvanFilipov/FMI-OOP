#include<iostream>

/*

first of all compile the example.
then go to directory with the executable file.
run you preferred shell (CLI)
-----------------------------------------------------
from the command line :

WINDOWS						LINUX
>command_line.exe			$./command_line

will start your program without parameters and with the default
I/Os :  output[both STDOUT/STDERR] : screen (aka the console)
		input[STDIN] : keyboard
-----------------------------------------------------
Passing parameters
write from the command line :

>command_line.exe argument_1 argument_2

the strings argument_1 and argument_2 will be passed
into our main function as argv[1] and argv[2]

In Visual Studio you can pass parameter while debugging
your program. Follow these steps :
right click on you project -> Properties ->
Configuration Properties -> Debugging -> Command Line Arguments
write into the input box your desired arguments

-----------------------------------------------------
Redirecting the STDIN/STDOUT/STDERR
you can easily redirect all standard I/Os
by using the following syntax :

>command_line.exe > outputfile.txt    | will redirect the STDOUT to outputfile.txt
>command_line.exe < input.txt         | will redirect the STDIN from input.txt
>command_line.exe 2> errors.txt       | will redirect the STDERR to errors.txt

you can combine the redirection

>command_line.exe < input.txt > output.txt | STDIN now is input.txt, STDOUT is output.txt
>command_line.exe < input.txt > output.txt 2> errors.txt | all at once

*/

//output all the arguments , which have been passed through the command line
//from your cmd, shell, PowerShell and etc.
int main(int argc , char * argv []) {

	//first one ALWAYS is the path to the executable file
	if (argc == 1) {

		std::cout << "no arguments have been passed only the executable file path\n";
		std::cout << argv[0];
	}

	//prints all other arguments
	for (int i = 1; i < argc ; i++) {

		std::cout << "argument " << i << " is : ";
		std::cout << argv[i] << std::endl;
	}


	int a, b, c;

	//reading three numbers from STDIN [ standard input ]
	std::cin >> a >> b >> c;

	//outputs to STDOUT [ standard output ]
	std::cout << a * a << std::endl;
	std::cout << 2 * b << std::endl;
	std::cout << c - a << std::endl;

	//outputs to STDERR [ standard error output ]
	std::cerr << "an error occur!\n";

	return 0;
}