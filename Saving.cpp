#include "Saving.h"
#include "Account.h"

using namespace std;

Saving::Saving(const string & name, float balance, float rate):Account(name, balance), m_Rate(rate)
{
}

float Saving::getInterestRate() const
{
    return m_Rate;
}

void Saving::accumulateInterest()
{
    m_balance += (m_balance * m_Rate);
}
Saving::~Saving()
{
}
