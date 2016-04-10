#Nanolisp Grammar



##Syntax 

ID: [a-Z]([a-Z0-9_]+)
NUMBER: -?[0-9]+(.[0-9]+)?
STRING: "[^"]+"
LP: \(
RP: \)

##Grammar


program : expression

expression : ID | NUMBER | STRING | list

list : LP expression* RP


---

