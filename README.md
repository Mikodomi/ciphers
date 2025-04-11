# Ciphers
A basic implementation of the most famous classical ciphers in the C programming language. In the future I plan to combine them all into a CLI tool, but for now,
this project contains just individual files with my solutions to these encryption algorithms that anyone is free to study or *(more likely)* find mistakes in
and/or optimize.

## Caesar
Otherwise known as the shift cipher, is one of the most famous ciphers in history and . All it is, is just "shifting" each letter of the text along the alphabet.

For example, if one was to encode **"KREMOWKA"** with shift value of 3 (classical caesar) the process would look like this:
  +3
K -> N

R -> U

E -> H

  .

  .
  
  .

A -> D

... since the third letter in the standard english alphabet after K is N, after R is U and so on. The resulting cipher string is **NUHPRZND**

Decoding is very similar, in that instead of shifting forwards in the alphabet, you would shift backwards.
[Visit for more details](https://en.wikipedia.org/wiki/Caesar_cipher)

## Vigenère
Todo. For now, just read [here](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)

## Railfence

Todo. For now, just read [here](https://en.wikipedia.org/wiki/Rail_fence_cipher)
