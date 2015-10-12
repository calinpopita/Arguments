
RM = rm
CLS = clear

CPPTOOL = g++
CPPFLAGS = -Wall

CPP = $(CPPTOOL) $(CPPFLAGS) -c
LINK = $(CPPTOOL) -o

GTEST_DIR = c:\reskill\gtest-1.7.0

GTEST_LIB = $(GTEST_DIR)\make\gtest_main.a

GTEST_INC = -isystem $(GTEST_DIR)\include

HEADERS=Arguments.h

all: main.exe test.exe
	$(CLS)
	main.exe 1st_argument 2nd_argument 3rd_argument
	test.exe
	
run: main.exe
	main.exe 1st_argument 2nd_argument 3rd_argument

test: test.exe
	test.exe

main.exe: main.o Arguments.o
	$(LINK) main.exe main.o Arguments.o

main.o: main.cpp Arguments.h
	$(CPP) main.cpp

Arguments.o: Arguments.cpp Arguments.h
	$(CPP) Arguments.cpp

test.exe: test.o Arguments.o $(GTEST_LIB)
	$(LINK) test.exe test.o Arguments.o $(GTEST_LIB)	

test.o: test.cpp
	$(CPP) $(CPPFLAGS) $(GTEST_INC) -o test.o -c test.cpp	


# clean up
clean:
	$(RM) Arguments.o
	$(RM) main.o
	$(RM) main.exe
	$(RM) test.o
	$(RM) test.exe
	