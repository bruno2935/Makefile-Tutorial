# Bit-Fields

Bit fields are data structures that consist of one or more adjacent bits allocated for specific purposes, allowing any single bit or group of bits within the structure to be set or inspected. These are commonly used to represent integral types of known, fixed bit-width, such as single-bit Booleans en.wikipedia.org. In C, you can specify the size (in bits) of structure and union members to use memory efficiently when the value of a field or group of fields will never exceed a limit or is within a small range geeksforgeeks.org.

In C, bit fields can be declared within a structure using the following syntax:

    ````c
    struct {
      data_type member_name: width_of_bit-field;
    };
    ```g


For example:

    ```c
    struct date {
      int month : 4;
    };
    ```

Here, the month variable uses only 4 bits to store its value, as the value will be between 0 and 15. Bit fields can be used to reduce memory consumption when a program requires integer variables with low values en.wikipedia.org. Keep in mind that some properties of bit fields, such as the order of bit fields within an allocation unit and whether a bit field can straddle an allocation unit boundary, are implementation-defined en.cppreference.com.

Use of bit fields:
  - Flags in function arguments

Reduce memory consuption of struct members

 - The __attribute__((packed)) attribute in the struct definition you provided is used to request that the compiler pack the members of the struct tightly, without adding any padding between them. This can help to reduce the size of the struct in memory.
    ```C
      struct counters {
      unsigned int little : 2;
      unsigned int medium : 4;
      unsigned int large : 6;
    } __attribute__((packed));

    ```
