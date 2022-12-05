CMC ;complement carry
IAC ;incrementing accumulator
NOP ;no operation

loop,
 LDM 5
 INC 1p 
 INC 3p ;increment 3p register

FIM 1p $c0 ;write register 1p value hex c0
