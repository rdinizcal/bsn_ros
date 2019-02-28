#include <gtest/gtest.h>

#include "goalmodel/Context.hpp"
#include "goalmodel/Property.hpp"
#include "goalmodel/Goal.hpp"

using namespace bsn::goalmodel;

class GoalTest : public testing::Test { 
    protected:
        GoalTest() {}

        virtual void SetUp() {
        }
};

TEST_F(GoalTest, SimpleConstruct) {
    std::string id = "G3_T1.11";
    std::string description = "Read data";

    Goal task(id, description);

    ASSERT_EQ(task.getID(), id);
    ASSERT_EQ(task.getDescription(), description);
}
/*
TEST_F(GoalTest, AddChild) {

    Goal parentGoal("G3_T1", "Read");
    Goal childGoal("G3_T1.4", "Read ABP");

    parentGoal.addChild(childGoal);

    ASSERT_EQ(parentGoal.getChildren().size(), 1);
    EXPECT_TRUE(parentGoal.getChildren().at(0)==childGoal);

}

TEST_F(GoalTest, RemoveChild) {

    Goal parentGoal("G3_T1", "Read");
    Goal childGoal("G3_T1.4", "Read ABP");
    parentGoal.addChild(childGoal);

    parentGoal.removeChild("G3_T1.412");

    ASSERT_EQ(parentGoal.getChildren().size(), 0);
}

TEST_F(GoalTest, RemoveChildNotFound) {

    Goal parentGoal("G3_T1", "Read");
    Goal childGoal("G3_T1.4", "Read ABP");
    parentGoal.addChild(childGoal);

    try {
        parentGoal.removeChild("XXX");
        FAIL() << "Expected Not Found exception";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("Not Found"));
    }
}

TEST_F(GoalTest, GetChild) {

    Goal parentGoal("G3_T1", "Read");
    Goal childGoal("G3_T1.4", "Read ABP");
    parentGoal.addChild(childGoal);

    Goal returnedGoal = parentGoal.getChild("G3_T1.412");

    ASSERT_EQ(returnedGoal.getID(), "G3_T1.412");
}

TEST_F(GoalTest, GetChildNotFound) {

    Goal parentGoal("G3_T1", "Read");
    Goal childGoal("G3_T1.4", "Read ABP");
    parentGoal.addChild(childGoal);

    try {
        Goal returnedGoal = parentGoal.getChild("XXX");
        FAIL() << "Expected Not Found exception";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("Not Found"));
    }
}*/