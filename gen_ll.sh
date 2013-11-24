#! /bin/bash

# $1 is the header file that declares the struct
# $2 is the struct name
# e.g. "my_blob.h" file has "struct blob { int i; char *name; };" in it.
# $1 := my_blob.h, $2 := blob
base="${1%%.h}"
basecaps="`echo $base | tr '[:lower:]' '[:upper:]'`"
struct=$base
if [ -n "$2" ]; then
    struct=$2
fi
mkdir -p gen
rm -f gen/${base_ll}.h gen/${base}_ll.c
sed s/ll/"$struct"/g <ucll.c >gen/${base}_ll.c
sed s/ll/"$struct"/g <ucll.h >gen/${base}_ll.h
sed -i "" s/\\/\\/INCLUDE/"#include \"$1\""/ gen/${base}_ll.h
sed -i "" s/\\/\\/INCLUDE/"#include \"${base}_ll.h\""/ gen/${base}_ll.c
sed -i "" s/SOMETHING/"${basecaps}_H"/ gen/${base}_ll.h
sed -i "" s/SOMETHING/$basecaps/ gen/${base}_ll.c
