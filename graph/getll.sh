mkdir -p llir
for o in 0 1 2 3; do 
    clang app.c -emit-llvm -o llir/app_o$o.ll -O$o -S
done

