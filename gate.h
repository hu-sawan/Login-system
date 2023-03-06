#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>

class Gate
{
public:
    Gate(/* args */);
    ~Gate();

    // TODO: add a function to validate the password and username

    std::string hash(const std::string input)
    {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, input.c_str(), input.length());
        SHA256_Final(hash, &sha256);
        std::ostringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        return ss.str();
    }
};

Gate::Gate(/* args */)
{
}

Gate::~Gate()
{
}
