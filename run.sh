#!/bin/bash
#Run this in terminal
#+ Command to compile c++ program. here i used common one
g++ reader.cpp -o reader
./reader
diff loomings*txt 
exit 0