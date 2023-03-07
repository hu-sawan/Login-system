#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cctype>
#include <openssl/sha.h>

class Gate
{
public:
    Gate();
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

    bool check(const std::string input)
    {
        for (size_t i{}; i < input.length(); i++)
        {
            if (input[i] == ' ' || input[i] == '"' || input[i] == '\'')
            {
                return false;
            }
        }
        return true;
    }

    bool validate(const std::string username, const std::string password)
    {
        bool first_check = check(username);
        bool second_check = (check(password) && password.length() >= 8) ? true : false;

        bool result = (first_check && second_check) ? true : false;

        return result;
    }
};

Gate::Gate()
{
}

Gate::~Gate()
{
}
