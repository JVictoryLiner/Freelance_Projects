# ## # **Assembly To Hexadecimal**

## Format:

### ADD_DestReg,_SrcReg/Value
  
  - **ADD** = Command
  - **DestReg** = A | B | C | D | E **ONLY**
  - **SrcReg/Value** = A | B | C | D | E or Any Single Character Input
  
### MOVE_DestReg,_SrcReg/Value
  
  - **MOVE** = Command
  - **DestReg** = A | B | C | D | E **ONLY**
  - **SrcReg/Value** = A | B | C | D | E or Any Single Character Input

### STORE_Addr,_SrcReg
  
  - **STORE** = Command
  - **Addr** = Any Combination of Four Characters String
 -  **SrcReg** = A | B | C | D | E **ONLY**
  
### LOAD_DestReg,_Addr
  
-   **LOAD** = Command
-   **DestReg** = A | B | C | D | E **ONLY**
- **Addr** = Any Combination of Four Characters String
  
### JMP/JPZ/JPP/JPN_Addr
  
  - **JMP/JPZ/JPP/JPN** = Command
  - **Addr** = Any Combination of Four Characters String
