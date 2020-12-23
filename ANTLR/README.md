# ANTLR 4.9

``` PowerShell
java -jar antlr-4.9-complete.jar -Dlanguage=Cpp -o .\parser\ Grammar.g4
clang++ -I .\parser\ -I .\antlr4-runtime\ main.cpp .\parser\*.cpp antlr4-runtime.lib
```
