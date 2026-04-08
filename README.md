# Morse Code Translator

A two-way Morse code translator built in C. Converts plain text to Morse code and Morse code back to text.

## About
This project implements a complete Morse code system from scratch — no libraries, just pure C logic. It supports all 26 letters and digits 0-9, and includes input validation to check if a Morse code string is valid before decoding.

## Features
- Text → Morse code encoding
- Morse code → Text decoding
- Input validation for Morse code strings
- Supports all letters (A-Z) and digits (0-9)
- Clean separation between encoder and decoder logic using header files

## How to run
```bash
gcc main.c morse.c -o morse
./morse
```

## Example output
