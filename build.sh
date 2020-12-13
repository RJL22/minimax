g++ -c -o minimax.o src/minimax.cpp 
g++ -c -o node.o src/node.cpp

ar ru libminimax.a minimax.o node.o
ranlib libminimax.a
