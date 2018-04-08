# Stream States
When an error occurs that isn't recoverable, it will put the stream into an error state. When a stream is in such a 
state, anything that happens afterwards will fail. The simplest way to determine whether or not a stream experienced an
error is to use it as a condition:
 ```
while(cin >> var) {
    // ...
}
``` 
The above example will only tell you whether or not the stream is valid or not and not what went wrong. The 
machine-dependent integral type `iostate` that contains information about the state of the stream. There are four `constexpr` values of type `iostream` that represented by bit patterns which can be used with bitwise operators for testing or setting. In addition to the state flags are functions that interrogate them.

|Bit or Function | Description |
|---|---|
|*strm*::`iostate`|Represents the condition of a stream|
|*strm*::`badbit`|Indicates that the stream is corrupted. This indicates a system-level failure. When this is set, it's usually not possible to continue using the stream.|
|*strm*::`failbit`|Set after a recoverable error, such as reading a character when a numeric value was expected. When this set, it's typically possible to correct the error and continue using the stream.|
|*strm*::`eofbit`|Set when the end of the file being read is hit. In this scenario, both this bit and the `failbit` is set.|  
|*strm*::`goodbit`|Indicates that the stream is good and guarenteed to be zero.|
|`bad()`|Returns the value of the `badbit` (`true` or `false`)|
|`eof()`|Returns the value of the `eofbit` (`true` or `false`)|
|`fail()`|Returns the value of the `failbit` (`true` or `false`). When using `fstream` objects, if a file cannot be opened, this bit is set.|
|`good()`|Returns the value of the `goodbit` (`true` or `false`)|
|`clear(iostate flags)`|Returns void, resets the bits on the stream when no parameter is passed. When used with a parameter, the bits specified are reset.|
|`setstate(iostate flags)`|Adds specified conditions to the stream. Returns `void`|
|`rdstate()`|Returns current condition of the stream as a *strm*::`iostate` value.|

