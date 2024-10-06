## Example of adding my own pass to LLVM to collect stats

It adds call to log function after every LLIR instruction. To compile it, run `bash comrun.sh`. Using this info you can collect and analyze stats. To do so, run `a.out > stats.txt` and then `py analyse.py`.

## Result

![stats](stats.png)

Total: 64 instrs combos; top 30 of them:

inst <- dependency | count
--- | ---
load <- alloca | 274724
br <- icmp | 74973
icmp <- load | 71391
alloca | 66456
br | 61669
store <- alloca | 40989
store <- add <- alloca | 30128
store <- trunc <- alloca | 23956
sdiv <- mul | 19118
ashr <- load | 17967
trunc <- and | 17967
load | 13180
sdiv <- load | 13040
mul <- load | 13040
mul <- load <- load | 11998
add <- load <- sdiv | 11998
and <- ashr | 11978
sext <- load | 11838
getelementptr <- alloca <- sext | 11838
icmp <- call | 9559
add <- load | 9252
xor <- phi | 8959
zext <- xor | 8959
ret <- zext | 8959
call | 8443
ret | 7189
call <- load <- load | 6599
add <- load <- load | 6518
trunc <- ashr | 5989
and <- load | 5989
