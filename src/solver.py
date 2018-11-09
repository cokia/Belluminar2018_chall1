q = input()
for f in ['<[', ']>', '=>> ((???))', '!']:
    q = q.replace(f, '').strip()
print('question:', q)

num = []
oper = []
for idx, this in enumerate(q.split(' ')):
    if idx%2!=0: # operater
        oper.append(this)
    else: # num
        num.append(int(this))
print(num, oper)
ans = num[0]
for i in range(4):
    if oper[i] in ('-', '/'):
        ans += num[i+1]
    elif oper[i] in ('+', '%'):
        ans -= num[i+1]
    else:
        ans *= num[i+1]
print(ans)
