#include <sstream>
#include <string>
#include <vector>
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

TEST(TopCommonWordsTest,CountWordsWorks){
    std::stringstream in("Hello hello, the THE and bob bob !!");
    std::map<std::string,int> m=countWords(in);
    EXPECT_EQ(m["hello"],2);
    EXPECT_EQ(m["bob"],2);
    EXPECT_EQ(m.count("the"),0);
    EXPECT_EQ(m.count("and"),0);
}

TEST(TopCommonWordsTest,TopWordsKeepsTies){
    std::map<std::string,int> m;
    m["apple"]=5;
    m["banana"]=5;
    m["cat"]=4;
    m["dog"]=3;
    std::vector<std::pair<int,std::vector<std::string>>> v=topWords(m,1);
    ASSERT_EQ(v.size(),1);
    EXPECT_EQ(v[0].first,5);
    std::vector<std::string> ans={"apple","banana"};
    EXPECT_EQ(v[0].second,ans);
}

TEST(TopCommonWordsTest,PrintTopWorks){
    std::vector<std::pair<int,std::vector<std::string>>> v;
    v.push_back({5,{"apple","banana"}});
    v.push_back({3,{"dog"}});
    std::stringstream out;
    printTop(v,out);
    EXPECT_EQ(out.str(),"1.) These words appeared 5 times: {apple, banana}\n2.) These words appeared 3 times: {dog}\n");
}
