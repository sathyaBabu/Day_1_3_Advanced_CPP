//
//  main.cpp
//  FactoryAbsBank_SingleObject
//
//  Created by Sathya Babu on 30/07/23.
//
#include <iostream>
#include <memory>

 
 
 /*
  
  Code demonstrates how the abstract factory pattern can be used to create families of related objects (different types of loans and loans on FD) while adhering to the Single Responsibility Principle.
  
  
 We have created factories for different types of loans (StudyLoanFactory, CarLoanFactory, and HousingLoanFactory) and factories for different banks' loans on FD (HDFCLoanOnFDFactory, ICICILoanOnFDFactory, and CitiLoanOnFDFactory). Each factory is responsible for creating the respective type of loan.

 We then use these factories to create different types of loans and loans on FD. Finally,
  we display the interest rates of each loan and loan on FD using the displayLoanInterest and displayLoanOnFDInterest functions, respectively.

  
 */





// Abstract class BankLoanOnFD
class BankLoanOnFD {
public:
    virtual ~BankLoanOnFD() = default;
    virtual double getLoanInterest() const = 0;
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
    virtual double getLoanInterestRate() const = 0;
};

// Study Loan implementation of BankLoan
class StudyLoan : public BankLoan {
public:
    double getLoanInterestRate() const override {
        return 6.0; // Return study loan interest rate
    }
};

// Car Loan implementation of BankLoan
class CarLoan : public BankLoan {
public:
    double getLoanInterestRate() const override {
        return 7.5; // Return car loan interest rate
    }
};

// Housing Loan implementation of BankLoan
class HousingLoan : public BankLoan {
public:
    double getLoanInterestRate() const override {
        return 8.0; // Return housing loan interest rate
    }
};

// Abstract class BankLoanFactory
class BankLoanFactory {
public:
    virtual ~BankLoanFactory() = default;
    virtual std::unique_ptr<BankLoan> createLoan() const = 0;
};

// Study Loan Factory
class StudyLoanFactory : public BankLoanFactory {
public:
    std::unique_ptr<BankLoan> createLoan() const override {
        return std::make_unique<StudyLoan>();
    }
};

// Car Loan Factory
class CarLoanFactory : public BankLoanFactory {
public:
    std::unique_ptr<BankLoan> createLoan() const override {
        return std::make_unique<CarLoan>();
    }
};

// Housing Loan Factory
class HousingLoanFactory : public BankLoanFactory {
public:
    std::unique_ptr<BankLoan> createLoan() const override {
        return std::make_unique<HousingLoan>();
    }
};

// Abstract class BankLoanOnFDFactory
class BankLoanOnFDFactory {
public:
    virtual ~BankLoanOnFDFactory() = default;
    virtual std::unique_ptr<BankLoanOnFD> createLoanOnFD() const = 0;
};

// HDFC Bank Loan on FD Factory
class HDFCLoanOnFDFactory : public BankLoanOnFDFactory {
public:
    std::unique_ptr<BankLoanOnFD> createLoanOnFD() const override {
        return std::make_unique<HDFCLoanOnFD>();
    }
};

// ICICI Bank Loan on FD Factory
class ICICILoanOnFDFactory : public BankLoanOnFDFactory {
public:
    std::unique_ptr<BankLoanOnFD> createLoanOnFD() const override {
        return std::make_unique<ICICILoanOnFD>();
    }
};

// Citi Bank Loan on FD Factory
class CitiLoanOnFDFactory : public BankLoanOnFDFactory {
public:
    std::unique_ptr<BankLoanOnFD> createLoanOnFD() const override {
        return std::make_unique<CitiLoanOnFD>();
    }
};

// Example usage of the factories

void displayLoanInterest(const BankLoan& loan) {
    std::cout << "Loan Interest Rate: " << loan.getLoanInterestRate() << "%" << std::endl;
}

void displayLoanOnFDInterest(const BankLoanOnFD& loanOnFD) {
    std::cout << "Loan on FD Interest Rate: " << loanOnFD.getLoanInterest() << "%" << std::endl;
}

int main() {
    // Create factories
    std::unique_ptr<BankLoanFactory> studyLoanFactory = std::make_unique<StudyLoanFactory>();
    std::unique_ptr<BankLoanFactory> carLoanFactory = std::make_unique<CarLoanFactory>();
    std::unique_ptr<BankLoanFactory> housingLoanFactory = std::make_unique<HousingLoanFactory>();

    std::unique_ptr<BankLoanOnFDFactory> hdfcLoanOnFDFactory = std::make_unique<HDFCLoanOnFDFactory>();
    std::unique_ptr<BankLoanOnFDFactory> iciciLoanOnFDFactory = std::make_unique<ICICILoanOnFDFactory>();
    std::unique_ptr<BankLoanOnFDFactory> citiLoanOnFDFactory = std::make_unique<CitiLoanOnFDFactory>();

    // Create loans
    std::unique_ptr<BankLoan> studyLoan = studyLoanFactory->createLoan();
    std::unique_ptr<BankLoan> carLoan = carLoanFactory->createLoan();
    std::unique_ptr<BankLoan> housingLoan = housingLoanFactory->createLoan();

    std::unique_ptr<BankLoanOnFD> hdfcLoanOnFD = hdfcLoanOnFDFactory->createLoanOnFD();
    std::unique_ptr<BankLoanOnFD> iciciLoanOnFD = iciciLoanOnFDFactory->createLoanOnFD();
    std::unique_ptr<BankLoanOnFD> citiLoanOnFD = citiLoanOnFDFactory->createLoanOnFD();

    // Display loan interest rates
    displayLoanInterest(*studyLoan);
    displayLoanInterest(*carLoan);
    displayLoanInterest(*housingLoan);

    // Display loan on FD interest rates
    displayLoanOnFDInterest(*hdfcLoanOnFD);
    displayLoanOnFDInterest(*iciciLoanOnFD);
    displayLoanOnFDInterest(*citiLoanOnFD);

    return 0;
}

/*
 
 Loan Interest Rate: 6%
 Loan Interest Rate: 7.5%
 Loan Interest Rate: 8%
 Loan on FD Interest Rate: 8.5%
 Loan on FD Interest Rate: 9%
 Loan on FD Interest Rate: 7.8%
 Program ended with exit code: 0
 
 */
