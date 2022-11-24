#include <iostream>
#include <map>
#include <sstream>
#include <iomanip>
#include <string>

class FakeCantor {
 private:
  std::map<std::string, float> rates{{"USD", 1.0366f},
                                     {"GBP", 0.87063f},
                                     {"CHF", 0.9881f},
                                     {"JPY", 145.12f}};
 public:
  FakeCantor() = default;
  float EuroToRate(const std::string &currency) {
    return rates[currency];
  };
};

class Currency {
 public:
  virtual Currency *AddedCurrency(float value, std::string currency) = 0;
  virtual Currency *SubtractedCurrency(float value, std::string currency) = 0;
  virtual std::string Abbreviation() = 0;
  virtual std::string Symbol() = 0;
  virtual std::string Balance() = 0;
  virtual float DollarExchangeRate() = 0;
};

class Euro : public Currency {
  // TODO: implement class
    private:
        float money;
        FakeCantor *rates=new FakeCantor;
    public:
        Euro()
        {
            this->money=0;
        }
        std::string Balance()
        {
            return std::to_string(this->money);
        }
        std::string Abbreviation()
        {
            return "EUR";
        }
        std::string Symbol()
        {
            return "E";
        }
        Euro(float bank)
        {
            this->money=bank;
        }
        float DollarExchangeRate()
        {
            std::string Dollar="USD";
            return rates->EuroToRate(Dollar);
        }
        Euro *AddedCurrency(float value, std::string currency)
        {
            Euro *client=new Euro;
            client->money+=(value*rates->EuroToRate(currency));
            return client;
        }
        Euro *SubtractedCurrency(float value, std::string currency)
        {
            Euro *client=new Euro;
            client->money-=(value*rates->EuroToRate(currency));
            return client;
        }

};

int main() {
  // TODO: showcase usage
    Euro client(132.63);
    std::cout<<client.Abbreviation()<<"\n";
    std::cout<<client.Balance()<<"\n";
    std::cout<<client.DollarExchangeRate()<<"\n";
    std::cout<<client.Symbol()<<"\n";
    client.AddedCurrency(13,"USD");
    std::cout<<client.Balance()<<"\n";

  return 0;
}
