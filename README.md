# mandarin-substitution-cipher
C++ substitution cipher that maps text to Mandarin characters to encode and decode .txt files. Built for learning, not for secure encryption.
---------------------------------------------------------------------------------------------------------------------------------------------

# Instructions to use the Mandarin Encryption Algorithm:

1. Create a .txt file within the same file as the main.cc program, containing the
information you would like to encrypt.
2. Run the program with ./main. You will be prompted to type in a file name. Type in the
exact name of the file you created in step 1. This portion of the program IS case
sensitive so make sure that all punctuation, spelling, and capitalization are correct or
else it will not recognize the .txt file you created.
3. Proceed to encrypt the file with the (E) option of the next prompt. This portion of the
program is NOT case-sensitive, so typing in “e” or “E” will suffice. You do need to
encrypt before decryption if this is your first time running the program, so encryption
should be the only option you choose as there is nothing to decrypt yet.
4. After encryption is complete, there should be a new file within the directory titled
“encrypted_yourfilenamehere.txt”, this is the new name for the file that you will be
inputting into the decryption prompt if you decide to decrypt it.
5. Next, re-run the program, and when prompted for the filename, provide the newly
encrypted filename provided to you from step 4.
6. After providing the encrypted file name, the prompt for encryption or decryption will
appear. This time you type (D) for decryption as you provided the encryption file and
now need to decrypt it. Note: do not use the original file name for this step, the newly
encrypted file name needs to be used in order for decryption to occur. Use
“encrypted_yourfilename.txt” NOT “yourfilename.txt”.
7. The function should then create a new file in the directory titled
“decrypted_encrypted_yourfilename.txt”. This is your final result from the encryption
and decryption algorithm and you can proceed to restart from step 1 for any new .txt
files you would like to encrypt
