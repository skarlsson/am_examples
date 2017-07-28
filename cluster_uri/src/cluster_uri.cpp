#include "cluster_uri.h"

#include <iostream>

cluster_uri::cluster_uri(std::string s)
: good_(false)
{
  std::cout << s << std::endl;
  authority_ = "host1.domain.com:2110,host2.domain.com:2111,host3.domain.com:2112";
 if (s.size()<5) {
   good_ = true;
 }

}


