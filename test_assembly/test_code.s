MVI a, 0h

LXI b, 0h
MVI c, c0h

MVI a, aah

loop:
  MOV m,a
  INR a
  INR c
  CNZ loop
  
 INR b
 INR d
 CNZ loop
