# eofck

A command to check that a file ends with a line feed (`\n`). The file is
considered correct if it is empty.

```bash
$ gcc eofck.c -o eofck
$ ./eofck /your/file /another/file...
```
