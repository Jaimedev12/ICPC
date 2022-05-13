# VARIABLES
cases = int(input())
y = []

# BLOQUE
for i in range(0,cases):
  numero = int(input())
  y.append(numero)

for element in y:
  ls_cor = []
  #victory = False

  if element % 2 == 0:
    ls_cor.append(str(2))
    #victory = True
    
  if element % 3 == 0:
    ls_cor.append(str(3))
    #victory = True
    
  if element % 4 == 0:
    ls_cor.append(str(4))
    #victory = True
    
  if element % 5 == 0:
    ls_cor.append(str(5))
    #victory = True
    
  if element % 6 == 0:
    ls_cor.append(str(6))
    #victory = True
    
  if not ls_cor:
    ls_cor.append(str(-1))
    
  print(' '.join(ls_cor))