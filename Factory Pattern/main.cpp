#include <iostream>
#include <string>
#include <stdio.h>
#include "factory.hpp"
#include "base.hpp"
int main(int argc,char** argv) {
string temp = argv[1];
 char* input[argc-1];
for(int i = 0; i < argc-1; i++)
{
	input[i] = argv[i+1];
}
	Factory* factory = new Factory();
	Base* conversion = factory->parse(input,argc-1);
    std::cout << conversion->stringify() << " = " << conversion->evaluate() << std::endl;
    return 0;
}
