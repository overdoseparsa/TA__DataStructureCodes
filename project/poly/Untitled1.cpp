
#include <iostream>
#define MAX 1000

class Polynomial {
private:
    int coeff[MAX];
    int power[MAX];
    int termCount;

public:
    Polynomial() {
        termCount = 0;
    }

    void getPolynomial() {
        std::cout << "Enter the number of terms in the polynomial: ";
        std::cin >> termCount;
        std::cout << "Enter the coefficients and powers for each term:\n";
        for (int i = 0; i < termCount; i++) {
            std::cin >> power[i] >> coeff[i];
        }

        
        for (int i = 0; i < termCount; i++) {
            for (int j = i + 1; j < termCount; j++) {
                if (power[j] > power[i]) {
                    std::swap(power[i], power[j]);
                    std::swap(coeff[i], coeff[j]);
                }
            }
        }
    }

    void displayPolynomial() {
        for (int i = 0; i < termCount; i++) {
            if (i > 0) std::cout << " + ";
            std::cout << coeff[i] << "x^" << power[i];
        }
        std::cout << "\n";
    }

    Polynomial addPolynomials(const Polynomial& other) const {
        Polynomial result;
        result.termCount = termCount;

        for (int i = 0; i < termCount; i++) {
            result.power[i] = power[i];
            result.coeff[i] = coeff[i];
        }

        for (int i = 0; i < other.termCount; i++) {
            bool found = false;
            for (int j = 0; j < result.termCount; j++) {
                if (other.power[i] == result.power[j]) {
                    result.coeff[j] += other.coeff[i];
                    found = true;
                    break;
                }
            }
            if (!found) {
                result.power[result.termCount] = other.power[i];
                result.coeff[result.termCount] = other.coeff[i];
                result.termCount++;
            }
        }

        return result;
    }

    Polynomial multiplyPolynomials(const Polynomial& other) const {
        Polynomial result;
        result.termCount = 0;

        for (int i = 0; i < termCount; i++) {
            for (int j = 0; j < other.termCount; j++) {
                int newPower = power[i] + other.power[j];
                int newCoeff = coeff[i] * other.coeff[j];
                bool found = false;
                for (int k = 0; k < result.termCount; k++) {
                    if (result.power[k] == newPower) {
                        result.coeff[k] += newCoeff;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    result.power[result.termCount] = newPower;
                    result.coeff[result.termCount] = newCoeff;
                    result.termCount++;
                }
            }
        }

        return result;
    }
};

int main() {
    Polynomial p1, p2, p3, p4;
    std::cout << "vared conid avalin poly:\n";
    p1.getPolynomial();
    std::cout << "vared konid dovomi:\n";
    p2.getPolynomial();
    std::cout << "avali poly: ";
    p1.displayPolynomial();
    std::cout << "deomi poly: ";
    p2.displayPolynomial();
    p3 = p1.addPolynomials(p2);
    std::cout << "jame poly: ";
    p3.displayPolynomial();
    p4 = p1.multiplyPolynomials(p2);
    std::cout << "Prod poly: ";
    p4.displayPolynomial();
    return 0;
}