@echo off
gcc -std=c11 -Wall -Wextra -Wpedantic src\main.c src\conto.c src\funzioni.c src\gestione_file.c src\testing.c -o gestione_conti.exe
if %errorlevel% neq 0 (
  echo Compilazione fallita.
  exit /b %errorlevel%
)
echo Compilazione completata.
