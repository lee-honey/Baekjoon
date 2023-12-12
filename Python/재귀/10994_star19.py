def add_star(ptn):
    return "* " + ptn + " *"
def star(n):
    if n == 1:
        return ["*"]
    else:
        return ['*' * (1 + 4 * (n - 1)), '*'+' ' * (4 * (n - 1) - 1)+'*']\
        +list(map(add_star, star(n - 1)))\
        +['*'+' ' * (4 * (n - 1) - 1)+'*', '*' * (1 + 4 * (n - 1))]
print(star(int(input())))
print("\n".join(star(int(input()))))