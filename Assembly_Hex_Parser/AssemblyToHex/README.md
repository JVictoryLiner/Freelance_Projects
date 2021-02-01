Assembly To Hexadecimal

Format:

ADD_<DestReg>,_<SrcReg/Value>
  
  ADD = Command
  DestReg = A | B | C | D | E ONLY
  SrcReg/Value = A | B | C | D | E or Any Single Character Input
  
MOVE_<DestReg>,_<SrcReg/Value>
  
  MOVE = Command
  DestReg = A | B | C | D | E ONLY
  SrcReg/Value = A | B | C | D | E or Any Single Character Input

STORE_<Addr>,_<SrcReg>
  
  STORE = Command
  Addr = Any Combination of Four Characters String
  SrcReg = A | B | C | D | E ONLY
  
LOAD_<DestReg>,_<Addr>
  
  LOAD = Command
  DestReg = A | B | C | D | E ONLY
  Addr = Any Combination of Four Characters String
  
JMP/JPZ/JPP/JPN_<Addr>
  
  JMP/JPZ/JPP/JPN = Command
  Addr = Any Combination of Four Characters String
