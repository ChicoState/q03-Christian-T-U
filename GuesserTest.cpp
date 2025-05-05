/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Example "smoke test" (can be deleted)
TEST(GuesserTest, smoke_test)
{
  Guesser object("Secret");
  ASSERT_EQ( 1+1, 2 );
}



//class initialization tests...
TEST(GuesserTest, empty_class) //basic initialization
{
  Guesser object("password");
  ASSERT_EQ( 3, object.remaining() );
}
TEST(GuesserTest, truncated_password) //truncated initialization
{
  Guesser object("onetwothreefourfivesixseveneightnine");
  ASSERT_EQ( 1, object.match("onetwothreefourfivesixseveneight") );
}



//dist tests (N/A privated)...



//remaining tests...
TEST(GuesserTest, remaining_after_4_guesses) //guesses wrong four times to see if it goes below 0
{
  Guesser object("Secret");
  object.match("Cecret");
  object.match("Kecret");
  object.match("Eecret");
  object.match("Zecret");
  ASSERT_EQ( 0, object.remaining() );
}
TEST(GuesserTest, remaining_after_3_guesses) //guesses wrong thrice
{
  Guesser object("Secret");
  object.match("Cecret");
  object.match("Kecret");
  object.match("Eecret");
  ASSERT_EQ( 0, object.remaining() );
}
TEST(GuesserTest, remaining_after_2_guesses) //guesses wrong twice
{
  Guesser object("Secret");
  object.match("Cecret");
  object.match("Kecret");
  ASSERT_EQ( 1, object.remaining() );
}
TEST(GuesserTest, remaining_after_1_guess) //guesses wrong once
{
  Guesser object("Secret");
  object.match("Cecret");
  ASSERT_EQ( 2, object.remaining() );
}
TEST(GuesserTest, remaining_after_no_guesses) //no guess yet
{
  Guesser object("Secret");
  ASSERT_EQ( 3, object.remaining() );
}
TEST(GuesserTest, remaining_reset) //remaining reset
{
  Guesser object("Secret");
  object.match("Cecret");
  object.match("Kecret");
  object.match("Secret");
  ASSERT_EQ( 3, object.remaining() );
}
TEST(GuesserTest, count_down_after_lockout) //remaining reset
{
  Guesser object("Secret");
  object.match("wrong");
  object.match("Cecret");
  ASSERT_EQ( 1, object.remaining() );
}



//match tests...
TEST(GuesserTest, correct_guess) //correct match
{
  Guesser object("Secret");
  ASSERT_EQ( 1, object.match("Secret") );
}
TEST(GuesserTest, guess_too_long) //string longer than secret
{
  Guesser object("Secret");
  ASSERT_EQ( 0, object.match("Secretsss") );
}
TEST(GuesserTest, guess_too_short) //string shorter than secret
{
  Guesser object("Secret");
  ASSERT_EQ( 0, object.match("Secr") );
}
TEST(GuesserTest, guess_different_by_2) //off by 2
{
  Guesser object("Secret");
  ASSERT_EQ( 0, object.match("Secrip") );
}
TEST(GuesserTest, case_sensitivity) //test k-sensitivity
{
  Guesser object("Secret");
  ASSERT_EQ( 0, object.match("secreT") );
}
TEST(GuesserTest, Lock_test_3_guesses) //3 guesses to see if it locked
{
  Guesser object("Secret");
  object.match("Cecret");
  object.match("Eecret");
  object.match("Kecret");
  ASSERT_EQ( 0, object.match("Secret") );
}
TEST(GuesserTest, Lock_test_2_guesses) //2 guesses to see if it locked
{
  Guesser object("Secret");
  object.match("Cecret");
  object.match("Eecret");
  ASSERT_EQ( 1, object.match("Secret") );
}
TEST(GuesserTest, Lock_test_1_guess) //1 guess to see if it locked
{
  Guesser object("Secret");
  object.match("Cecret");
  ASSERT_EQ( 1, object.match("Secret") );
}



//gcov appended tests...
TEST(GuesserTest, Line_32) //1 guess to see if it locked
{
  Guesser object("Secret");
  object.match("hbdcknsceniveknvk");
  ASSERT_EQ( 0, object.match("Secret") );
}