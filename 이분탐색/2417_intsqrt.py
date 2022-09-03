import decimal
n = int(input())
e = decimal.Decimal(str(n))
if e.sqrt() == int(e.sqrt()):
    print(int(e.sqrt()))
else:
    print(int(e.sqrt()) + 1)