#include <fstream>
#include <numeric>

#include "Euler.h"

int Euler::xorDecryption()
{
    const int file_size = 1201;

    std::ifstream file;
    std::vector<int> cypher;
    std::string character;
    std::string word = " the ";

    file.open("files/p059_cipher.txt");

    while(getline(file, character, ','))
        cypher.push_back(atoi(character.c_str()));

    char message[file_size];
    int pwd[3];

    for (pwd[0] = 'a'; pwd[0] < 'z' + 1; ++pwd[0])
    {
        for (pwd[1] = 'a'; pwd[1] < 'z' + 1; ++pwd[1])
        {
            for (pwd[2] = 'a'; pwd[2] < 'z' + 1; ++pwd[2])
            {
                for (int i = 0; i < file_size; ++i)
                    message[i] = cypher[i] ^ pwd[i % 3];

                if (std::string(message).find(word) != std::string::npos)
                    return std::accumulate(message, message + file_size, 0);
            }
        }
    }

    return 0;
}
