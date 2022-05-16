#if defined(CRYPTOPP_IS_DLL)
# include <cryptopp/dll.h> // See upstream readme.txt
#endif

#include <cryptopp/sha.h>

int main() {
  using namespace CryptoPP;

  SHA256 hash;
  hash.Update((byte*)"aaaa", 4);
  std::string digest(hash.DigestSize(), '\0');
  hash.Final((byte*)&digest[0]);

  if (digest == "\x61\xbe\x55\xa8\xe2\xf6\xb4\xe1\x72\x33\x8b\xdd\xf1\x84\xd6\xdb\xee\x29\xc9\x88\x53\xe0\xa0\x48\x5e\xce\xe7\xf2\x7b\x9a\xf0\xb4") {
    return 0;
  }

  return -1;
}
