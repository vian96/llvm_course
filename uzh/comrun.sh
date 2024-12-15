set -e
antlr4 -Dlanguage=Cpp UzhLang.g4 -visitor
clang++ *.cpp -I /usr/include/antlr4-runtime/ -lantlr4-runtime  $(llvm-config --cppflags --ldflags --libs) ../graph/sim.c -lSDL2
./a.out $1
