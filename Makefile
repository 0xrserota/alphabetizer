#
#
#  COMP 15 HW4 - Tree-Mendous Alphabetizer
#
#  Makefile
#  Makefile for alphabetizer 
#  Modified By (UTLN): rserot01
#          On       : 10/26/2017
#
#

CXX 	 = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11
LDFLAGS  = -g3


alphabetizer: 	main.o StringBST.o Alphabetizer.o 
	${CXX} ${CXXFLAGS} ${LDFLAGS} -o alphabetizer main.o StringBST.o \
									Alphabetizer.o


main.o:		    main.cpp Alphabetizer.h StringBST.h
StringBST.o:    StringBST.cpp StringBST.h  
Alphabetizer.o: Alphabetizer.cpp Alphabetizer.h 


clean: rm -rf alphabetizer */dSYM *.o

provide: 


# End Makefile	