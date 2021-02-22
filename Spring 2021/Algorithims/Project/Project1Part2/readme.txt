Overview of messagedigest
    Uses standard makefile that came with package, no files were modified other than messagedigest.
    Make sure both e_n.txt and d_n.txt are in the same folder!
    to sign a file, use:
        ./messagedigest s file.txt
    This creates a file.txt.copy, containing the original message
    This also creates a file.txt.signature containing the privately "decrypted" (using d and n) signature.

    To see if a file is changed, use:
        ./messagedigest v file.txt file.txt.signature
    The file you want to compare goes first, followed by
    the file you wish to "encrypt". The program takes the sha256 of the first file and
    compares it to the value generated from using the public key on file.txt.signature.
    The program, if used with option v, will report to the command line if the doument has been
    modified or not.
