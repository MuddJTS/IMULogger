
#ifndef __SENTRAL_H__
#define __SENTRAL_H__

#include "filestructures.hpp"
#include "EM7180_Master.h"

class SentralManager {
public:
  SentralManager();
  SentralManager& operator=(const SentralManager& rhs) = default;
  ~SentralManager() = default;
  
  void getSentral(EM7180_Master &em7180);
}


#endif