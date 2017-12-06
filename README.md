# iota_seed_generator
A secure generator for a IOTA seeds that works on Windows and Linux. It generates 81 characters cryptographically secure random seeds, that consist of uppercase latin characters and the digit 9. 

The codebase is tiny, so it can be easily reviewed for correctness.

You can compile it yourself or download the precompiled versions below:

### windows (64 bit):  [iota_seed_generator-0.1.zip](https://github.com/spjsschl/iota_seed_generator/raw/master/versions/0.1/iota_seed_generator-0.1.zip)

### linux (64 bit): [iota_seed_generator-0.1.tar.gz](https://github.com/spjsschl/iota_seed_generator/raw/master/versions/0.1/iota_seed_generator-0.1.tar.gz)

## Example:

PLEASE DO NOT USE THESE SEEDS, MAKE YOUR OWN!

C:\\> iota_seed_generator.exe                                                                                                                                                                                              
Generated seed:                                                                                                                                                                                                     
JJCBVUYWASAHJHXACXOXGXZRNWTFVJVJP9UVYFOLBEJUBGFNVELYLNMTLALVOATWTZTCQDWHOLPPWPGZB

or

$ ./iota_seed_generator
Generated seed:                                                                                                                                                                                                     
DS9TCFWYE9J9FPOHCDZS9RHJDGXNKWDIVPPWQUWERSKUDNXTDKZSXQWCO9PW9KCTQBMCTYURKQGABHFNE

## Problems:
Q: The generator hangs after running it a couple of times.
A: You have run out of buffered entropy, this is a good thing, as you do not want to use weak entropy sources. Give it some time and use the machine, this will eventually generate new entropy and your seed generation will finish.

## Donate
If you find this software useful, please consider donating some iota: IQ9KVFAXMNOUGQLVISTQUVHZUZFGBSCQRVKFBBUEGTTMHQQXWHBSUSEHJNLDELFXVBJWHJTSLTTCFSLHBDRCYWWUYZ

