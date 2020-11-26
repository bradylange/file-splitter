# file-splitter
Splits file input based upon byte size input.

Brady Lange

04/16/18

Op Sys Programming

Assignment 4

## `src/file_splitter.c`
This program splits a file into multiple files based on a given byte size input. This is made possible 
because of the read and write functions. 

### Input:

`a.out file_splitter.c 400`

### Output:
None

## Issues:
- `file_splitter.c`: Only creates 1 file when splitting a `528 byte` file into `100 bytes`, doesn't compile on Windows (`code=3221225477`)