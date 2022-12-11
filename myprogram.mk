# Specify the target file and the source files.
# The target file is the file that will be created when the makefile is run.
# The source files are the files that the target file depends on.
# In this example, the target file is "myprogram" and the source files are "main.cpp", "Calculator.cpp", "KNN.cpp", "Data.cpp".
myprogram: main.cpp Calculator.cpp KNN.cpp Data.cpp

# Specify the commands that will be used to build the target file.
# In this example, the g++ compiler is used to build the "myprogram" executable from the source files.
# The -o option specifies the name of the output file, and the -std=c++11 option specifies that the C++11 standard should be used.
# The $^ variable is used to expand to the names of all of the prerequisites (i.e., the source files in this case).
# The @ symbol at the beginning of the line tells make to not display the command that is being run.
myprogram:
    @g++ -o $@ $^ -std=c++11

# This is the default target. When you run "make" without specifying a target, make will run the first target in the makefile.
# In this example, the default target is the "myprogram" target, so running "make" will build the "myprogram" executable.
# The "phony" keyword tells make that this target does not correspond to a file that should be created.
.PHONY: all
all: myprogram