


import math

def calcularCucharadasChidas(c, r, s):
  totalCereal = c + r
  totalCucharadas = math.ceil(totalCereal / s)

  cucharadasHorribles = math.ceil(r / s)
  cucharadasChidas_max = totalCucharadas - cucharadasHorribles

  if totalCucharadas - r < 0:
    cucharadasChidas_min = 0
  elif totalCucharadas - r > 0:
    cucharadasChidas_min = totalCucharadas - r

  return str(cucharadasChidas_max), str(cucharadasChidas_min)

n = int(input())

if 1 <= n <= 1000:

  listaR = []
  for n in range(n):
    listaDatos = input().split(' ') 
    c = int(listaDatos[0])
    r = int(listaDatos[1])
    s = int(listaDatos[2])

    if 0 <= c and r <= 10 ** 9 and 1 <= s <= 10 ** 9:
      x = " ".join(calcularCucharadasChidas(c, r, s))
      listaR.append(x)

  print(*listaR, sep = "\n")
