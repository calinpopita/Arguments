//reviewed by calin-ciprian.popita
#include "Arguments.h"
#include <iostream>

using namespace std;

Arguments::Arguments(int argc, char* argv[])
{
    try
    {
        if ( argc < 0 || argv == 0 )
        {
            throw argc;			
        }
        else
        {
            //#RCC set app to be the first item from argv
			app = argv[0];
            //#RCC save the remaining from argv into the args vector (push_back)
			for (int i = 1; i < argc; i++)
			{
				args.push_back(argv[i]);
			}
			
        }
    }
    catch (int e)
    {
        cerr << "error: constructing argument object..." << endl;
        throw;
    }
}

//#RCC copy constructor
Arguments::Arguments(const Arguments& rhs):
		args(rhs.args),
		app(rhs.app)
{
}

//#RCC returns number of arguments for current object
int Arguments::count() const 
	{
		return args.size();
	}

//#RCC returns appName for current object
std::string Arguments::appName() const
	{
		return app;
	}


const string& Arguments::operator[](const size_t i) const
{
    try
    {
        if ( i >= args.size() ) throw i;
    }
    catch(size_t e)
    {
        cerr << "error: index out of range " << e << endl;
        throw;
    }
    //#RCC return argument on index
	return args[i];
}

//#RCC assigns rhs' parameters to current object
Arguments& Arguments::operator=(const Arguments& rhs)
{
	// handling exception for self assignment
	try
    {
		// check if current object is the same with argument
        if ( this == &rhs ) throw rhs; 
    }
    catch(Arguments& rhs)
    {
		// print error message
        cerr << "error: cannot assign the object to itself " << endl;
        throw; // to main  
    }

	// handling valid argument assignment
	args = rhs.args;
	app = rhs.app;
	
	return *this;// return current object with new parameters
} 

