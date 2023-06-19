#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

#define BUF_SIZE 1024

int main() {
    // Plaintext to be encrypted
    char plaintext[] = "Hello World";

    // Initialize RSA
    RSA *rsa = NULL;
    FILE *pubKeyFile = fopen("public_key.pem", "rb");
    rsa = PEM_read_RSA_PUBKEY(pubKeyFile, &rsa, NULL, NULL);
    fclose(pubKeyFile);

    // Encryption
    int encLen;
    unsigned char encrypted[BUF_SIZE];
    encLen = RSA_public_encrypt(strlen(plaintext), (unsigned char *)plaintext, encrypted, rsa, RSA_PKCS1_PADDING);
    if (encLen == -1) {
        printf("Encryption failed.\n");
        return 1;
    }

    printf("Encrypted: ");
    for(int i = 0; i < encLen; i++) {
        printf("%02x", encrypted[i]);
    }
    printf("\n");

    // Decryption
    FILE *privKeyFile = fopen("private_key.pem", "rb");
    rsa = PEM_read_RSAPrivateKey(privKeyFile, &rsa, NULL, NULL);
    fclose(privKeyFile);

    char decrypted[BUF_SIZE];
    int decLen = RSA_private_decrypt(encLen, encrypted, (unsigned char *)decrypted, rsa, RSA_PKCS1_PADDING);
    if (decLen == -1) {
        printf("Decryption failed.\n");
        return 1;
    }

    decrypted[decLen] = '\0';
    printf("Decrypted: %s\n", decrypted);

    // Clean up
    RSA_free(rsa);
    ERR_free_strings();

    return 0;
}