#include "doctest.h"
#include "OrgChart.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

TEST_CASE("Making the tree"){
    CHECK_NOTHROW(OrgChart());
    OrgChart org = OrgChart();
    CHECK_NOTHROW(org.add_root("CEO"));
    CHECK_NOTHROW(org.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(org.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(org.add_sub("CEO", "COO"));
    CHECK_NOTHROW(org.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(org.add_sub("CTO", "VP_HR"));
    CHECK_NOTHROW(org.add_sub("CFO", "VP_FIN"));
    CHECK_NOTHROW(org.add_sub("COO", "VP_BI"));
    CHECK_NOTHROW(org.add_sub("VP_HR", "HR"));
    CHECK_NOTHROW(org.add_sub("VP_HR", "HR2"));
    
    for (int i=0; i<50; i++){
        CHECK_THROWS(org.add_sub("CEO" + to_string(i), "CTO")); 
    }

    for (int i=0; i<50; i++){
        CHECK_NOTHROW(org.add_root("CEO" + to_string(i)));
    }
}

TEST_CASE("Testing the iterator"){
    OrgChart org = OrgChart();
    CHECK_NOTHROW(org.add_root("CEO"));
    CHECK_NOTHROW(org.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(org.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(org.add_sub("CEO", "COO"));
    CHECK_NOTHROW(org.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(org.add_sub("CTO", "VP_HR"));
    CHECK_NOTHROW(org.add_sub("CFO", "VP_FIN"));
    CHECK_NOTHROW(org.add_sub("COO", "VP_BI"));
    CHECK_NOTHROW(org.add_sub("VP_HR", "HR"));
    CHECK_NOTHROW(org.add_sub("VP_HR", "HR2"));
    auto it = org.begin();
    CHECK_EQ(*it, "CEO");
    CHECK_EQ(*(++it), "CTO");
    CHECK_EQ(*(++it), "CFO");
    CHECK_EQ(*(++it), "COO");
    CHECK_EQ(*(++it), "VP_SW");
    CHECK_EQ(*(++it), "VP_HR");
    CHECK_EQ(*(++it), "VP_FIN");
    CHECK_EQ(*(++it), "VP_BI");
    CHECK_EQ(*(++it), "HR");
    CHECK_EQ(*(++it), "HR2");

    auto it_level = org.begin_level_order();
    CHECK_EQ(*it_level, "CEO");
    CHECK_EQ(*(++it_level), "CTO");
    CHECK_EQ(*(++it_level), "CFO");
    CHECK_EQ(*(++it_level), "COO");
    CHECK_EQ(*(++it_level), "VP_SW");
    CHECK_EQ(*(++it_level), "VP_HR");
    CHECK_EQ(*(++it_level), "VP_FIN");
    CHECK_EQ(*(++it_level), "VP_BI");
    CHECK_EQ(*(++it_level), "HR");
    CHECK_EQ(*(++it_level), "HR2");

    auto it_pre = org.begin_preorder();
    CHECK_EQ(*it_pre, "CEO");
    CHECK_EQ(*(++it_pre), "CTO");
    CHECK_EQ(*(++it_pre), "VP_SW");
    CHECK_EQ(*(++it_pre), "VP_HR");
    CHECK_EQ(*(++it_pre), "HR");
    CHECK_EQ(*(++it_pre), "HR2");
    CHECK_EQ(*(++it_pre), "CFO");
    CHECK_EQ(*(++it_pre), "VP_FIN");
    CHECK_EQ(*(++it_pre), "COO");
    CHECK_EQ(*(++it_pre), "VP_BI");

    auto it_rev = org.begin_reverse_order();
    CHECK_EQ(*it_rev, "HR2");
    CHECK_EQ(*(++it_rev), "HR");
    CHECK_EQ(*(++it_rev), "VP_BI");
    CHECK_EQ(*(++it_rev), "VP_FIN");
    CHECK_EQ(*(++it_rev), "VP_HR");
    CHECK_EQ(*(++it_rev), "VP_SW");
    CHECK_EQ(*(++it_rev), "COO");
    CHECK_EQ(*(++it_rev), "CFO");
    CHECK_EQ(*(++it_rev), "CTO");
    CHECK_EQ(*(++it_rev), "CEO");
}

TEST_CASE("<< operator"){
    OrgChart org = OrgChart();
    CHECK_NOTHROW(org.add_root("CEO"));
    CHECK_NOTHROW(org.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(org.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(org.add_sub("CEO", "COO"));
    CHECK_NOTHROW(org.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(org.add_sub("CTO", "VP_HR"));
    CHECK_NOTHROW(org.add_sub("CFO", "VP_FIN"));
    CHECK_NOTHROW(org.add_sub("COO", "VP_BI"));
    CHECK_NOTHROW(org.add_sub("VP_HR", "HR"));
    CHECK_NOTHROW(org.add_sub("VP_HR", "HR2"));
    CHECK_NOTHROW(cout << org);
}

