# msh
jvcortes &amp; jsgalvish - simple shell

## Installation
Execute the following command from the project root:
```shell
$ gcc -Wall -Werror -Wextra -pedantic *.c -o msh
```

## Usage
<b>msh</b> can be used in non-interactive mode, piping the output of the
command of your choice:
```shell
$ echo "ls -l" | ./msh
```
If you want to use the shell in interactive mode you can directly use the
executable:
```shell
$ ./msh
```
You will be greeted with the following prompt, ready to receive your next command:
```shell
[._.] >>
[._.] >> ls
-rw-r--r-- 1 helium helium   216 ago 28 00:20 arrutil.c
-rw-r--r-- 1 helium helium  1914 ago 28 01:55 cmd.c
-rw-r--r-- 1 helium helium   761 ago 28 01:54 man_1_simple_shell
-rw-r--r-- 1 helium helium  1492 ago 28 00:17 mem_util.c
-rwxr-xr-x 1 helium helium 39992 ago 27 23:27 msh
-rw-r--r-- 1 helium helium  1316 ago 28 00:05 path.c
-rw-r--r-- 1 helium helium    55 ago 24 15:44 README.md
-rw-r--r-- 1 helium helium   308 ago 28 00:23 shell.c
-rwxr-xr-x 1 helium helium  1020 ago 27 23:35 shell.h
-rw-r--r-- 1 helium helium  1604 ago 28 00:14 strutil_1.c
-rw-r--r-- 1 helium helium   440 ago 27 23:05 strutil_2.c
-rw-r--r-- 1 helium helium  2403 ago 28 01:57 tags
-rw-r--r-- 1 helium helium   691 ago 28 00:24 trace
-rw-r--r-- 1 helium helium  1824 ago 27 23:53 util.c
```

