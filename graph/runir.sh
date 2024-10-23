clang++ $(llvm-config --cppflags --ldflags --libs) sim.c app_ir.cpp -lSDL2
./a.out
