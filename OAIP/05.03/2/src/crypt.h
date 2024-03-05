#define uint unsigned int
const uint ENCRYPTION_MAX_LENGTH = 4;

uint *to_digits_array(uint);
uint encrypt(uint[ENCRYPTION_MAX_LENGTH]);
uint decrypt(uint[ENCRYPTION_MAX_LENGTH]);
