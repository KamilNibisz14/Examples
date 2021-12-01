from decimal import Decimal

d1 = -3.34
d2 = -40.8
minus = (bool(d1 < 0) ^ bool(d2 < 0))

s1 = str(-d1 if d1 < 0 else d1)
s2 = str(-d2 if d2 < 0 else d2)

if isinstance(d1, int):
    dot1 = len(s1)
else:
    dot1 = s1.index('.')
if isinstance(d2, int):
    dot2 = len(s2)
else:
    dot2 = s2.index('.')

str1 = s1.replace('.', '')
str2 = s2.replace('.', '')

l1 = int(str1)
l2 = int(str2)

w = 0
t = l1
o = 1
while o <= l2:
    if l2 & o:
        w += t
    t += t
    o += o
s = str(w)
lvlD = len(s) - ((len(str1)) + (len(str2)) - (dot1 + dot2))
s = s[:lvlD] + '.' + s[lvlD:]
result = Decimal(s)
if minus:
    result = -result
print(result)
