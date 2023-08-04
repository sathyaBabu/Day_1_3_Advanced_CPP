//
//  main.cpp
//  FactoryAbsBank
//
//  Created by Sathya Babu on 30/07/23.
//
#include <iostream>
#include <memory>

// Abstract class BankLoanOnFD
class BankLoanOnFD {
public:
    virtual ~BankLoanOnFD() = default;
    constexpr  virtual double getLoanInterest() const = 0;
};

// HDFC Bank implementation of BankLoanOnFD
class HDFCLoanOnFD : public BankLoanOnFD {
public:
    double getLoanInterest() const override {
        return 8.5; // Return HDFC bank's loan interest rate on FD
    }
};

// ICICI Bank implementation of BankLoanOnFD
class ICICILoanOnFD : public BankLoanOnFD {
public:
    double getLoanInterest() const override {
        return 9.0; // Return ICICI bank's loan interest rate on FD
    }
};

// Citi Bank implementation of BankLoanOnFD
class CitiLoanOnFD : public BankLoanOnFD {
public:
    double getLoanInterest() const override {
        return 7.8; // Return Citi bank's loan interest rate on FD
    }
};

// Abstract class BankLoan
class BankLoan {
public:
                virtual ~BankLoan() = default;
    constexpr   virtual double getLoanInterestRate() const = 0;
};

// Study Loan implementation of BankLoan
class StudyLoan : public BankLoan {
public:
    constexpr  double getLoanInterestRate() const override {
        return 6.0; // Return study loan interest rate
    }
};

// Car Loan implementation of BankLoan
class CarLoan : public BankLoan {
public:
    constexpr   double getLoanInterestRate() const override {
        return 7.5; // Return car loan interest rate
    }
};

// Housing Loan implementation of BankLoan
class HousingLoan : public BankLoan {
public:
    constexpr  double getLoanInterestRate() const override {
        return 8.0; // Return housing loan interest rate
    }
};

// Abstract class Bank (Abstract Factory)
// ironacally it can be called as provider in test casses.

class BankFactoryProducer {
public:
               virtual ~BankFactoryProducer() = default;
    constexpr  virtual std::unique_ptr<BankLoanOnFD> createLoanOnFD() const = 0;
    constexpr  virtual std::unique_ptr<BankLoan>     createLoan()     const = 0;
};

// HDFC Bank Factory
class HDFCBank : public BankFactoryProducer {
public:
    std::unique_ptr<BankLoanOnFD> createLoanOnFD() const override {
        return std::make_unique<HDFCLoanOnFD>();
    }

    std::unique_ptr<BankLoan> createLoan() const override {
        return std::make_unique<StudyLoan>();
    }
};

// ICICI Bank Factory
class ICICIBank : public BankFactoryProducer {
public:
    std::unique_ptr<BankLoanOnFD> createLoanOnFD() const override {
        return std::make_unique<ICICILoanOnFD>();
    }

    std::unique_ptr<BankLoan> createLoan() const override {
        return std::make_unique<CarLoan>();
    }
};

// Citi Bank Factory
class CitiBank : public BankFactoryProducer {
public:
    std::unique_ptr<BankLoanOnFD> createLoanOnFD() const override {
        return std::make_unique<CitiLoanOnFD>();
    }

    std::unique_ptr<BankLoan> createLoan() const override {
        return std::make_unique<HousingLoan>();
    }
};

int main() {
    std::unique_ptr<BankFactoryProducer> hdfcBank = std::make_unique<HDFCBank>();
    std::unique_ptr<BankFactoryProducer> iciciBank = std::make_unique<ICICIBank>();
    std::unique_ptr<BankFactoryProducer> citiBank = std::make_unique<CitiBank>();

    std::unique_ptr<BankLoanOnFD> hdfcLoan = hdfcBank->createLoanOnFD();
    std::unique_ptr<BankLoanOnFD> iciciLoan = iciciBank->createLoanOnFD();
    std::unique_ptr<BankLoanOnFD> citiLoan = citiBank->createLoanOnFD();

    std::unique_ptr<BankLoan> hdfcLoanType = hdfcBank->createLoan();
    std::unique_ptr<BankLoan> iciciLoanType = iciciBank->createLoan();
    std::unique_ptr<BankLoan> citiLoanType = citiBank->createLoan();

    std::cout << "HDFC Bank FD Loan Interest Rate: " << hdfcLoan->getLoanInterest() << "%\n";
    std::cout << "ICICI Bank FD Loan Interest Rate: " << iciciLoan->getLoanInterest() << "%\n";
    std::cout << "Citi Bank FD Loan Interest Rate: " << citiLoan->getLoanInterest() << "%\n";

    std::cout << "HDFC Bank Loan Type Interest Rate: " << hdfcLoanType->getLoanInterestRate() << "%\n";
    std::cout << "ICICI Bank Loan Type Interest Rate: " << iciciLoanType->getLoanInterestRate() << "%\n";
    std::cout << "Citi Bank Loan Type Interest Rate: " << citiLoanType->getLoanInterestRate() << "%\n";

    return 0;
}
/*
 
 HDFC Bank FD Loan Interest Rate: 8.5%
 ICICI Bank FD Loan Interest Rate: 9%
 Citi Bank FD Loan Interest Rate: 7.8%
 
 HDFC Bank Loan Type Interest Rate: 6%
 ICICI Bank Loan Type Interest Rate: 7.5%
 Citi Bank Loan Type Interest Rate: 8%
 
 Program ended with exit code: 0
 
 */
