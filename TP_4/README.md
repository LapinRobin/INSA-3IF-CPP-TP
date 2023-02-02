# Apache Logs Analysis

## Description

This project is a simple tool to analyze Apache logs.

For more information, refer to the [User Manual](User_Manual.md).

## Dependencies

- g++ compiler required
- C++11
  
## Project Structure
```
./
├── README.md
├── StructureDuFrameworkDeTests.pdf
├── Tests
│   ├── Test11
│   ├── Test12
│   ├── Test13
│   ├── Test14
│   ├── Test15
│   ├── Test16
│   ├── Test17
│   ├── Test18
│   ├── Test19
│   ├── Test20
│   ├── Test21
│   ├── Test22
│   ├── Test23
│   ├── Test24
│   ├── Test25
│   ├── Test26
│   ├── Test27
│   ├── Test8
│   ├── Test9
│   ├── mktest.sh
│   ├── readme.txt
│   ├── results.csv
│   └── test.sh
├── User_Manual.md
├── User_Manual.pdf
├── bin
├── src
│   ├── Flux.cpp
│   ├── Flux.h
│   ├── Makefile
│   ├── Stats.cpp
│   ├── Stats.h
│   └── analog.cpp
└── tmp
    ├── anonyme.log
    ├── big.log
    └── test.log

```

## Test

Tested under MacOS 12.6 and Ubuntu 20.04

**Important:** Test framework will not work under Ubuntu 18.04 as there is minor differences in the arrangement of nodes with the same number of responses, which doesn't at all affect the correctness of the program.

## License

The MIT License (MIT)

Copyright (c) 2023 NGUYEN Le Tuan Khai and SU Yikang

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
