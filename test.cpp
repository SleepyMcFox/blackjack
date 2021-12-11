#include "utils.h"
#include "../blackjack/Blackjack.h"
#include "../blackjack/Card.h"

class TEST_LOGIC
{    
    public:
        int CheckTotalHandValue(Player &p)
        {
            int total = 0;
            int nbOfAces = 0;
            int handSize = p.handSize;

            for(int i = 0; i < handSize; i++)
            {
                if(p.plaHand[i].getValue() == 1)
                {
                    nbOfAces++;
                }
                else
                {
                    total += p.plaHand[i].getValue();
                }
            }

            //Checks to determine the value of the aces in your hand, Dealer
            //will have a different check
            while(nbOfAces != 0)
            {
                nbOfAces--;
                if((total + 11 + nbOfAces) <= 21)
                {
                    total += 11;
                }
                else
                {
                    total++;
                }
            }
            return total;
        }

};

class CARD_CREATION_TEST_HARNESS : public AbstractTestHarness
{
    private:
        TEST_LOGIC T = TEST_LOGIC();
    public:
    //Since I'm not familiar with unit testing in c++, I'm doing my best from what I can remember
        Player p;

        CARD_CREATION_TEST_HARNESS()
        {
            p.handSize = 3;
            p.plaHand[0] = Card(10, 'S');
            p.plaHand[1] = Card(10, 'H');
            p.plaHand[2] = Card(1, 'H');
            register_test_func("Hand Value of Test Player 21",
                                 [this]()-> void { assert_equal(21,T.CheckTotalHandValue(p)); });
            // p.handSize = 2;
            // p.plaHand[0] = Card(12, 'S');
            // p.plaHand[1] = Card(1, 'S');
            // register_test_func("Hand Value of Test Player 10",
            //                      [this]()->void{ assert_equal(21, T.CheckTotalHandValue(p)); } );
        }

};

class GlobalTestManager : public TestManager
{
    public:
        GlobalTestManager() { add_test("Hand Value Tests", CARD_CREATION_TEST_HARNESS()); }
};

int main(int argc, char ** argv) 
{
    GlobalTestManager tr = GlobalTestManager();
    tr.execute();
}
