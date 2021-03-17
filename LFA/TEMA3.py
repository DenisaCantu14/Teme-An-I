cuv = ['S']
l = 8
n = {
  "S":['AB', '$'],
  "A": ['aAbb', '$'],
  "B":['cBeee', '$', 'dC'],
  "C": ['dC', '$']
}
mul = set()
tup = ()
def solutie (cuvant):
    for x in cuvant:
        if x.isupper():
            return 0
    return 1
def count(cuv):
    nr = 0
    for x in cuv:
        if x.isupper():
            nr += 1
    return nr
def bkt(i, cuv):
    if len(cuv) <= l and solutie(cuv):
        tup = tuple(cuv)
        mul.add(tup)
    elif solutie(cuv) == 0:
        ok=0
        if i == len(cuv) and len(cuv)-count(cuv) <= l:
            bkt(0, cuv)
        while i < len(cuv) and ok == 0:
            if cuv[i].isupper():
                ok = 1
                for x in n[cuv[i]]:
                    poz = i-1
                    new = cuv.copy()
                    new.pop(i)
                    for c in x:
                        if c != '$':
                            poz += 1
                            new.insert(poz, c)
                    pas = poz+1

                    bkt(pas, new)
            i += 1
        if ok == 0 and len(cuv)-count(cuv) <= l:
            bkt(0, cuv)



bkt(0, cuv)
print(mul)
print(len(mul))
