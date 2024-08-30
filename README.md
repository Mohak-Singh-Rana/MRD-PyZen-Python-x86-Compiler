# MRD PyZen: Python-x86 Compiler

## Overview

The `MRD PyZen: Python-x86 Compiler` is a sophisticated compilation toolchain developed to translate **Python source code into x86_64 assembly code**. The compiler integrates several advanced features, including **recursion**, **multilevel inheritance**, **static polymorphism**, **constructors**, and **self-calls**. This project utilizes flex and bison for bottom-up parsing and generates intermediate code, which is then converted into x86_64 code. The python code output is generated using the GNU assembler.


## Project Milestones

The development of the `MRD PyZen` compiler was organized into three key milestones, each contributing to its overall functionality:

1. **Milestone 1 (Lexer, Parser, AST)**
   - **Task:** Created a lexer and parser for Python 3.8 grammar. Implemented indent and dedent tokens using an indent stack and states in flex. Supported Python's implicit/explicit line joining. Extracted and resolved grammar conflicts from Python 3.8. Added semantic actions for AST generation with node and edge functions. Implemented error handling for syntax and indentation issues.
   - **Output:** Successfully implemented a fully functional lexer and parser, generated accurate ASTs, and handled syntax and indentation errors effectively.

2. **Milestone 2 (Maintaining Symbol Tables and Generating 3AC)**
   - **Task:** Generated and maintained symbol tables for functions, classes, and global variables. Managed type checking and error handling. Handled 3AC generation for control flow statements, comparison, and basic operators using backpatching. Managed function and class definitions, self calls, and in-built functions. Added necessary marker non-terminals and managed backpatching lists.
   - **Output:** Developed a robust system for symbol table management, type checking, and 3AC generation, including control flow and function/class handling.

3. **Milestone 3 (Generating x86 Code)**
   - **Task:** Handled self-calls and class function calls with inheritance and polymorphism. Implemented array allocation using `malloc` and static string management. Supported string operations and developed functions for l-value/r-value calculations and variable offset handling.
   - **Output:** Successfully generated x86 assembly code, handled complex operations, and managed memory allocation and string processing.


## Achievements

The development of the `MRD PyZen` compiler was a significant and rewarding challenge. Our team dedicated extensive hours and effort to overcome various hurdles, resulting in a highly functional and efficient compiler. We are proud to be among the few groups to achieve a perfect score in all project evaluations.


## Team Members

* **Mohak Singh Rana**
* **Rajat Gattani**
* **Dhruv Garg**

