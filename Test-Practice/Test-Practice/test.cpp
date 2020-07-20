#include "pch.h"
struct BankAccount
{
	int balance = 0;

	BankAccount()
	{
		//DEFAULT CONSTRUCTOR
	}

	explicit BankAccount(const int balance) : balance{ balance }
	{

	}

	void deposit(const int n)
	{
		balance += n;
	}
};

struct BankAccountTest :testing::Test
{
	BankAccount* account;//setting up a local bank account to avoid creating a copy in every test case
	BankAccountTest()
	{
		account = new BankAccount;
	}
	~BankAccountTest()
	{
		delete account;
	}
};

TEST_F(BankAccountTest, BankAccountStartsEmpty) //basic test to see if the balance has been initialised to a default value of 0
{
	
	EXPECT_EQ(0, account->balance); //checking if what we expect is true
}
TEST_F(BankAccountTest, CanDepositMoney)
{
	account->deposit(100);
	EXPECT_EQ(100, account->balance);
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
