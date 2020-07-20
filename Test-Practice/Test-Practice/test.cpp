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

	bool withdraw(const int amount)
	{
		if (amount <= balance)
		{
			balance -= amount;
			return true;
		}
		return false;
	}
};

struct BankAccountTest :testing::Test
{
	BankAccount* account;//setting up a local bank account to avoid creating a copy in every test case
	BankAccountTest()
	{
		account = new BankAccount;
	}
	virtual ~BankAccountTest()
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

struct account_state
{
	int init_balance;
	int withdraw_amount;
	int final_balance;
	bool success;
};

struct WithdrawAccountTest : BankAccountTest, testing::WithParamInterface<account_state> //parametirized test case
{
	WithdrawAccountTest()
	{
		account->balance = GetParam().init_balance;
	}
};

TEST_P(WithdrawAccountTest, FinalBalance)
{
	auto as = GetParam();
	auto success = account->withdraw(as.withdraw_amount);
	EXPECT_EQ(as.final_balance, account->balance);//does the final balance equal the right amount in the account
	EXPECT_EQ(as.success, success); 
}

INSTANTIATE_TEST_CASE_P(default, WithdrawAccountTest, testing::Values(account_state{ 100,50,50,true }, account_state{ 100,200,100,false })); 
//first account state should allow you to start with 100 then withdraw 50, be left with 50 and the success should be set to true.
//second account state should start the balance at 100 then upon requesting to withdraw 200 this should fail and the account balance should be left as 100.

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
