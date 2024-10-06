from collections import defaultdict

import numpy as np
import matplotlib.pyplot as plt

d = defaultdict(int)
stind = len('inst: ')

with open('stats.txt', 'r') as f:
    for i in f.readlines():
        d[i[stind:-1]] += 1

kv_srt = sorted(d.items(), key=lambda x: -x[1])

print(f'total: {len(d.keys())} instrs combos; top 30 of them: ')
print('inst <- dependency | count\n--- | ---')
print('\n'.join([f'{k} | {v}' for k, v in kv_srt][:30]))

plt.figure(figsize=(15,9))
plt.xticks(rotation=90)
plt.bar(*zip(*kv_srt))
# plt.bar(d.keys(), d.values())
plt.tight_layout()
plt.savefig('stats.png')
plt.show()

