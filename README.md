ucll
====

Static-memory-based linked list template complete with a bash script to generate
linked list files for a given struct that has a next pointer.

Usage
-----

Assuming you have some `foo.h` file defining your `struct Foo` data type:

    //in foo.h
    struct Bar {
        int bar_id;
        //whatever fields you want
        struct Bar *next;//This is the only required field for ll to work
    }

__Note that the struct has a next field that is a pointer to the same type__

You can then generate your linked list files with the gen\_ll.sh script as such:

    ./gen_ll.sh foo.h Bar

The script will put the files (foo\_ll.h and foo\_ll.c) in the gen/folder. You
can copy them to your project, hard link them (so you can re-generate them later
and not have to copy, ideally as part of your build process), or even modify
them (*gasp*). To test that it worked, you can run the test baked into the .c
file. If your header is in your current directory and the files are in ./gen/
then it might look like:

    gcc -I. -DFOO_TEST gen/foo_ll.c && ./a.out

which counts to and from 14 using different features. Take a look at the test to
get a sense of how to use your new linked list files!
