//by calin-ciprian.popita
//should by divided according to interface items tested (lack of time)

//tests Argument.h interface

#include "gtest/gtest.h"
#include "Arguments.h"

// checks exception throwing for constructor
bool helpConstructorTest(const int argc, char* argv[])
{
	bool hasException = false;
	try
	{
		Arguments args(argc, argv);
	}
	catch (int e)
	{
		hasException = true;
	}
	return hasException;
}

TEST(constructorTest, argcRangeBoundaries) // valid argv values
{
	char *arg[3] = {
		(char*) "application",
		(char*) "1st_argument", 
		(char*) "2nd_argument"};
	
	//test constructor with valid arguments
	EXPECT_EQ (false, helpConstructorTest(3, arg));
	
	//constructor with with valid arguments
	EXPECT_EQ (false, helpConstructorTest(2, arg));
	
	//constructor with valid arguments
	EXPECT_EQ (false, helpConstructorTest(1, arg));
	
	//constructor with out of range argument
	EXPECT_EQ (true, helpConstructorTest(0, arg)); //BUG DETECTED !!!
	//CHECK ARGC EVALUATION
	
	//constructor with out of range argument
	EXPECT_EQ (true, helpConstructorTest(-1, arg));
} 

TEST(constructorTest, argvRangeBoundaries) // valid argc values
{
	char *arg[3] = {
		(char*) "application",
		(char*) "1st_argument", 
		(char*) "2nd_argument"};
	char **arg1 = 0;
	
	//test constructor with valid arguments
	EXPECT_EQ (false, helpConstructorTest(3, arg));
	
	//constructor with out of range arguments
	EXPECT_EQ (true, helpConstructorTest(3, arg1)); 
} 

// checks exception throwing for operator[] ("array subscript")
bool helpArraySubscriptTest(const size_t i, Arguments& args)
{
	bool hasException = false;
	try
	{
		EXPECT_EQ(args[i], args.operator[](i));
	}
	catch (size_t e)
	{
		hasException = true;
	}
	return hasException;
}

TEST(arraySubscriptTest, rangeBoundaries)
{
	char *arg[] = {
		(char*) "application",
		(char*) "1st_argument",
		(char*) "2nd_argument",
		(char*) "3rd_argument"};
	

	Arguments args(4, arg);
	EXPECT_EQ (true, helpArraySubscriptTest(3, args));
	EXPECT_EQ (false, helpArraySubscriptTest(2, args));
	EXPECT_EQ (false, helpArraySubscriptTest(1, args));
	EXPECT_EQ (false, helpArraySubscriptTest(0, args));
	//EXPECT_EQ (true, helpArraySubscriptTest(-1, args));
	
} 

// checks exception throwing for operator= 
bool helpAssignmentOperatorTest(Arguments& args, Arguments& args1)
{
	bool hasException = false;
	try
	{
		args.operator=(args1);
	}
	catch (Arguments& e)
	{
		hasException = true;
	}
	return hasException;
}	

TEST(assignmentOperator, selfAssignment)
{
	char *arg[] = {
		(char*) "application",
		(char*) "1st_argument",
		(char*) "2nd_argument",
		(char*) "3rd_argument"};

	Arguments args(4, arg);
	
	// self assignment
	EXPECT_EQ(true, helpAssignmentOperatorTest(args, args));
}

TEST(assignmentOperator, sense)
{
	char *arg[] = {
		(char*) "application",
		(char*) "1st_argument",
		(char*) "2nd_argument",
		(char*) "3rd_argument"};
	char *arg1[] = {(char*) "app", (char*) "1st", 	(char*) "2nd"};

	Arguments args(4, arg);
	Arguments args1(3, arg1);
	Arguments args2(4, arg);
	
	// assignment "wide = narrow"
	EXPECT_EQ(false, helpAssignmentOperatorTest(args, args1));

	// assignment "narrow = wide" 
	EXPECT_EQ(false, helpAssignmentOperatorTest(args1, args2));
}

TEST(countTest, rangeBoundaries)
{
	char *arg[] = {
		(char*) "application",
		(char*) "1st_argument",
		(char*) "2nd_argument",
		(char*) "3rd_argument"};
	Arguments args(4, arg);
	EXPECT_EQ(3, args.count());
	EXPECT_NE(2, args.count());
	EXPECT_NE(4, args.count());
	
}

TEST(appTest, overall)
{
	char *arg[] = {
		(char*) "application",
		(char*) "1st_argument",
		(char*) "2nd_argument",
		(char*) "3rd_argument"};
	//char *arg1[] = {(char*) "", (char*) "1st", 	(char*) "2nd"};
	Arguments args(4, arg);
	//Arguments args1(3, arg1);
	
	EXPECT_EQ(arg[0], args.appName());
	//EXPECT_NE(arg1[0], args1.appName());
	
}