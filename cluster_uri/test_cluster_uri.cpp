#include <iostream>
#include <gtest/gtest.h>
#include "src/cluster_uri.h"

TEST(CLUSTER_URI, _check_valid_scheme1) {
  std::string s0 = "zk://host1.domain.com:2110,host2.domain.com:2111,host3.domain.com:2112/foo/bar";
  cluster_uri my_uri(s0);
  EXPECT_EQ(my_uri.good(), true);
  auto s = my_uri.scheme();
  EXPECT_EQ(s, "zk");
}

TEST(CLUSTER_URI, check_bad_format1) {
  std::string s0 = "zk:/host1.domain.com:2110,host2.domain.com:2111,host3.domain.com:2112/foo/bar";
  cluster_uri my_uri(s0);
  EXPECT_EQ(my_uri.good(), false);
  auto s = my_uri.scheme();
  EXPECT_EQ(s, "");
}

TEST(CLUSTER_URI, check_authority) {
  cluster_uri my_uri("zk://host1.domain.com:2110,host2.domain.com:2111,host3.domain.com:2112/foo/bar");
  EXPECT_EQ(my_uri.authority(), "host1.domain.com:2110,host2.domain.com:2111,host3.domain.com:2112");
}

TEST(CLUSTER_URI, check_path1) {
  cluster_uri my_uri("zk://host1.domain.com:2110,host2.domain.com:2111,host3.domain.com:2112/foo/bar");
  EXPECT_EQ(my_uri.path(), "/foo/bar");
}

TEST(CLUSTER_URI, check_path2) {
  cluster_uri my_uri("zk://host1.domain.com:2110,host2.domain.com:2111,host3.domain.com:2112/foo");
  EXPECT_EQ(my_uri.path(), "/foo");
}

TEST(CLUSTER_URI, check_path3) {
  cluster_uri my_uri("zk://host1.domain.com:2110,host2.domain.com:2111,host3.domain.com:2112");
  EXPECT_EQ(my_uri.good(), true);
  EXPECT_EQ(my_uri.path(), "");
  EXPECT_EQ(my_uri.str(), "zk://host1.domain.com:2110,host2.domain.com:2111,host3.domain.com:2112");
}


TEST(CLUSTER_URI, check_str) {
  cluster_uri my_uri("zk://host1.domain.com:2110,host2.domain.com:2111,host3.domain.com:2112/foo");
  EXPECT_EQ(my_uri.str(), "zk://host1.domain.com:2110,host2.domain.com:2111,host3.domain.com:2112/foo");
}



