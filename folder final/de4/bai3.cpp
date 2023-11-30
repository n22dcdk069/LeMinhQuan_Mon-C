#include <iostream>
#include <string>
#include <vector>

class Info {
protected:
    std::string name;
    std::string idCard;
    std::string address;

public:
    Info(std::string n, std::string id, std::string addr) : name(n), idCard(id), address(addr) {}

    // Accessor function for name
    std::string getName() const {
        return name;
    }
};

class Billing {
protected:
    double callRate;
    double dataRate;
    int freeDataLimit;
    double fixedCharge;

public:
    Billing(double call, double data, int limit, double fixed) : callRate(call), dataRate(data), freeDataLimit(limit), fixedCharge(fixed) {}
    virtual ~Billing() {}

    virtual double calculateCharge(int callMinutes, int dataUsage) = 0;
};

class BasicBilling : public Billing {
public:
    BasicBilling(double call, double data, int limit, double fixed) : Billing(call, data, limit, fixed) {}

    virtual double calculateCharge(int callMinutes, int dataUsage) override {
        double callCharge = callMinutes * callRate;
        double dataCharge = dataUsage > freeDataLimit ? (dataUsage - freeDataLimit) * dataRate : 0;
        double totalCharge = callCharge + dataCharge + fixedCharge;
        return totalCharge * 1.1; // VAT is 10%
    }
};

class DataFree : public BasicBilling {
public:
    DataFree(double call, double data, int limit, double fixed) : BasicBilling(call, data, limit, fixed) {}

    virtual double calculateCharge(int callMinutes, int dataUsage) override {
        return fixedCharge * 1.1; // Only charge fixed fee, no additional data charge
    }
};

class DataFix : public BasicBilling {
public:
    DataFix(double call, double data, int limit, double fixed) : BasicBilling(call, data, limit, fixed) {}

    virtual double calculateCharge(int callMinutes, int dataUsage) override {
        double basicCharge = BasicBilling::calculateCharge(callMinutes, dataUsage);
        return basicCharge - basicCharge * 0.1; // 10% discount
    }
};

class Contract {
private:
    Info customerInfo;
    Billing* billingInfo;

public:
    Contract(Info info, Billing* billing) : customerInfo(info), billingInfo(billing) {}

    ~Contract() {
        delete billingInfo;
    }

    void notifyCharge(int callMinutes, int dataUsage) {
        double charge = billingInfo->calculateCharge(callMinutes, dataUsage);
        std::cout << "Customer: " << customerInfo.getName() << "\nTotal Charge: " << charge << std::endl;
    }
};

int main() {
    Info customer("John Doe", "123456789", "123 Main St");
    BasicBilling basicBill(0.5, 0.1, 100, 50);
    DataFree dataFreeBill(0.4, 0.08, 200, 40);
    DataFix dataFixBill(0.6, 0.12, 150, 70);

    Contract basicContract(customer, new BasicBilling(0.5, 0.1, 100, 50));
    Contract dataFreeContract(customer, new DataFree(0.4, 0.08, 200, 40));
    Contract dataFixContract(customer, new DataFix(0.6, 0.12, 150, 70));

    // Simulate usage
    basicContract.notifyCharge(120, 300);
    dataFreeContract.notifyCharge(80, 150);
    dataFixContract.notifyCharge(90, 180);

    return 0;
}
