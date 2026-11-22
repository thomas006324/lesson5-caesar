# Lesson 5: Caesar (IT 145-5)

**caesar.c** encrypts a message with the Caesar cipher. The key is given as a command-line argument; the program refuses to run (and returns 1) unless there is exactly one argument made only of digits. Each letter is rotated forward by the key, keeping its case and wrapping from Z back to A with `% 26`. Everything that is not a letter is left unchanged.

Compile and run:

    make caesar
    ./caesar 13
