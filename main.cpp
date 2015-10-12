//reviewed by calin-ciprian.popita
/// App using the Arugments class
#include <iostream>

#include "Arguments.h"


int main( int argc, char* argv[] )
{
    using namespace std;

    try
    {
        Arguments args(argc, argv);
	
        cout << "Name of the application: " <<
            args.appName() << endl;

        for ( int i = 0; i < args.count(); ++i )
        {
            cout << args[i] << endl;
        }
		
		//#RCC copy constructor example
		Arguments args1(args);
		
		cout << "\nNew object:\n";
		
		//#RCC display new created object		
		for ( int i = 0; i < args1.count(); ++i )
        {
            cout << args[i] << endl;
        }
		
		//#RCC operator[] example
		cout << "First argument is: " << args1.operator[](0) << endl;
		
		//#RCC operator= example
		args1.operator=(args);
		
		cout << "\nObject after assignment:\n";
		
		//#RCC display object after assignment
		for ( int i = 0; i < args1.count(); ++i )
        {
            cout << args[i] << endl;
        }
    }
    /// This will catch throws from the try block with an integer param
    catch (int e)
    {
        cerr << "Construction error occured..." << endl;
    }
    /// This will catch throws from the try block with a size_t param
    catch (size_t e)
    {
        cerr << "Out of range error occured ..." << endl;
    }
	
	//#RCC throw function for assignment operator
	/// This will catch throws from the try block with a Arguments& param
	catch (Arguments& rhs)
	{
		cerr << "Objects assignment error occured ..." << endl;
	}

    cout << "Ending application... " << endl;
    return 0;
}

