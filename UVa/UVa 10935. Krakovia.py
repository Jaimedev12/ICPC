import sys

inputs = sys.stdin.read().splitlines()
caseNo = 1
ln = 0

while True: 
  N, F  = map(int, inputs[ln].split())
  ln += 1
  if N == 0 and F == 0: break
  sum = 0
  for _ in range(N):
    sum += int(inputs[ln])
    ln += 1
  print("Bill #%d costs $d: each friend should pay %d\n" % (caseNo, sum, sum/F))
  caseNo += 1