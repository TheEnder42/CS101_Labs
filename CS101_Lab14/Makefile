#
# Makefile for a CS 101 lab or programming assignment.
# Do not modify this file!!!
#

SUBMIT_URL = https://cs.ycp.edu/marmoset/bluej/SubmitProjectViaBlueJSubmitter
COURSE_NAME = CS 101
SEMESTER = Spring 2016
PROJECT_NUMBER = lab14

# Some unknown software on the KEC Windows load
# sets the GCC_EXEC_PREFIX environment variable, which
# prevents Cygwin's gcc/g++ from working correctly.
# Make sure it is unset when we invoke g++.
CXX = unset GCC_EXEC_PREFIX && g++

CXXFLAGS = -g -Wall

SRC = Stats.cpp
OBJ = $(SRC:.cpp=.o)
EXE = $(SRC:.cpp=.exe)

$(EXE) : $(OBJ)
	$(CXX) -o $@ $(OBJ)

submit : submit.properties solution.zip
	perl submitToMarmoset.pl solution.zip submit.properties

solution.zip : collected-files.txt
	@echo "Creating a solution zip file"
	@zip -9 $@ `cat collected-files.txt`
	@rm -f collected-files.txt

# Create the submit.properties file that describes how
# the project should be uploaded to the Marmoset server.
submit.properties : nonexistent
	@echo "Creating submit.properties file"
	@rm -f $@
	@echo "submitURL = $(SUBMIT_URL)" >> $@
	@echo "courseName = $(COURSE_NAME)" >> $@
	@echo "semester = $(SEMESTER)" >> $@
	@echo "projectNumber = $(PROJECT_NUMBER)" >> $@

# Collect the names of all files that don't appear
# to be generated files.
collected-files.txt :
	@echo "Collecting the names of files to be submitted"
	@rm -f $@
	@find . -not \( \
				-name '*\.o' \
				-or -name '*\.exe' \
				-or -name '*~' \
				-or -name 'collected-files.txt' \
				-or -name 'submit.properties' \
				-or -type d \
			\) -print \
		| perl -ne 's,\./,,; print' \
		> $@

# This is just a dummy target to force other targets
# to always be out of date.
nonexistent :

# Remove generated files.
clean : 
	rm -f *.o *.exe collected-files.txt submit.properties solution.zip
