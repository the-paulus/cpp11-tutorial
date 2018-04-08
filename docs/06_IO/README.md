# IO

1. [Output Buffer](Output-Buffer.md)
    1. [Flushing the Output Buffer](Output-Buffer.md#flushing-the-output-buffer)
    2. [Tying Input and Output Streams Together](Output-Buffer.md#tying-input-and-output-streams-together)
2. [Streams](Streams.md)
    1. [Stream States](Streams.md#stream-states)
    2. [File Streams](Streams.md#file-streams)
    3. [File Modes](Streams.md#file-modes)

---

## IO Classes

1. iostream
    1. istream, wistream -- input stream
    2. ostream, wostram -- output stream
    3. iostream, wiostream -- input and output stream
2. fstream
    1. ifstream, wifstream -- reads files
    2. ofstream, wofstream -- writes files
    3. fstream, wfstream -- reads and writes files
3. sstream
    1. istringstream, wistringstream -- reads from a string
    2. ostringstream, wostringstream -- writes to a string
    3. stringstream, wstringstream -- reads and writes to a string

IO types use inherentance, therefore device types or character size affect IO operations.

- can't copy or assign IO objects
- functions that pass IO typically pass and return streams through returns

IO Library defines types and objects that manipulate wchar_t data which begin with a 'w'. `wcin`, `wcout`, and `werr` are
the wchar_t eqovolent of `cin`, `cout`, `err`, respectively. Each header includes the wchar_t version.