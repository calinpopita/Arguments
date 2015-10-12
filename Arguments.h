//reviewed by calin-ciprian.popita
#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <string>
#include <vector>

class Arguments
{
private:
    /**
    * vector of argument strings (except the application name)
    */
    std::vector<std::string> args;
    /**
    * application name
    */
    std::string app;
    /**
    * Prohibit instantiation without arguments
    */
    Arguments(){} // #RCC missing {}

public:

    /**
    * Constructor
    * Throws exception (int) if argc < 1 or argv == 0.
    * Otherwise app is argv[0], and the rest of the elements
    * from the argument vector will be pushed back into args.
    */
    Arguments(int argc, char* argv[]);

    /**
    * Copy constructor
    * Copies all the member variables into the new object.
    */
    Arguments(const Arguments& rhs);

    /**
    * Array subscript operator for const objects
    * Throws exception (size_t) if index is out of range
    * Returns reference to argument at index i from args.
    */
    const std::string& operator[](const std::size_t i) const;

    /**
    * Assignment operator
    * Copies all members from rhs into the current object
    * Skips copy if this == &rhs
    */
	//#RCC throws exception rhs
    Arguments& operator=(const Arguments& rhs);

    /**
    * returns number of arguments stored in args
    */
    int count() const;

    /**
    * returns application name save in app
    */
    std::string appName() const;

    /**
    * Destructor
    */
    virtual ~Arguments(){} //#RCC missing {}
};

#endif //ARGUMENTS_H
