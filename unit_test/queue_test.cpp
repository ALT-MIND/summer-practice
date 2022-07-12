extern "C"{
    #include "../include/queue.h"
}

#include "gtest/gtest.h"

TEST(Basic_Queue_Func, Queue){
    Queue * test = create_queue(5);
    pos test_ites;
    for (int i = 0; i < 5; i++) {
        test_ites.x = i;
        test_ites.y = i * 2 + 1;
        enqueue(test, test_ites);
    }
    test_ites = front(test);
    EXPECT_EQ(0, test_ites.x);
    EXPECT_EQ(1, test_ites.y);
    dequeue(test);
    test_ites = dequeue(test);
    EXPECT_EQ(1, test_ites.x);
    EXPECT_EQ(3, test_ites.y);
    dequeue(test);
    dequeue(test);
    dequeue(test);
    test_ites = dequeue(test);
    EXPECT_EQ(-2, test_ites.x);
    EXPECT_EQ(-2, test_ites.y);

}