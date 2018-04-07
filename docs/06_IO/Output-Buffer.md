# Output Buffer
Each stream manages a buffer, which it uses to retain data until an appropriate time to flush it. Using a buffer allows the operating system to combine several operations into a single one and executing the operation when the OS feels that the time is right.

Several conditions cause the buffer to be flushed:

- The program completes normally.
- The buffer has become full and needs to clear it in order to continue reading or writing.
- Explicitly flushing the buffer such as using the `endl` manipulator.
- Using the `unitbuf` manipulator to set the stram's internal state to empty the buffer after each operation. By default this is set for `cerr` so that errors are displayed immediately.
- A stream that is tied to another that gets flushed will also get flushed. `cin` and `cerr` are both tied to `cout` so when reading `cin` or writing to `cerr`, `cout`'s buffer gets flushed.

## Flushing the Output Buffer
In addition to the `endl` manipulator, that flushes buffer are `flsuh` and `ends`.

`endl` flushes the buffer while adding a new line.
`flush` simply flushes the buffer.
`ends` flushes the buffer and adds a null.

Using the `unitbuf` sets the stream to flush the buffer after each write. To stop this behavior use `nounitbuf`.

```
cout << unitbuf;
cout << "1 ";
cout << "2 ";
cout << "3 ";
cout << nounitbuf;
```

## Tying Input and Output Streams Together
When an input stream is tied to an output stream, any attempts to read from input will flush the buffer that has been 
tied to it as the output stream. This is done by using `tie`. There are two versions `tie`.

```
cout << cin.tie() << endl; // Retrieves the stream that is tied to cin.
ostream *prev_stream = cin.tie(nullptr); // Unties cout from cin and stores the old stream in a variable.
cin.tie(&cerr); // Ties cerr to cin.
cin.tie(prev_stream); // Ties original stram back to cin.
``` 