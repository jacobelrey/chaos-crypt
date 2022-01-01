# Chaos-Crypt

This repo contains the code and binaries for a symmetric, 288-bit key, 128-bit block cipher with qualities that make it resistant to quantum attack.
They can be run using the binaries found in the bin folder on linux or windows 10 systems, or compiled from src.

## Getting Started

In order to run the program, simply execute the command
for linux users

`encryptor-unix input_file output_file`

or on windows

`encryptor-win.exe input_file output_file`

once this is run, you will be prompted to type in 9 32-bit float sub-keys, or alternately a 36 character string, in order to encrypt the input file and write it to the output file.  In order to decrypt a file, the process simply needs to be repeated with the encrypted file as the input, and the same key as used to encrypt.

## Authors

  - **Jacob Elrey** - *Principal Developer* -
    [elrey12104](https://github.com/elrey12104)

  - **Billie Thompson** - *Provided README Template* -
    [PurpleBooth](https://github.com/PurpleBooth)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for
details

## Acknowledgments

  - Thanks to my project supervisor Alex Schuddeboom for his guidance
  - Thanks to Lorenz for doing most of the math for me :)
