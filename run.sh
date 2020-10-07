#!/bin/bash
g++ reader.cpp -o reader
./reader

diff loomings*txt 
exit 0
