clang++ pass.cpp -fPIC -shared -I$(llvm-config --includedir) -o libPass.so
# clang -fpass-plugin=./libPass.so log.c ../SDL/sim.c ../SDL/app2.c ../SDL/start.c -lSDL2
clang -fpass-plugin=./libPass.so log.c ../graph/sim.c ../graph/app.c ../graph/start.c -lSDL2 -O2 #-emit-llvm -S
echo starting run...
./a.out > stats.txt
