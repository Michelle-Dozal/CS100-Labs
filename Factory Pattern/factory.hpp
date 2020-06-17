#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "base.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "Div.hpp"
#include <stdlib.h>

#include <iostream>
using namespace std;

class Factory
{
	private:
	Base* opOne;
	Base* opTwo;
	Base* express;
	const char mult = '*';
	const char div = '/';
	const char add = '+';
	const char sub = '-';
	const char exp = '^';
	string numOne = "";
	string numTwo = "";
	public:
	
	Factory(){};
	
	Base* parse(char** input, int length)
	{
		/*int j;
		for(j = 0; j < length; j++)
		{
			if((int)*input[j] - 48 >= 0 &&  (int)*input[j]- 48 <= 9)
				numOne += *input[j];
			else
				break;//that means it hit an operator 
		}*/
		if((int)*input[0] - 48 < 0 &&  (int)*input[0]- 48 > 9)
		{
			return nullptr;
		}
		
		numOne = input[0];
		opOne = new Op(stoi(numOne));
		cout << "opOne is " << opOne->stringify() << endl;
		//cout << "j is " << j << endl;
		for(int i = 1; i < length-1; i++)
		{	
			numTwo = "";
			/*int k;
			int count = 0;
			for(k = i + 1; k < length; k++)
			{
			cout << "k is " << k << endl;
			
				if((int)*input[k] - 48 >= 0 && (int)*input[k]- 48 <= 9)
				{
					count++;
					numTwo += *input[k];
				}
				else
					break;//that means it hit an operator 
			}*/
			//cout << "count is " << count << endl;
			if((int)*input[i+1] - 48 < 0 &&  (int)*input[i+1]- 48 > 9)
			{
				return nullptr;
			}
			
			numTwo = input[i+1];
			opTwo = new Op(stoi(numTwo));
			cout << "opTwo" << opTwo->stringify() << endl;
			if(*input[i]==mult)	
			{
			//	cout << "In mult" << endl;
				express = new Mult(opOne,opTwo);
			}
			else if(*input[i]==div)
			{
			//	cout << "In div" << endl;
				express = new Div(opOne,opTwo);
			}
			else if(*input[i]==add)
			{
			//	cout << "In add" << endl;
				express = new Add(opOne,opTwo);
			}
			else if(*input[i]==sub)
			{
			//	cout << "In sub" << endl;
				express = new Sub(opOne,opTwo);
			}
			else if(*input[i]==exp)
			{
			//	cout << "In exp" << endl;
				express = new Pow(opOne,opTwo);
			}
			else
				return nullptr;
			opOne = express;
			i++;
			/*if((i + count) < length)
			{
				i += count;
			}*/
						
		}
		return opOne;		
	}
};
#endif
