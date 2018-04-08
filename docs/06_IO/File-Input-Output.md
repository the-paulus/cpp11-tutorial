# File Input and Output
The `fstream` header provides three types to perform file IO: `ifstream` for reading, `ofstream` for writing, and `fstream` for both. Reading and writing ot file streams is no different than when working with input and output streams (`cin` and `cout`).

File streams have additional members to manage the file assigned to them:

|Function|Description|
|:---|:---|
|`fstream fstrm;`|Creates an unbound file stream.|
|`fstream fstrm(const char *filename);`|Craetes a new file stream bound to the file named.|
|`fstream fstrm(const string &filename);`|Craetes a new file stream bound to the file named.|
|`fstream fstrm(const char *filename, openmode_mode mode)`|Craetes a new file stream bound to the file named in the first parameter. The first parameter can also be either a `const char *` or a `const string &`. The default mode depends on the kind of stream that is desired.|
|`fstream fstrm(const string &filename, openmode_mode mode)`|Craetes a new file stream bound to the file named in the first parameter. The first parameter can also be either a `const char *` or a `const string &`. The default mode depends on the kind of stream that is desired.|
|`fstrm.open(const char *filename);`|Opens *filename*.|
|`fstrm.open(const string &filename);`|Opens *filename*.|
|`fstrm.open(const char *filename, openmode_mode mode);`|Opens *filename* in the specified *mode*|
|`fstrm.open(const string &filename, openmode_mode mode);`|Opens *filename* in the specified *mode*|
|`fstrm.close()`|Closes the file returning nothing. This method is called when the fstream object is destroyed.|
|`fstrm.is_open()`|Returns a `bool` indicating whether the file assocated with the object was successfully opened and has not been closed.|

## File Streams
In order to read or write to a file a file stream object associated with a file must exist. 

```
ifstream in("out.txt"); // Constructs a new object called in, which will read from the file called "out.txt"
ofstream out; // Constructs a new object called out with no associated file
```

Because of inheritance, any object of type `iostream` can be replaced by an `fstream` object.

```
istream &read(istream &is, string &line) {
    getline(is, line);
    return is;
}

ostream &write(ostream &os, string &line) {
    os << line;
    return os;
}

istream input("input.txt");
ostream output("output.txt");

while(read(input, line)) {
    write(output, line) << endl;
}
``` 

When working with files, you should always test the `fstream` object to ensure that it is not in a state of error.

## File Modes
There are a total of six different file mode types between `ifstream` and `ofstream`.

|mode|description|
|---|---|
|in|Open for input, this is only valid for `ifstream` and `fstream` objects.|
|out|Open for output, this is only valid for `ofstream` and `fstream` objects. This mode implies `trunc`|
|app|Open for appending. `trunc` cannot be specificed when using `app`. This mode implies `out`|
|ate|Open and go to the end of the file. Can be used on either type of stream.|
|binary|Do IO operations in binary mode. Can be used on either type of stream.|

Files opened by `ifstream`, `ofstream`, or `fstraem` are opened by default in `in`, `out`, or both, respectively. 