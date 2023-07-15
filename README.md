# get_next_line - 42 Network Project

This project is part of the 42 Network curriculum and focuses on implementing the get_next_line function in C programming language. The purpose of this project is to read and retrieve lines from a file descriptor, one line at a time.

# Table of Contents
- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Function](#function)
- [ReturnValues](#returnValues)
- [Examples](#examples)
- [Contributing](#contributing)

## Introduction
The get_next_line function is used to read and retrieve lines from a file descriptor, one line at a time. It allows you to read a line from a file, perform operations on it, and move on to the next line efficiently. The function provides a dynamic buffer that grows as needed to accommodate lines of varying lengths.

## Installation
To use the get_next_line function, follow these steps:

Clone the repository:
```
git clone https://github.com/your_username/get_next_line.git
```
Navigate to the project directory:
```
cd get_next_line
```
Compile the source code by running the Makefile:
```
make
```
The compilation process will generate a libgnl.a library file.

Link the library file to your own project or create a test program using get_next_line.

## Usage
To use the get_next_line function, include the get_next_line.h header file in your code:
```c
#include "get_next_line.h"
```
You can then call the get_next_line function using the following format:
```c
char *get_next_line(int fd);
```
The fd parameter is the file descriptor of the file you want to read from, and the line parameter is a pointer to a string where the line will be stored.

The function will return 1 when a line is successfully read, 0 when the end of file (EOF) is reached, and -1 in case of an error.

## Function
The function signature of get_next_line is as follows:
```c
char *get_next_line(int fd);
```
* fd: The file descriptor for the file to read from.
## ReturnValues
The get_next_line function returns:

* Line by line
## Examples
Here's an example demonstrating the usage of get_next_line:
```c
#include "get_next_line.h"

int main(void) {
    int fd;
    char *line;

    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
```
This example opens a file named "example.txt" for reading, reads the file line by line using get_next_line, and prints each line to the standard output. The dynamically allocated memory for each line is freed after use.

## Contributing
Contributions to the project are welcome. If you encounter any issues or have suggestions for improvements, please open an issue or submit a pull request.
