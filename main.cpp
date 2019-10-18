#include <iostream>
#include <random>

using namespace std;

unsigned short query(const bool binary[], const unsigned short binaryLength) {
    cout << "Q";

    for (unsigned short index = 0; index < binaryLength; index++) {
        cout << " " << binary[index];
        cout.flush();
    }

    unsigned short result;
    cin >> result;

    return result;
}

void answer(bool binary[], unsigned short binaryLength) {
    cout << "A";

    for (unsigned short index = 0; index < binaryLength; index++) {
        cout << " " << binary[index];
        cout.flush();
    }
}

unsigned short randomBit(const bool correctBinary[], const unsigned short binaryLength) {
    bool isCorrect = true;
    unsigned short randomPos = 0;

    while (isCorrect) {
        std::mt19937 rng;
        rng.seed(std::random_device()());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(0, binaryLength);

        randomPos = static_cast<unsigned short>(rand() % 100);

        if (randomPos >= 0 && randomPos < binaryLength) {
            if (!correctBinary[randomPos]) {
                isCorrect = false;
            }
        }
    }

    return randomPos;
}


int main() {
    unsigned short binaryLength; cin >> binaryLength;

    bool binary[binaryLength];
    bool correctBinary[binaryLength];

    for (unsigned short index = 0; index < binaryLength; index++) {
        binary[index] = false;
        correctBinary[index] = false;
    }

    unsigned short prevCorrectCount;
    unsigned short correctCount = query(binary, binaryLength);
    unsigned short bitPoint;

    while (correctCount != binaryLength) {
        bitPoint = randomBit(correctBinary, binaryLength);
        binary[bitPoint] = !binary[bitPoint];

        prevCorrectCount = correctCount;
        correctCount = query(binary, binaryLength);

        if (prevCorrectCount < correctCount) {
            correctBinary[bitPoint] = true;
        } else {
            binary[bitPoint] = !binary[bitPoint];
        }
        correctBinary[bitPoint] = true;
    }

    answer(binary, binaryLength);

    return 0;
}
