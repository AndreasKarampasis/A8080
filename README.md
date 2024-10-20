# Intel 8080 Assembler

This project is an Intel 8080 Assembler written in C using the flex and bison tools for parsing and lexical analysis. The goal is to convert Intel 8080 language into correspondig machine code.

## Features
- Assembler for Intel 8080: Converts Intel 8080 assmbly language into machine code.
- Written in C: For perfomarnce and flexibility.
- Lexical analysis with flex: Handles the tokenisation of the assembly code.
- Syntax Parsing with bison: Manages the assembly syntax and generates machine code.

## Reuirements
To build and run ths project, you will need:
- C Compiler: GCC
- flex: Lexical analyser generator.
- bison: Parser generator.

## Installation
1. Clone the repository:
```bash
git clone https://github.com/andreaskarampasis/A8080.git
cd A8080
```
2. Install flex and bison (if not already installer)
```bash
sudo dnf install flex bison
```
3. Compile the project
```bash
make
```

## Usage
Once compiled, you can run the assembler with the following command:
```bash
./A8080 <inputfile.asm>
```
- Replace `<inputfile.asm>` with the path to your Intel 8080 assembly source file.
- The output will be a binary file containing the assembled machine code.

## Example
Sample assembly file (`test.asm`)
```asm
LXI H, 1234H
MVI A, 56H
ADD B
HLT
```
To assemble the code:
```bash
./A8080 test.asm
```

## Roadmap
- [ ] Add support for chars/strings.
- [ ] Add support for macros.
- [ ] Implement error reporting.

## Contributing
Contributions are welcome! Feel free to submit pull requests to add new features, fix bugs, or improve documentation.

## License
This project is licensed under the MIT License.