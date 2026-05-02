#include <string>
#include "TopCommonWords.h"
#include "gtest/gtest.h"
#include "rapidcheck/gtest.h"

TEST(TopCommonWordsTest,CleanWordWorks){
    EXPECT_EQ(cleanWord("HELLO"),"hello");
    EXPECT_EQ(cleanWord("!!$#%hello<>?/"),"hello");
    EXPECT_EQ(cleanWord("123abc!!!"),"123abc");
    EXPECT_EQ(cleanWord("!!!"),"");
}

TEST(TopCommonWordsTest,SkipWordWorks){
    EXPECT_TRUE(skipWord("a"));
    EXPECT_TRUE(skipWord("the"));
    EXPECT_FALSE(skipWord("hello"));
}

TEST(TopCommonWordsTest,ShowWordsWorks){
    std::vector<std::string> v={"apple","banana","dog"};
    EXPECT_EQ(showWords(v),"{apple, banana, dog}");
}
