import math

listaMasaxBolsa = []
listaPrecio = []
listaEficiencia = []
listaLados1 = []
listaLados2 = []
listaLados3 = []
listaAreas = []
listaPrecioPorCaso = []

#Darle valor a las variables de acuerdo el input
lista1 = input().split(" ")
bolsas = int(lista1[0])
nTriangulos = int(lista1[1])

if bolsas < 1 or bolsas > 5 or nTriangulos < 0 or nTriangulos > 10 ** 5:
  print(-1)
  exit()

#Asignar los pesos y precios de las bolsas a una lista
for counter in range(0, bolsas, 1):
  lista2 = input().split(" ")

  peso = int(lista2[0])
  precio = int(lista2[1])

  listaMasaxBolsa.append(peso)
  listaPrecio.append(int(precio))
  eficiencia = precio / peso
  listaEficiencia.append(eficiencia)

  if peso < 0 or peso > 25 or precio < 0 or precio > 100:
    print(-1)
    exit()
  
#Lados del triángulos
for counter in range(0, nTriangulos, 1):
  lista3 = input().split(" ")
  lado1 = int(lista3[0])
  lado2 = int(lista3[1])
  lado3 = int(lista3[2])
  listaLados1.append(lado1)
  listaLados2.append(lado2)
  listaLados3.append(lado3)

#Calcular área dados los lados
def calcularAreaTriangulo(a, b, c):
  s = (a + b + c) / 2

  area = math.sqrt(s * (s - a) * (s - b) * (s - c))

  return area

#Encontrar menor valor dentro de una lista
def encontrarMenorEnLista(a):
  numero = a[0]
  for x in a:
    if numero > x:
      numero = x
  return numero


#Generar lista con las áreas de los triángulos
for counter in range(0, nTriangulos, 1):
  area = calcularAreaTriangulo(listaLados1[counter], listaLados2[counter], listaLados3[counter])
  listaAreas.append(area)

#Area que debeos cubrir
areaTotal = sum(listaAreas)
#Encontrar la cantidad de kilos necesarios
kilosNecesarios = math.ceil(areaTotal / 30)

      
for counter in range(0, bolsas, 1):
  if kilosNecesarios // listaMasaxBolsa[counter] != 0:

    precioxCaso = kilosNecesarios / listaMasaxBolsa[counter] * listaPrecio[counter]
    listaPrecioPorCaso.append(int(precioxCaso))

print(encontrarMenorEnLista(listaPrecioPorCaso))


#Encontrar la bolsa con mayor eficiencia y buscar su índice
def encontrarBolsaMasEficiente():
  numero = listaEficiencia[0]
  for x in listaEficiencia:
    if numero > x:
      numero = x
  indiceBolsaMasEficiente = listaEficiencia.index(numero)
  return indiceBolsaMasEficiente
