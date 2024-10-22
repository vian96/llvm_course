import re
import sys
with open(sys.argv[1], 'r') as f:
    ss = f.read()

for s in ss.split('; Function Attrs')[1:-1]:
    fname = re.match(r'[\w ]+ @(\w+)', s.split('\n')[1]).group(1)
    print('// ', s.split('\n')[1])
    print(f'FunctionType *{fname}Type = ...')
    print(f'Function *{fname}Func = ...')
    print("{\n// BasicBlocks:")
    print('BasicBlock *BB0 = BasicBlock::Create(context, "", {fname}Func);')
    for i in s.split('\n'):
        if (match := re.match(r'(\d+):', i)):
            n = int(match.group(1))
            print(f'BasicBlock *BB{n} = BasicBlock::Create(context, "", {fname}Func);')

    print('// MAIN CODE')

    for i in s.split('\n')[1:]:
        i = i.lstrip()
        if (match := re.match(r'(\d+):', i)):
            n = int(match.group(1))
            print(f'builder.SetInsertPoint(BB{n});')
        elif (match := re.match(r'%(\d+) = ([\w ]+) ([%\d-]+), ([%\d-]+)', i)):
            arg1 = match.group(3)
            if arg1.startswith('%'):
                arg1 = f'val{arg1[1:]}'
            else:
                arg1 = f'builder.getInt32({arg1})'
            arg2 = match.group(4)
            if arg2.startswith('%'):
                arg2 = f'val{arg2[1:]}'
            else:
                arg2 = f'builder.getInt32({arg2})'
            cmd = match.group(2)
            cmdn = cmd.split(' ')[0]
            if cmdn != 'icmp':
                op = {
                    'add': 'Add',
                    'mul': 'Mul',
                    'sdiv': 'SDiv',
                    'shl': 'Shl',
                    'or': 'Or',
                    'and': 'And',
                    'urem': 'URem',
                    'srem': 'SRem',
                    'sub': 'Sub',
                }.get(cmdn)
            else:
                op = 'ICmp{cmd.split(' ')[1].upper()}'
            if op:
                print(f'Value *val{match.group(1)} = builder.Create{op}({arg1}, {arg2});')
            else:
                print(f'unknown op {i}')
                
            
        elif (match := re.match(r'br label %(\d+)', i)):
            n = int(match.group(1))
            print(f'builder.CreateBr(BB{n});')
        elif (match := re.match(r'ret void', i)):
            print('builder.CreateRetVoid();')
        elif (match := re.match(r'ret i32 %(\d+)', i)):
            n = int(match.group(1))
            print('builder.CreateRet(..)')
        elif i in ['', '}']:
            continue 
        else:
            print(f'unknown cmd: {i}')
    print('}')




